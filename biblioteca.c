#include<stdio.h>

/**
Funcao para adicionar ou remover um livro pelo seu ID
*/
int adicionar_remover(int livros[100], int contador){
    int aux = 0, flag = 1;

    while(flag != 2){
        int id;
        printf("Voce deseja:\n1->Adicionar um livro\n2->Remover um livro\n");
        scanf("%d", &aux);

        //adiciona um livro
        if(aux == 1){
            printf("Insira o ID do livro que deseja adicionar\n");
            scanf("%d", &id);

            //verifica se o livro ja esta cadastrado
            for(int i = 0; i<contador; i++){
                if(livros[i] == id){
                    printf("Esse livro ja esta cadastrado\n");
                }
            }
            //verifica se ja atingiu o limite
            if(contador == 100){
                printf("Nao existe mais espaço na biblioteca\n");
            }
            else{
                livros[contador] = id;
                contador++;
                printf("Adicionado com sucesso!\n");
            }

        //remove um livro
        }
        else if(aux == 2){
            int flag2 = 0, aux;
            printf("Insira o ID do livro que deseja remover\n");
            scanf("%d", &id);

            //verifica se o livro consta na biblioteca e o remove
            for(int i = 0; i<contador; i++){
                if(livros[i] == id){
                    flag2 = 1;
                    aux = i;
                    for(aux; aux<contador; aux++){
                        livros[aux] = livros[aux+1]; 
                    }
                    contador--;
                    printf("Removido com sucesso!\n");
                }
            }
            if(flag2 == 0){
                printf("Esse livro nao estava na biblioteca\n");
            }
        }
        else{
            printf("Insira uma opcao valida!\n");
        }
        
        printf("voce deseja sair do menu de adicionar e remover?\n1->nao\n2->sim\n");
        scanf("%d", &flag);
    }

    return livros, contador;
}

int main(){

    int aux = -1, flag = 0;
    //vetor com id de todos os livros e o contador com quantos livros tem
    int livros[100], contador_livros = 0;
    
    printf("Ola boa, seja bem-vindo a Biblioteca UFABC! Voce gostaria de acessar nosso sistema como?\nDigite 1 - Cliente\nDigite 2 - Funcionario\n");
    while(flag == 0){
        scanf("%d", &aux);
        if(aux == 1){
            printf("Ainda estamos preparando o sistema para nossos clientes\n");
            flag = 1;
        }
        else if(aux == 2){
            printf("Ainda estamos preparando o sistema para nossos funcionarios\n");
            livros, contador_livros = adicionar_remover(livros, contador_livros);
            flag = 1;
        }
        else{
            printf("Essa entrada nao eh valida\n");
        }
    }

    return 0;
}