#include "biblioteca.h"

/*
Recebe o nome de um livro e retorna seu id
o id � calculado pela soma do valor int das letras que compoem o nome do livro
*/
int id_nome(char nome[100]){
    int id = 0;

    for(int i=0; nome[i]!='\0'; i++){
        nome[i] = converte_maiuscula(nome[i]);
        id += nome[i];
    }

    return id;
}