#include "blb.h"

void interageOrdenacao(){
    
       
    int opcao;
    
    do{
            
        printf("4. Ordenar com Bubble Sort\n");
        printf("5. Ordenar com Quick Sort Recursivo\n");
        printf("6. Ordenar com Quick Sort Interativo\n");
        printf("7. Ordenar com Insertion Sort\n");
        printf("8. Ordenar com Merge Sort Interativo\n");
        printf("9. Ordenar com Merge Sort Recursivo\n");
        printf("0. Retornar para o menu principal\n");
        
        scanf("%d", &opcao);
    
    switch(opcao){
        
            case 4: 
            {
                clock_t inicio, fim;
                inicio = clock();
                bubbleSort(numeros, quantidade);
                fim = clock();
                printf("Números ordenados com Bubble Sort. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;

            case 5: 
            {
                clock_t inicio, fim;
                inicio = clock();
                quickSortRecursivo(numeros, 0, quantidade - 1);
                fim = clock();
                printf("Números ordenados com Quick Sort. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
            
            case 6: 
            {
                
            clock_t inicio, fim;
            inicio = clock();
            quickSortIterativo(numeros, quantidade);
            fim = clock();
            printf("Números ordenados com Quick Sort Iterativo. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
                    

            case 7:
            {
                clock_t inicio, fim;
                inicio = clock();
                insertionSort(numeros, quantidade);
                fim = clock();
                printf("Números ordenados com Insertion Sort. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
            
            case 8: {
                
            
                clock_t inicio, fim;
                inicio = clock();
                mergeSortIterativo(numeros, quantidade);
                fim = clock();
                printf("Números ordenados com Merge Sort Iterativo. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
                
            
            case 9: {
            clock_t inicio, fim;
            inicio = clock();
            mergeSortRecursivo(numeros, 0, quantidade - 1);
            fim = clock();
            
            printf("Números ordenados com Merge Sort Recursivo. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
        
        case 0: {
              
            printf("Saindo do programa.\n");
            return;
        }
        break;
    
             
        default:
        printf("Erro! Por favor, escolha uma das opções fornecidadas.\n");
        
        }
                
    }while(opcao != 0);
        
    
}

void carregarNumeros(const char *nomeArquivo, int *numeros, int *quantidade){

    int num;
    *quantidade = 0;
    
    FILE *arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL) 
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

        while (fscanf(arquivo, "%d", &num) == 1)
        {
    
            numeros[*quantidade] = num;
            (*quantidade)++;
        }

    fclose(arquivo);
}


void bubbleSort(int *numeros, int quantidade) {
    
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}

//Recusão
int particionarQuickSort(int *numeros, int esquerda, int direita){
    
    if(esquerda < direita) 
    {
        int numEscolhido = numeros[direita];
        int i = esquerda - 1;

        for(int j = esquerda; j < direita; j++)
        {
            if(numeros[j] <= numEscolhido) 
            {
                i++;
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }

        int temp = numeros[i + 1];
        numeros[i + 1] = numeros[direita];
        numeros[direita] = temp;

        int posicaoNumEscolhido = i + 1;

        //Chamada recursiva para as partições à esquerda e à direita do numEscolhido
        particionarQuickSort(numeros, esquerda, posicaoNumEscolhido - 1);
        particionarQuickSort(numeros, posicaoNumEscolhido + 1, direita);

        return posicaoNumEscolhido;
    }

    //Quando esquerda >= direita, não há nada para fazer (caso base)
    return esquerda;
}

void insertionSort(int *numeros, int quantidade){
    
    for (int i = 1; i < quantidade; i++) 
    {
        int num = numeros[i];
        int j = i - 1;

        while (j >= 0 && numeros[j] > num) 
        {
            numeros[j + 1] = numeros[j];
            j--;
        }

        numeros[j + 1] = num;
    }
}


void particionarMergeSort(int *numeros, int esquerda, int meio, int direita){
    
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = numeros[esquerda + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = numeros[meio + 1 + j];
    }

    i = 0;
    j = 0;
    k = esquerda;
    
    while (i < n1 && j < n2)
    {
        if(L[i] <= R[j]) 
        {
            numeros[k] = L[i];
            i++;
        }else{
            
            numeros[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        numeros[k] = L[i];
        i++;
        k++;
    }
    
        while (j < n2)
        {
            numeros[k] = R[j];
            j++;
            k++;
        }
}
    


// Implementação recursiva do Merge Sort
void mergeSortRecursivo(int *numeros, int esquerda, int direita){
    
    if(esquerda < direita){
        int meio = esquerda + (direita - esquerda) / 2;

        mergeSortRecursivo(numeros, esquerda, meio);
        mergeSortRecursivo(numeros, meio + 1, direita);

        particionarMergeSort(numeros, esquerda, meio, direita);
    }
}

//Recusão
void quickSortRecursivo(int *numeros, int esquerda, int direita){
    
    int numEscolhido = 0;
    
    if (esquerda < direita)
    {
        numEscolhido = particionarQuickSort(numeros, esquerda, direita);
        
        quickSortRecursivo(numeros, esquerda, numEscolhido - 1);
        quickSortRecursivo(numeros, numEscolhido + 1, direita);
    }
}


//Merge Sort interativo
void mergeSortIterativo(int *numeros, int quantidade){
    
    int meio = 0, direita = 0;
    
    for (int tamanhoAtual = 1; tamanhoAtual <= quantidade - 1; tamanhoAtual *= 2) 
    {
        for (int esquerda = 0; esquerda < quantidade - 1; esquerda += 2 * tamanhoAtual) 
        {
            
            meio = esquerda + tamanhoAtual - 1;
            direita = fmin(esquerda + 2 * tamanhoAtual - 1, quantidade - 1);

            particionarMergeSort(numeros, esquerda, meio, direita);
        }
    }
}


// Implementação iterativa do Quick Sort
void quickSortIterativo(int *numeros, int quantidade){
    
    int pilha[quantidade];
    int topo = -1;

    pilha[++topo] = 0;
    pilha[++topo] = quantidade - 1;

    while (topo >= 0) 
    {
        int direita = pilha[topo--];
        int esquerda = pilha[topo--];

        int pivoIndex = particionarQuickSort(numeros, esquerda, direita);

        if (pivoIndex - 1 > esquerda) {
            pilha[++topo] = esquerda;
            pilha[++topo] = pivoIndex - 1;
        }

        if (pivoIndex + 1 < direita) {
            pilha[++topo] = pivoIndex + 1;
            pilha[++topo] = direita;
        }
    }
}



