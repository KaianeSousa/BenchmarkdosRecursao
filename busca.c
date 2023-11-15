#include "blb.h"

void interageBusca(){
    
       
      int opcao;  
      
      do{
          //Menu de operações
        printf("\nOperações Disponíveis:\n");
        printf("1. Busca Linear\n");
        printf("2. Busca Sentinela\n");
        printf("3. Busca Binária\n");
        printf("0. Retornar para o menu principal\n");
        
        scanf("%d", &opcao);
        
         switch (opcao) 
        {
            case 1: {
            
                int num;
                
                printf("Digite o número que deseja buscar: ");
                scanf("%d", &num);
                int posicao = buscaLinear(numeros, quantidade, num);
                if (posicao != -1) {
                    printf("Número encontrado na posição %d.\n", posicao);
                } else {
                    printf("Número não encontrado.\n");
                }
            }
            break;

            case 2:
            {
            
                int num;
                
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
            
            int num;
            
            printf("Digite o número que deseja buscar: ");
            scanf("%d", &num);
            
            int posicao = buscaBinariaRecursiva(numeros, 0, quantidade - 1, num);
                if (posicao != -1) 
                {
                    printf("Número encontradao na posição %d.\n", posicao);
                    
                }else{
                    
                    printf("Número não encontrado.\n");
                }
        }
            break;
            
            case 0: {
                
                     printf("Saindo do programa.\n");
            }//Falta o link de retorno pro código
                break;
                
                default:
                printf("Erro! Por favor, escolha uma das opções fornecidadas.\n");
        }
    
      }while(opcao !=0);
        
    
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


int buscaLinear(int *numeros, int quantidade, int num){
    
    for (int i = 0; i < quantidade; i++) 
    {
        if (numeros[i] == num) {
            return i;
        }
    }
    
    return -1;
}

int buscaSentinela(int *numeros, int quantidade, int num) 
{
    int last = numeros[quantidade - 1];
    numeros[quantidade - 1] = num;
    int i = 0;

    while (numeros[i] != num) 
    {
        i++;
    }

    numeros[quantidade - 1] = last;

    if (i < quantidade - 1 || numeros[quantidade - 1] == num) 
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

    
        
        
        
        


