#include "biblioteca.h"

void troca(char p1[100][20], int palavra){ //troca a palavra da posicao [X] com a palavra da posicao [X+1]
    char temp[20];
    strcpy(temp, p1[palavra]);
    strcpy(p1[palavra], p1[palavra+1]);
    strcpy(p1[palavra+1], temp);

}

char converte_maiuscula(char letra){ // converte uma letra maiuscula em minuscula
    if (letra>=65 && letra<=90)
    {
        letra= letra+32;
    }

    return letra;
}

  void ordenar_livros(struct livros livro[], int qtde){
    char ordenado[qtde][20];  //vetor temporario para receber livros em ordem, sera apagado no fim da funcao
    int count = 0;

    for (int i = 0 ; i < qtde; i++)
    {
        for(int n=0; n<=strlen(livro[i].nome); n++){
                ordenado[i][n] = livro[i].nome[n];
        }
    }


    while(count!=qtde-1) //o count eh quantidade de vezes que um dupla de palavras esta na ordem certa, em um vetor de comprimento "qtde" a quatidade de duplas eh "qtde-1"
    {
        count=0;

        for (int x = 0; x < qtde-1; x++) //como eh verificado n e n+1, eh necessario -1 para nao comparar com um valor nao determinado
        {
            int comp; //armazena o comprimento da palavra
            if(strlen(ordenado[x])<strlen(ordenado[x+1])) //verificar a palavra de menor comprimento
            {
                comp=strlen(ordenado[x]);
            }else
            {
                comp=strlen(ordenado[x+1]);
            }

            int n=0;

            while (converte_maiuscula(ordenado[x][n])==converte_maiuscula(ordenado[x+1][n]) && n<comp) //muda a posicao do caractere comparado e "n<comp" evita a comparacao com lixo de memoria da menor palavra
                {
                    n++;
                }

            if (converte_maiuscula(ordenado[x][n]) >converte_maiuscula(ordenado[x+1][n]) ) // troca a palavra [x] com a [x+1] se o caractere de mesma posicao for maior.
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
        printf("%s\n", ordenado[i]);
    }

}
