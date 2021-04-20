#include "biblioteca.h"

//Funcao para aluguel/compra de livros
int AlugarComprar(struct livros livro[], int contador){

    int idlivro, aux=0, op=0, escolha = 0;
    char nome[100];

    printf("\n Deseja ver o catalogo antes? \n Digite 1 - Sim \n Digite 2 - Nao\n");
    scanf("%i", &escolha);

    do{
        if(escolha == 1){
            catalogo(livro, contador);

            escolha = 2;
        }
        else if(escolha != 2){
            printf("\n Essa entrada nao eh valida\n");
        }

    }while(escolha!= 2);

    while(op!=3){

        printf("\n O que deseja fazer: \n 1-Alugar um livro \n 2-Comprar um livro \n 3-Sair\n");
        scanf("%i", &op);


        if(op==1){
            printf("\n Por favor digite o nome do livro que deseja alugar: \n");
            fflush(stdin);
            gets(nome);

            idlivro = id_nome(nome);

            for(int i = 0; i<contador; i++){
                if(livro[i].id == idlivro){
                    printf("\n O livro %s alugado com sucesso, tenha uma otima leitura! \n", nome);
                    //Aumenta o contador de alugueis
                    livro[i].qtd_alugado++;
                    //Diminue a quatidade em estoque
                    livro[i].qtd_estoque--;
                    aux=1;
                }
            }

        }

        else if(op==2){
            aux=0;
            printf("\n Por favor digite o nome do livro que deseja comprar: \n");
            fflush(stdin);
            gets(nome);

            idlivro = id_nome(nome);

            for(int i = 0; i<contador; i++){
                if(livro[i].id == idlivro){
                    printf("\n O livro %s comprado com sucesso, agradecemos a preferencia e boa leitura!\n", nome);
                    //Aumenta o contador de compras
                    livro[i].qtd_comprado++;
                    //Diminui a quatidade em estoque
                    livro[i].qtd_estoque--;
                    aux=1;
                }
            }
        }

        else if(op!= 3){
            printf("\n Essa entrada nao eh valida\n");
        }

        if (aux==0 && op!=3){
            printf("\n Desculpe mas o livro %s nao foi encontrado.\n", nome);
            idlivro=0;
        }
    }

    printf("\n Voce saiu da sessao de compras/alugueis! \n");

    return contador;
}

///Funcao pra devolver livros alugados
int Devolver(struct livros livro[], int contador){
    int idlivro, aux=0, op=0;
    char nome[100];


    while(aux==0){

        printf("\n Por favor digite o nome do livro que deseja devolver \n");
        fflush(stdin);
        gets(nome);

        idlivro = id_nome(nome);

        for(int i = 0; i<contador; i++){
            if(livro[i].id==idlivro){
                printf("\n O livro %s foi devolvido com sucesso!\n", nome);

                //Aumenta a quatidade em estoque
                livro[i].qtd_estoque++;
                aux=1;

                printf("\n Deseja avaliar o livro?\n1 - Sim\n2 - Nao\n");
                scanf("%i", &op);

                if(op == 1){
                    avaliar(livro, contador);
                }
            }
        }
        if(aux==0){
            printf("\n Desculpe mas o livro %s nao foi encontrado.\n", nome);
            idlivro=0;
        }
    }

    return contador;

}
