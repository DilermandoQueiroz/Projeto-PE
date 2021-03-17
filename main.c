#include "biblioteca.h"

int main(){

    int aux = -1, flag = 0, escolha_cliente = 0, escolha_funcionario = 0;

    //vetor com id de todos os livros e o contador com quantos livros tem:
    //livros[pos][0] = ID
    //livros[pos][1] = qtd alugado
    //livros[pos][2] = qtd em estoque
    //livros[pos][3] = nota de 0-100
    //livros[pos][4] = qtd avaliacao
    //livros[pos][5] = qtd comprado
    int livros[100][6], contador_livros = 0;

    //nome_livros[pos] onde cada pos armazena uma string de tamanho 20
    char nome_livros[100][20];


    while(flag != 2){

        printf("-----------------------------------------------------------------------------------");
        printf("\n Ola seja bem-vindo a Biblioteca UFABC! Voce gostaria de acessar nosso sistema como? \n Digite 1 - Cliente \n Digite 2 - Funcionario\n Digite 3 - Sair da biblioteca\n");
        scanf("%d", &aux);

        if(aux == 1){

            do{
                printf("\n Eh muito bom te-lo conosco! O que voce deseja? \n Digite 1 - Ver o nosso catalogo de livros \n Digite 2 - Comprar \n Digite 3 - Devolver um livro \n Digite 4 - Avaliar um livro \n Digite 5 - Ver detalhes de um livro \n Digite 6 - Sair da �rea do cliente\n");
                scanf("%i", &escolha_cliente);

                if(escolha_cliente == 1){
                    catalogo(livros, nome_livros, contador_livros);
                }

                else if(escolha_cliente == 2){
                    livros, contador_livros = AlugarComprar(livros, nome_livros, contador_livros);
                }

                else if(escolha_cliente == 3){
                    Devolver(livros, contador_livros);
                }

                else if(escolha_cliente == 4){
                    livros, contador_livros = avaliar(livros, contador_livros);
                }

                else if(escolha_cliente == 5){
                    detalhes(livros, contador_livros);
                }

                else if(escolha_cliente == 6){
                    printf("\n Voce saiu da area do cliente!\n");
                }

                else{
                    printf("\n Essa entrada nao eh valida!\n");
                }

            }while(escolha_cliente != 6);

            escolha_cliente = 0;
        }

        else if(aux == 2){

            do{
                printf("\n E muito bom te-lo conosco! O que voce deseja? \n Digite 1 - Cadastrar/Remover um livro \n Digite 2 - Ver o estoque \n Digite 3 - Sair da area do funcionario\n");
                scanf("%i", &escolha_funcionario);

                if(escolha_funcionario == 1){
                    livros, contador_livros = adicionar_remover(livros, nome_livros, contador_livros);
                }

                else if(escolha_funcionario == 2){
                    estoque(livros, nome_livros, contador_livros);
                }

                else if(escolha_funcionario == 3){
                    printf("\n Voce saiu da area do funcionario!\n");
                }

                else{
                    printf("\n Essa entrada nao eh valida!\n");
                }

            }while(escolha_funcionario!=3);

            escolha_funcionario = 0;
        }

        else if(aux == 3){
            printf("\n Voce saiu da Biblioteca!\n");
        }

        else{
            printf("\n Essa entrada nao eh valida\n");
        }

        printf("\n Voce deseja fazer mais alguma coisa?\n1->sim\n2->nao\n");
        scanf("%d", &flag);

        if(flag == 2){
            printf("\nVoce saiu da Biblioteca!\n");
        }
    }

    printf("-----------------------------------------------------------------------------------");

    return 0;
}
