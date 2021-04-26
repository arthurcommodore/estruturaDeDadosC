#include<stdio.h>

void shellSort(int *vetor, int tam){
    int grupo = 1;

    while(grupo < tam) {
        //Gerar o tamanho do grupo de acordo com o tamanho do vetor
        grupo = 3 * grupo + 1; 
    }

    while(grupo > 1) {
        grupo /= 3;

        for(int i = grupo; i < tam; i++) {
            int troca = vetor[i];
            int j = i - grupo;

            while(j >= 0 && troca < vetor[j]) {
                vetor[j + grupo] = vetor[j];
                j -= grupo;
            }
            vetor[j + grupo] = troca;
        }
    }
}

int main() {
    int vetor[6] = {8,3,1,42,12,5}; 
    shellSort(vetor, 6);

    for(int i = 0; i < 6; i++) {
        printf("%d\n", vetor[i]);

    }

}
