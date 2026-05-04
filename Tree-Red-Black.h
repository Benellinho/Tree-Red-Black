#ifndef TREE_RED_BLACK_H
#define TREE_RED_BLACK_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Funções auxiliares para as funções principais não devem imprimir nada no console

// Funções de memoria
/**
 * Função interna para alocação de memoria do no
 *
 * Dados esperados: Valor do nó.
 * O que faz: cria o no aloca ele é ajusta os parâmetros e valores.
 */
No *aloca_no(int valor);

/**
 * Função interna para alocação de memoria da árvore
 *
 * Dados esperados: nenhum.
 * O que faz: cria a árvore, aloca ela e ajusta seus parâmetros iniciais.
 */
Arvore *aloca_arvore();

/**
 * Função interna para liberação de memoria do no
 *
 * Dados esperados: Nó.
 * O que faz: Libera a memoria do nó.
 */
void libera_no(No *no);

/**
 * Função interna para liberação de memoria da árvore
 *
 * Dados esperados: árvore.
 * O que faz: Libera a memoria dos nós sequencialmente é por fim a árvore.
 */
void libera_arvore(Arvore *arvore);

/**
 * Função interna para definir a cor de um nó.
 *
 * Dados esperados: ponteiro para o nó da árvore e cor que será definida.
 * O que faz: altera a cor do nó para B de black ou R de red.
 */
void definir_cor_no(No *no, char cor);

// Funções de inserção
/**
 * Função interna para inserir o primeiro nó como raiz.
 *
 * Dados esperados: ponteiro para a árvore e ponteiro para o nó.
 * O que faz: define o nó como raiz da árvore e ajusta sua cor para preta.
 */
void inserir_raiz(Arvore *arvore, No *no);

/**
 * Função interna para verificar se um valor já existe na árvore.
 *
 * Dados esperados: ponteiro para a árvore e valor buscado.
 * O que faz: chama a busca do nó e retorna se o valor já está presente.
 */
bool verifica_no_existente(Arvore *arvore, int valor);

/**
 * Função interna para inserir um nó seguindo as regras de árvore binária.
 *
 * Dados esperados: ponteiro para a árvore e ponteiro para o nó.
 * O que faz: posiciona o nó na esquerda ou direita de acordo com seu valor.
 */
void inserir_no_comum(Arvore *arvore, No *no);

/**
 * Função interna para corrigir a árvore após a inserção.
 *
 * Dados esperados: ponteiro para a árvore e ponteiro para o novo nó.
 * O que faz: realiza os ajustes de cores e rotações necessários após inserir.
 */
void corrigir_insercao(Arvore *arvore, No *novo);

// Funções auxiliares gerais
/**
 * Função interna para calcular a altura da árvore.
 *
 * Dados esperados: ponteiro para o nó pai.
 * O que faz: percorre os filhos do nó e retorna a altura encontrada.
 */
int arvore_altura(No *pai);

/**
 * Função interna para rotação à direita.
 *
 * Dados esperados: ponteiro para a árvore e ponteiro para o nó da árvore.
 * O que faz: realiza a rotação à direita durante o balanceamento.
 */
void rotacao_direita(Arvore *arvore, No *no);

/**
 * Função interna para rotação à esquerda.
 *
 * Dados esperados: ponteiro para a árvore e ponteiro para o nó da árvore.
 * O que faz: realiza a rotação à esquerda durante o balanceamento.
 */
void rotacao_esquerda(Arvore *arvore, No *no);

/**
 * Validação das cores de cada nó.
 *
 * Dados esperados: ponteiro para a árvore.
 * O que faz: verifica se todos os nós têm uma cor definida.
 */
bool verifica_cor_arvore(Arvore *arvore);

/**
 * Validação da cor da raiz.
 *
 * Dados esperados: ponteiro para a árvore.
 * O que faz: verifica se a raiz é preta.
 */
bool verifica_raiz_preta(Arvore *arvore);

/**
 * Validação da cor dos nós nulos.
 *
 * Dados esperados: ponteiro para a árvore.
 * O que faz: verifica se todos os nós nulos são pretos.
 */
bool verifica_nos_null(Arvore *arvore);

/**
 * Validação de nós vermelhos consecutivos.
 *
 * Dados esperados: ponteiro para a árvore.
 * O que faz: verifica se um nó vermelho não possui filho vermelho.
 */
bool verifica_filho_vermelho_vermelho(Arvore *arvore);

/**
 * Validação dos caminhos até as folhas.
 *
 * Dados esperados: ponteiro para a árvore.
 * O que faz: verifica se todos os caminhos de um nó até suas folhas nulas possuem o mesmo número de nós pretos.
 */
bool verifica_caminho_folhas(Arvore *arvore);

// Funções principais do código todas devem só imprimir o resultado no console se necessário sem retorno

/**
 * Função para inserir um nó na árvore.
 *
 * Dados esperados: ponteiro para a árvore e valor do nó para inserção.
 * O que faz: aloca os dados do novo nó, insere na árvore e chama o balanceamento.
 */
void inserir_no(Arvore *arvore, int valor);

/**
 * Função para remover um nó da árvore.
 *
 * Dados esperados: ponteiro para a árvore e valor do nó para remoção.
 * O que faz: remove os dados do nó, libera a memória e chama o balanceamento.
 */
void remove_no(Arvore *arvore, int valor);

/**
 * Função para buscar um valor na árvore.
 *
 * Dados esperados: ponteiro para a árvore e valor buscado.
 * O que faz: busca o valor na árvore e indica se foi encontrado ou não.
 */
No *busca_no(Arvore *arvore, int valor);

/**
 * Função para imprimir a árvore em ordem da altura.
 *
 * Dados esperados: ponteiro para a árvore.
 * O que faz: imprime a árvore em sequência de níveis.
 */
void imprime_tree_red_black(Arvore *arvore);

/**
 * Função para imprimir a árvore em ordem crescente.
 *
 * Dados esperados: ponteiro para a árvore.
 * O que faz: imprime a árvore em sequência crescente.
 */
void ordem_tree_red_black(Arvore *arvore);

/**
 * Função para exibir percurso em pré-ordem.
 *
 * Dados esperados: ponteiro para a árvore.
 * O que faz: percorre a árvore da raiz em sentido da esquerda para a direita.
 */
void pre_ordem_tree_red_black(Arvore *arvore);

/**
 * Função para validar critérios da árvore Red-Black.
 *
 * Dados esperados: ponteiro para a árvore.
 * O que faz: chama as funções para verificar se as propriedades da árvore estão sendo respeitadas.
 */
bool validar_tree_red_black(Arvore *arvore);

/**
 * Função para finalizar a árvore Red-Black.
 *
 * Dados esperados: ponteiro para a árvore.
 * O que faz: libera os nós da memória, libera a árvore e finaliza o programa.
 */
void finalizar(Arvore *arvore);

/**
 * Função usada na main para integração com o usuário.
 *
 * Dados esperados: string que o usuário colocou no terminal.
 * O que faz: Toda a interação do usuário com o código é aqui chama a função correspondente
 * ao código inserido e passa os parâmetros, se tiver.
 */
int leitor(char *dados);

#endif
