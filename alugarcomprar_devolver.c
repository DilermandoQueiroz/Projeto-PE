#include "biblioteca.h"

//Fun��o para aluguel/compra de livros
int AlugarComprar(int livros[100][6], int contador){

    int idlivro, aux=0, op=0;
    char nome[100];

    //Mostra os catalogo
    //Catalogo();


    while(op!=3){

        printf("\nOque deseja fazer:\n1-Alugar um livro\n2-Comprar um livro\n3-Sair\n");
        scanf("%i", &op);


        if(op==1){
            printf("\nPor favor digite o nome do livro que deseja alugar: \n");
            fflush(stdin);
            gets(nome);

            idlivro = id_nome(nome);

            for(int i = 0; i<contador; i++){
                if(livros[i][0]==idlivro){
                    printf("\nO livro %s alugado com sucesso, tenha uma otima leitura!\n", nome);
                    //Aumenta o contador de alugueis
                    livros[i][1]++;
                    //Diminue a quatidade em estoque
                    livros[i][3]--;
                    aux=1;
                }
            }
        }

        if(op==2){
            aux=0;
            printf("\nPor favor digite o nome do livro que deseja comprar: \n");
            fflush(stdin);
            gets(nome);

            idlivro = id_nome(nome);

            for(int i = 0; i<contador; i++){
                if(livros[i][0]==idlivro){
                    printf("\nO livro %s comprado com sucesso, agradecemos a preferencia e boa leitura!\n", nome);
                    //Aumenta o contador de compras
                    livros[i][5]++;
                    //Diminue a quatidade em estoque
                    livros[i][2]--;
                    aux=1;
                }
            }
        }

        if (aux==0 && op!=3){
            printf("\nDesculpe mas o livro %s nao foi encontrado.\n", nome);
            idlivro=0;
        }
    }

    return livros, contador;
}

//Fun��o pra devolver livros alugados
int Devolver(int livros[100][6], int contador){
    int idlivro, aux=0, op=0;
    char nome[100];


    while(aux==0){

        printf("\nPor favor digite o nome do livro que deseja devolver \n");
        fflush(stdin);
        gets(nome);

        idlivro = id_nome(nome);

        for(int i = 0; i<contador; i++){
            if(livros[i][0]==idlivro){
                printf("\nO livro %s foi devolvido com sucesso!\n", nome);
                //Aumenta a quatidade em estoque
                livros[i][2]++;
                aux=1;
                printf("\nDeseja avaliar o livro?\n1 - Sim\n2 - Nao\n");
                scanf("%i", &op);
                if(op == 1){
                    //Chamar fun�ao de avalia��o
                    //avaliar(livros);
                }
            }
        }
        if(aux==0){
            printf("\nDesculpe mas o livro %s nao foi encontrado.\n", nome);
            idlivro=0;
        }
    }

    return livros, contador;



}
