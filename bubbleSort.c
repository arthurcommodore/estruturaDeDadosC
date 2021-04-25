#include<stdio.h>

void bubbleSort(int *vetor, int tam){
    int proximo = 0;
    for(int i = 0; i < tam; i++) {
        for(int j = 0; j < (tam - 1); j++) {
            if(vetor[j] > vetor[j+1]) {
                proximo = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = proximo;
            }
        }
    }
}

int main() {
    int vetor[6] = {8,3,1,42,12,5}; 
    bubbleSort(vetor, 6);

    for(int i = 0; i < 6; i++) {
        printf("%d\n", vetor[i]);

    }

}
