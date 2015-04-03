#include <stdlib.h>
#include "Quick.h"

/* funcao de ordenacao pelo metodo quicksort */
void quicksort(int *vet, int inf, int sup){
	int k;
	
	if(sup > inf){
		k = particao(vet, inf, sup);	//recebendo o indice da chave particionadora
		quicksort(vet, inf, k-1);		//ordenando dados do conjunto que vai de 0 ate k-1
		quicksort(vet, k+1, sup);		//ordenando dados do conjunto que vai de k+1 ate tam-1
	}
}

/* funcao que particiona o vetor em conjuntos e retorna o indice da chave particionadora */
int particao(int *vet, int inf, int sup){
	//declaracao de variaveis
	int M;		//recebe a chave particionadora
	int k;		//indice da chave particionadora
	int aux; 	//variavel auxiliar na troca dos valores
	int *p;		//aponta para o inicio do vetor
	int *q;		//aponta para o final do vetor	

	//inicializacao de variaveis
	k = inf;		//recebendo o indice inferior
	p = inf + vet; 		//apontando para o inicio do vetor
	/* funcao que faz a leitura dos dados de um arquivo*/
        q = sup + vet;	//apontando para o fim do vetor
	M = *p;			//recebendo o primeiro elemento do vetor
	
	//operacao de particao
	do{		
		while(sup > inf && *q >= M){	//partindo do ultimo elemento do vetor e verificando se os valores sao maiores que a chave particionadora
			sup--;
			q = sup + vet;
		}
		k = sup;	//o indice da chave particionadora eh o indice superior do vetor
		
		if(sup != inf){	//troca de valores
			aux = *p;
			*p = *q;
			*q = aux;
			
			while(inf < sup && *p <= M){	//partindo do primeiro elemento do vetor e verificando se os valores sao menores que a chave particionadora
				inf++;
				p++; 
			}

			k = inf;	//o indice da chave particionadora eh o indice inferior do vetor
			
			if(inf != sup){	//troca de valores
				aux = *p;
				*p = *q;
				*q = aux;
			}
		}
	}while(inf != sup);		//as operacoes acima sao executadas enquanto os indices inferior e superior forem diferentes
	
	return k;		//retorno do indice da chave particionadora
}

// Função que troca dois elementos
void trocar ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
// Função particiona também ultilizada na versão recursiva
int particiona (int * arr, int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
    
    int j;
    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            trocar (&arr[i], &arr[j]);
        }
    }
    trocar (&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
// Quick sort iterativo, vetor à ser ordenado, de l à h
void quickSortIterativo (int * arr, int l, int h)
{
    // Cria uma pilha auxiliar
    int pilha[ h - l + 1 ];
 
    // Inicializa topo da pilha
    int top = -1;
 
    // push os valores iniciais de l e h na pilha
    pilha[ ++top ] = l;
    pilha[ ++top ] = h;
 
    // Continua dando poping na pilha até ela fica vazia
    while ( top >= 0 )
    {
        // Pop h e l
        h = pilha[ top-- ];
        l = pilha[ top-- ];
 
        // Elemento pivô em sua posição correta em um vetor ordenado
        int p = particiona( arr, l, h );
 
        // Se existem elemento à esquerda do pivô, então push lado esquerdo da pilha
        if ( p-1 > l )
        {
            pilha[ ++top ] = l;
            pilha[ ++top ] = p - 1;
        }
 
        // Se existem elemento à direita do pivô, então push lado direito da pilha
        if ( p+1 < h )
        {
            pilha[ ++top ] = p + 1;
            pilha[ ++top ] = h;
        }
    }
}