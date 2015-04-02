#include <stdlib.h>

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

// A utility function to swap two elements
void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
/* This function is same in both iterative and recursive*/
int partition (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
    
    int j;
    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
/* A[] --> Array to be sorted, l  --> Starting index, h  --> Ending index */
void quickSortIterative (int * arr, int l, int h)
{
    // Create an auxiliary stack
    int stack[ h - l + 1 ];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];
 
        // Set pivot element at its correct position in sorted array
        int p = partition( arr, l, h );
 
        // If there are elements on left side of pivot, then push left
        // side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }
 
        // If there are elements on right side of pivot, then push right
        // side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
}