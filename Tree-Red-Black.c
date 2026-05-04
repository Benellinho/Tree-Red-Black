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

void libera_no(No *no) {
    if(no == NULL) return;

    libera_no(no->esquerda);
    libera_no(no->direita);

    free(no);
}

void libera_arvore(Arvore *arvore)
{
    if(arvore == NULL) return;
    libera_no(arvore->raiz);

    arvore->raiz = NULL;
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
    if (arvore->raiz->cor == "B")
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

// Auxiliar para função de busca
static bool busca_aux(No *no, int valor) {
    if(no == NULL) return false;

    if(no->valor == valor) return true;

    if(valor < no->valor) {
        return busca_aux(no->esquerda, valor);
    }

    return busca_aux(no->direita, valor);
}

void busca_no(Arvore *arvore, int valor) {
    if(arvore == NULL || arvore->raiz == NULL) {
        printf("Valor nao encontrado\n");
        return;
    } 

    if(busca_aux(arvore->raiz, valor)) {
        printf("Valor encontrado\n");
    } else {
        printf("Valor nao encontrado\n");
    }
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

void validar_tree_red_black(Arvore *arvore) {
    if(arvore == NULL) {
        printf("Arvore invalida\n");
        return;
    }

    // A árvore deve ter raiz preta, não deve ter nós consecutivos vermelhos e deve ter o mesmo número de nós pretos até as folhas
    // em todos os caminhos
    if(!verifica_raiz_preta(arvore) || !verifica_filho_vermelho_vermelho(arvore) || !verifica_caminho_folhas(arvore)) {
        printf("Arvore invalida\n");
        return;
    } 

    printf("Arvore valida\n");
}


void Finalizar(Arvore *arvore) {
    if(arvore == NULL) return;
    libera_arvore(arvore);
    free(arvore);
    exit(0);
}
