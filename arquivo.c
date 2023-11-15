#include "blb.h"

void interageArquivos(){
        
    char nomeArquivo[] = "numeros.txt";
    int numeros[100];
    int quantidade;
    FILE *arquivo = NULL; //Declaração da variável arquivo
    int opcao;


        printf("\nO que deseja fazer com os arquivos?:\n");
        printf("1. Adicionar números\n");
        printf("2. Limpar arquivos\n");
        printf("0. Sair\n");
        
        scanf("%d", &opcao);
        
        switch(opcao){
        
    case 1:
            {
                int novaQuantidade, novoNumero;
                
                printf("Informe a quantidade de números que deseja adicionar ao arquivo:\n ");
                scanf("%d", &novaQuantidade);

                printf("Digite os números (um por linha):\n");

                for(int i = 0; i < novaQuantidade; i++){
                    scanf("%d", &novoNumero);

                    arquivo = fopen(nomeArquivo, "r");
                    int existe = 0;
                    int numLido;

                    if(arquivo != NULL){
                        while (fscanf(arquivo, "%d", &numLido) != EOF){
                            if (numLido == novoNumero) {
                                printf("\nO número %d já existe. Digite outro: ", novoNumero);
                                i--;
                                fclose(arquivo);
                                arquivo = NULL;
                                break;
                            }
                        }
                    }

                    if(existe != novoNumero){
                        arquivo = fopen(nomeArquivo, "a");
                        if (arquivo == NULL) {
                            printf("Erro! Não foi possível abrir o arquivo.\n");
                            return 1;
                        }
                        fprintf(arquivo, "%d\n", novoNumero);
                    }

                    if (arquivo != NULL) {
                        fclose(arquivo);
                        arquivo = NULL;
                    }
                }

                printf("Números adicionados com sucesso ao arquivo 'numeros.txt'.\n");
            }
            break;
            
            case 2: {
                
                int interacao;
                
                printf("Tem certeza de que deseja eliminar o conteúdo desse arquivo? Essa ação é irreversível.\n");
                printf(" 0 - Sim\n 1 - Não\n");
                scanf("%d", &interacao);
                
                        if(interacao == 0)
                        {
                            
                            limparArquivo(nomeArquivo);
                        
                        }
            }
                break;
                
            case 0:
            {
                printf("Saindo do programa.\n");
                return;
            }
            break;
                break;

            default:
                printf("Opção inválida.\n");
    
    

} 
    
    
    
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

void limparArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para limpeza.\n");
        return;
    }

    fclose(arquivo);

    printf("Conteúdo do arquivo '%s' foi limpo.\n", nomeArquivo);
}



