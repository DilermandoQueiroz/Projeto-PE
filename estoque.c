#include<stdio.h>

void estoque(int livros[100][5], char nome_livros[100][20],int qtde){
    int escolha = 0, i;
    char nome[20];

    do{
        printf("O que voce deseja?\nDigite 1 - Ver o estoque de um livro específico\nDigite 2 - Ver o estoque geral\nDigite 3 - Sair\n");
        scanf("%i", &escolha);

        if(escolha == 1){
            printf("Ver o estoque de qual livro?\n");
            fflush(stdin);
            gets(nome);

            //imprime a quantidade do livro escolhido
            for(i=0;i<100;i++){
                if(strcmp (nome, nome_livros[i]) == 0){
                    printf("%s : %i unidades disponiveis\n", nome, livros[i][1]);

                    i=100;
                }
            }

            if(i == 100){
                printf("Este livro ainda nao foi cadastrado.\n");
            }
        }

        //imprime o estoque de todos os livros cadastrados
        else if(escolha == 2){
            if(qtde == 0){
                printf("Nenhum livro cadastrado\n");
            }
            else{
                printf("----------------------------------------\n");
                printf("ESTOQUE:\n");
                for(int i=0;i<qtde;i++){
                    printf("%s : %i unidades disponiveis\n", nome_livros[i], livros[i][1]);
                }
                printf("----------------------------------------\n");
            }
        }

        else if(escolha != 3 ){
            printf("Insira uma opcao valida!\n");
        }

    }while(escolha!=3);
}
