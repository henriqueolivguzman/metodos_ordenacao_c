#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define VERMELHO     "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AZUL    "\x1b[34m"
#define RESET   "\x1b[0m"


typedef struct {
    int codigo_aluno;
    char nome[60];
    float nota1, nota2, nota3, nota4;
}aluno;

void menu_principal();

void menu_busca_aluno();

void adicionar_aluno(aluno *alunos , int posicoes);

void aluno_maior_nota(aluno * alunos, int posicoes);

void calculo_maior_media(aluno *alunos , int posicoes);

void calculo_menor_media(aluno *alunos , int posicoes);

void calculo_aprovado(aluno * alunos, int posicoes);

void selection_sort (aluno * alunos , int posicoes);

char * pesquisa_ordenada_aluno(aluno alunos[] , int tamanho_vetor , int codigo_aluno);

void escrever_arquivo(aluno alunos[] , int tamanho_vetor);

void leitura_arquivo();

int main()
{
    int opcao_escolhida = -1 ;
    aluno alunos[3];

    printf(AZUL"------------------------------------"RESET"\n" );
    printf("ALUNOS JA CADASTRADOS : \n");
    leitura_arquivo();
    printf(AZUL"------------------------------------"RESET"\n\n" );

    while(opcao_escolhida != 0) {
        system("cls");
        menu_principal();
        scanf("%d", &opcao_escolhida);

        if (opcao_escolhida == 1) {
            adicionar_aluno(alunos , 3);
            escrever_arquivo(alunos, 3);
            system("pause");
            system("cls");

        }
        else if (opcao_escolhida == 2) {
            int codigo_aluno;
            char * nome_aluno;

            menu_busca_aluno();
            scanf("%d", &codigo_aluno);
            selection_sort(alunos , 3);

            nome_aluno = pesquisa_ordenada_aluno(alunos , 3 , codigo_aluno);

            printf(AZUL"ALUNO : "RESET);
            printf("%s\n\n", nome_aluno);

            system("pause");

        }
        else if (opcao_escolhida == 3) {
            printf("\n\nRELATORIO : \n\n");

            aluno_maior_nota(alunos , 3);

            calculo_maior_media(alunos , 3);

            calculo_menor_media(alunos , 3);

            calculo_aprovado(alunos , 3);

            system("pause");


        }
        else if (opcao_escolhida == 0) {
            printf("\nOBRIGADO POR USAR O PROGRAMA !\n\n");
            printf("------------------------------------\n" );
            printf(VERDE"CRIADO POR HENRIQUE GUZMAN"RESET"\n");
            printf("------------------------------------\n" );
        }
        else {
            printf(VERMELHO"\nOPCAO INVALIDA !"RESET "\n");

        }
    }




    return 0;
}

void menu_principal(){
    printf("------------------------------------\n" );
    printf(AZUL "BEM VINDO ! " RESET "\n");
    printf("------------------------------------\n");
    printf("ESCOLHA UMA OPCAO : " RESET "\n");
    printf("------------------------------------");
    printf(VERDE"\n[1] NOVO ALUNO" RESET "\n");
    printf(VERDE"[2] BUSCAR ALUNO" RESET "\n");
    printf(VERDE"[3] RELATORIO" RESET "\n");
    printf(VERMELHO"[0] SAIR" RESET "\n");
    printf("------------------------------------\n");
    printf(AZUL "OPCAO ESCOLHIDA : " RESET);
}

void adicionar_aluno(aluno *alunos, int posicoes ){
    for (int i = 0 ; i<posicoes ; i++){
        printf("\n------------------------------------\n");
        printf(VERDE"ALUNO %d : " RESET "\n", i+1);
        printf("DIGITE O CODIGO DO ALUNO : ");
        scanf("%d", &alunos[i].codigo_aluno);

        printf("DIGITE O NOME DO ALUNO : ");
        scanf("%s", &alunos[i].nome);

        printf("DIGITE A PRIMEIRA NOTA DO ALUNO : ");
        scanf("%f", &alunos[i].nota1);

        printf("DIGITE A SEGUNDA NOTA DO ALUNO : ");
        scanf("%f", &alunos[i].nota2);

        printf("DIGITE A TERCEIRA NOTA DO ALUNO : ");
        scanf("%f", &alunos[i].nota3);

        printf("DIGITE A QUARTA NOTA DO ALUNO : ");
        scanf("%f", &alunos[i].nota4);
        printf("------------------------------------\n");
    }
}

void menu_busca_aluno(){
    printf("BUSCA DE ALUNO : \n");
    printf("DIGITE O CODIGO DO ALUNO : ");
}

void aluno_maior_nota(aluno * alunos, int posicoes){
    char aluno_maior_nota ;
    int indice_maior_nota = 0;
    float maior_nota = 0;

    for (int i = 0 ; i<posicoes ; i++){
        if (alunos[i].nota1>= maior_nota){
            maior_nota = alunos[i].nota1;
            indice_maior_nota = i;
        }
    }
    printf("------------------------------------\n" );
    printf("O ALUNO COM MAIOR NOTA NA PRIMEIRA PROVA FOI : %s\n", alunos[indice_maior_nota].nome);
}

void calculo_maior_media(aluno *alunos , int posicoes){
    float media , maior_media = 0 ;
    int indice_maior_media ;

    for (int i = 0 ; i<posicoes ; i++) {
        media = ((alunos[i].nota1 * 3) + (alunos[i].nota2 * 2) + (alunos[i].nota3 * 3) + (alunos[i].nota4 * 2)) / 10;
        if(media> maior_media){
            maior_media = media ;
            indice_maior_media = i ;
        }
    }
    printf("O ALUNO COM MAIOR MEDIA FOI %s ", alunos[indice_maior_media].nome);
    printf(" A SUA MEDIA FOI %.2f\n " , maior_media);
}

void calculo_menor_media(aluno *alunos , int posicoes){
    float media , menor_media = 10 ;
    int indice_menor_media ;

    for (int i = 0 ; i<posicoes ; i++) {
        media = ((alunos[i].nota1 * 3) + (alunos[i].nota2 * 2) + (alunos[i].nota3 * 3) + (alunos[i].nota4 * 2)) / 10;
        if(media < menor_media){
            menor_media = media ;
            indice_menor_media = i ;
        }
    }

    printf("O ALUNO COM MENOR MEDIA FOI %s ", alunos[indice_menor_media].nome);
    printf(" A SUA MEDIA FOI %.2f\n" , menor_media);
    printf("------------------------------------\n" );
}

void calculo_aprovado(aluno * alunos, int posicoes){
    float media ;

    for (int i = 0 ; i<posicoes ; i++) {
        printf("O ALUNO %s ESTA ", alunos[i].nome);
        media = ((alunos[i].nota1 * 3) + (alunos[i].nota2 * 2) + (alunos[i].nota3 * 3) + (alunos[i].nota4 * 2)) / 10;

        if(media >6){
            printf(VERDE"APROVADO"RESET "\n");
        }
        else{
            printf(VERMELHO"REPROVADO"RESET "\n");
        }
    }
    printf("------------------------------------\n" );
}

void selection_sort (aluno * alunos , int posicoes) {
    int i, j, min, aux;

    for (i = 0; i < (posicoes - 1); i++) {
        /* O minimo é o primeiro número não ordenado ainda */
        min = i;
        for (j = i + 1; j < posicoes; j++) {
            /* Caso tenha algum numero menor ele faz a troca do minimo*/
            if (alunos[j].codigo_aluno < alunos[min].codigo_aluno) {
                min = j;
            }
        }
        /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
        if (i != min) {
            aux = alunos[i].codigo_aluno;
            alunos[i].codigo_aluno = alunos[min].codigo_aluno;
            alunos[min].codigo_aluno = aux;
        }
    }
}

char * pesquisa_ordenada_aluno(aluno * alunos , int tamanho_vetor , int codigo_aluno) {
    char *retorno;
    for (int i = 0; i < tamanho_vetor; i++) {
        if (alunos[i].codigo_aluno  == codigo_aluno) {
            retorno = alunos[i].nome;
            break;
        }
        else{
            retorno = VERMELHO"O ITEM NAO FOI ENCONTRADO"RESET"\n";
        }
    }
    return retorno;
}



void escrever_arquivo(aluno alunos[], int tamanho_vetor) {
    int i;
    FILE *arq;

    arq = fopen("dados.txt", "ab");

    if (arq != NULL){
        for (int i = 0; i<tamanho_vetor ; i++){
            fprintf(arq , "%s\n" , alunos[i].nome);
        }
    }
    else {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        exit(1);
    }
    fclose(arq);
}

// função para ler do arquivo
// recebe o vetor que ela irá preencher
// retorna a quantidade de elementos preenchidos
int ler_arquivo(aluno alunos[]) {
    // abre o arquivo para leitura
    FILE *arq = fopen("dados.txt", "rb");

    if (arq != NULL) {
        int indice = 0;
        while (1) {
            aluno aluno;

            // fread ler os dados
            // retorna a quantidade de elementos lidos com sucesso
            size_t r = fread(&aluno, sizeof(aluno), 1, arq);

            // se retorno for menor que o count, então sai do loop
            if (r < 1)
                break;
            else
                alunos[indice++] = aluno;
        }
        fclose(arq); // fecha o arquivo
        return indice;
    } else {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        exit(1); // aborta o programa
    }
}

void leitura_arquivo(){
    FILE *arq;
    char nome[50];

    arq = fopen("dados.txt" , "r");

    if(arq != NULL) {
        while (fgets(nome, 50, arq) != NULL) {
            printf("%s", nome);
        }
    }
    else{
        printf(VERMELHO"NAO FORAM ENCONTRADOS REGISTROS PREVIOS!"RESET "\n");
    }
    fclose(arq);
}
