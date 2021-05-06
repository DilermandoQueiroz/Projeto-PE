#include <biblioteca.h>

// Esta funcao recebe o struct com os dados dos livros, os ordena e imprime os 3 mais vendidos.

int particiona(struct livros livro[], int inicio, int final1){
    int esq, dir;

    struct livros aux;
    struct livros pivo;

    esq=inicio;
    dir=final1;
    pivo = livro[inicio];

    while(esq<dir){
        while(livro[esq].qtd_comprado>=pivo.qtd_comprado){
            esq++;
        }
        while(livro[dir].qtd_comprado<pivo.qtd_comprado){
            dir--;
        }
        if (esq<dir){

            aux=livro[esq];
            livro[esq]=livro[dir];
            livro[dir]=aux;
        }
    }

    livro[inicio]=livro[dir];
    livro[dir]=pivo;

    return dir;
}

void quickSort(struct livros livro[], int inicio, int fim){
    int pivo=0;
    if (fim>inicio){
        pivo=particiona(livro, inicio, fim);
        quickSort(livro, inicio, pivo-1);
        quickSort(livro, pivo+1, fim);
    }
}

void best_seller(struct livros livro[], int contador){

    quickSort(livro, 0, contador-1);

    printf("\n  **BEST SELLERS** \n1: %s. \n2: %s. \n3: %s.\n\n", livro[0].nome, livro[1].nome, livro[2].nome);
}
