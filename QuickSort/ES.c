#include <stdio.h>
#include <stdlib.h>

void preencheArquivo(FILE * arquivo, int semente, int tam){
	int i;
	int valores;
	srand(semente);
        printf("Vetor:\n");
	for(i=1 ; i <= tam ; i++){
		valores = rand();
                fprintf(arquivo,"%d\n",valores);
	}
	return;
}

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

int *gerarVetor(char * nomeArquivo, int semente){
    int i = 0;
    int tam = 0;
        
    // Abrir arquivo para preenche-lo
    FILE * arquivo = fopen (nomeArquivo, "a+");							
    if (!arquivo){
        printf("Nao foi possivel abrir o arquivo %s.\n", nomeArquivo);
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
        printf("%d\n",vetor[i]);
        if (ferror(arquivo)){
            printf("Erro ao ler o arquivo de dados\n");
            return NULL;
        }
        i++;
    }
    fclose(arquivo);
    return vetor;
}