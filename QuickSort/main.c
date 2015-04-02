#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Quick.h"
#include "ES.h"

int main(int argc, char** argv){				
        
    if(argc==5){
    
	int * vetor;
        const int ORDENACAO = atoi(argv[1]);
        const int SEMENTE = atoi(argv[2]);				
	const char * ARQUIVOENTRADA = argv[3];  
        const char * ARQUIVOSAIDA = argv[4]; 
        clock_t inicio, fim;
        
    
	vetor = gerarVetor(ARQUIVOENTRADA, SEMENTE);
        
	if(!vetor){ 
		printf("Erro ao preencher o vetor.\n");
		return 0;
	}
        
        int tam = vetorTamanho(ARQUIVOENTRADA);
        
        if(ORDENACAO==1){
            inicio = clock();
            quicksort(vetor,0,tam-1);
            fim = clock();
        }else{
            if(ORDENACAO==2){
                inicio = clock();
                quickSortIterative(vetor,0,tam-1);
                fim = clock();
            }else{
                printf("Erro");
            }
        }
        
        int cont=0;
        printf("Vetor ordenado:\n");
        for(cont;cont<tam;cont++){
            printf("%d\n",vetor[cont]);
        }
        
        double tempo;
        tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
        printf("\n Tempo gasto: %lf", tempo);
        
        
    }else{
        printf("\nNúmero de argumentos inválido\n");
    }
	return 0;
}

