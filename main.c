#include "Tree-Red-Black.h"

int main(void)
{
    Arvore *arvore = aloca_arvore();
    char dados[256];

    if (arvore == NULL)
        return 1;

    printf("Programa funcionando.\n");

    while (fgets(dados, sizeof(dados), stdin) != NULL)
    {
        leitor(arvore, dados);
    }

    return 0;
}
