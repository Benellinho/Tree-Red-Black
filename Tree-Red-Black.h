#ifndef TREE_RED_BLACK_H
#define TREE_RED_BLACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct No
{
    int valor;
    char cor;
    struct No *esquerda;
    struct No *direita;
    struct No *pai;
} No;

typedef struct TreeRedBlack
{
    No *raiz;
} Arvore;

// Funcoes publicas para uso fora deste modulo.
Arvore *aloca_arvore();
void libera_arvore(Arvore *arvore);

void inserir_no(Arvore *arvore, int valor);
void remove_no(Arvore *arvore, int valor);
No *busca_no(Arvore *arvore, int valor);

void imprime_tree_red_black(Arvore *arvore);
void ordem_tree_red_black(Arvore *arvore);
void pre_ordem_tree_red_black(Arvore *arvore);

bool validar_tree_red_black(Arvore *arvore);
void finalizar(Arvore *arvore);
int leitor(Arvore *arvore, char *dados);

#endif /* TREE_RED_BLACK_H */
