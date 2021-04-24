#include<stdio.h>
#include<stdlib.h>

typedef struct _no {
    int data;
    struct _no *ne, *nd;  

}No;

typedef struct {
    No *raiz;
}ArvB;


No* insert(No *raiz, int valor) {
   if(raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->data = valor;
        novo->ne = NULL;
        novo->nd = NULL;
        return novo; 
   }else {
        if(valor < raiz->data)        
           raiz->ne = insert(raiz->ne, valor); 

        if(valor > raiz->data)        
           raiz->nd = insert(raiz->nd, valor); 

    return raiz;
   } 
}

void imprimir(No *raiz) {
    if(raiz != NULL) {
        imprimir(raiz->ne);
        printf("%d\n", raiz->data);
        imprimir(raiz->nd);
    }
}

int size(No* raiz) {
    if(raiz == NULL)
        return 0;
    else 
        return 1 + size(raiz->ne) + size(raiz->nd);
}

int search(No* raiz, int chave) {
    if(raiz == NULL)
        return -1;
    else if(raiz->data == chave)
        return raiz->data;
    else if(chave < raiz->data)
        return search(raiz->ne, chave);
    else
        return search(raiz->nd, chave);

}

No* removeArvore(No *raiz, int chave) {
    if(raiz == NULL) {
        puts("Raiz nao encontrada");
        return NULL;
    }else if(raiz->data == chave) {
        if(raiz->ne == NULL && raiz->nd == NULL) {
            free(raiz);
            return NULL;
        }else if(raiz->ne != NULL || raiz->nd != NULL) {
            No* aux;
            if(raiz->ne != NULL) 
                aux = raiz->ne;
            else
                aux = raiz->nd;
            
            free(raiz);
            return aux;
        }

    }else if(chave < raiz->data) {
        raiz->ne = removeArvore(raiz->ne, chave);

    }else if(chave > raiz->data) {
        raiz->nd = removeArvore(raiz->nd, chave);

    }
    return raiz;
}

int main() {
    int option, valor;
    ArvB arv;
    arv.raiz = NULL;

    do {
        puts("\n0- sair\n1- inserir\n2- imprimir\n3- buscar\n");
        scanf("%d", &option);

        switch(option) {
            case 0:
                puts("\nSainda..\n");
                break;

            case 1:
                puts("Digite um numero");
                scanf("%d", &valor);
                arv.raiz = insert(arv.raiz, valor);
                break;

            case 2:
                puts("Impressao da arvore binaria");
                imprimir(arv.raiz);
                printf("Tamanho: %d\n", size(arv.raiz));
                break;
            
            case 3:
                puts("Digite o número que deseja buscar");
                scanf("%d", &valor);
                printf("Resultado da busca %d\n", search(arv.raiz, valor));
                break;
            
            case 4:
                puts("Digite um numero");
                scanf("%d", &valor);
                arv.raiz = removeArvore(arv.raiz, valor);
                break;

        }
    }while(option != 0);
}


