Tree-Red-Black em C

Implementação acadêmica de uma Árvore Red-Black (Red-Black Tree) em linguagem C, desenvolvida como trabalho em grupo para estudo de estruturas de dados balanceadas.

Objetivo

Este projeto tem como finalidade compreender, na prática, o funcionamento de árvores binárias de busca balanceadas, com foco em:

Inserção de elementos
Busca de valores
Remoção de nós
Balanceamento automático por:
Rotações
Recolorimento
Correções estruturais

A implementação foi realizada sem bibliotecas prontas de estruturas de dados, visando aprofundar o entendimento dos mecanismos internos desse tipo de árvore.

Características da implementação
Armazena valores inteiros
Não permite valores duplicados
Ignora inserções repetidas com mensagem informativa
Permite operações via entrada padrão ou arquivo texto
Valida automaticamente as propriedades Red-Black
Exibe a árvore e seus percursos
Propriedades Red-Black respeitadas

A árvore implementada segue rigorosamente as seguintes regras:

Cada nó é vermelho ou preto
A raiz é sempre preta
Todo nó nulo é considerado preto
Um nó vermelho não pode ter filho vermelho
Todos os caminhos de um nó até folhas nulas possuem o mesmo número de nós pretos
Comandos suportados
Comando	Função
I x	Insere o valor x
R x	Remove o valor x
B x	Busca o valor x
P	Imprime a árvore
E	Exibe percurso em ordem
O	Exibe percurso em pré-ordem
V	Valida propriedades Red-Black
F	Finaliza o programa
Exemplo de entrada
I 10
I 20
I 30
P
E
B 20
R 20
P
V
F
Exemplo de saída
Inserido: 10
Inserido: 20
Inserido: 30

Arvore:
20(B)
  10(R)
  30(R)

Em ordem: 10(R) 20(B) 30(R)

Busca 20: encontrado

Removido: 20

Arvore:
30(B)
  10(R)

Valida: sim
Representação das cores
Símbolo	Cor
R	Vermelho
B	Preto
Estrutura esperada

O projeto contempla:

Estrutura de nó personalizada
Inserção balanceada
Remoção balanceada
Busca binária
Impressão hierárquica
Percursos:
Em ordem
Pré-ordem
Validação completa da árvore
Aprendizados envolvidos

Este trabalho reforça conhecimentos sobre:

Árvores binárias de busca
Balanceamento automático
Complexidade de operações O(log n)
Ponteiros e alocação dinâmica em C
Algoritmos de correção estrutural
Estruturas de dados avançadas
