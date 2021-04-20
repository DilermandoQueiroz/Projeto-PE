#include "biblioteca.h"

/*
Funcao para adicionar ou remover um livro pelo seu ID
*/
int adicionar_remover(struct livros livro[], int contador, int tam_atual)
{
    int aux = 0, flag = 1, colunas = 6;

    while(flag != 2){
        printf("\n Voce deseja: \n 1->Adicionar um livro \n 2->Remover um livro\n 3->Voltar para o menu\n");
        scanf("%d", &aux);

        // Adiciona um livro
        if(aux == 1){
            char nome[50];
            int id, flag = 1;

            printf("\n Insira o nome do livro\n");
            fflush(stdin);
            gets(nome);
            id = id_nome(nome);

            // Verifica se o livro ja esta cadastrado
            for(int i = 0; i<contador; i++){
                if(livro[i].id == id){

                    // adiciona mais um no estoque
                    livro[i].qtd_estoque += 1;

                    printf("\n Esse livro ja esta cadastrado, foi adicionado mais um em estoque\n");
                    flag = 0;
                }
            }

            // Verifica se ja atingiu o limite
            //Se a capacidade maxima for alcançada com a adicao de um livro, o tamanho do vetor aumenta
            if((contador+1) > tam_atual){
                livro = (struct livros *) realloc(livro,(contador + 50)*sizeof(struct livros));

                if(livro == NULL){
                    printf("\nA memoria esta cheia!\n");

                    flag = 0;
                }
                else{
                    tam_atual = contador + 50;
                }

            }

            // Se o livro nao estiver cadastrado, cadastra ele
            if(flag != 0){

                // Insere as informacoes do livro
                strcpy(livro[contador].nome, nome);
                livro[contador].id = id;
                livro[contador].qtd_alugado = 0;
                livro[contador].qtd_estoque = 0;
                livro[contador].avaliacao = 0;
                livro[contador].qtd_avaliacoes = 0;

                // Incrementa o contador
                contador++;
                printf("\n Adicionado com sucesso!\n");

                // Adicionando ao arquivo livros.bin
                escrever_livros(livro, contador);
            }

        // Remove um livro
        }
        else if(aux == 2){
            int flag2 = 0, aux = 0, id=0;
            char nome[100];

            printf("\n Insira o nome do livro que deseja remover\n");
            fflush(stdin);
            gets(nome);

            id = id_nome(nome);

            // Verifica se o livro consta na biblioteca e o remove
            for(int i = 0; i<contador; i++){
                if(livro[i].id == id){
                    flag2 = 1;
                    aux = i;
                }
            }

            // Caso nao estiver na biblioteca
            if(flag2 == 0){
                printf("\n Esse livro nao estava na biblioteca\n");
            }

            // Caso estiver na biblioteca
            else{
                // Desloca uma possicao para a esquerda a partir da que foi removida
                for(int j = aux; j<contador; j++){
                    livro[j] = livro[j+1];
                }

                // Decrementa o contador
                contador--;
                printf("\n Removido com sucesso!\n");

                //escrever_livros(livro, contador);
            }
        }

        // Sai da funcao adicionar_remover e volta pra onde foi chamada main
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
