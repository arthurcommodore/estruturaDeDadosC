#include<stdio.h>
#include<stdbool.h>

#define TAM 10

int fila[TAM] = {0,0,0,0,0,0,0,0,0,0}; 
int head = 0;
int tail = 0;

void lista_elementos() {
    puts("\n========= FILA ATUAL ============\n");
    for(int i = 0; i < TAM; i++) {
        printf("-");
        printf("|%d", fila[i]);
        printf("-");
    }

    printf("\nHead: %d\n", head);
    printf("\nTail: %d\n", tail);
    puts("\n\n");
}

void enqueue() {
    int val;
    if(tail < TAM) {
        printf("Informe o elemento para adicionar na fila: ");
        scanf("%d", &val);

        fila[tail] = val;
        tail += 1;
    }else
        printf("A fila está cheia...\n");

}

void sort() {
    bool naoVazio = false;
    for(int i = 0; i < TAM; i++) {
        if(fila[i] > 0)
            naoVazio = true;
    }

    if(naoVazio) {
        while(fila[0] == 0) {
            for(int i = 0; i < TAM; i++) {
                if(fila[i] == 0 && fila[i + 1] != 0 && (i + 1) < TAM) {
                    fila[i] = fila[i + 1];
                    fila[i + 1] = 0; 
                }
            }
        }
    }

    for(int i = 0; i < TAM; i++) {
        if(fila[i] == 0) {
            head = i - 1;
            tail = i;
            break;
        }

    }
}

void dequeue() {
    if(head < tail) {
        fila[head] = 0;
        head += 1; 
        sort();
    }else
        puts("A fila está vazia");

}


void clear() {
    head = 0;
    tail = 0;
    for(int i = 0; i < TAM; i++) {
        fila[i] = 0;
    }
}

int main() {
    int option = 0;

    do {
        puts("Selecione a opção: \n\n");
        puts("[1] - Inserir (enqueue): \n");
        puts("[2] - Remover (dequeue): \n");
        puts("[3] - Listar \n");
        puts("[4] - Limpra a fila: \n");
        puts("[-1] - Sair \n");
        scanf("%d", &option);


        switch(option) {
            case 1:
                enqueue();
                break;

            case 2: 
                dequeue();
                break;

            case 3:
                lista_elementos();
                break;

            case 4:
                clear();
                break;

            case -1:
                break;

            default:
                puts("opção invalida");

        }

    }while(option != -1);

}
