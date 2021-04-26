#include<stdio.h>

int buscaLinear(int *vetor, int chave, int tam) {
    for(int i = 0; i < tam; i++) {
        if(vetor[i] == chave)
            return vetor[i];
    }
    return -1;

}

int main() {
    int vetor[6] = {1,3,5,12,42};
    int chave = 5;

    int ret = buscaLinear(vetor, chave, 6);
    printf("%d", ret);
    
    return 0;
}
