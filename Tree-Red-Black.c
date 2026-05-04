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

// Funções auxiliares memoria

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

Arvore *aloca_arvore()
{
    Arvore *arv = (Arvore *)malloc(sizeof(Arvore));

    if (arv == NULL)
    {
        printf("Erro ao alocar memoria para a arvore.\n");
        return NULL;
    }

    arv->raiz = NULL;

    return arv;
}

void libera_no(No *no)
{
}

void libera_arvore(Arvore *arv)
{
}

void definir_cor_no(No *no, char cor)
{
    no->cor = cor;
}

// Funções auxiliares inserção
void inserir_raiz(Arvore *arv, No *no)
{
    arv->raiz = no;
    definir_cor_no(no, 'B');
}

bool verifica_no_existente(Arvore *arv, int valor)
{
    No *existe = busca_no(arv, valor);
    if (existe == NULL)
    {
        return false;
    }
    return true;
}

void inserir_no_comum(Arvore *arv, No *no)
{
    No *pai = arv->raiz;
    while (true)
    {
        if (pai->valor > no->valor)
        {
            if (pai->esquerda == NULL)
            {
                pai->esquerda = no;
                break;
            }
            pai = pai->esquerda;
        }
        else
        {
            if (pai->direita == NULL)
            {
                pai->direita = no;
                break;
            }
            pai = pai->direita;
        }
    }
    no->pai = pai;
}

void corrigir_insercao(Arvore *arv, No *novo)
{
}

// Funções auxiliares gerais

int arvore_altura(No *pai)
{
    if (pai->direita == NULL && pai->esquerda == NULL)
    {
        return 1;
    }
    int altura_direita = arvore_altura(pai->direita);
    int altura_esquerda = arvore_altura(pai->esquerda);
    if (altura_direita >= altura_esquerda)
    {
        return altura_direita;
    }
    else
    {
        return altura_esquerda;
    }
}

void rotacao_direita(Arvore *arv, No *no)
{
}

void rotacao_esquerda(Arvore *arv, No *no)
{
}

bool verifica_cor_arvore(Arvore *arv)
{
    return false;
}

bool verifica_raiz_preta(Arvore *arv)
{
    if (arv->raiz->cor == 'B')
    {
        return true;
    }
    return false;
}

bool verifica_nos_null(Arvore *arv)
{
    return false;
}

bool verifica_filho_vermelho_vermelho(Arvore *arv)
{
    return false;
}

bool verifica_caminho_folhas(Arvore *arv)
{
    return false;
}

int leitor(char *dados)
{
    return 0;
}

// Funções primarias
void inserir_no(Arvore *arv, int valor)
{
    No *novo = aloca_no(valor);

    if (arv->raiz == NULL)
    {
        inserir_raiz(arv, novo);
        return;
    }
    if (verifica_no_existente(arv, valor))
    {
        libera_no(novo);
        return;
    }
    inserir_no_comum(arv, novo);
    corrigir_insercao(arv, novo);
}

void remove_no(Arvore *arv, int valor)
{
    return 0;
}

No *busca_no(Arvore *arv, int valor)
{
    return;
}

void imprime_tree_red_black(Arvore *arv)
{
    return 0;
}

void ordem_tree_red_black(Arvore *arv)
{
    return 0;
}

void pre_ordem_tree_red_black(Arvore *arv)
{
    return 0;
}

bool validar_tree_red_black(Arvore *arv)
{
    return false;
}

void finalizar(Arvore *arv)
{
}
