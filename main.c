#include "biblioteca.h"

int main(){

    int aux = -1, flag = 0;

    //vetor com id de todos os livros e o contador com quantos livros tem:
    //livros[pos][0] = ID
    //livros[pos][1] = qtd de vezes alugado 
    //livros[pos][2] = qtd em estoque
    //livros[pos][3] = nota de 0-100
    //livros[pos][4] = qtd avaliacao
    int livros[100][5], contador_livros = 0;

    //nome_livros[pos] onde cada pos armazena uma string de tamanho 20
    char nome_livros[100][20];
    
    
    while(flag != 2){

        printf("Ola seja bem-vindo a Biblioteca UFABC! Voce gostaria de acessar nosso sistema como?\nDigite 1 - Cliente\nDigite 2 - Funcionario\n");
        scanf("%d", &aux);

        if(aux == 1){
            printf("Ainda estamos preparando o sistema para nossos clientes\n");
        }
        else if(aux == 2){
            printf("Ainda estamos preparando o sistema para nossos funcionarios\n");
            livros, contador_livros = adicionar_remover(livros, nome_livros, contador_livros);
        }
        else{
            printf("Essa entrada nao eh valida\n");
        }

        printf("Voce deseja fazer mais alguma coisa?\n1->sim\n2->nao\n");
        scanf("%d", &flag);
    }

    return 0;
}