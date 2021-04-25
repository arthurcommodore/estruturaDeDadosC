#include<stdio.h>


void selectSort(int *vetor, int tam){
    int menor, troca;

    //Loop externo para repassar todo o vetor
    for(int i = 0; i < (tam - 1); i++) {
        menor = i;
        for(int j = (i + 1); j < tam; j++) {
            if(vetor[j] < vetor[menor])
                menor = j;
        }

        if(i != menor){
            troca = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = troca; 
        }
    }
}

int main() {
    int vetor[6] = {8,3,1,42,12,5}; 
    selectSort(vetor, 6);

    for(int i = 0; i < 6; i++) {
        printf("%d\n", vetor[i]);

    }

}
