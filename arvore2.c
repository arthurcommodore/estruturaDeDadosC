#include<stdio.h>
#include<stdlib.h>

typedef struct _no {
    int data;
    struct _no *ne, *nd;  

}No;

typedef struct {
    No *raiz;
}ArvB;


void insertEsquerda(No*, int);
void insertDireita(No*, int);

void insertDireita(No *no, int valor) {
    if(no->nd == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->data = valor;
        novo->ne = NULL;
        novo->nd = NULL;
        no->nd = novo;
    }else {
        if(valor > no->nd->data) {
            insertDireita(no->nd, valor);
        }else 
            insertEsquerda(no->nd, valor);
    }
}

void insertEsquerda(No *no, int valor) {
    if(no->ne == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->data = valor;
        novo->ne = NULL;
        novo->nd = NULL;
        no->ne = novo;
    }else {
        if(valor < no->ne->data)
            insertEsquerda(no->ne, valor);
        else 
            insertDireita(no->nd, valor);
    }

}


void insert(ArvB *arv, int valor) {
   if(arv->raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->data = valor;
        novo->ne = NULL;
        novo->nd = NULL;
        arv->raiz = novo;
   }else {
        if(valor < arv->raiz->data)        
            insertEsquerda(arv->raiz, valor);
        else 
            insertDireita(arv->raiz, valor);
   } 
}

void imprimir(No *raiz) {
    if(raiz != NULL) {
        printf("%d\n", raiz->data);
        imprimir(raiz->ne);
        imprimir(raiz->nd);
    }
}

int main() {
    int option, valor;
    ArvB arv;
    arv.raiz = NULL;

    do {
        puts("\n0- sair\n1- inserir\n2- imprimir\n");
        scanf("%d", &option);

        switch(option) {
            case 0:
                puts("\nSainda..\n");
                break;

            case 1:
                puts("Digite um numero");
                scanf("%d", &valor);
                insert(&arv, valor);
                break;

            case 2:
                puts("Impressao da arvore binaria");
                imprimir(arv.raiz);
        }
    }while(option != 0);
}


