#include "biblioteca.h"

//Funcao para aluguel/compra de livros
void AlugarComprar(struct livros livro[], int contador, int id, struct clientes cliente[], int contadorcliente){

    int idlivro, aux=0, op=0, escolha = 0, sim = 0;
    char nome[100] = "  ";

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

        sim=0;

        if(op==1){
            printf("\n Por favor digite o nome do livro que deseja alugar: \n");
            fflush(stdin);
            gets(nome);

            idlivro = id_nome(nome);

            for(int i = 0; i<contador; i++){
                if(livro[i].id == idlivro){
                    printf("\n O livro %s foi alugado com sucesso, tenha uma otima leitura! \n", nome);
                    //Aumenta o contador de alugueis
                    livro[i].qtd_alugado++;
                    //Diminue a quantidade em estoque
                    livro[i].qtd_estoque--;

                    int sim=0;
                    // Adiciona o nome do livro alugado na strutct do cliente
                    for(int i=0; i < contadorcliente; i++){
                        if(cliente[i].id == id){
                            for(int j=0; j < 20 ; j++){
                                if(cliente[i].livros_alugado[j][0] == '.' && sim != 1){
                                    strcpy(cliente[i].livros_alugado[j], nome);
                                    sim = 1;
                                }
                            }
                        }
                    }

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
                    printf("\n O livro %s foi comprado com sucesso, agradecemos a preferencia e boa leitura!\n", nome);
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

}

///Funcao pra devolver livros alugados
void Devolver(struct livros livro[], int contador, int id, struct clientes cliente[], int contadorcliente){
    int idlivro, aux=0, op=0, poslivro=0, posalugado=0;
    char nome[50];


    while(aux==0){

        printf("\n Por favor digite o nome do livro que deseja devolver \n");
        fflush(stdin);
        gets(nome);

        idlivro = id_nome(nome);

        for(int i = 0; i<contador; i++){
            if(livro[i].id==idlivro){
                poslivro=i;
            }
        }

        for(int i=0; i < contadorcliente; i++){
            if(cliente[i].id == id){
                //Verifica se o livro foi realmente alugado por esse cliente
                for(int j=0; j < 20 ; j++){
                    if(strncmp(cliente[i].livros_alugado[j],nome,50) == 0){
                        posalugado=j;

                        printf("\n O livro %s foi devolvido com sucesso!\n", nome);

                        //Aumenta a quatidade em estoque
                        livro[poslivro].qtd_estoque++;

                        aux=1;

                        printf("\n Deseja avaliar o livro?\n1 - Sim\n2 - Nao\n");
                        scanf("%i", &op);

                        if(op == 1){
                            avaliar(livro, contador);
                        }

                        //Tira o nome do livro do struct do cliente e desloca os outros livros pra esquerda
                        for(int k=j; k < 20; k++){
                            strcpy(cliente[i].livros_alugado[k], cliente[i].livros_alugado[k+1]);
                        }

                    }
                }
            }
        }

        if(aux==0){
            printf("\n Desculpe mas o livro %s nao foi encontrado.\n", nome);
            idlivro=0;
        }
    }

}
