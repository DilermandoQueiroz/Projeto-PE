#include "biblioteca.h"

void catalogo(struct livros livro[], int qtde){
    int interesse = 0;

    printf("\n----------------------------------------\n");
    printf("\n Catalogo Biblioteca UFABC: \n");

    //add opcao do cliente ver o catalogo por ordem de avaliacao e qtd de vendas

    if(qtde == 0){
        printf("\n Nenhum livro cadastrado\n");
    }
    else{
        int escolha;
        printf("\n Deseja ver o catalogo em qual ordem? \n Digite 1 - ordem alfabetica \n Digite 2 - melhor avaliacao \n Digite 3 - mais vendidos \n");
        scanf("%i", &escolha);

        if(escolha == 1){
            ordenar_livros(livro, qtde);
        }

        else if(escolha == 2){
            ordenar_melhores(livro, qtde);
        }

        else if(escolha == 3){
            best_seller(livro, qtde);
        }

        
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
