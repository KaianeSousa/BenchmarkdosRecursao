#ifndef BLB_H
#define BLB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//Funções de interação
void interageBusca();
void interageOrdenacao();
void interageOperacoes();
void interageArquivo();
                
//Funções dos arquivos
void carregarNumeros(const char *nomeArquivo, int *numeros, int *quantidade);
void limparArquivo(const char *nomeArquivo);

//Funções de busca
int buscaLinear(int *numeros, int quantidade, int num);
int buscaSentinela(int *numeros, int quantidade, int num);
int buscaBinariaRecursiva(int *numeros, int esquerda, int direita, int num);

//Funções de ordenação
void bubbleSort(int *numeros, int quantidade);
int particionarQuickSort(int *numeros, int esquerda, int direita);
void insertionSort(int *numeros, int quantidade);
void particionarMergeSort(int *numeros, int esquerda, int meio, int direita);
void mergeSortRecursivo(int *numeros, int esquerda, int direita);
void quickSortRecursivo(int *numeros, int esquerda, int direita);
void mergeSortIterativo(int *numeros, int quantidade);
void quickSortIterativo(int *numeros, int quantidade);

//Funções de cálculos
int somatorio(int n);
int fatorial(int n);
int fibonacci(int n);

    
#endif




