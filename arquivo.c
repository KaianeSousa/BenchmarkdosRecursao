#include "blb.h" //Inclui o arquivo da biblioteca "blb.h"

//Função principal para interação com o arquivo
void interageArquivo(){

    char nomeArquivo[] = "numeros.txt"; //Nome do arquivo a ser lido
    int numeros[100]; //Array que armazenará os números a serem ordenados
    int quantidade; //Variável para armazenar a quantidade de números lidos
    FILE *arquivo = NULL; //Declaração da variável arquivo
    
    int opcao; //Variável para armazenar a escolha do usuário

        do{
         //Menu para interação com o arquivo
        printf("\nO que deseja fazer com o arquivo?:\n");
        printf("1. Adicionar números\n");
        printf("2. Limpar arquivos\n");
        printf("0. Sair\n");

        scanf("%d", &opcao); //Variável para a leitura da escolha do usuário

        switch(opcao){

    case 1: //Opção para adicionar números ao arquivo
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
                            return;
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

            case 2:  //Opção para limpar o conteúdo do arquivo
            {

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

            case 0: //Encerra essa função e volta para a anterior
            {
                printf("Saindo do programa...\n");
                return;
            }
                break;

            default:
                printf("Opção inválida.\n"); //Mensagem de opção inválida
         }
    
    }while(opcao != 0);

}

//Função para carregar números do arquivo para um array
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

//Função para limpar o conteúdo do arquivo
void limparArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para limpeza.\n");
        return;
    }

    fclose(arquivo);

    printf("Conteúdo do arquivo '%s' foi limpo.\n", nomeArquivo);
}
