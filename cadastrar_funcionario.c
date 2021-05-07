#include "biblioteca.h"

int cadastrar_funcionarios(struct funcionarios funcionario[], int contador){
    char nome[50], usuario[50];
    int id;

    // Recebe o nome da pessoa que esta cadastrando
    printf("\n Ola, seja bem-vindo ao cadastramento de funcionarios da Biblioteca UFABC \n Voce poderia nos informar seu nome ?\n");
    fflush(stdin);
    gets(nome);

    // Cadastra o usuario
    int flag = 0, existe = 0;

    while(flag!=1){

        printf("\n Ola %s, Insira seu nome de usuario\n", nome);
        gets(usuario);
        id = id_nome(usuario);
        existe=0;

        // Verifica se aquele usuario ja esta cadastrado
        for(int i=0; i<contador; i++){
            if(!strcmp (funcionario[i].usuario,usuario)){
                existe = 1;
            }
        }

        // Se nao existir um usuario, cadastra ele
        if(existe == 0){
            // cadastra apenas o id por seguranca, nao utiliza nome
            funcionario[contador].id = id;
            strcpy(funcionario[contador].usuario, usuario);

            // Cadastra a senha, podemos usar a biblioteca #include <openssl/md5.h> para criptografa a senha
            char senha[50];
            printf("\n Insira uma senha \n");
            fflush(stdin);
            gets(senha);

            // armazena a senha ela nao esta segura!!!
            funcionario[contador].senha = id_nome(senha);

            // incrementa o contador de funcionarios
            contador++;

            // Grava no funcionarios.bin
            escrever_funcionario(funcionario, contador);

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
int verificacao_funcionario(int id, int senha, struct funcionarios funcionario[], int contador){
    int flag = 0;

    // Busca o id do usuario na lista funcionario[]
    for(int i = 0; i < contador; i++){
        // verifica se o id é igual
        if(funcionario[i].id == id){
            // verifica se a senha é igual
            if(funcionario[i].senha == senha){
                // esta tudo certo !
                flag = 1;
            }
        }
    }

    return flag;
}
