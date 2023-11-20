#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // declarar e inicializar como árvore vazia
    int opcao, valor;
    arvore a = NULL;

    while (1)
    {
        scanf("%d", &opcao);
        switch (opcao)
        {

        case 1:
            scanf("%d", &valor);
            a = inserir(a, valor);
            break;
        case 2:
            preorder(a);
            break;
        case 3:
            inorder(a);
            break;
        case 4:
            posorder(a);
            break;
        case 5:
            reverso(a);
            break;
        case 6:
            qtdPar(a);
            break;
        case 7:
            scanf("%d", &valor);
            printf("antecessor do nó com valor %d:\n", valor);
            ascendentes(a, valor);
            break;
        case 8:
            scanf("%d", &valor);
            printf("Pai do nó com valor %d:\n", valor);
            imprimir_pai(a, valor);
            break;
        case 9:
            scanf("%d", &valor);
            remover(a, valor);
            break;
        case 10:
            soma_par(a);
            break;

        case 11:
            scanf("%d", &valor);
            podar(a, valor);
            break;

        case 12:
            dobrar_valores(a);
            break;
        case 13:
            scanf("%d", &valor);
            busca(a, valor);
            break;

        case 14:
            scanf("%d", &valor);
            descendentes(a, valor);
            break;
        case 15:
            altura(a);
            break;

        case 99:
            exit(0);
        }
    }
    }
