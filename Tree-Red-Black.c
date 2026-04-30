#include "Tree-Red-Black.h"

/*
typedef struct No
{
    int valor;
    char cor;
    struct No *esquerda;
    struct No *direita;
    struct No *pai;
} No;

typedef struct arvore
{
    No *raiz;
} arvore;
*/

void troca_cor_no(No *no)
{
    if (no->cor == "R")
    {
        no->cor = "B";
    }
    else
    {
        no->cor = "R";
    }
}

void rotação_direita(No *no)
{
}

void rotação_esquerda(No *no)
{
}

bool verifica_cor(arvore *arvore)
{
    return false;
}

bool verifica_raiz_preta(arvore *arvore)
{
    if (arvore->raiz->cor == "P")
    {
        return true;
    }
    return false;
}

bool verifica_nos_null(arvore *arvore)
{
    return false;
}

bool verifica_filho_vermelho_vermelho(arvore *arvore)
{
    return false;
}

bool verifica_caminho_folhas(arvore *arvore)
{
    return false;
}

int leitor(char *dados)
{
    return 0;
}

int insere_no(arvore *arvore, int valor)
{
    return 0;
}

int remove_no(arvore *arvore, int valor)
{
    return 0;
}

int busca_no(arvore *arvore, int valor)
{
    return 0;
}

int imprime_tree_red_black(arvore *arvore)
{
    return 0;
}

int ordem_tree_red_black(arvore *arvore)
{
    return 0;
}

int pre_ordem_tree_red_black(arvore *arvore)
{
    return 0;
}

bool validar_tree_red_black(arvore *arvore)
{
    return false;
}

void Finalizar(arvore *arvore)
{
}
