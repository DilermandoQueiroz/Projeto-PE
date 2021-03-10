#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include<stdio.h>
#include<string.h>

int adicionar_remover(int livros[100][5], char nome_livros[][20], int contador);
int id_nome(char nome[100]);
void avaliar(int livros[100][5]);
void detalhes(int livros[100][5]);

#endif // BIBLIOTECA_H