#include "blb.h" //Inclui o arquivo da biblioteca "blb.h"

//Função de interação para realizar as operações disponíveis
void interageOperacoes(){

    int opcao; //Variável para a leitura da escolha do usuário

    do{
        //Menu de operações
        printf("Qual operação deseja realizar?\n")
        printf("1. Descobrir o fatorial de um número\n");
        printf("2. Descobrir o somatório de um número\n");
        printf("3. Descobrir a sequência de fibonacci de um número\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch(opcao){
            
            int resultado = 0; //Variável para receber o resultado de cada operação

            case 1: //Calcula o fatorial de um número digitado pelo usuário
            {
                int numero;
                
                printf("Digite um número para calcular o fatorial: ");
                scanf("%d", &numero);
                
                resultado = fatorial(numero);
                
                printf("Fatorial de %d: %d\n", numero, resultado);
            }
            break;

            case 2: //Calcula o somatório de 1 até o número digitado pelo usuário
            {
                int n;

                printf("Digite um número para calcular o somatório de 1 até %d: ", n);
                scanf("%d", &n);
                
                resultado = somatorio(n);
                
                printf("Somatório de 1 até %d: %d\n", n, resultado);
            }
            break;

            case 3: //Calcula n termo da sequência de Fibonacci
            {
                int termo;
                
                printf("Digite um número para calcular o termo na sequência de Fibonacci: ");
                scanf("%d", &termo);
                
                resultado = fibonacci(termo);
                
                printf("Termo %d na sequência de Fibonacci: %d\n", termo, resultado);
                
            }
            break;

            case 0: //Encerra essa função e volta para a anterior
            {

                printf("Saindo do programa.\n");
                return;
             }
                break;

            default:
                printf("Erro! Por favor, escolha uma das opções fornecidadas.\n");

            }

    }while(opcao != 0);

}

//Função para calcular o fatorial de um número
int fatorial(int n){

    if(n == 0 || n == 1)
    {
        return 1;

    }else{

        return n * fatorial(n - 1);
    }
}

//Função para calcular o somatório de 1 até n
int somatorio(int n){

    if (n == 0)
    {
        return 0;

    }else{

        return n + somatorio(n - 1);
    }
}

//Função para calcular o n-ésimo termo da sequência de Fibonacci
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



