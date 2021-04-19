#include<stdio.h>
#include<stdlib.h>

typedef struct _arvore {
    int data;
    struct _arvore *ad;
    struct _arvore *ae;
}Arvore;

int vazia(Arvore *p) {
    return p == NULL;
}

void showArvore(Arvore* t) {
    puts("<");
    if(!vazia(t)) {
        printf("%d", t->data);
        showArvore(t->ae);
        showArvore(t->ad);
    }
    puts(">");
}

void insertArvore(Arvore** t, int num) {
    if(*t == NULL) {
        *t = (Arvore*) malloc(sizeof(Arvore));
        (*t)->ae = NULL;
        (*t)->ad = NULL;
        (*t)->data = num;
    }else {
        if(num < (*t)->data) {
            insertArvore(&(*t)->ae, num);
        }
        if(num > (*t)->data) {
            insertArvore(&(*t)->ad, num);
        }
    } 
}

int isArvore(Arvore* t, int num) {
    if(vazia(t)) {
        return 0;
    }

    return t->data == num || isArvore(t->ae, num)  || isArvore(t->ad, num);
}

int main() {

}
