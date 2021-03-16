#include "biblioteca.h"

void troca(char p1[100][20], int palavra){ //troca a palavra X com a palavra X+1
    char temp[20];
    strcpy(temp, p1[palavra]);
    strcpy(p1[palavra], p1[palavra+1]);
    strcpy(p1[palavra+1], temp);

}

char converte_maiuscula(char letra){ // converte uma letra maiuscula em minuscula
    if (letra>=65 && letra<=90)
    {
        letra= letra+32;
    }

    return letra;
}

 void ordenar_livros(int livros[100][6], char nome_livros[100][20],int qtde){
    char ordenado[qtde][20];  //vetor temporário para receber livros em ordem, será apagado no fim da função
    int count = 0;

    for (int i = 0 ; i < qtde; i++)
    {
        for(int n=0; n<=strlen(nome_livros[i]); n++){
                ordenado[i][n] = nome_livros[i][n];
        }
    }


    while(count!=qtde-1) //o count é quantidade de vezes que um dupla de palavras está na ordem certa, em um vetor de comprimento "qtde" a quatidade de duplas é "qtde-1"
    {
        count=0;

        for (int x = 0; x < qtde-1; x++) //como é verificado n e n+1, é necessário -1 para não comparar com um valor não determinado
        {
            int comp;
            if(strlen(ordenado[x])<strlen(ordenado[x+1])) { // achar o menor comprimento
                comp=strlen(ordenado[x]);
            }else{  comp=strlen(ordenado[x+1]); }
                int n=0;
            while (converte_maiuscula(ordenado[x][n])==converte_maiuscula(ordenado[x+1][n]) && n<comp) // como é verificado n e n+1, é necessário -1 para não comparar com um valor não determinado
                {
                    n++;
                }

            if (converte_maiuscula(ordenado[x][n]) >converte_maiuscula(ordenado[x+1][n]) ) // troca
            {
                troca(ordenado,x);

            }else
            {
                count++;
            }

        }

    }

    for (int i = 0; i < qtde; i++)
    {
        printf("%s\n", ordenado[i]);
    }

}

void estoque(int livros[100][6], char nome_livros[100][20],int qtde){
    int escolha = 0, i;
    char nome[20];

    do{
        printf("\n O que voce deseja? \n Digite 1 - Ver o estoque de um livro especifico \n Digite 2 - Ver o estoque geral \n Digite 3 - Sair\n");
        scanf("%i", &escolha);

        if(escolha == 1){
            printf("\n Ver o estoque de qual livro?\n");
            fflush(stdin);
            gets(nome);

            //imprime a quantidade do livro escolhido
            for(i=0;i<100;i++){
                if(strcmp (nome, nome_livros[i]) == 0){
                    printf("%s : %i unidades disponiveis\n", nome, livros[i][1]);

                    i=100;
                }
            }

            if(i == 100){
                printf("\n Este livro ainda nao foi cadastrado.\n");
            }
        }

        //imprime o estoque de todos os livros cadastrados
        else if(escolha == 2){
            if(qtde == 0){
                printf("\n Nenhum livro cadastrado\n");
            }
            else{
                printf("\n----------------------------------------\n");
                printf("ESTOQUE:\n");
                for(int i=0;i<qtde;i++){
                    printf("%s : %i unidades disponiveis\n", nome_livros[i], livros[i][1]);
                }
                printf("\n----------------------------------------\n");
            }
        }

        else if(escolha == 3){
            printf("\n Voce saiu do estoque!\n");
        }

        else if(escolha != 3 ){
            printf("\n Insira uma opcao valida!\n");
        }

    }while(escolha!=3);
}

/*Avalia um livro
*/
int avaliar(int livros[100][6], int contador){

    char nome[20];
    printf("\n Por favor, entre com o nome do livro que deseja avaliar:\n");
    fflush(stdin);
    gets(nome);

    int id = id_nome(nome);
    int aux = 0;
    int cont = 0;
    int nota = 0;

    // Encontrar o livro na lista
    while(aux == 0){

        if(id == livros[cont][0]){

            while(aux == 0){

                printf("\n Entre com a sua avaliacao(0-100):\n");
                scanf("%i", &nota);

                // Verificar se a nota inserida está no intervalo indicado
                if(nota<0 || nota>100){

                    printf("\n Nota invalida!\n");
                }
                else{

                    aux = 1;
                }
            }

            printf("\n Obrigado!\n");

            // Atualizar a média do livro

            int n = livros[cont][4];
            int media = livros[cont][3];

            media = (n*media+nota)/(n+1);

            livros[cont][4] = n+1;
            livros[cont][3] = media;

        }

        // Se o nome do livro ja foi comparado com todos os nomes do vetor, este ainda nao foi cadastrado
        if(cont == contador+1){
            printf("\n Este livro ainda nao foi cadastrado.\n");
            aux = 1;
        }
        cont = cont+1;
    }

    return livros, contador; // Retorna a matriz livros atualizada
}

void detalhes(int livros[100][6], int contador){
    char nome[50];

    fflush(stdin);
    printf("\n Insira o nome do livro que voce gostaria de saber detalhes: \n");
    gets(nome);

    int id = id_nome(nome);
    int aux = 0;
    int cont = 0;

    // Encontrar o livro na lista de livros cadastrados
    while(aux == 0){
        if(id == livros[cont][0]){
            aux = 1;
            printf("\n O livro '%s' foi alugado %i vezes, avaliado por %i pessoas e possui media %i.\n", nome, livros[cont][1], livros[cont][4], livros[cont][3]);
            printf("Existem %i copias em nosso estoque.\n\n", livros[cont][2]);
        }
        if(cont == contador+1){
            printf("Este livro ainda nao foi cadastrado.\n\n");
            aux = 1;
        }
        cont = cont + 1;
    }

    int a =0;
    aux = 0;

    while(aux==0){
        printf("Gostaria de saber mais detalhes sobre outro livro? \n Digite 1 - Sim \n Digite 2 - Nao\n");

        scanf("%i", &a);

        if(a == 1){
            detalhes(livros,contador);
            aux = 1;
        }
        else if(a == 2){
            aux = 1;
            printf("\n Ate logo!\n");
        }
        else{
            printf("\n Essa entrada nao eh valida\n\n");
        }
    }
}

//Funcao para aluguel/compra de livros
int AlugarComprar(int livros[100][6], char nome_livros[100][20], int contador){

    int idlivro, aux=0, op=0, escolha = 0;
    char nome[100];

    printf("\n Deseja ver o catálogo antes? \n Digite 1 - Sim \n Digite 2 - Nao\n");
    scanf("%i", &escolha);

    do{
        if(escolha == 1){
            catalogo(livros, nome_livros, contador);

            escolha = 2;
        }
        else if(escolha != 2){
            printf("\n Essa entrada nao eh valida\n");
        }

    }while(escolha!= 2);

    while(op!=3){

        printf("\n O que deseja fazer: \n 1-Alugar um livro \n 2-Comprar um livro \n 3-Sair\n");
        scanf("%i", &op);


        if(op==1){
            printf("\n Por favor digite o nome do livro que deseja alugar: \n");
            fflush(stdin);
            gets(nome);

            idlivro = id_nome(nome);

            for(int i = 0; i<contador; i++){
                if(livros[i][0] == idlivro){
                    printf("\n O livro %s alugado com sucesso, tenha uma otima leitura! \n", nome);
                    //Aumenta o contador de alugueis
                    livros[i][1]++;
                    //Diminue a quatidade em estoque
                    livros[i][3]--;
                    aux=1;
                }
            }
            printf("\n Voce saiu da sessao de compras/alugueis! \n");
        }

        else if(op==2){
            aux=0;
            printf("\n Por favor digite o nome do livro que deseja comprar: \n");
            fflush(stdin);
            gets(nome);

            idlivro = id_nome(nome);

            for(int i = 0; i<contador; i++){
                if(livros[i][0]==idlivro){
                    printf("\n O livro %s comprado com sucesso, agradecemos a preferencia e boa leitura!\n", nome);
                    //Aumenta o contador de compras
                    livros[i][5]++;
                    //Diminui a quatidade em estoque
                    livros[i][2]--;
                    aux=1;
                }
            }
        }

        else if(op!= 3){
            printf("\n Essa entrada nao eh valida\n");
        }

        if (aux==0 && op!=3){
            printf("\n Desculpe mas o livro %s nao foi encontrado.\n", nome);
            idlivro=0;
        }
    }

    return livros, contador;
}

//Funcao pra devolver livros alugados
int Devolver(int livros[100][6], int contador){
    int idlivro, aux=0, op=0;
    char nome[100];


    while(aux==0){

        printf("\n Por favor digite o nome do livro que deseja devolver \n");
        fflush(stdin);
        gets(nome);

        idlivro = id_nome(nome);

        for(int i = 0; i<contador; i++){
            if(livros[i][0]==idlivro){
                printf("\n O livro %s foi devolvido com sucesso!\n", nome);

                //Aumenta a quatidade em estoque
                livros[i][2]++;
                aux=1;

                printf("\n Deseja avaliar o livro?\n1 - Sim\n2 - Nao\n");
                scanf("%i", &op);

                if(op == 1){
                    avaliar(livros, contador);
                }
            }
        }
        if(aux==0){
            printf("\n Desculpe mas o livro %s nao foi encontrado.\n", nome);
            idlivro=0;
        }
    }

    return livros, contador;

}

void catalogo(int livros[100][6], char nome_livros[100][20], int qtde){
    int interesse=0;

    printf("\n----------------------------------------\n");
    printf("\n Catalogo Biblioteca UFABC: \n");

    if(qtde == 0){
        printf("\n Nenhum livro cadastrado\n");
    }
    else{
        ordenar_livros(livros, nome_livros, qtde);
    }

    printf("\n----------------------------------------\n");

    do{
        printf("\n Gostaria de saber mais detalhes de algum livro? \n Digite 1 - Sim \n Digite 2 - Nao\n");
        scanf("%i", &interesse);

        if(interesse==1){
            detalhes(livros, qtde);
        }

        else if(interesse != 2){
            printf("\n Insira uma opcao valida!\n");
        }

    }while(interesse!=2);

}

/*
Funcao para adicionar ou remover um livro pelo seu ID
*/

int adicionar_remover(int livros[100][6], char nome_livros[100][20], int contador)
{
    int aux = 0, flag = 1, colunas = 6;

    while(flag != 2){
        printf("\n Voce deseja: \n 1->Adicionar um livro \n 2->Remover um livro\n");
        scanf("%d", &aux);

        //adiciona um livro
        if(aux == 1){
            char nome[100];
            int id, flag = 1;
            printf("\n Insira o nome do livro\n");
            scanf("%s", nome);
            id = id_nome(nome);

            //verifica se o livro ja esta cadastrado
            for(int i = 0; i<contador; i++){
                if(livros[i][0] == id){
                    printf("\n Esse livro ja esta cadastrado\n");
                    flag = 0;
                }
            }
            //verifica se ja atingiu o limite
            if(contador == 100){
                printf("\n Nao existe mais espaço na biblioteca\n");
            }
            //se o livro nao estiver cadastrado, cadastra ele
            else if(flag != 0){
                //insere o id do livro
                livros[contador][0] = id;

                //inicializa como 0 as outras colunas
                for(int k=1; k<colunas; k++){
                    livros[contador][k] = 0;
                }

                //insero o nome do livro
                for(int n=0; n<=strlen(nome); n++){
                    nome_livros[contador][n] = nome[n];
                }
                contador++;
                printf("\n Adicionado com sucesso!\n");
            }

        //remove um livro
        }
        else if(aux == 2){
            int flag2 = 0, aux, id;
            char nome[100];

            printf("\n Insira o nome do livro que deseja remover\n");
            scanf("%s", nome);

            id = id_nome(nome);

            //verifica se o livro consta na biblioteca e o remove
            for(int i = 0; i<contador; i++){
                if(livros[i][0] == id){
                    flag2 = 1;
                    aux = i;

                    //desloca uma possicao para a esquerda a partir da que foi removida
                    for(aux; aux<contador; aux++){
                        //realiza para cada coluna do livros
                        for(int k=0; k<colunas; k++){
                            livros[aux][k] = livros[aux+1][k];
                        }
                    }
                    contador--;
                    printf("\n Removido com sucesso!\n");
                }
            }
            if(flag2 == 0){
                printf("\n Esse livro nao estava na biblioteca\n");
            }
        }
        else{
            printf("\n Insira uma opcao valida!\n");
        }

        printf("\n Voce deseja sair do menu de adicionar e remover? \n 1->nao \n 2->sim\n");
        scanf("%i", &flag);

        if(flag == 2){
            printf("\n Voce saiu do menu de adicionar e remover\n");
        }
    }

    return livros, contador;
}

/*
Recebe o nome de um livro e retorna seu id
o id é calculado pela soma do valor int das letras que compoem o nome do livro
*/
int id_nome(char nome[100]){
    int id = 0;

    for(int i=0; nome[i]!='\0'; i++){
        nome[i] = converte_maiuscula(nome[i]);
        id += nome[i];
    }

    return id;
}

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
                printf("\n Eh muito bom te-lo conosco! O que voce deseja? \n Digite 1 - Ver o nosso catalogo de livros \n Digite 2 - Comprar \n Digite 3 - Devolver um livro \n Digite 4 - Avaliar um livro \n Digite 5 - Ver detalhes de um livro \n Digite 6 - Sair da área do cliente\n");
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
