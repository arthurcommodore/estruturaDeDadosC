#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>

void showArray(int *vet, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("%d - ", vet[i]);
    }
    puts("\n");
}

void preencheArray(int *vet, int tam) {
    for(int i = 0; i < tam; i++) {
        vet[i] = (rand() % 100) + 1;
    }
}

void bubbleSort(int *vet, int chave, int tam) {
    int tmp;
    bool change = false;
    do {
        for(int i = 0; i < tam; i++) {
            if(vet[i] > vet[i + 1]) {
                tmp = vet[i - 1];
                vet[i - 1] = vet[i]; 
                vet[i] = tmp;
                change = true;
            }
        }
    }while(change != false);
}

int buscaBinaria(int *vet, int chave, int tam) {
    int inicio = 0;
    int fim = tam - 1;

    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if(chave == vet[meio])
            return vet[meio]; 
        else if(chave < vet[meio])
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return -1;
}

int main() {
    
    srand(time(0));

    int vet[6];
    int chave;
    int option;


    do {
        puts("1- Mostrar o array, 2- Procurar um array, 0- Sair");
        scanf("%d", &option);
        switch(option) {
            case 1:
                showArray(vet, 6);                
                break;
            case 2: 
                puts("Escolha um valor\n");
                scanf("%d", &chave);
                buscaBinaria(vet,chave, 6); 
                break;
            case 0:
                break;
        }
    }while(option != 0);
}


