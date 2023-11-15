#include "blb.h"


int main(){
    
    char nomeArquivo[] = "numeros.txt";
    int numeros[1000];
    int quantidade;
    FILE *arquivo = NULL; //Declaração da variável arquivo

    int opcao;
    
    do{
          //Menu de operações
        printf("\nOperações Disponíveis:\n");
        printf("1. Busca\n");
        printf("2. Ordenação\n");
        printf("3. Descobrir número\n");
        printf("4. Manipular arquivo\n");
        printf("0. Sair");
        scanf("%d", &opcao);
        
        switch(opcao){
            
            case 1: 
                interageBusca();
                break;
            case 2:
                interageOrdenacao();
                break;
            case 3:
                interageOperacoes();
                break;
            case 4:
                interageArquivo();
                break;
            case 0:
                printf("Agradecemos pela sua visita!\n");
                exit(1);
                break;
            default:
                printf("Essa opção não existe, reveja as operações oferecidas atentamente.\n");
            }
            
        
        }while(opcao != 0);
        
    return 0;
    
}


