#include<stdio.h>
#include<stdlib.h>

typedef struct _lista {
    int data;
    struct _lista *prox;

}Lista;

int vazia(Lista*);
void clear(Lista*);
void listAll(Lista*);
void insertInicio(Lista*);
void insertFim(Lista*);
void choice(Lista*, int);
int menu();

int main() {
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->prox = NULL;

    if(!lista) {
        puts("Sem memória disponível");
        exit(1);
    }

    int option;
    do {

        option = menu();
        choice(lista, option);

    }while(option);
}

int vazia(Lista *p) {
    if(p->prox == NULL) 
        return 1;
    
    else 
        return 0;  
}

void clear(Lista *p) {
    if(!vazia(p)) {
        Lista *prox,*atual; 
        atual = p->prox;
        
        while(atual != NULL) {
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
    }
}

void listAll(Lista *p) {
    if(vazia(p)) {
        puts("A lista está vazia!\n\n");
        return;
    }
    Lista *tmp;
    tmp = p->prox;

    while(tmp != NULL) {
       printf("|%d| --> ", tmp->data); 
       tmp = tmp->prox;
    }
    puts("NULL\n");
}

void insertInicio(Lista *p) {
    Lista *new = (Lista*) malloc(sizeof(Lista));
    if(!new) {
        puts("Sem memória disponível");
        exit(1);
    }
    puts("Informe o valor");
    scanf("%d", &new->data);

    Lista *oldList = p->prox;
    p->prox = new;
    new->prox = oldList;
}

void insertFim(Lista *p) {
    Lista *new = (Lista*) malloc(sizeof(Lista)); 
    new->prox = NULL;
    if(!new) {
        puts("Sem memória disponível");
        exit(1);
    }
    puts("Informe o valor");
    scanf("%d", &new->data);

    if(vazia(p)) {
       p->prox = new; 
    }else{

        Lista *tmp = p->prox;
        while(tmp->prox != NULL) {
            tmp = tmp->prox;
        }
        tmp->prox = new;
    } 
}

void choice(Lista *p, int option) {
    switch(option) {
        case 0:
            clear(p);
            break;
        case 1:
            listAll(p);
            break;
        case 2:
            insertInicio(p);
            break;
        case 3:
            insertFim(p);
            break;
        case 4:
            clear(p);
            break;
        default:
            puts("Comando Inválido\n");
    }
}

int menu() {
    int option;

    puts("%Escolha a opção: \n");
    puts("[0] - Sair\n");
    puts("[1] - Exibir \n");
    puts("[2] - Adicionar no inicío\n");
    puts("[3] - Adicionar no final\n");
    puts("[4] - Zerar a lista \n");
    scanf("%d", &option);
        
    return option;
}
