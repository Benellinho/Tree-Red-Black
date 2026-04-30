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
} TreeRedBlack;

/**
 * Função interna para trocar a cor de um nó.
 *
 * Dados esperados: nó da árvore.
 * O que faz: altera a cor do nó.
 */
void troca_cor_no(No no);

/**
 * Função interna para rotação à direita.
 *
 * Dados esperados: nó da árvore.
 * O que faz: realiza a rotação à direita durante o balanceamento.
 */
void rotação_direita(No no);

/**
 * Função interna para rotação à esquerda.
 *
 * Dados esperados: nó da árvore.
 * O que faz: realiza a rotação à esquerda durante o balanceamento.
 */
void rotação_esquerda(No no);

/**
 * Validação das cores de cada nó.
 *
 * Dados esperados: árvore.
 * O que faz: verifica se todos os nós têm uma cor definida.
 */
bool verifica_cor(TreeRedBlack arvore);

/**
 * Validação da cor da raiz.
 *
 * Dados esperados: árvore.
 * O que faz: verifica se a raiz é preta.
 */
bool verifica_raiz(TreeRedBlack arvore);

/**
 * Validação da cor dos nós nulos.
 *
 * Dados esperados: árvore.
 * O que faz: verifica se todos os nós nulos são pretos.
 */
bool verifica_nos_null(TreeRedBlack arvore);

/**
 * Validação de nós vermelhos consecutivos.
 *
 * Dados esperados: árvore.
 * O que faz: verifica se um nó vermelho não possui filho vermelho.
 */
bool verifica_filho_vermelho_vermelho(TreeRedBlack arvore);

/**
 * Validação dos caminhos até as folhas.
 *
 * Dados esperados: árvore.
 * O que faz: verifica se todos os caminhos de um nó até suas folhas nulas possuem o mesmo número de nós pretos.
 */
bool verifica_caminho_folhas(TreeRedBlack arvore);

/**
 * Função usada na main para integração com o usuário.
 *
 * Dados esperados: string que o usuário colocou no terminal.
 * O que faz: chama a função correspondente ao código inserido e passa os parâmetros, se tiver.
 */
int leitor(char *dados);

/**
 * Função para inserir um nó na árvore.
 *
 * Dados esperados: árvore e valor do nó para inserção.
 * O que faz: aloca os dados do novo nó, insere na árvore e chama o balanceamento.
 */
int insere_no(TreeRedBlack arvore, int valor);

/**
 * Função para remover um nó da árvore.
 *
 * Dados esperados: árvore e valor do nó para remoção.
 * O que faz: remove os dados do nó, libera a memória e chama o balanceamento.
 */
int remove_no(TreeRedBlack arvore, int valor);

/**
 * Função para buscar um valor na árvore.
 *
 * Dados esperados: árvore e valor buscado.
 * O que faz: busca o valor na árvore e indica se foi encontrado ou não.
 */
int busca_no(TreeRedBlack arvore, int valor);

/**
 * Função para imprimir a árvore em ordem da altura.
 *
 * Dados esperados: árvore.
 * O que faz: imprime a árvore em sequência de níveis.
 */
int imprime_tree_red_black(TreeRedBlack arvore);

/**
 * Função para imprimir a árvore em ordem crescente.
 *
 * Dados esperados: árvore.
 * O que faz: imprime a árvore em sequência crescente.
 */
int ordem_tree_red_black(TreeRedBlack arvore);

/**
 * Função para exibir percurso em pré-ordem.
 *
 * Dados esperados: árvore.
 * O que faz: percorre a árvore da raiz em sentido da esquerda para a direita.
 */
int pre_ordem_tree_red_black(TreeRedBlack arvore);

/**
 * Função para validar critérios da árvore Red-Black.
 *
 * Dados esperados: árvore.
 * O que faz: chama as funções para verificar se as propriedades da árvore estão sendo respeitadas.
 */
bool validar_tree_red_black(TreeRedBlack arvore);

/**
 * Função para finalizar a árvore Red-Black.
 *
 * Dados esperados: árvore.
 * O que faz: libera os nós da memória, libera a árvore e finaliza o programa.
 */
void Finalizar(TreeRedBlack arvore);

#endif
