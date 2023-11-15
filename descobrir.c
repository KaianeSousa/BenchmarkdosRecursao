#include "blb.h"

void interageOperacoes(){
    
    int opcao;
    
    do{
        printf("10. Descobrir o fatorial de um número\n");
        printf("11. Descobrir o somatório de um número\n");
        printf("12. Descobrir o fatorial de um número\n");
        
        scanf("%d", &opcao);
        
        switch(opcao){
            
                        
            case 10:
            {
                int numero;
                printf("Digite um número para calcular o fatorial: ");
                scanf("%d", &numero);
                int resultado = fatorial(numero);
                printf("Fatorial de %d: %d\n", numero, resultado);
            }
            break;
            
            
            case 11:
            {
                int n;
                
                printf("Digite um número para calcular o somatório de 1 até n: ");
                scanf("%d", &n);
                int resultado = somatorio(n);
                printf("Somatório de 1 até %d: %d\n", n, resultado);
            }
            break;
            
            case 12:
            {
                int termo;
                printf("Digite um número para calcular o termo na sequência de Fibonacci: ");
                scanf("%d", &termo);
                int resultado = fibonacci(termo);
                printf("Termo %d na sequência de Fibonacci: %d\n", termo, resultado);
            }
            break;
            
            case 0: {
              
            printf("Saindo do programa.\n");
            }//Falta o link de retorno pro código
            return;
             
            default:
            printf("Erro! Por favor, escolha uma das opções fornecidadas.\n");
            
            }

    }while(opcao != 0);
    
    

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

// Função para calcular o somatório de 1 até n
int somatorio(int n){
    
    if (n == 0)
    {
        return 0;
        
    }else{
        
        return n + somatorio(n - 1);
    }
}

// Função para calcular o fatorial de um número
int fatorial(int n){
    
    if(n == 0 || n == 1)
    {
        return 1;
        
    }else{
        
        return n * fatorial(n - 1);
    }
}

// Função para calcular o n-ésimo termo da sequência de Fibonacci
int fibonacci(int n){
    
    if (n == 0) 
    {
        return 0;
    }else if (n == 1){
        
        return 1;
        
    }else{
        
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}




