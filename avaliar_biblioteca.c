#include "biblioteca.h"

int atualizar_media(int alterar, struct servico *biblioteca){
    int nota, feito=0, media=0, n=0;

    media = (*biblioteca).avaliacao;
    n = (*biblioteca).qtd_avaliacoes;

    if(alterar!=0 && n!=0){
        media = (n*media-alterar)/(n);
        n--;
    }

    while(feito == 0){

        printf("\n Entre com a sua avaliacao(0-100):\n");
        scanf("%i", &nota);

        // Verificar se a nota inserida est� no intervalo indicado
        if(nota<0 || nota>100){

            printf("\n Nota invalida!\n");
        }
        else{

            feito = 1;
                    
        }
    }

    
    printf("\n Obrigado!\n");

    // Atualizar a m�dia do livro

    

    media = (n*media+nota)/(n+1);

    (*biblioteca).qtd_avaliacoes = n+1;
    (*biblioteca).avaliacao = media;

   // printf("\n A biblioteca foi avaliada %i vezes e possui media %i.\n", (*biblioteca).qtd_avaliacoes, (*biblioteca).avaliacao );

    return nota;
}

void avaliar_biblioteca(int id, struct clientes cliente[], struct servico *biblioteca, int contador){
    int atual;

    // encontrar o indice do cliente atual
    for(int i = 0; i < contador; i++){
       
        if(id == cliente[i].id){
            atual = i;
            //printf("------- %s --------", cliente[atual].usuario);
        }
    }

    // saber se nao fez avalicao
    if (cliente[atual].avaliacao_biblioteca == -1)
    {
        cliente[atual].avaliacao_biblioteca = atualizar_media(0, biblioteca);
    }else{
        printf("\n Voce ja avaliou a biblioteca, deseja alterar a avaliacao? \n 1-Sim \n 2-Nao \n");
        int resp;
        scanf("%d",&resp);

        if (resp==1)
        {
            cliente[atual].avaliacao_biblioteca = atualizar_media(cliente[atual].avaliacao_biblioteca, biblioteca);
        }
        
    }
    

}

void resultados_biblioteca(struct servico *biblioteca){

    printf("\n A biblioteca foi avaliada %i vezes e possui media %i.\n", (*biblioteca).qtd_avaliacoes, (*biblioteca).avaliacao );

}