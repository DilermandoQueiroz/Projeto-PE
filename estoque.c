#include "biblioteca.h"

void OrganizaEstoqueDecrescente(struct livros livro[], int qtde){
    int maior = livro[0].qtd_estoque, posMaior = 0, ordenado = 0, mudanca = 0, j = 0;
    struct livros livro_aux;

    do{
        for(int i= j+1; i<qtde; i++){
            if(livro[i].qtd_estoque > maior){
                maior = livro[i].qtd_estoque;
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
        maior = livro[j].qtd_estoque;
        mudanca = 0;

        if(j == qtde-1){
            ordenado = 1;
        }

        escrever_livros(livro, qtde);

    }while(ordenado != 1);
}

void OrganizaEstoqueCrescente(struct livros livro[], int qtde){
    int menor = livro[0].qtd_estoque, posMenor = 0, ordenado = 0, mudanca = 0, j = 0;
    struct livros livro_aux;

    do{
        for(int i= j+1; i<qtde; i++){
            if(livro[i].qtd_estoque < menor){
                menor = livro[i].qtd_estoque;
                posMenor = i;
                mudanca = 1;
            }
        }

        if(mudanca == 1){
            livro_aux = livro[posMenor];
            livro[posMenor] = livro[j];
            livro[j] = livro_aux;
        }

        j++;
        menor = livro[j].qtd_estoque;
        mudanca = 0;

        if(j == qtde-1){
            ordenado = 1;
        }

        escrever_livros(livro, qtde);

    }while(ordenado != 1);

}

void estoque(struct livros livro[], int qtde){
    int escolha = 0, escolha_ordem = 0, i;
    char nome[20];

    do{
        printf("\n O que voce deseja? \n Digite 1 - Ver o estoque de um livro especifico \n Digite 2 - Ver o estoque geral \n Digite 3 - Sair\n");
        scanf("%i", &escolha);

        if(escolha == 1){
            printf("\n Ver o estoque de qual livro?\n");
            fflush(stdin);
            gets(nome);

            //imprime a quantidade do livro escolhido
            for(i=0; i<qtde; i++){
                if(strcmp (nome, livro[i].nome) == 0){
                    printf("%s : %i unidades disponiveis\n", nome, livro[i].qtd_estoque);

                    i = qtde;
                }
            }

            if(i == qtde){
                printf("\n Este livro ainda nao foi cadastrado.\n");
            }
        }

        //imprime o estoque de todos os livros cadastrados
        else if(escolha == 2){
            if(qtde == 0){
                printf("\n Nenhum livro cadastrado\n");
            }
            else{
                int indices_ordenados[qtde];

                do{
                    printf("\nDeseja ver o estoque em qual ordem? \n 1- Crescente\n 2- Decrescente\n 3- Sair desta sessao do estoque\n 4- Sair do estoque\n");
                    scanf("%i", &escolha_ordem);

                    if(escolha_ordem == 1){
                        OrganizaEstoqueCrescente(livro, qtde);
                    }
                    else if(escolha_ordem == 2){
                        OrganizaEstoqueDecrescente(livro, qtde);
                    }
                    else if(escolha_ordem == 3){
                        printf("\n Voce saiu da sessao estoque geral\n");
                    }
                    else if(escolha_ordem == 4){
                        escolha = 3;
                        printf("\n Voce saiu do estoque!\n");
                    }
                    else{
                        printf("\n Escolha invalida\n");
                    }

                }while(escolha_ordem != 1 && escolha_ordem != 2 && escolha_ordem != 3 && escolha_ordem != 4);

                if(escolha_ordem == 1 || escolha_ordem == 2){
                    printf("\n----------------------------------------\n");
                    printf("ESTOQUE:\n");
                    for(int i=0; i<qtde; i++){
                        printf("%s : %i unidades disponiveis\n", livro[i].nome, livro[i].qtd_estoque);
                    }
                    printf("\n----------------------------------------\n");
                }
            }
        }

        else if(escolha == 3){
            printf("\n Voce saiu do estoque!\n");
        }

        else if(escolha != 3 ){
            printf("\n Insira uma opcao valida!\n");
        }

    }while(escolha!=3);
}
