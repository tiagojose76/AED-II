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
int soma_par(arvore raiz);
int calcularAltura(arvore raiz);
arvore busca(arvore raiz, int valor);
arvore podar(arvore raiz, int valor );
arvore remover(arvore raiz, int valor);
arvore menorNo(arvore raiz);
void liberarSubarvore(arvore raiz);
void dobrar_valores(arvore raiz);
void descendentes(arvore raiz, int valor);
void imprimir_antecessor(arvore raiz, int valor);
void reverso(arvore raiz);
void imprimir_pai(arvore raiz, int troca);
void dobrar_valor(arvore raiz);

#endif