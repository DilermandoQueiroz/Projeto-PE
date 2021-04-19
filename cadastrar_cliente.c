#include "biblioteca.h"

/* Cadastramento de clientes
*/
int cadastrar_cliente(struct clientes cliente[10], int contador){
    char nome[50], usuario[50];
    int id;

    // Recebe o nome da pessoa que esta cadastrando
    printf("\n Ola seja bem-vindo ao da cadastramento da Biblioteca UFABC \n Voce poderia nos informar seu nome ?");
    fflush(stdin);
    gets(nome);


    // Cadastra o usuario
    int flag = 0, existe = 0;

    while(flag!=1){

        printf("\n Ola %s, isira seu nome de usuario", nome);
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

            // Cadastra a senha, podemos usar a biblioteca #include <openssl/md5.h> para criptografa a senha
            char senha[50];
            printf("\n Insira uma senha");
            fflush(stdin);
            gets(senha);

            // armazena a senha ela nao esta segura!!!
            strcpy(cliente[contador].senha, senha);

            // incrementa o contador de clientes
            contador++;

            flag = 1;
        }
    }

    printf("\n Seu cadastro foi realizado com sucesso");

    return contador;
}
