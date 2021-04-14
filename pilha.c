#include<stdio.h>
#include<stdbool.h>

#define TAM 10

int pilha[TAM] = {0,0,0,0,0,0,0,0,0,0};
int top = 0;

void lista_elementos() {
    puts("\n=========Pilha Atual=========\n");
    for(int i = 0; i < TAM; i++) {
        puts("-");
        printf("|%d|", pilha[i]);
        puts("-");
    }
    printf("Top: %d", top);
    puts("\n\n");
}

void push() {
    int val;
    puts("Informe o valor");
    scanf("%d", &val);

    if(top < TAM) {
        pilha[top] = val; 
        top += 1;
        lista_elementos();

    }else
        puts("Pilha cheia...\n");
}

void pop() {
    if(top >= 0) {
        pilha[top - 1] = 0;
        top -= 1;
        lista_elementos();
    }else 
        puts("Pilha cheia..\n");
}

void clear () {
    for(int i = 0; i < TAM; i++) {
        pilha[i] = 0;
    }
    top = 0;
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
                push();
                break;

            case 2: 
                pop();
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


