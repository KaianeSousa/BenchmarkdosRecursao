#include "blb.h"

void interageBusca(){
    
    int num = 0;
    char nomeArquivo[] = "numeros.txt";
    int numeros[100];
    int quantidade;
    FILE *arquivo = NULL; //Declaração da variável arquivo
    int opcao;


      do{
        //Menu de buscas
        printf("\nBuscas Disponíveis:\n");
        printf("1. Busca Linear\n");
        printf("2. Busca Sentinela\n");
        printf("3. Busca Binária\n");
        printf("0. Sair\n");

        scanf("%d", &opcao);

         switch (opcao)
        {
            case 1: {

                printf("Digite o número que deseja buscar: ");
                scanf("%d", &num);
                
                int posicao = buscaLinear(numeros, quantidade, num);
                
                if(posicao != -1){
                    
                    printf("Número encontrado na posição %d.\n", posicao);
                    
                }else{
                    printf("Número não encontrado.\n");
                }
            }
            break;

            case 2:
            {

                printf("Digite o número que deseja buscar: ");
                scanf("%d", &num);
                
                int posicao = buscaSentinela(numeros, quantidade, num);

                if(posicao != -1)
                {
                    printf("Número encontrado na posição %d.\n", posicao);

                }else{

                    printf("Número não encontrado.\n");
                }
            }
            break;

            case 3:
            {

            printf("Digite o número que deseja buscar: ");
            scanf("%d", &num);

            int posicao = buscaBinariaRecursiva(numeros, 0, quantidade - 1, num);
            
                if(posicao != -1)
                {
                    printf("Número encontradao na posição %d.\n", posicao);

                }else{

                    printf("Número não encontrado.\n");
                }
        }
            break;

            case 0: 
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

int buscaLinear(int *numeros, int quantidade, int num){

    for (int i = 0; i < quantidade; i++)
    {
        if (numeros[i] == num) {
            return i;        }
    }

    return -1;
}

int buscaSentinela(int *numeros, int quantidade, int num)
{
    int last = numeros[quantidade - 1];
    int i = 0;
    
    numeros[quantidade - 1] = num;

    while (numeros[i] != num)
    {
        i++;
    }

    numeros[quantidade - 1] = last;

    if (i < quantidade - 1)
    {
        return i;

    }
    
    else
    {
        return -1;
    }
}


int buscaBinariaRecursiva(int *numeros, int esquerda, int direita, int num)
{
    if (esquerda <= direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        if (numeros[meio] == num)
        {
            return meio;
        }

        if (numeros[meio] < num)
        {
            return buscaBinariaRecursiva(numeros, meio + 1, direita, num);
        }
        else
        {
            return buscaBinariaRecursiva(numeros, esquerda, meio - 1, num);
        }
    }

    return -1;
}


