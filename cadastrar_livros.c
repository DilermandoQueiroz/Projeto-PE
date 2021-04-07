#include "biblioteca.h"

/*
Funcao para adicionar ou remover um livro pelo seu ID
*/
int adicionar_remover(struct livros livro[100], int contador)
{
    int aux = 0, flag = 1, colunas = 6;

    while(flag != 2){
        printf("\n Voce deseja: \n 1->Adicionar um livro \n 2->Remover um livro\n 3->Voltar para o menu");
        scanf("%d", &aux);

        //adiciona um livro
        if(aux == 1){
            char nome[50];
            int id, flag = 1;

            printf("\n Insira o nome do livro\n");
            fflush(stdin);
            gets(nome);
            id = id_nome(nome);

            //verifica se o livro ja esta cadastrado
            for(int i = 0; i<contador; i++){
                if(livro[i].id == id){

                    // adiciona mais um no estoque
                    livro[i].qtd_estoque += 1;

                    printf("\n Esse livro ja esta cadastrado, foi adicionado mais um em estoque\n");
                    flag = 0;
                }
            }

            //verifica se ja atingiu o limite
            if(contador == 100){
                printf("\n Nao existe mais espaço na biblioteca\n");
            }

            //se o livro nao estiver cadastrado, cadastra ele
            else if(flag != 0){

                //insere as informacoes do livro
                strcpy(livro[contador].nome, nome);
                livro[contador].id = id;
                livro[contador].qtd_alugado = 0;
                livro[contador].qtd_estoque = 0;
                livro[contador].avaliacao = 0;
                livro[contador].qtd_avaliacoes = 0;

                //incrementa o contador
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
                if(livro[i].id == id){
                    flag2 = 1;
                    aux = i;

                    //desloca uma possicao para a esquerda a partir da que foi removida
                    for(aux; aux<contador; aux++){
                        livro[aux] = livro[aux+1];
                    }

                    //decrementa o contador
                    contador--;
                    printf("\n Removido com sucesso!\n");
                }
            }
            if(flag2 == 0){
                printf("\n Esse livro nao estava na biblioteca\n");
            }
        }
        
        //sai da funcao adicionar_remover e volta pra onde foi chamada main
        else if(aux == 3){
            flag = 2;
            printf("\n Voce saiu do menu de adicionar e remover\n");
        }

        // Caso aux seja diferenta de 1, 2 ou 3
        else{
            printf("\n Insira uma opcao valida!\n");
        }
    }

    return contador;
}
