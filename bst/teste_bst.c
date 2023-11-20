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
        
        
        printf("Escolha uma opção:\n");
        printf("1-Inserir\n");
        printf("2-preorder\n");
        printf("3-inorder\n");
        printf("4-posorder\n");
        printf("5-reverso\n");
        printf("6-qtdPar\n");
        printf("7-antecessor\n");
        printf("8-pai\n");
        printf("9-remover\n");
        printf("10-somaPar\n");
        printf("11-podar\n");
        printf("12-dobro\n");
        printf("13-busca\n");
        printf("14-descendentes\n");
        printf("15-altura\n");
        printf("99-sair\n");
        

        
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
            imprimir_antecessor(a, valor);
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
            calcularAltura(a);
            break;
        case 99:
            exit(0);
        }
    }
    }
