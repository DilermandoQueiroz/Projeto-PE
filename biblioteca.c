#include<stdio.h>
#include<string.h>

/*
Recebe o nome de um livro e retorna seu id
o id é calculado pela soma do valor int das letras que compoem o nome do livro 
*/
int id_nome(char nome[100]){
    int id;

    for(int i=0; nome[i]!='\0'; i++){
        id += nome[i];
    }
    
    return id;
}

/*
Funcao para adicionar ou remover um livro pelo seu ID
*/
int adicionar_remover(int livros[100][4], char nome_livros[][20], int contador){
    int aux = 0, flag = 1;

    while(flag != 2){
        printf("Voce deseja:\n1->Adicionar um livro\n2->Remover um livro\n");
        scanf("%d", &aux);

        //adiciona um livro
        if(aux == 1){
            char nome[100];
            int id, flag = 1;
            printf("Insira o nome do livro\n");
            scanf("%s", nome);
            id = id_nome(nome);

            //verifica se o livro ja esta cadastrado
            for(int i = 0; i<contador; i++){
                if(livros[i][0] == id){
                    printf("Esse livro ja esta cadastrado\n");
                    flag = 0;
                }
            }
            //verifica se ja atingiu o limite
            if(contador == 100){
                printf("Nao existe mais espaço na biblioteca\n");
            }
            //se o livro nao estiver cadastrado, cadastra ele
            else if(flag != 0){
                livros[contador][0] = id;
                livros[contador][1] = 0;
                livros[contador][2] = 0;
                livros[contador][3] = 0;
                for(int n=0; n<=strlen(nome); n++){
                    nome_livros[contador][n] = nome[n];
                }
                contador++;
                printf("Adicionado com sucesso!\n");
            }

        //remove um livro
        }
        else if(aux == 2){
            int flag2 = 0, aux, id;
            char nome[100];

            printf("Insira o nome do livro que deseja remover\n");
            scanf("%s", nome);

            id = id_nome(nome);

            //verifica se o livro consta na biblioteca e o remove
            for(int i = 0; i<contador; i++){
                if(livros[i][0] == id){
                    flag2 = 1;
                    aux = i;
                    for(aux; aux<contador; aux++){
                        livros[aux][0] = livros[aux+1][0];
                        livros[aux][1] = livros[aux+1][1];
                        livros[aux][2] = livros[aux+1][2];
                        livros[aux][3] = livros[aux+1][3];
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

    //vetor com id de todos os livros e o contador com quantos livros tem:
    //livros[pos][0] = ID
    //livros[pos][1] = qtd de vezes alugado 
    //livros[pos][2] = qtd em estoque
    //livros[pos][3] = nota de 0-100
    int livros[100][4], contador_livros = 0;

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