#include "blb.h" //Inclui o arquivo da biblioteca "blb.h"

int main(){

    int opcao;
    
    do{
        //Menu de operações
        printf("\nOperações Disponíveis:\n");
        printf("1. Busca\n");
        printf("2. Ordenação\n");
        printf("3. Descobrir número\n");
        printf("4. Manipular arquivo\n");
        printf("0. Sair");
        scanf("%d", &opcao); //Leitura da escolha do usuário
        
        switch(opcao){
            
            case 1: 
                interageBusca(); //Chama a função para interação com a busca
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


