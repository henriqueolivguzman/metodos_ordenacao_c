#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>
void menu_principal();

void selection_sort(int * vet, int posicoes);

void gera_vetor(int * vet , int n);

void quick_sort(int *vet, int left, int right);

int posicoes_vetor();

void imprime_vetor(int * vet , int posicoes);

int main(void) {

    int opcao_menu = 10;
    clock_t t;
    int posicoes;

    while(opcao_menu!=0) {
        menu_principal();
        scanf("%d", &opcao_menu);

        if (opcao_menu == 1) {
            posicoes = posicoes_vetor();
            int vet[posicoes];

            t = clock();
            gera_vetor(vet, posicoes);

            selection_sort(vet, posicoes);
            t = clock() - t;

            imprime_vetor(vet, posicoes);
            printf("\n\nTEMPO DE EXECUCAO: %lf\n\n", ((double) t) / ((CLOCKS_PER_SEC / 1000)));


        }

        else if (opcao_menu == 2) {
            posicoes = posicoes_vetor();
            int vet[posicoes];

            t = clock();
            gera_vetor(vet, posicoes);

            quick_sort(vet, 0, posicoes);
            t = clock() - t;
            imprime_vetor(vet, posicoes);
            printf("\n\nTEMPO DE EXECUCAO: %lf\n\n", ((double) t) / ((CLOCKS_PER_SEC / 1000)));
        }

        else if (opcao_menu !=0) {
            printf("OPCAO INVALIDA ! \n\n");
        }
    }

    printf("OBRIGADO PRO UTILIZAR !");

    return 0;
}


void gera_vetor(int * vet , int posicoes){
    for(int i=0; i<posicoes; i++) {
        vet[i] = rand() % 1000;
    }
    printf("VETOR GERADO : ");
    for(int i=0; i<posicoes; i++) {
        printf("[%d] " , vet[i]);
    }
    printf("\n");

}

void selection_sort (int * vet, int n){
    for(int i = 0; i < n - 1; i++) {
        int menor = i;
        for(int j = i + 1; j < n; j++) {
            if (vet[j] < vet[menor]) menor = j;
        }
        int aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }

}

void quick_sort(int *vet, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = vet[(left + right) / 2];

    while(i <= j) {
        while(vet[i] < x && i < right) {
            i++;
        }
        while(vet[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(vet, left, j);
    }
    if(i < right) {
        quick_sort(vet, i, right);
    }

}

void menu_principal(){
    printf("BEM VINDO ! \n");
    printf("ESCOLHA O METODO DE ORDENACAO DESEJADO : \n");
    printf("[1] SELECTION SORT\n");
    printf("[2] QUICK SORT\n");
    printf("[0] SAIR\n");
}

int posicoes_vetor(){
    int posicoes = 0;

    while(posicoes<=0){
        printf("ESCOLHA UM VALOR POSITIVO DE POSICOES PARA O VETOR :  ");
        scanf("%d", &posicoes);
        if(posicoes<=0){
            printf("ENTRADA INVALIDA !");
        }
    }
    return posicoes;

}

void imprime_vetor(int * vet , int posicoes){
    printf("\n");
    for (int i = 0 ; i<posicoes ; i++){
        printf("[%d] ", vet[i] );
    }
}




