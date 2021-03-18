#include "biblioteca.h"

/*
Funcao para adicionar ou remover um livro pelo seu ID
*/

int adicionar_remover(int livros[100][6], char nome_livros[100][20], int contador)
{
    int aux = 0, flag = 1, colunas = 6;

    while(flag != 2){
        printf("\n Voce deseja: \n 1->Adicionar um livro \n 2->Remover um livro\n");
        scanf("%d", &aux);

        //adiciona um livro
        if(aux == 1){
            char nome[100];
            int id, flag = 1;
            printf("\n Insira o nome do livro\n");
            fflush(stdin);
            gets(nome);
            id = id_nome(nome);

            //verifica se o livro ja esta cadastrado
            for(int i = 0; i<contador; i++){
                if(livros[i][0] == id){
                    printf("\n Esse livro ja esta cadastrado\n");
                    flag = 0;
                }
            }
            //verifica se ja atingiu o limite
            if(contador == 100){
                printf("\n Nao existe mais espaço na biblioteca\n");
            }
            //se o livro nao estiver cadastrado, cadastra ele
            else if(flag != 0){
                //insere o id do livro
                livros[contador][0] = id;

                //inicializa como 0 as outras colunas
                for(int k=1; k<colunas; k++){
                    if(k==2){
                        livros[contador][k]=10;
                    }else{
                        livros[contador][k] = 0;
                    }
                }

                //insero o nome do livro
                for(int n=0; n<=strlen(nome); n++){
                    nome_livros[contador][n] = nome[n];
                }
                contador++;
                printf("\n Adicionado com sucesso!\n");
            }

        //remove um livro
        }
        else if(aux == 2){
            int flag2 = 0, aux, id=0;
            char nome[100];

            printf("\n Insira o nome do livro que deseja remover\n");
            fflush(stdin);
            gets(nome);

            id = id_nome(nome);

            //verifica se o livro consta na biblioteca e o remove
            for(int i = 0; i<contador; i++){
                if(livros[i][0] == id){
                    flag2 = 1;
                    aux = i;

                    //desloca uma possicao para a esquerda a partir da que foi removida
                    for(aux; aux<contador; aux++){
                        //realiza para cada coluna do livros
                        for(int k=0; k<colunas; k++){
                            livros[aux][k] = livros[aux+1][k];
                        }
                    }
                    contador--;
                    printf("\n Removido com sucesso!\n");
                }
            }
            if(flag2 == 0){
                printf("\n Esse livro nao estava na biblioteca\n");
            }
        }
        else{
            printf("\n Insira uma opcao valida!\n");
        }

        printf("\n Voce deseja sair do menu de adicionar e remover? \n 1->nao \n 2->sim\n");
        scanf("%i", &flag);

        if(flag == 2){
            printf("\n Voce saiu do menu de adicionar e remover\n");
        }
    }

    return livros, contador;
}
