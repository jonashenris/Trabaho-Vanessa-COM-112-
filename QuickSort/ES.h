/* 
 * File:   ES.h
 * Author: vitorpio
 *
 * Created on 1 de Abril de 2015, 21:09
 */

#ifndef ES_H
#define	ES_H

void preencheArquivo(FILE * arquivo, int semente, int tam);
int vetorTamanho(char * nome_arq);
int *gerarVetor(char * nomeArquivo, int semente);
void gerarRelatorio(char * nomeArquivo, double tempo, int ordenacao, int tam, int semente);

#endif	/* ES_H */

