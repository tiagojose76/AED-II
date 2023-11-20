#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

arvore inserir(arvore raiz, int valor)
{
    // caso base
    if (raiz == NULL)
    {
        // 1. Alocar espaço em memória
        arvore nova = (arvore)malloc(sizeof(struct no));
        // 2. Inicializar o novo nó
        nova->valor = valor;
        nova->esq = NULL;
        nova->dir = NULL;
        // 3. Retornar o ponteiro para a raiz (relativa) da nova árvore
        return nova;
    }
    // caso indutivo
    else
    {
        if (valor > raiz->valor)
        {
            raiz->dir = inserir(raiz->dir, valor);
        }
        else
        {
            raiz->esq = inserir(raiz->esq, valor);
        }
        return raiz;
    }
}

void preorder(arvore raiz)
{
    // caso indutivo...
    if (raiz != NULL)
    {
        // pre-order: processa raiz, depois esq e direita
        printf("[%d]", raiz->valor);

        //... chamadas recursivas
        preorder(raiz->esq);
        preorder(raiz->dir);
    }

    // caso base, fim da recursão
    else
    {
        // imprimir uma árvore vazia é não fazer nada
    }
}

void inorder(arvore raiz)
{
    if (raiz != NULL)
    {
        inorder(raiz->esq);
        printf("[%d]", raiz->valor);
        inorder(raiz->dir);
    }
}
void posorder(arvore raiz)
{
    if (raiz != NULL)
    {
        posorder(raiz->esq);
        posorder(raiz->dir);
        printf("[%d]", raiz->valor);
    }
}

/*int somatorio(arvore raiz){
    int soma = 0;

    if(raiz != NULL) {
        soma += raiz->valor +
            somatorio(raiz->esq) +
            somatorio(raiz->dir);
    }
    return soma;
}*/

int somatorio(arvore raiz)
{
    return (raiz == NULL) ? 0 : raiz->valor + somatorio(raiz->esq) + somatorio(raiz->dir);
}

void dobrar_valores(arvore raiz)
{
    // Verifica se o nó atual não é nulo
    if (raiz != NULL)
    {
        // Recursivamente duplica os valores na subárvore esquerda
        dobrar_valores(raiz->esq);

        // Duplica o valor do nó atual
        raiz->valor *= 2;
        printf("[%d]", raiz->valor);

        // Recursivamente duplica os valores na subárvore direita
        dobrar_valores(raiz->dir);
    }
}

arvore busca(arvore raiz, int valor)
{
    if (raiz == NULL || raiz->valor == valor)
    {
        if (raiz != NULL)
        {
            printf("Valor encontrado: %d\n", raiz->valor);
        }
        return raiz;
    }

    if (valor > raiz->valor)
    {
        return busca(raiz->dir, valor);
    }
    else
    {
        return busca(raiz->esq, valor);
    }
}
void descendentes(arvore raiz, int valor)
{
    if (raiz == NULL)
    {
        return;
    }

    if (raiz->valor == valor)
    {
        if (raiz->esq != NULL)
        {
            printf("Descendente à esquerda: %d\n", raiz->esq->valor);
        }
        if (raiz->dir != NULL)
        {
            printf("Descendente à direita: %d\n", raiz->dir->valor);
        }
    }

    // Continuar a busca pelos descendentes do nó com o valor desejado
    if (valor > raiz->valor)
    {
        descendentes(raiz->dir, valor);
    }
    else
    {
        descendentes(raiz->esq, valor);
    }
}
void imprimir_antecessor(arvore raiz, int valor)
{
    arvore atual = raiz;
    int antecessor = -1; // Inicia com -1 para indicar que não existe antecessor

    while (atual != NULL)
    {
        if (valor > atual->valor)
        {
            antecessor = atual->valor; // Atualiza o antecessor
            atual = atual->dir;        // Move para a direita, já que o valor é maior
        }
        else if (valor < atual->valor)
        {
            atual = atual->esq; // Move para a esquerda, não atualiza o antecessor
        }
        else
        {
            break; // Valor encontrado
        }
    }

    if (atual == NULL)
    {
        // O valor não foi encontrado na árvore
        printf("-1\n");
    }
    else
    {
        // Imprime o valor do antecessor
        printf("%d\n", antecessor);
    }
}

arvore podar(arvore raiz, int valor)
{
    if (!raiz)
    {
        return NULL;
    }

    if (valor < raiz->valor)
    {
        raiz->esq = podar(raiz->esq, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->dir = podar(raiz->dir, valor);
    }
    else
    {
        if (!raiz->esq || !raiz->dir)
        {
            arvore temp = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return temp;
        }

        arvore temp = raiz->dir;
        while (temp->esq)
        {
            temp = temp->esq;
        }

        raiz->valor = temp->valor;
        raiz->dir = podar(raiz->dir, temp->valor);
    }
    return raiz;
}




void reverso(arvore raiz)
{
    if (raiz != NULL)
    {
        reverso(raiz->dir);
        printf("[%d]", raiz->valor);
        reverso(raiz->esq);
    }
}
int qtdPar(arvore raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    int contagem = qtdPar(raiz->esq);
    if (raiz->valor % 2 == 0)
    {
        printf("%d\n", raiz->valor); // Imprime o valor do nó se ele for par
        contagem++;
    }
    contagem += qtdPar(raiz->dir);
    return contagem;
}

void imprimir_pai(arvore raiz, int troca)
{
    arvore atual = raiz;
    arvore pai = NULL;

    // Busca pelo nó que contém o valor n e mantém o registro do pai
    while (atual != NULL && atual->valor != troca)
    {
        pai = atual; // atualiza o pai antes de seguir para o próximo nó
        if (troca < atual->valor)
        {
            atual = atual->esq;
        }
        else
        {
            atual = atual->dir;
        }
    }

    // Se o valor foi encontrado e ele tem um pai, imprime o valor do pai
    if (atual != NULL && pai != NULL)
    {
        printf("%d\n", pai->valor);
    }
    else
    {
        // Se o valor não foi encontrado ou não tem pai, imprime -1
        printf("-1\n");
    }
}


int soma_par(arvore raiz)
{
    if (raiz == NULL)
    {
        return 0;
    }
    int soma = 0;
    if (raiz->valor % 2 == 0)
    {
        printf("Nó par encontrado: %d\n", raiz->valor); // Imprime o valor do nó par
        soma += raiz->valor;
    }
    soma += soma_par(raiz->esq);
    soma += soma_par(raiz->dir);
    return soma;
}
void dobrar_valor(arvore raiz)
{
    if (raiz != NULL)
    {
        // Dobrar o valor do nó atual
        raiz->valor *= 2;
        printf("Valor dobrado: %d\n", raiz->valor); // Imprime o valor dobrado

        // Recursivamente dobrar o valor dos nós da subárvore esquerda
        dobrar_valor(raiz->esq);
        // Recursivamente dobrar o valor dos nós da subárvore direita
        dobrar_valor(raiz->dir);
    }
}


/*
void ascendentes(arvore raiz, int valor) {
    if (raiz == NULL) {
        printf("Nó com valor %d não encontrado na árvore.\n", valor);
        return;
    }

    if (raiz->valor == valor) {
        printf("Ascendentes do nó com valor %d:\n", valor);
        return;
    }

    if ((raiz->esq != NULL && raiz->esq->valor == valor) || (raiz->dir != NULL && raiz->dir->valor == valor)) {
        printf("%d\n", raiz->valor);
        return;
    }

    if (valor < raiz->valor) {
        printf("%d\n", raiz->valor);
        ascendentes(raiz->esq, valor);
    } else {
        printf("%d\n", raiz->valor);
        ascendentes(raiz->dir, valor);
    }
}
*/

/*arvore remover(arvore raiz, int valor)
{
    if (raiz == NULL)
    {
        return NULL;
    }

    // Encontrar o nó a ser removido
    if (valor < raiz->valor)
    {
        raiz->esq = remover(valor, raiz->esq);
    }
    else if (valor > raiz->valor)
    {
        raiz->dir = remover(valor, raiz->dir);
    }
    else
    {
        // Caso com nenhum ou um filho
        if (raiz->esq == NULL)
        {
            arvore temp = raiz->dir;
            free(raiz);
            return temp;
        }
        else if (raiz->dir == NULL)
        {
            arvore temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // Caso com dois filhos: Obter o sucessor in-order (menor na subárvore direita)
        arvore temp = raiz->dir;
        while (temp->esq != NULL)
        {
            temp = temp->esq;
        }

        // Copiar o valor do sucessor in-order para este nó
        raiz->valor = temp->valor;
        // Remover o sucessor in-order
        raiz->dir = remover(temp->valor, raiz->dir);
    }
    return raiz;
}*/

/*int altura(arvore raiz)
{
    if (!raiz)
    {
        return -1;
    }
    return 1 + (altura_bst(raiz->esq) > altura_bst(raiz->dir) ? altura_bst(raiz->esq) : altura_bst(raiz->dir));
}*/