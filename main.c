#include "blb.h" //Inclui o arquivo da biblioteca "blb.h"


int main(){

    int opcao; //Variável para armazenar a escolha do usuário
    
    do{
        //Menu de operações
        printf("\nOperações Disponíveis:\n");
        printf("1. Busca\n");
        printf("2. Ordenação\n");
        printf("3. Descobrir número\n");
        printf("4. Manipular arquivo\n");
        printf("0. Sair");
        scanf("%d", &opcao); //Variável para a leitura da escolha do usuário
        
        switch(opcao){
            
            case 1: 
                interageBusca(); //Chama a função para interação com a busca
                break;
            case 2:
                interageOrdenacao(); //Chama a função para interação com a ordenação
                break;
            case 3:
                interageOperacoes(); //Chama a função para interação com as operações
                break;
            case 4:
                interageArquivo(); //Chama a função para interação com o arquivo
                break;
            case 0:
                printf("Agradecemos pela sua visita!\n");
                exit(1); //Encerra o programa com status de sucesso
                break;
            default: //Mensagem de opção inserida inválida
                printf("Essa opção não existe, reveja as operações oferecidas atentamente.\n");
            }
            
        
        }while(opcao != 0); //Loop continua até o usuário escolher sair
        
    return 0; //Retorna 0 para indicar que o programa foi executado com sucesso
    
}




