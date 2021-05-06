#include "biblioteca.h"

int main(){

    int aux = -1, flag = 0, escolha_cliente = 0, escolha_funcionario = 0, tam_atual = 100, contador_clientes = 0, contador_livros = 0,
    tam_atual_clientes = 100, id_cliente = 0;

    // Abre o arquivo que esta salvo o struct livros
    FILE *arquivo = fopen("./dados/livros.bin", "rb");
    FILE *arquivo_cliente = fopen("./dados/clientes.bin", "rb");

    // Cria um vetor dinamico de struct livros, definido em biblioteca.h
    struct livros *livro = NULL;
    livro = (struct livros *) malloc(tam_atual*sizeof(struct livros));

    // Cria um vetor dinamica de struct clientes, definido em biblioteca.h
    struct clientes *cliente = NULL;
    cliente = (struct clientes *) malloc(tam_atual_clientes*sizeof(struct clientes));

    if(livro == NULL || cliente == NULL){
        printf("Aconteceu um erro, tente mais tarde\n");
    }

    // Se o arquivo existir leia os dados contido nele
    if(arquivo != NULL){
        contador_livros = ler_livros(livro);
    }
    if(arquivo_cliente != NULL){
        contador_clientes = ler_clientes(cliente);
    }

    fclose(arquivo);
    fclose(arquivo_cliente);

    while(flag != 2){

        printf("-----------------------------------------------------------------------------------");
        printf("\n Ola seja bem-vindo a Biblioteca UFABC! Voce gostaria de acessar nosso sistema como? \n Digite 1 - Cliente \n Digite 2 - Funcionario\n Digite 3 - Sair da biblioteca\n");
        scanf("%d", &aux);

        if(aux == 1){
            int login_cliente = 0;

            do{

                while(login_cliente != 1){
                        int op = 0, senha_cliente = 0;
                        char usuario[50], senha[50];

                        printf("\n Ola, voce ja possui cadastro na nossa biblioteca? \n Digite 1 - Sim \n Digite 2 - Nao\n");
                        scanf("%i", &op);

                        if(op == 1){
                            printf("\nPor favor digite o usuario: \n");
                            fflush(stdin);
                            gets(usuario);
                            id_cliente = id_nome(usuario);

                            printf("\nPor favor digite a senha: \n");
                            fflush(stdin);
                            gets(senha);
                            senha_cliente = id_nome(senha);

                            //Chama função de verificar cadastro
                            login_cliente = verificacao(id_cliente, senha_cliente, cliente, contador_clientes);

                        }else if(op == 2){
                            //Chama função de cadastrar os clientes;
                            contador_clientes = cadastrar_cliente(cliente, contador_clientes);

                        }else{
                            printf("\n Essa entrada nao eh valida\n");
                        }

                    }

                //DevolverLivros(cliente, contador_clientes, id_cliente);

                printf("\n Eh muito bom te-lo conosco! O que voce deseja? \n Digite 1 - Ver o nosso catalogo de livros \n Digite 2 - Alugar/Comprar \n Digite 3 - Devolver um livro \n Digite 4 - Avaliar um livro \n Digite 5 - Ver detalhes de um livro \n Digite 6 - Sair da area do cliente\n");
                scanf("%i", &escolha_cliente);

                if(escolha_cliente == 1){
                    catalogo(livro, contador_livros);
                }

                else if(escolha_cliente == 2){
                    AlugarComprar(livro, contador_livros, id_cliente, cliente, contador_clientes);
                }

                else if(escolha_cliente == 3){
                    Devolver(livro, contador_livros, id_cliente, cliente, contador_clientes);
                }

                else if(escolha_cliente == 4){
                    contador_livros = avaliar(livro, contador_livros);
                }

                else if(escolha_cliente == 5){
                    detalhes(livro, contador_livros);
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
            int login_funcionario = 0;
            do{
                
                while(login_funcionario != 1){
                        int op = 0, senha_funcionario = 0, id_funcionario;
                        char usuario[50], senha[50];

                        printf("\n Ola, voce ja possui cadastro na nossa biblioteca? \n Digite 1 - Sim \n Digite 2 - Nao\n");
                        scanf("%i", &op);

                        if(op == 1){
                            printf("\nPor favor digite o usuario: \n");
                            fflush(stdin);
                            gets(usuario);
                            id_funcionario = id_nome(usuario);

                            printf("\nPor favor digite a senha: \n");
                            fflush(stdin);
                            gets(senha);
                            senha_funcionario = id_nome(senha);

                            //Chama função de verificar cadastro funcionario

                        }else if(op == 2){
                            //Chama função de cadastrar funcionarios;

                        }else{
                            printf("\n Essa entrada nao eh valida\n");
                        }

                }
                

                EstoqueBaixo(livro, contador_livros);

                printf("\n E muito bom te-lo conosco! O que voce deseja? \n Digite 1 - Cadastrar/Remover um livro \n Digite 2 - Ver o estoque \n Digite 3 - Sair da area do funcionario\n");
                scanf("%i", &escolha_funcionario);

                if(escolha_funcionario == 1){
                    contador_livros = adicionar_remover(livro, contador_livros, tam_atual);
                }

                else if(escolha_funcionario == 2){
                    estoque(livro, contador_livros);
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
