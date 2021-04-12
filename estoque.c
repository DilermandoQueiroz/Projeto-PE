#include "biblioteca.h"

void estoque(struct livros livro[100], int qtde){
    int escolha = 0, i;
    char nome[20];

    do{
        printf("\n O que voce deseja? \n Digite 1 - Ver o estoque de um livro especifico \n Digite 2 - Ver o estoque geral \n Digite 3 - Sair\n");
        scanf("%i", &escolha);

        if(escolha == 1){
            printf("\n Ver o estoque de qual livro?\n");
            fflush(stdin);
            gets(nome);

            //imprime a quantidade do livro escolhido
            for(i=0; i<100; i++){
                if(strcmp (nome, livro[i].nome) == 0){
                    printf("%s : %i unidades disponiveis\n", nome, livro[i].qtd_estoque);

                    i = 100;
                }
            }

            if(i == 100){
                printf("\n Este livro ainda nao foi cadastrado.\n");
            }
        }

        //imprime o estoque de todos os livros cadastrados
        else if(escolha == 2){
            if(qtde == 0){
                printf("\n Nenhum livro cadastrado\n");
            }
            else{
                printf("\n----------------------------------------\n");
                printf("ESTOQUE:\n");
                for(int i=0; i<qtde; i++){
                    printf("%s : %i unidades disponiveis\n", livro[i].nome, livro[i].qtd_estoque);
                }
                printf("\n----------------------------------------\n");
            }
        }

        else if(escolha == 3){
            printf("\n Voce saiu do estoque!\n");
        }

        else if(escolha != 3 ){
            printf("\n Insira uma opcao valida!\n");
        }

    }while(escolha!=3);
}
