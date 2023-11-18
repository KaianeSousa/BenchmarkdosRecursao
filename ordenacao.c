#include "blb.h"  //Inclui o arquivo da biblioteca "blb.h"

void interageOrdenacao(){

    char nomeArquivo[] = "numeros.txt"; //Nome do arquivo a ser lido
    int numeros[100]; //Array que armazenará os números a serem ordenados
    int quantidade; //Variável para armazenar a quantidade de números lidos
    FILE *arquivo = NULL; //Declaração da variável arquivo

    int opcao; //Variável para armazenar a escolha do usuário

    do{
        //Menu de opções para escolher o tipo de ordenação
        printf("\nEscolha o tipo de ordenação:\n");
        printf("1. Ordenar com Bubble Sort\n");
        printf("2. Ordenar com Quick Sort Recursivo\n");
        printf("3. Ordenar com Quick Sort Interativo\n");
        printf("4. Ordenar com Insertion Sort\n");
        printf("5. Ordenar com Merge Sort Interativo\n");
        printf("6. Ordenar com Merge Sort Recursivo\n");
        printf("0. Sair\n");

        scanf("%d", &opcao); //Variável para a leitura da escolha do usuário

    switch(opcao){
             //Mede o tempo de execução do Bubble Sort e exibe os resultados
            case 1:
            {
                clock_t inicio, fim;
                inicio = clock();
                bubbleSort(numeros, quantidade);
                fim = clock();
                printf("Números ordenados com Bubble Sort. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
            //Mede o tempo de execução do Quick Sort Recursivo e exibe os resultados
            case 2:
            {
                clock_t inicio, fim;
                inicio = clock();
                quickSortRecursivo(numeros, 0, quantidade - 1);
                fim = clock();
                printf("Números ordenados com Quick Sort. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
            //Mede o tempo de execução do Quick Sort Interativo e exibe os resultados
            case 3:
            {

            clock_t inicio, fim;
            inicio = clock();
            quickSortIterativo(numeros, quantidade);
            fim = clock();
            printf("Números ordenados com Quick Sort Iterativo. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
            //Mede o tempo de execução do Insertion Sort e exibe os resultados
            case 4:
            {
                clock_t inicio, fim;
                inicio = clock();
                insertionSort(numeros, quantidade);
                fim = clock();
                printf("Números ordenados com Insertion Sort. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
            //Mede o tempo de execução do Merge Sort Interativo e exibe os resultados
            case 5: 
            {
                clock_t inicio, fim;
                inicio = clock();
                mergeSortIterativo(numeros, quantidade);
                fim = clock();
                printf("Números ordenados com Merge Sort Iterativo. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
            //Mede o tempo de execução do Merge Sort Recursivo e exibe os resultados
            case 6: 
            { 
            clock_t inicio, fim;
            inicio = clock();
            mergeSortRecursivo(numeros, 0, quantidade - 1);
            fim = clock();

            printf("Números ordenados com Merge Sort Recursivo. \nTempo: %f segundos.\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
            }
            break;
        //Encerra essa função e volta para a anterior
        case 0:
        {
            printf("Saindo do programa...\n");
            return;
        }
        break;
        //Mensagem de erro para escolha inválida
        default:
        printf("Erro! Por favor, escolha uma das opções fornecidadas.\n");
        }
        
    }while(opcao != 0); //Loop continua até o usuário escolher sair


}
//Implementação do algoritmo Bubble Sort
void bubbleSort(int *numeros, int quantidade){
    
    int temp;

    for (int i = 0; i < quantidade - 1; i++) 
    {
        for (int j = 0; j < quantidade - i - 1; j++) 
        {
            if (numeros[j] > numeros[j + 1]) 
            {
                temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}

//Implementação do particionamento da divisão do Quick Sort
int particionarQuickSort(int *numeros, int esquerda, int direita){
    
    int temp;
    int i;
    int numEscolhido;

    if(esquerda < direita)
    {
        numEscolhido = numeros[direita];
        i = esquerda - 1;

        for(int j = esquerda; j < direita; j++)
        {
            if(numeros[j] <= numEscolhido)
            {
                i++;
                temp = numeros[i];
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

//Implementação do algoritmo Insertion Sort
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


//Implementação do particionamento do Merge Sort
void particionarMergeSort(int *numeros, int esquerda, int meio, int direita){

    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int ESQ[n1], DIR[n2];

    for (i = 0; i < n1; i++){
        ESQ[i] = numeros[esquerda + i];
    }
    for (j = 0; j < n2; j++){
        DIR[j] = numeros[meio + 1 + j];
    }

    i = 0;
    j = 0;
    left = esquerda;

    while (i < n1 && j < n2)
    {
        if(ESQ[i] <= DIR[j])
        {
            numeros[left] = ESQ[i];
            i++;
        }else{

            numeros[left] = DIR[j];
            j++;
        }
        left++;
    }

    while (i < n1)
    {
        numeros[left] = ESQ[i];
        i++;
        left++;
    }
    
        while (j < n2)
        {
            numeros[left] = DIR[j];
            j++;
            left++;
        }
}



//Implementação recursiva do Merge Sort
void mergeSortRecursivo(int *numeros, int esquerda, int direita){
    
    int meio;

    if(esquerda < direita){
        meio = esquerda + (direita - esquerda) / 2;

        mergeSortRecursivo(numeros, esquerda, meio);
        mergeSortRecursivo(numeros, meio + 1, direita);

        particionarMergeSort(numeros, esquerda, meio, direita);
    }
}

//Implementação recursiva do algoritmo do Quick Sort
void quickSortRecursivo(int *numeros, int esquerda, int direita){

    int numEscolhido = 0;

    if (esquerda < direita)
    {
        numEscolhido = particionarQuickSort(numeros, esquerda, direita);

        quickSortRecursivo(numeros, esquerda, numEscolhido - 1);
        quickSortRecursivo(numeros, numEscolhido + 1, direita);
    }
}


//Implementação do algoritmo de Merge Sort Iterativo
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


//Implementação do algoritmo Iterativa do Quick Sort
void quickSortIterativo(int *numeros, int quantidade){

    int ordem[quantidade];
    int topo = -1;

    ordem[++topo] = 0;
    ordem[++topo] = quantidade - 1;

    while (topo >= 0)
    {
        int direita = ordem[topo--];
        int esquerda = ordem[topo--];

        int pontoPartida = particionarQuickSort(numeros, esquerda, direita);

        if (pontoPartida - 1 > esquerda) {
            ordem[++topo] = esquerda;
            ordem[++topo] = pontoPartida - 1;
        }

        if (pontoPartida + 1 < direita) {
            ordem[++topo] = pontoPartida + 1;
            ordem[++topo] = direita;
        }
    }
}


