#include "biblioteca.h"

void catalogo(struct livros livro[100], int qtde){
    int interesse = 0;

    printf("\n----------------------------------------\n");
    printf("\n Catalogo Biblioteca UFABC: \n");

    if(qtde == 0){
        printf("\n Nenhum livro cadastrado\n");
    }
    else{
        ordenar_livros(livro, qtde);
    }

    printf("\n----------------------------------------\n");

    do{
        printf("\n Gostaria de saber mais detalhes de algum livro? \n Digite 1 - Sim \n Digite 2 - Nao\n");
        scanf("%i", &interesse);

        if(interesse==1){
            detalhes(livro, qtde);
            interesse = 2;
        }

        else if(interesse != 2){
            printf("\n Insira uma opcao valida!\n");
        }

    }while(interesse!=2);

}
