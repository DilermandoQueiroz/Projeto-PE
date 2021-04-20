#include "biblioteca.h"

/* Funcao para exportar uma struct para um arquivo csv
*/
void exporta_csv(struct livros livro[100], int contador){
    FILE *arquivo = fopen("dados/livros.csv", "w");

    //verifica se aconteceu um erro
    if(arquivo == NULL){
        printf("Aconteceu um erro, tente mais tarde\n");
        exit(1);
    }

    // caso contrario grava os dados em um arquivo .csv
    else{
        // Escreve o cabecalho 
        fprintf(arquivo, "Nome, ID, Avaliacao, Qtd Alugado, Qtd Estoque, Qtd Avaliacao\n");
        
        // Escreve os dados dos livros
        for(int i=0; i<contador; i++){
            fprintf(arquivo, "%s, %i, %i, %i, %i, %i\n", livro[i].nome, livro[i].id, livro[i].avaliacao, livro[i].qtd_alugado, livro[i].qtd_estoque, livro[i].qtd_avaliacoes);
        }

        printf("\n Exportado com sucesso ! \n Agora voce pode analisar como esta indo sua biblioteca !\n");
        fclose(arquivo);
    }
} 

/* Escreve um struct livros livro[] em um .bin para ser lido depois
*/
void escrever_livros(struct livros livro[], int contador){
    FILE *arquivo = fopen("dados/livros.bin", "wb");

    // verifica se aconteceu algum erro com o arquivo
    if(arquivo == NULL){
        printf("Aconteceu um erro, tente mais tarde\n");
        exit(1);
    }

    // caso contrario escreve os aquivos em um binario
    // para cada um struct em livro[]
    for(int i = 0; i < contador; i++){
        fwrite(&livro[i], sizeof(struct livros), 1, arquivo);
    }
        
    printf("\n Exportado com sucesso ! \n");
    fclose(arquivo);
    
}

/* Escreve um struct clientes cliente[] em um .bin para ser lido depois
*/
void escrever_cliente(struct clientes cliente[], int contador){
    FILE *arquivo = fopen("dados/clientes.bin", "wb");

    // verifica se aconteceu algum erro com o arquivo
    if(arquivo == NULL){
        printf("Aconteceu um erro, tente mais tarde\n");
        exit(1);
    }

    // caso contrario escreve os aquivos em um binario
    // para cada um struct em livro[]
    for(int i = 0; i < contador; i++){
        fwrite(&cliente[i], sizeof(struct clientes), 1, arquivo);
    }
        
    fclose(arquivo);
    
}


/* Peguei como ideia do link https://gist.github.com/marcoscastro/842e3a5d2ec5e1bd457b
*/
int ler_livros(struct livros livro[]){
    FILE *arquivo = fopen("dados/livros.bin", "rb");

    // verifica se aconteceu algum erro com o arquivo
    if(arquivo == NULL){
        printf("Aconteceu um erro, tente mais tarde");
        exit(1);
    }
    // caso nao aconteca nenhum erro
    else{
        int contador = 0;
        int flag = 0;

        // enquanto nao terminar de ler os livros guardado
        while(flag == 0){
            struct livros livro_aux;

            size_t r = fread(&livro_aux, sizeof(struct livros), 1, arquivo);

            // caso termine    
            if(r < 1){
                flag = 1;
            }
            // caso ainda possua livro
            else{
                livro[contador] = livro_aux;
                contador++;
            }
        }
        // terminado com sucesso
        fclose(arquivo);
        return contador;
    }
}

/* Peguei como ideia do link https://gist.github.com/marcoscastro/842e3a5d2ec5e1bd457b
*/
int ler_clientes(struct clientes cliente[]){
    FILE *arquivo = fopen("dados/clientes.bin", "rb");

    // verifica se aconteceu algum erro com o arquivo
    if(arquivo == NULL){
        printf("Aconteceu um erro, tente mais tarde");
        exit(1);
    }
    // caso nao aconteca nenhum erro
    else{
        int contador = 0;
        int flag = 0;

        // enquanto nao terminar de ler os livros guardado
        while(flag == 0){
            struct clientes cliente_aux;

            size_t r = fread(&cliente_aux, sizeof(struct clientes), 1, arquivo);

            // caso termine    
            if(r < 1){
                flag = 1;
            }
            // caso ainda possua livro
            else{
                cliente[contador] = cliente_aux;
                contador++;
            }
        }
        // terminado com sucesso
        fclose(arquivo);
        return contador;
    }
}