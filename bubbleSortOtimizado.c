#include<stdio.h>
#include<stdbool.h>

void bubbleSort(int *vet, int tam){
    int tmp;
    bool change = false;
    do {
        for(int i = 0; i < (tam - 1); i++) {
            if(vet[i] < vet[i - 1]) {
                tmp = vet[i - 1];    
                vet[i - 1] = vet[i];
                vet[i] = tmp;
                change = true;
            }
        }

    }while(change != false);
}
int main() {
    int vetor[6] = {8,3,1,42,12,5}; 
    bubbleSort(vetor, 6);

    for(int i = 0; i < 6; i++) {
        printf("%d\n", vetor[i]);

    }

}
