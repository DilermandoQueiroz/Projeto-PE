#include "biblioteca.h"

//Funcao para avisar o funcionario que os estoque de um livro esta baixo
void EstoqueBaixo(struct livros livros[], int contador){

    int qtd=0, num=0;;

    //Verifica a quantidade de livros com menos de 6 unidades no estoque
    for(int i=0; i < contador ;i++){
        if(livros[i].qtd_estoque <= 5){
            qtd++;
        }
     }

    //Cria uma struct temporaria pra armazenar os livros com estoque baixo
    struct livros *livrotemp = NULL;
    livrotemp = (struct livros *) calloc(qtd,sizeof(struct livros));

    //Verifica se alocacao deu certo
    if(livrotemp == NULL){
        printf("Erro, memoria insuficiente.\n");

    }else{

        //Adiciona os livros com 5 unidades os menos na struct temporaria
        for(int i=0; i < contador ;i++){
            if(livros[i].qtd_estoque <= 5){
                livrotemp[num].id = livros[i].id;
                strcpy(livrotemp[num].nome, livros[i].nome);
                livrotemp[num].qtd_estoque = livros[i].qtd_estoque;
                num++;
            }

        }

        //Imprime os livros que estao na struct temporaria
        if(qtd>0){
            printf("\n------------------------ ! Aviso ! ------------------------\n \n");
            printf("Os seguintes livros estao com baixa quantidade em estoque.\n");
            printf("Por favor adicionar mais unidades ao estoque.\n \n");
            for(int j=0; j < qtd; j++){
                printf("ID: %i | ", livrotemp[j].id);
                printf("Nome: %s | ", livrotemp[j].nome);
                printf("Quantidade em estoque: %i ", livrotemp[j].qtd_estoque);
                printf("\n");
            }
            printf("\n-----------------------------------------------------------\n");
        }
    }

    //Libera memoria
    free(livrotemp);

}

//Funcao pra lembrar o cliente de devolver os livros alugados
void DevolverLivros(struct clientes cliente[], int contador, int id){

    //Encontra na struct o cliente
    for(int i=0; i < contador ;i++){
        if(cliente[i].id == id){
            //Verifica se possui algum livro alugado
            if(cliente[i].livros_alugado[0][0] != '.'){
                //Imprime os livros alugados
                printf("\n------------------------- ! Aviso ! -------------------------\n \n");
                printf("Voce alugou os seguintes livros:\n\n");
                for(int j=0; j < 20 ; j++){
                    if(cliente[i].livros_alugado[j][0] != '.'){
                        printf("%s \n",cliente[i].livros_alugado[j]);
                    }
                }
                printf("\nPor favor delvolva-os depois de utiliza-los.\n");
                printf("\nTambem nao se esqueca de avaliar o livro depois de devolver.\n");
                printf("\n------------------------------------------------------------\n");
            }
        }
    }



}
