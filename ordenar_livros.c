#include "biblioteca.h"

void troca(struct livros aux[], int palavra){ //troca a palavra da posicao [X] com a palavra da posicao [X+1]
    char temp[50];
    strcpy(temp, aux[palavra].nome);
    strcpy(aux[palavra].nome, aux[palavra+1].nome);
    strcpy(aux[palavra+1].nome, temp);

}

char converte_maiuscula(char letra){ // converte uma letra maiuscula em minuscula
    if (letra>=65 && letra<=90)
    {
        letra= letra+32;
    }

    return letra;
}

  void ordenar_livros(struct livros livro[], int qtde){
    struct livros ordenado[qtde];  //struct temporario para receber livros em ordem, sera apagado no fim da funcao
    int count = 0;

    for (int i = 0 ; i < qtde; i++)
    {
        strcpy(ordenado[i].nome, livro[i].nome );
    }


    while(count!=qtde-1) //o count eh quantidade de vezes que um dupla de palavras esta na ordem certa, em um vetor de comprimento "qtde" a quatidade de duplas eh "qtde-1"
    {
        count=0;

        for (int x = 0; x < qtde-1; x++) //como eh verificado n e n+1, eh necessario -1 para nao comparar com um valor nao determinado
        {
            int comp; //armazena o comprimento da palavra
            if(strlen(ordenado[x].nome)<strlen(ordenado[x+1].nome)) //verificar a palavra de menor comprimento
            {
                comp=strlen(ordenado[x].nome);
            }else
            {
                comp=strlen(ordenado[x+1].nome);
            }

            int n=0;

            while (converte_maiuscula(ordenado[x].nome[n])==converte_maiuscula(ordenado[x+1].nome[n]) && n<comp) //muda a posicao do caractere comparado e "n<comp" evita a comparacao com lixo de memoria da menor palavra
                {
                    n++;
                }

            if (converte_maiuscula(ordenado[x].nome[n]) >converte_maiuscula(ordenado[x+1].nome[n]) ) // troca a palavra [x] com a [x+1] se o caractere de mesma posicao for maior.
            {
                troca(ordenado,x);

            }else
            {
                count++;
            }

        }

    }

    for (int i = 0; i < qtde; i++) //imprime os livros ordenados
    {
        printf("%s\n", ordenado[i].nome);
    }

}


void ordenar_melhores(struct livros livro[], int qtde){
    int maior = livro[0].avaliacao, posMaior = 0, ordenado = 0, mudanca = 0, j = 0;
    struct livros livro_aux;

    do{
        for(int i= j+1; i<qtde; i++){
            if(livro[i].avaliacao > maior){
                maior = livro[i].avaliacao;
                posMaior = i;
                mudanca = 1;
            }
        }

        if(mudanca == 1){
            livro_aux = livro[posMaior];
            livro[posMaior] = livro[j];
            livro[j] = livro_aux;
        }

        j++;
        maior = livro[j].avaliacao;
        mudanca = 0;

        if(j == qtde-1){
            ordenado = 1;
        }

       
    }while(ordenado != 1);

    for (int i = 0; i < qtde; i++) //imprime os livros ordenados
    {
        printf("%s\n", livro[i].nome);
    }
}
