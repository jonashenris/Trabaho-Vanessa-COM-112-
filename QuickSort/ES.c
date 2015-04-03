#include <stdio.h>
#include <stdlib.h>

// Preencher arquivo de entrada com elementos rândomicos gerados à partir da semente fornecida
void preencheArquivo(FILE * arquivo, int semente, int tam){
    int i;
    int valores;
    srand(semente);
    for(i=1 ; i <= tam ; i++){
        valores = rand();
        fprintf(arquivo,"%d\n",valores);      
    }
    return;
}

// Retorna tamanho do vetor, primeira linha do arquivo
int vetorTamanho(char * nome_arq){
     FILE * arquivo;
     int vetor_tamanho;
    arquivo = fopen(nome_arq,"r");
    if(!arquivo){
        return 0;
    }
    fscanf(arquivo,"%d",&vetor_tamanho);
    fclose(arquivo);
    return vetor_tamanho;
}

// Retorna vetor
int *gerarVetor(char * nomeArquivo, int semente){
    int i = 0;
    int tam = 0;
        
    // Abrir arquivo para preenche-lo
    FILE * arquivo = fopen (nomeArquivo, "a+");							
    if (!arquivo){
        printf("Nao foi possivel abrir o arquivo %s\n", nomeArquivo);
        return NULL;
    }
    fscanf (arquivo, "%d", &tam);
    if (ferror(arquivo)){
        printf("Erro ao ler o arquivo de dados\n");
        return NULL;
    }
    
    // Preencher arquivo
    preencheArquivo(arquivo, semente, tam);
    fclose(arquivo);			
    
    // Abrir arquivo para preencher o vetor
    arquivo = fopen (nomeArquivo, "r");
    fscanf (arquivo, "%d", &tam);
    
    // Aloca vetor
    int *vetor = (int*) calloc(tam, sizeof(int));
    
    // Preencher vetor
    while (!feof(arquivo) && i < tam){
        fscanf(arquivo, "%d", &vetor[i]);
        if (ferror(arquivo)){
            printf("Erro ao ler o arquivo de dados\n");
            return NULL;
        }
        i++;
    }
    fclose(arquivo);
    return vetor;
}

// Gera relatório final
void gerarRelatorio(char * nomeArquivo, double tempo, int ordenacao, int tam, int semente){
    FILE * arquivo = fopen(nomeArquivo,"w+");
    if(ordenacao==1){
        fprintf(arquivo,"Método de ordenação: QuickSort\n");
    }else{
        fprintf(arquivo,"Método de ordenação: QuickSort iterativo\n");
    }
    fprintf(arquivo,"Tamanho do vetor: %d\n",tam);
    fprintf(arquivo,"Semente: %d\n",semente);
    fprintf(arquivo,"Tempo de ordenação: %lf\n",tempo);
    if (ferror(arquivo)){
        printf("Erro ao escrever resultado no arquivo de saída\n");
        return;
    }
    return;
}