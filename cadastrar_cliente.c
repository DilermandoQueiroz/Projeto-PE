#include "biblioteca.h"

/* Cadastramento de clientes
*/
int cadastrar_cliente(struct clientes cliente[10], int contador){
    char nome[50], usuario[50];
    int id;

    // Recebe o nome da pessoa que esta cadastrando
    printf("\n Ola seja bem-vindo ao cadastramento da Biblioteca UFABC \n Voce poderia nos informar seu nome ?\n");
    fflush(stdin);
    gets(nome);


    // Cadastra o usuario
    int flag = 0, existe = 0;

    while(flag!=1){

        printf("\n Ola %s, insira seu nome de usuario\n", nome);
        gets(usuario);
        id = id_nome(usuario);

        // Verifica se aquele usuario ja esta cadastrado
        for(int i=0; i<contador; i++){
            if(cliente[i].usuario == usuario){
                existe = 1;
            }
        }

        // Se nao existir um usuario, cadastra ele
        if(existe == 0){
            // cadastra apenas o id por seguranca, nao utiliza nome
            cliente[contador].id = id;
            strcpy(cliente[contador].usuario, usuario);

            // Cadastra a senha
            char senha[50];
            printf("\n Insira uma senha \n");
            fflush(stdin);
            gets(senha);

            // armazena a senha
            cliente[contador].senha = id_nome(senha);

            //Inicializa os livros_alugados com alguma coisa pra não ficar lixo de memoria
            for(int i=0; i<20; i++){
                cliente[contador].livros_alugado[i][0]= '.';
            }

            //inicia o valor de avaliacao igual a -1 para saber se a pessoa nao avaliou a plataforma
            cliente[contador].avaliacao_biblioteca=-1;

            // incrementa o contador de clientes
            contador++;

            // Grava no clientes.bin
            escrever_cliente(cliente, contador);

            flag = 1;
        }
    }

    printf("\n Seu cadastro foi realizado com sucesso\n");

    return contador;
}

/* Verifica se a pessoa esta cadastrada na BIBLIOTECA
* retorna 1 para sim
* retorna 0 para não
*/
int verificacao_cliente(int id, int senha, struct clientes cliente[], int contador){
    int flag = 0;

    // Busca o id do usuario na lista cliente[]
    for(int i = 0; i < contador; i++){
        // verifica se o id é igual
        if(cliente[i].id == id){
            // verifica se a senha é igual
            if(cliente[i].senha == senha){
                // esta tudo certo !
                flag = 1;
            }
        }
    }

    return flag;
}
