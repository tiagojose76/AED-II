#ifndef BST_H
#define BST_H

typedef struct no {
    int valor;
    struct no *esq;
    struct no *dir;
} no;

typedef no* arvore;

arvore inserir (arvore raiz, int valor) ;

void preorder(arvore raiz);
void inorder(arvore raiz);
void posorder(arvore raiz);
int somatorio(arvore raiz);
int altura(arvore raiz);
int qtdPar(arvore raiz);
int soma_par(arvore raiz) ;
arvore busca(arvore raiz, int valor);
arvore podar(arvore raiz, int valor );
arvore remover(arvore raiz, int valor);
void dobrar_valores(arvore raiz);
void mesclar (arvore raiz1, arvore raiz2);
void descendentes(arvore raiz, int valor);
void ascendentes(arvore raiz, int valor);
void imprimir_antecessor(arvore raiz, int valor);
void reverso(arvore raiz);
void imprimir_pai(arvore raiz, int troca);
void dobrar_valor(arvore raiz);

#endif
