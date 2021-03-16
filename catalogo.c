#include "biblioteca.h"

void catalogo(int livros[100][5], char nome_livros[100][20]){
    int interesse=0;
    printf("----------------------------------------\n");
    printf("Cat�logo Biblioteca UFABC: \n");
    //chamar metodo de ordem alfabetica
    printf("----------------------------------------\n");

    do{
        printf("Gostaria de saber mais detalhes de algum livro?\nDigite 1 - Sim\nDigite 2 - Nao\n");

        if(interesse==1){
            //chamar detalhes(livros)
        }

        else if(interesse != 2){
            printf("Insira uma opcao valida!");
        }

    }while(interesse!=2);

}
