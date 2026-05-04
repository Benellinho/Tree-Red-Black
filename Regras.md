Regras da Árvore Red-Black

Propriedades obrigatórias

A árvore deve obedecer sempre às seguintes regras:

Todo nó é vermelho (R) ou preto (B)
A raiz é sempre preta
Todo nó nulo (folha NIL) é considerado preto
Um nó vermelho não pode ter filho vermelho
Todo caminho de um nó até suas folhas nulas deve ter a mesma quantidade de nós pretos

Regra inicial
Todo novo nó deve ser inserido como vermelho
Motivo
Inserir como vermelho não altera a quantidade de nós pretos nos caminhos
Isso evita quebrar a propriedade de balanceamento global
Correção após inserção

Após inserir um nó, podem ocorrer violações.

Caso 2: Pai vermelho + tio vermelho
Caso 3: Pai vermelho + tio preto (ou nulo)
Regra final

Após qualquer inserção:

Garantir que a raiz seja preta
Todos os caminhos da raiz até folhas nulas possuem o mesmo número de nós pretos