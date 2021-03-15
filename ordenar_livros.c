#include "biblioteca.h"

void troca(char p1[100][20], int palavra){
    char temp[20];
    strcpy(temp, p1[palavra]);
    strcpy(p1[palavra], p1[palavra+1]);
    strcpy(p1[palavra+1], temp);
    
}

void ordenar_livros(int livros[100][6], char nome_livros[100][20],int qtde){
    char ordenado[qtde][20];  //vetor temporário para receber livros em ordem, será apagado no fim da função
    int count = 0;

    for (int i = 0 ; i < qtde; i++)
    {
        for(int n=0; n<=strlen(nome_livros[i]); n++){
                ordenado[i][n] = nome_livros[i][n];
        }
    }


    while(count!=qtde-1) //o count é quantidade de vezes que um dupla de palavras está na ordem certa, em um vetor de comprimento "qtde" a quatidade de duplas é "qtde-1"
    {
        count=0;

        for (int x = 0; x < qtde-1; x++) //como é verificado n e n+1, é necessário -1 para não comparar com um valor não determinado
        {
            int comp;
            if(strlen(ordenado[x])<strlen(ordenado[x+1])) { // achar o menor comprimento
                comp=strlen(ordenado[x]);
            }else
            {  
                comp=strlen(ordenado[x+1]); 
            }

            int n=0;

            while (ordenado[x][n]==ordenado[x+1][n] && n<comp) 
                {
                    n++;
                } 

            if (ordenado[x][n]>ordenado[x+1][n]) // troca 
            {
                
                troca(ordenado,x);

            }else
            {
                count++;
            }
              
        }
        

    }
    
    for (int i = 0; i < qtde; i++)
    {
        printf("%s\n", ordenado[i]);
    }


}