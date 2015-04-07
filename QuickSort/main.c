#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Quick.h"
#include "ES.h"

int main(int argc, char** argv){				

    // Verifica se o número de argumentos é válido
    if(argc==5){
        
	int * vetor;
        clock_t inicio, fim;
        
        // Constantes = argumentos
        const int ORDENACAO = atoi(argv[1]);
        const int SEMENTE = atoi(argv[2]);				
	const char * ARQUIVOENTRADA = argv[3];  
        const char * ARQUIVOSAIDA = argv[4];
        int dados[2]={0,0};
        
        // Obter tamanho do vetor
        int tam = vetorTamanho(ARQUIVOENTRADA);
        
        // Gerar vetor aleatório
	vetor = gerarVetor(ARQUIVOENTRADA, SEMENTE);
        
	if(!vetor){ 
            printf("Erro ao preencher o vetor\n");
            return 1;
	}
        
        // QuickSort
        if(ORDENACAO==1){
            inicio = clock();
            quicksort(vetor,0,tam-1,dados);
            fim = clock();
        }else{
            
            // QuickSort iterativo
            if(ORDENACAO==2){
                inicio = clock();
                quickSortIterativo(vetor,0,tam-1,dados);
                fim = clock();
            }else{
                printf("Metodo de ordenacao invalido, modo de uso:\nquicksort METODO_DE_ORDENACAO[1-Quick sort/2-Quick sort iterativo] SEMENTE ARQUIVOE_NTRADA ARQUIVO_SAIDA");
                return 1;
            }
        }
        
        // Calcular tempo de ordenação
        double tempo = (double)(fim - inicio)/CLOCKS_PER_SEC;
        
        // Gerar relatório
        gerarRelatorio(ARQUIVOSAIDA,tempo,dados,ORDENACAO,tam,SEMENTE);   
        printf("%d %d",dados[0],dados[1]);
        
    // Número de argumentos inválido
    }else{
        printf("Numero de argumentos invalido, modo de uso:\nquicksort METODO_DE_ORDENACAO[1-Quick sort/2-Quick sort iterativo] SEMENTE ARQUIVOE_NTRADA ARQUIVO_SAIDA");
        return 1;
    }
	return 0;
}

