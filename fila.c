#include<stdio.h>

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

int main() {
    lista_elementos();



}
