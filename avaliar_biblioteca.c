#include "biblioteca.h"

void atualizar_media(int atual, struct clientes cliente[], int contador){
    int nota, feito=0, media=0, n=0, soma=0;


    while(feito == 0){

        printf("\n Entre com a sua avaliacao(0-100):\n");
        scanf("%i", &nota);

        // Verificar se a nota inserida est� no intervalo indicado
        if(nota<0 || nota>100){

            printf("\n Nota invalida!\n");
        }
        else{

            feito = 1;
            cliente[atual].avaliacao_biblioteca = nota;
            printf("\n Nota atualizou____________\n");
        }
    }

    
    printf("\n Obrigado!\n");

    // Atualizar a m�dia do livro
    for (int i = 0; i < contador; i++)
    {
        if (cliente[i].avaliacao_biblioteca!=-1)
        {
            soma = soma + cliente[i].avaliacao_biblioteca;
            n++;
        }
        
    }
    
    media = soma/n;


   printf("\n A biblioteca foi avaliada %i vezes e possui media %i.\n", n, media);

}

void avaliar_biblioteca(int id, struct clientes cliente[], int contador){
    int atual;

    // encontrar o indice do cliente atual
    for(int i = 0; i < contador; i++){
       
        if(id == cliente[i].id){
            atual = i;
            printf("------- %s --------", cliente[atual].usuario);
        }
    }

    // saber se nao fez avalicao
    if (cliente[atual].avaliacao_biblioteca == -1)
    {
        atualizar_media(atual, cliente, contador);
    }else{
        printf("\n Voce ja avaliou a biblioteca, deseja alterar a avaliacao? \n 1-Sim \n 2-Nao \n");
        int resp;
        scanf("%d",&resp);

        if (resp==1)
        {
            atualizar_media(atual, cliente, contador);
        }
        
    }
    
}

void resultados_biblioteca(struct clientes cliente[], int contador){
    int soma=0, n=0, media=0;

    for (int i = 0; i < contador; i++)
    {
        printf("\n%d _______\n ",cliente[i].avaliacao_biblioteca);

        if (cliente[i].avaliacao_biblioteca!=-1)
        {
            soma = soma + cliente[i].avaliacao_biblioteca;
            n++;
        }
        
    }

    if (n==0)
    {
        printf("\n Nao foi feita nenhuma avaliacao \n");
    }else{
        media = soma/n;
        printf("\n A biblioteca foi avaliada %i vezes e possui media %i.\n", n, media);
    }
    

}