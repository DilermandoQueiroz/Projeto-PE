#include "biblioteca.h"

void exporta_csv(struct livros livro[100], int contador){
    FILE *file = fopen("dados/livros.csv", "w");

    //verifica se aconteceu um erro
    if(file == NULL){
        printf("Aconteceu um erro, tente mais tarde");
    }

    // caso contrario grava os dados em um arquivo .csv
    else{
        // Escreve o cabecalho 
        fprintf(file, "Nome, ID, Avaliacao, Qtd Alugado, Qtd Estoque, Qtd Avaliacao");
        
        // Escreve os dados dos livros
        for(int i=0; i<contador; i++){
            fprintf(file, "%s, %i, %i, %i, %i, %i\n", livro[i].nome, livro[i].id, livro[i].avaliacao, livro[i].qtd_alugado, livro[i].qtd_estoque, livro[i].qtd_avaliacoes);
        }

        printf("\n Exportado com sucesso ! \n Agora voce pode analisar como esta indo sua biblioteca !");
        fclose(file);
    }
} 
