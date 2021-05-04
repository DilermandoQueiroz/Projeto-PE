#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct livros{
    char nome[50];
    int id;
    int qtd_alugado;
    int qtd_comprado;
    int qtd_estoque;
    int avaliacao, qtd_avaliacoes;
};

struct clientes{
    int id;
    char livros_alugado[20][50];
    char usuario[50];
    int senha;
};

struct funcionarios{
    int id;
    char usuario[50];
    int senha;
};

// Feito por Dilermando Queiroz Neto RA: 11201722993
int adicionar_remover(struct livros livro[], int contador, int tam_atual);
int cadastrar_cliente(struct clientes cliente[10], int contador);
void exporta_csv(struct livros livro[], int contador);
void escrever_livros(struct livros livro[], int contador);
int ler_livros(struct livros livro[]);
int id_nome(char nome[100]);
int verificacao(int id, int senha, struct clientes cliente[], int contador);
void escrever_cliente(struct clientes cliente[], int contador);
int ler_clientes(struct clientes cliente[]);

int avaliar(struct livros livro[], int contador);
void detalhes(struct livros livro[], int contador);

void catalogo(struct livros livro[], int qtde);
void estoque(struct livros livro[], int qtde);

void AlugarComprar(struct livros livro[], int contador, int id, struct clientes cliente[], int contadorcliente);
void Devolver(struct livros livro[], int contador, int id, struct clientes cliente[], int contadorcliente);
void EstoqueBaixo(struct livros livro[], int contador);
void DevolverLivros(struct clientes cliente[], int contador, int id);


void troca(char p1[100][20], int palavra);
void ordenar_livros(struct livros livro[], int qtde);
char converte_maiuscula(char letra);

#endif // BIBLIOTECA_H
