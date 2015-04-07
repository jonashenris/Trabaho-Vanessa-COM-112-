/* 
 * File:   Quick.h
 * Author: vitorpio
 *
 * Created on 1 de Abril de 2015, 21:39
 */

#ifndef QUICK_H
#define	QUICK_H

void quicksort(int *vet, int inf, int sup,int * dados);
int particao(int *vet, int inf, int sup,int * dados);
void trocar ( int* a, int* b );
int particiona (int * arr, int l, int h, int * dados);
void quickSortIterativo (int * arr, int l, int h, int * dados);

#endif	/* QUICK_H */

