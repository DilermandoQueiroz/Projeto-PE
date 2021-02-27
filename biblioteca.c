#include<stdio.h>

int main(){

    int aux = -1, flag = 0;

    
    printf("Ola boa, seja bem-vindo a Biblioteca UFABC! Voce gostaria de acessar nosso sistema como?\nDigite 1 - Cliente\nDigite 2 - Funcionario\n");
    while(flag == 0){
        scanf("%d", &aux);
        if(aux == 1){
            printf("Ainda estamos preparando o sistema para nossos clientes\n");
            flag = 1;
        }
        else if(aux == 2){
            printf("Ainda estamos preparando o sistema para nossos funcionarios\n");
            flag = 1;
        }
        else{
            printf("Essa entrada nao eh valida\n");
        }
    }

    return 0;
}