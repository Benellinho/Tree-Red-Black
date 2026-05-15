#include "Tree-Red-Black.h"

/*
typedef struct No{
    int valor;
    char cor;
    struct No *esquerda;
    struct No *direita;
    struct No *pai;
} No;

typedef struct arvore{
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
    if (no == NULL)
        return;
    free(no);
}

void libera_todos_nos(No *no)
{
    if (no == NULL)
        return;
    libera_todos_nos(no->esquerda);
    libera_todos_nos(no->direita);
    free(no);
}

void libera_arvore(Arvore *arv)
{
    if (arv == NULL)
        return;
    libera_todos_nos(arv->raiz);
    free(arv);
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

void corrigir_insercao(Arvore *arvore, No *novo)
{
    // enquanto tiver pais vermelhos, tem que corrigir
    while (novo->pai != NULL && novo->pai->cor == 'R')
    {

        No *avo = novo->pai->pai;

        if (novo->pai == avo->esquerda)
        {
            No *tio = avo->direita;

            // Caso 1: tio vermelho
            if (tio != NULL && tio->cor == 'R')
            {
                novo->pai->cor = 'B';
                tio->cor = 'B';
                avo->cor = 'R';
                novo = avo;
            }
            else
            {
                // Caso 2: triângulo
                if (novo == novo->pai->direita)
                {
                    novo = novo->pai;
                    rotacao_esquerda(arvore, novo);
                }

                // Caso 3: linha
                novo->pai->cor = 'B';
                avo->cor = 'R';
                rotacao_direita(arvore, avo);
            }
        }
        else
        {
            // de forma análoga para o outro lado
            No *tio = avo->esquerda;

            if (tio != NULL && tio->cor == 'R')
            {
                novo->pai->cor = 'B';
                tio->cor = 'B';
                avo->cor = 'R';
                novo = avo;
            }
            else
            {
                if (novo == novo->pai->esquerda)
                {
                    novo = novo->pai;
                    rotacao_direita(arvore, novo);
                }

                novo->pai->cor = 'B';
                avo->cor = 'R';
                rotacao_esquerda(arvore, avo);
            }
        }
    }

    arvore->raiz->cor = 'B';
}

// Funções auxiliares gerais

int arvore_altura(No *no)
{
    if (no == NULL)
        return 0;

    int altura_esq = arvore_altura(no->esquerda);
    int altura_dir = arvore_altura(no->direita);

    if (altura_esq > altura_dir)
        return altura_esq + 1;
    else
        return altura_dir + 1;
}

void rotacao_direita(Arvore *arv, No *no)
{
    if (arv == NULL || no == NULL || no->direita == NULL)
        return;

    No *no_esq = no->esquerda;
    No *no_esq_dir = no_esq->direita;

    // 1) mover no_esq_dir para ser filho esquerdo de no
    no->esquerda = no_esq_dir;
    if (no_esq_dir != NULL)
        no_esq_dir->pai = no;
    no_esq->pai = no->pai;

    // 2) ligar no_esq ao pai original de no
    if (no->pai == NULL)
        arv->raiz = no_esq;
    else if (no == no->pai->direita)
        no->pai->direita = no_esq;
    else
        no->pai->esquerda = no_esq;

    // 3) completar rotação: no vira filho direito de no_esq
    no_esq->direita = no;
    no->pai = no_esq;
}

void rotacao_esquerda(Arvore *arv, No *no)
{
    if (arv == NULL || no == NULL || no->direita == NULL)
        return;

    No *no_dir = no->direita;
    No *no_dir_esq = no_dir->esquerda;

    // 1) mover no_dir_esq para ser filho direito de no
    no->direita = no_dir_esq;
    if (no_dir_esq != NULL)
        no_dir_esq->pai = no;

    // 2) ligar no_dir ao pai original de no
    no_dir->pai = no->pai;
    if (no->pai == NULL)
    {
        // no era a raiz da árvore
        arv->raiz = no_dir;
    }
    else if (no == no->pai->esquerda)
    {
        no->pai->esquerda = no_dir;
    }
    else
    {
        no->pai->direita = no_dir;
    }

    // 3) completar rotação: no vira filho esquerdo de no_dir
    no_dir->esquerda = no;
    no->pai = no_dir;
}

// Funções auxiliares verificação das regras
static bool verifica_cor_aux(No *no)
{
    // auxiliar para verificar se a cor de cada nó é válida
    if (no == NULL)
        return true;

    // verifica se a cor é válida
    if (no->cor != 'R' && no->cor != 'B')
        return false;

    return verifica_cor_aux(no->esquerda) && verifica_cor_aux(no->direita);
}

bool verifica_cor_arvore(Arvore *arv)
{
    if (arv == NULL)
        return true;

    return verifica_cor_aux(arv->raiz);
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

// Funções auxiliares para a impressão
static void imprime_nivel_arv_aux(No *no, int nivel)
{
    if (no == NULL)
    {
        return;
    }
    for (int i = 0; i < nivel; i++)
    {
        printf("    ");
    }
    printf("%d(%c)\n", no->valor, no->cor, nivel);
    nivel++;
    imprime_nivel_arv_aux(no->esquerda, nivel);
    imprime_nivel_arv_aux(no->direita, nivel);
}

static void imprime_ordem_arv_aux(No *no)
{
    if (no == NULL)
    {
        return;
    }
    imprime_ordem_arv_aux(no->esquerda);
    printf("%d(%c)", no->valor, no->cor);
    imprime_ordem_arv_aux(no->direita);
}

static void imprime_pre_ordem_arv_aux(No *no)
{
    if (no == NULL)
    {
        return;
    }
    printf("%d(%c)", no->valor, no->cor);
    imprime_pre_ordem_arv_aux(no->esquerda);
    imprime_pre_ordem_arv_aux(no->direita);
}

// Funções auxiliares para o leitor;

int string_para_numero(char *dados)
{
    return strtol(dados, NULL, 10);
}

int leitor(Arvore *arv, char *dados)
{
    char comando = toupper(dados[0]);
    int valor;
    switch (comando)
    {
    case 'I':
        valor = string_para_numero(&dados[2]);
        inserir_no(arv, valor);
        break;
    case 'R':
        valor = string_para_numero(&dados[2]);
        remove_no(arv, valor);
        break;
    case 'B':
        valor = string_para_numero(&dados[2]);
        busca_no(arv, valor);
        break;
    case 'P':
        imprime_tree_red_black(arv);
        break;
    case 'E':
        ordem_tree_red_black(arv);
        break;
    case 'O':
        pre_ordem_tree_red_black(arv);
        break;
    case 'V':
        validar_tree_red_black(arv);
        break;
    case 'F':
        libera_arvore(arv);
        return 0;
    default:
        printf("insira um comndo valido para o programa\n");
        break;
    }
    return 1;
}

// Funções primárias
void inserir_no(Arvore *arv, int valor)
{
    No *novo = aloca_no(valor);

    if (arv->raiz == NULL)
    {
        inserir_raiz(arv, novo);
    }
    else if (verifica_no_existente(arv, valor))
    {
        printf("Valor duplicado");
        libera_no(novo);
        return;
    }
    else
    {
        inserir_no_comum(arv, novo);
    }
    corrigir_insercao(arv, novo);
    printf("Inserido: %d \n", valor);
}

void remove_no(Arvore *arv, int valor)
{
    No *no_removido = busca_no(arv, valor);
}

void corrigir_remocao(Arvore *arv, No *no_removido)
{
    while (no_removido != arv->raiz && (no_removido == NULL || no_removido->cor == 'B'))
    {

        if (no_removido == no_removido->pai->esquerda)
        {
            No *irmao = no_removido->pai->direita;

            // Caso 1: irmão vermelho
            if (irmao != NULL && irmao->cor == 'R')
            {
                irmao->cor = 'B';
                no_removido->pai->cor = 'R';
                rotacao_esquerda(arv, no_removido->pai);
                irmao = no_removido->pai->direita;
            }

            // Caso 2: irmão preto com filhos pretos
            if ((irmao->esquerda == NULL || irmao->esquerda->cor == 'B') &&
                (irmao->direita == NULL || irmao->direita->cor == 'B'))
            {

                irmao->cor = 'R';
                no_removido = no_removido->pai;
            }
            else
            {
                // Caso 3: filho interno vermelho
                if (irmao->direita == NULL || irmao->direita->cor == 'B')
                {
                    if (irmao->esquerda != NULL)
                        irmao->esquerda->cor = 'B';

                    irmao->cor = 'R';
                    rotacao_direita(arv, irmao);
                    irmao = no_removido->pai->direita;
                }

                // Caso 4: filho externo vermelho
                irmao->cor = no_removido->pai->cor;
                no_removido->pai->cor = 'B';

                if (irmao->direita != NULL)
                    irmao->direita->cor = 'B';

                rotacao_esquerda(arv, no_removido->pai);
                no_removido = arv->raiz;
            }
        }
        else
        {
            // de maneira análoga para o outro lado
            No *irmao = no_removido->pai->esquerda;

            if (irmao != NULL && irmao->cor == 'R')
            {
                irmao->cor = 'B';
                no_removido->pai->cor = 'R';
                rotacao_direita(arv, no_removido->pai);
                irmao = no_removido->pai->esquerda;
            }

            if ((irmao->direita == NULL || irmao->direita->cor == 'B') &&
                (irmao->esquerda == NULL || irmao->esquerda->cor == 'B'))
            {

                irmao->cor = 'R';
                no_removido = no_removido->pai;
            }
            else
            {
                if (irmao->esquerda == NULL || irmao->esquerda->cor == 'B')
                {
                    if (irmao->direita != NULL)
                        irmao->direita->cor = 'B';

                    irmao->cor = 'R';
                    rotacao_esquerda(arv, irmao);
                    irmao = no_removido->pai->esquerda;
                }

                irmao->cor = no_removido->pai->cor;
                no_removido->pai->cor = 'B';

                if (irmao->esquerda != NULL)
                    irmao->esquerda->cor = 'B';

                rotacao_direita(arv, no_removido->pai);
                no_removido = arv->raiz;
            }
        }
    }

    if (no_removido != NULL)
        no_removido->cor = 'B';
}

// Auxiliar para função de busca
static No *busca_aux(No *no, int valor)
{
    if (no == NULL)
        return NULL;

    if (no->valor == valor)
        return no;

    if (valor < no->valor)
        return busca_aux(no->esquerda, valor);

    return busca_aux(no->direita, valor);
}

No *busca_no(Arvore *arvore, int valor)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        return NULL;
    }

    return busca_aux(arvore->raiz, valor);
}

void imprime_tree_red_black(Arvore *arv)
{
    printf("Arvore: \n");
    imprime_nivel_arv_aux(arv->raiz, 0);
    printf("\n");
}

void ordem_tree_red_black(Arvore *arv)
{
    printf("Em ordem: ");
    imprime_ordem_arv_aux(arv->raiz);
    printf("\n");
}

void pre_ordem_tree_red_black(Arvore *arv)
{
    printf("Em pre-ordem: ");
    imprime_pre_ordem_arv_aux(arv->raiz);
    printf("\n");
}

bool validar_tree_red_black(Arvore *arv)
{
    if (arv == NULL)
        return false;

    // A árvore deve ter raiz preta,
    // não deve ter nós consecutivos vermelhos e
    // deve ter o mesmo número de nós pretos até as folhas em todos os caminhos
    return (verifica_raiz_preta(arv) && verifica_filho_vermelho_vermelho(arv) && verifica_caminho_folhas(arv));
}

void Finalizar(Arvore *arv)
{
    if (arv == NULL)
        return;
    libera_arvore(arv);
    exit(0);
}
