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

// Funções auxiliares

// Funções de memoria
No *aloca_no(int valor)
{
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL)
    {
        printf("Erro ao alocar memoria para o no.\n");
        return NULL;
    }

    novo->valor = valor;
    novo->cor = 'R';
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->pai = NULL;

    return novo;
}

void libera_no(No *no)
{
}

void libera_arvore(Arvore *arvore)
{
}

// Pronta
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

bool verifica_cor_arvore(Arvore *arvore)
{
    return false;
}

bool verifica_raiz_preta(Arvore *arvore)
{
    if (arvore->raiz->cor == "P")
    {
        return true;
    }
    return false;
}

bool verifica_nos_null(Arvore *arvore)
{
    return false;
}

bool verifica_filho_vermelho_vermelho(Arvore *arvore)
{
    return false;
}

bool verifica_caminho_folhas(Arvore *arvore)
{
    return false;
}

int leitor(char *dados)
{
    return 0;
}

// Funções primarias
int insere_no(Arvore *arvore, int valor)
{
    return 0;
}

int remove_no(Arvore *arvore, int valor)
{
    return 0;
}

int busca_no(Arvore *arvore, int valor)
{
    return 0;
}

int imprime_tree_red_black(Arvore *arvore)
{
    return 0;
}

int ordem_tree_red_black(Arvore *arvore)
{
    return 0;
}

int pre_ordem_tree_red_black(Arvore *arvore)
{
    return 0;
}

bool validar_tree_red_black(Arvore *arvore)
{
    return false;
}

void Finalizar(Arvore *arvore)
{
}
