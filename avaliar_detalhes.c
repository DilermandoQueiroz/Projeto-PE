#include "biblioteca.h"

/*Avalia um livro
*/
void avaliar(int livros[100][5]){

    char nome[50];

    printf("Por favor, entre com o nome do livro que deseja avaliar:\n");
    gets(nome);

    int id = id_nome(nome);
    int aux = 0;
    int cont = 0;
    int nota = 0;

    while(aux == 0){

        if(id == livros[cont][0]){

            while(aux == 0){

                printf("\nEntre com a sua avaliacao(0-100):\n");
                scanf("%i", &nota);
                if(nota<0 || nota>100){

                    printf("Nota invalida!\n");
                }
                else{

                    aux = 1;
                }
            }

            printf("Obrigado!\n");
            int n = livros[cont][4];
            int media = livros[cont][3];

            media = (n*media+nota)/(n+1);

            livros[cont][4] = n+1;
            livros[cont][3] = media;
        }
        cont = cont+1;

        if(cont==99){
            printf("Este livro ainda nao foi cadastrado.\n");
            aux = 1;
        }
    }
}

void detalhes(int livros[100][5]){
    char nome[50];

    fflush(stdin);
    printf("\nInsira o nome do livro que voce gostaria de saber detalhes: \n");
    gets(nome);

    int id = id_nome(nome);
    int aux = 0;
    int cont = 0;

    while(aux == 0){
        if(id == livros[cont][0]){
            aux = 1;
            printf("\nO livro '%s' foi alugado %i vezes, avaliado por %i pessoas e possui media %i.\n", nome, livros[cont][1], livros[cont][4], livros[cont][3]);
            printf("Existem %i copias em nosso estoque.\n\n", livros[cont][2]);
        }
        if(cont == 99){
            printf("Este livro ainda nao foi cadastrado.\n\n");
            aux = 1;
        }
        cont = cont + 1;
    }

    int a =0;
    aux = 0;

    while(aux==0){
        printf("Gostaria de saber mais detalhes sobre outro livro?\nDigite 1 - Sim\nDigite 2 - Nao\n");
        scanf("%i", &a);

        if(a == 1){
            detalhes(livros);
            aux = 1;
        }
        else if(a == 2){
            aux = 1;
        }
        else{
            printf("Essa entrada nao eh valida\n\n");
        }
    }
}
