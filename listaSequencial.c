#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <time.h>


#define TAM_MAX_NOME 100
#define TAMANHO_MAX_RG_STR  15
#define TAMANHO_MAX_LINHA   128
#define TAM_MAX_ARQUIVO 10000
#define CAPACIDADE_INICIAL 10

typedef struct
{
    char nome[TAM_MAX_NOME];
    long int rg;

}Pessoa;

Pessoa* carregarPessoas(const char* nomeArquivo, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade);
void inserirPessoaInicio(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade);
void inserirPessoaFim(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade);
void inserirPessoaNPosicao(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade);
void removerPessoaInicio(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes);
void removerPessoaFim(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes);
void removerPessoaNPosicao(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes);
void salvarPessoas(const char* nomeArquivo, Pessoa* lista, int quantidade, int *comparacoes, int* movimentacoes);
void procurarPessoa(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes);
void imprimirPessoas(Pessoa* lista, int quant, int* comparacoes, int* movimentacoes);
void imprimirPessoasOrdenacao(Pessoa* lista, int quant, int* comparacoes, int* movimentacoes);
void selectionSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes);
void insertionSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes);
void mergeSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes);
void merge(Pessoa* lista, int inicio, int meio, int fim,int* comparacoes,int* movimentacoes, double temp_execucao);
void buscaBinaria(Pessoa* lista,long int encontrarRG,int quantidade, int* comparacoes, int* movimentacoes);
void bubbleSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes);
void ShellSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes);
void trocar(Pessoa* elemento1, Pessoa* elemento2,int* comparacoes, int* movimentacoes);
int particao(Pessoa *lista, int inicio, int fim, int* comparacoes, int* movimentacoes);
void mergeSortRecurvivo(Pessoa* lista, int inicio, int fim,int* comparacoes, int* movimentacoes);
void quickSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes);
void quickSortRecursivo(Pessoa* lista, int inicio, int fim, int* comparacoes, int* movimentacoes);

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int num_comparacoes = 0,num_movimentacoes = 0;
    int opcaoOrdenacao = 0;
    int opcao = 0;
    long int buscarRg;
    int capacidade = CAPACIDADE_INICIAL;
    char nomeArquivo[TAM_MAX_ARQUIVO];
    Pessoa* minhaLista = NULL;
    int quantidade = 0;

    while(opcao!= 13 ){

        printf("     <<BEM-VINDO>> \n");
        printf("<< A LISTA DE CLIENTES >> \n");
        printf("       <<MENU>> \n");
        printf(" 1 - Inserção de um nó no início da lista. \n");
        printf(" 2 - Inserção de um nó no fim da lista. \n");
        printf(" 3 - Inserção de um nó na posição N. \n");
        printf(" 4 - Retirar um nó do início da lista. \n");
        printf(" 5 - Retirar um nó no fim da lista. \n");
        printf(" 6 - Retirar um nó na posição N. \n");
        printf(" 7 - Procurar um nome e RG. \n");
        printf(" 8 - Busca Binária \n");
        printf(" 9 - Mostrar a lista na tela. \n");
        printf(" 10 - Salvar a lista em um arquivo \n");
        printf(" 11 - Ler um arquivo. \n");
        printf(" 12 - Ordenar por RG\n");
        printf(" 13 - Sair do sistema. \n");

        printf("-----------------------------------\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                inserirPessoaInicio(&minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes,&capacidade);
                break;
            case 2:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                inserirPessoaFim(&minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes,&capacidade);
                break;
            case 3:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                inserirPessoaNPosicao(&minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes,&capacidade);
                break;
            case 4:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                removerPessoaInicio(minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes);
                break;
            case 5:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                removerPessoaFim(minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes);

                break;
            case 6:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                removerPessoaNPosicao(minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes);

                break;
            case 7:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                procurarPessoa(minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes);
                break;

            case 8:
                num_comparacoes = 0;
                num_movimentacoes = 0;

                printf("Digite o RG que deseja procurar: ");
                scanf("%ld", &buscarRg);

                buscaBinaria(minhaLista,buscarRg,quantidade,&num_comparacoes,&num_movimentacoes);
                break;

            case 9:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                imprimirPessoas(minhaLista,quantidade,&num_comparacoes,&num_movimentacoes);
                break;
            case 10:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                printf("Digite o nome do arquivo para salvar: ");
                getchar();
                fgets(nomeArquivo, TAM_MAX_ARQUIVO, stdin);
                nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

                salvarPessoas(nomeArquivo, minhaLista, quantidade,&num_comparacoes,&num_movimentacoes);
                printf("Lista salva com sucesso!\n");
                break;
            case 11:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                printf("Digite o nome do arquivo para ser lido: ");
                getchar();
                fgets(nomeArquivo, TAM_MAX_ARQUIVO, stdin);
                nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

                if (minhaLista != NULL)
                {
                    free(minhaLista);
                    minhaLista = NULL;
                }

                minhaLista = carregarPessoas(nomeArquivo, &quantidade, &num_comparacoes, &num_movimentacoes,&capacidade);

                if (minhaLista != NULL) {
                    printf("Arquivo carregado com sucesso!\n");
                }
                break;
            case 12:


                printf("1 - Ordenar por selection Sort\n");
                printf("2 - Ordenar por Insertion Sort\n");
                printf("3 - Ordenar por Marge Sort\n");
                printf("4 - Ordenar por Bubble Sort\n");
                printf("5 - Ordenar por Shell Sort\n");
                printf("6 - Ordenar por Quick Sort\n");
                scanf("%d",&opcaoOrdenacao);

                switch(opcaoOrdenacao)
                {
                    case 1:
                        num_comparacoes = 0;
                        num_movimentacoes = 0;
                        selectionSort(minhaLista,quantidade,&num_comparacoes,&num_movimentacoes);
                        break;
                    case 2:
                        num_comparacoes = 0;
                        num_movimentacoes = 0;
                        insertionSort(minhaLista,quantidade,&num_comparacoes,&num_movimentacoes);
                        break;
                    case 3:
                        num_comparacoes = 0;
                        num_movimentacoes = 0;
                        mergeSort(minhaLista,quantidade-1,&num_comparacoes,&num_movimentacoes);
                        break;
                    case 4:
                        num_comparacoes = 0;
                        num_movimentacoes = 0;
                        bubbleSort(minhaLista,quantidade,&num_comparacoes,&num_movimentacoes);
                        break;
                    case 5:
                        num_comparacoes = 0;
                        num_movimentacoes = 0;
                        ShellSort(minhaLista,quantidade,&num_comparacoes,&num_movimentacoes);
                        break;
                    case 6:
                        num_comparacoes = 0;
                        num_movimentacoes = 0;
                        quickSort(minhaLista,quantidade-1,&num_comparacoes,&num_movimentacoes);
                        break;
                }

                break;
            case 13:
                free(minhaLista);
                exit(0);
                break;
        }
    }
    return 0;
}

Pessoa* carregarPessoas(const char* nomeArquivo, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade)
{
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro: Não foi possível abrir %s\n", nomeArquivo);
        return NULL;
    }


    int total_linhas = 0;
    char linha[TAMANHO_MAX_LINHA];

    while (fgets(linha, sizeof(linha), arquivo)) {
        char nome_temp[TAM_MAX_NOME];
        char rg_temp[TAMANHO_MAX_RG_STR];


        if (sscanf(linha, "%99[^,],%14s", nome_temp, rg_temp) == 2) {
            total_linhas++;
        }
    }

    rewind(arquivo);

    if (total_linhas > *capacidade) {
        *capacidade = total_linhas + 10;
    }


    Pessoa* lista = (Pessoa*)malloc((*capacidade) * sizeof(Pessoa));
    if (lista == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        fclose(arquivo);
        return NULL;
    }

    int cont = 0;


    while (fgets(linha, sizeof(linha), arquivo) && cont < *capacidade) {
        char nome_temp[TAM_MAX_NOME];
        char rg_temp[TAMANHO_MAX_RG_STR];

        (*comparacoes)++;

        if (sscanf(linha, "%99[^,],%14[^\n]", nome_temp, rg_temp) == 2) {

            nome_temp[strcspn(nome_temp, "\n")] = '\0';
            rg_temp[strcspn(rg_temp, "\n")] = '\0';


            strncpy(lista[cont].nome, nome_temp, TAM_MAX_NOME - 1);
            lista[cont].nome[TAM_MAX_NOME - 1] = '\0';

            lista[cont].rg = atol(rg_temp);

            (*movimentacoes)++;
            cont++;
        }
    }

    fclose(arquivo);
    *quantidade = cont;
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Carregados %d registros de %s\n", cont, nomeArquivo);
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);

    return lista;
}

void inserirPessoaInicio(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade)
{
    clock_t inicio, fim;
    double tempo_execucao;
    int i;

    inicio = clock();


    if (*quantidade >= *capacidade) {
        (*comparacoes)++;
        *capacidade*=2;
        *lista = realloc(*lista, (*capacidade) * sizeof(Pessoa));
        if (*lista == NULL) {
            perror("Erro ao realocar memória");
            exit(1);
        }
    }

    Pessoa novaPessoa;
    printf("Digite o nome: ");
    getchar();
    fgets(novaPessoa.nome, TAM_MAX_NOME, stdin);
    novaPessoa.nome[strcspn(novaPessoa.nome, "\n")] = '\0';

    printf("Digite o RG: ");
    scanf("%ld", &novaPessoa.rg);


    for (i = *quantidade; i > 0; i--) {
        (*comparacoes)++;
        (*lista)[i] = (*lista)[i-1];
        (*movimentacoes)++;
    }


    (*lista)[0] = novaPessoa;
    (*movimentacoes)++;

    (*quantidade)++;
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nFoi inserido %s, RG %ld na posição %d da lista.\n", novaPessoa.nome, novaPessoa.rg, 1);
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("\n");
}

void imprimirPessoas(Pessoa* lista, int quant, int* comparacoes,int* movimentacoes)
{
    int i;
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();

    printf("--- Lista de Pessoas ---\n\n");
     if (quant == 0) {
        (*comparacoes)++;
        printf("Nenhuma pessoa para exibir.\n");
        return ;
     }

     for (i = 0; i < quant; i++) {
        (*comparacoes)++;
        printf("%d Nome: %s\n",i+1, lista[i].nome);
        printf("RG:   %ld\n", lista[i].rg);
        printf("-----------------------------------\n");
     }
    fim = clock();
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("C(n) = %d comparações feitas.\n", *comparacoes);
    printf("M(n) = %d movimentações feitas.\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("\n");


}

void inserirPessoaFim(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade)
{
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();


    if (*quantidade >= *capacidade) {
        (*comparacoes)++;
        *capacidade *= 2;
        *lista = realloc(*lista, (*capacidade) * sizeof(Pessoa));
        if (*lista == NULL) {
            perror("Erro ao realocar memória");
            exit(1);
        }
    }

    Pessoa novaPessoa;
    printf("Digite o nome: ");
    getchar();
    fgets(novaPessoa.nome, TAM_MAX_NOME, stdin);
    novaPessoa.nome[strcspn(novaPessoa.nome, "\n")] = '\0';

    printf("Digite o RG: ");
    scanf("%ld", &novaPessoa.rg);


    (*lista)[*quantidade] = novaPessoa;
    (*movimentacoes)++;

    (*quantidade)++;
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nFoi inserido a pessoa: %s, RG: %ld na posição %d da lista.\n", novaPessoa.nome, novaPessoa.rg, *quantidade);
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("\n");

}
void inserirPessoaNPosicao(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade)
{
    int posicao;
    clock_t inicio, fim;
    double tempo_execucao;
    int i;

    inicio = clock();

    if (*quantidade >= *capacidade) {
        (*comparacoes)++;
        *capacidade *= 2;
        *lista = realloc(*lista, (*capacidade) * sizeof(Pessoa));
        if (*lista == NULL) {
            perror("Erro ao realocar memória");
            exit(1);
        }
    }

    printf("Digite a posição (1 a %d) onde deseja inserir: ", *quantidade);
    scanf("%d", &posicao);
    posicao-=1;

    if (posicao < 0 || posicao > *quantidade) {
        printf("Posição inválida!\n");
        return;
    }

    Pessoa novaPessoa;
    printf("Digite o nome: ");
    getchar();
    fgets(novaPessoa.nome, TAM_MAX_NOME, stdin);
    novaPessoa.nome[strcspn(novaPessoa.nome, "\n")] = '\0';

    printf("Digite o RG: ");
    scanf("%ld", &novaPessoa.rg);


    for (i = *quantidade; i > posicao; i--) {
        (*comparacoes)++;
        (*lista)[i] = (*lista)[i-1];
        (*movimentacoes)++;
    }


    (*lista)[posicao] = novaPessoa;
    (*movimentacoes)++;

    (*quantidade)++;
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Foi inserido a pessoa: %s, RG:  %ld na posição %d da lista.\n", novaPessoa.nome, novaPessoa.rg, posicao+1);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("\n");

}
void removerPessoaInicio(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;
    int i;

    if(*quantidade == 0)
    {
        (*comparacoes)++;
        printf("Lista está vazia");
        return;
    }

    inicio = clock();

    Pessoa remover = (lista)[0];

    for(i = 1; i < *quantidade; i++)
    {
        (*comparacoes)++;
        (lista)[i-1] = (lista)[i];
        (*movimentacoes)++;

    }

    (*quantidade)--;

    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Removido o nó de início com sucesso... Nome: %s e RG: %ld\n",remover.nome,remover.rg);
    printf("C(n) = %d comparações \n", *comparacoes);
    printf("M(n) = %d movimentações \n", *movimentacoes);
    printf("Tempo de execução = %.6f", tempo_execucao);
    printf("\n");

}
void removerPessoaFim(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;
    int i;

    if(*quantidade == 0)
    {
        (*comparacoes)++;
        printf("Lista está vazia");
        return;
    }

    inicio = clock();

    Pessoa remover = (lista)[*quantidade-1];
    (*movimentacoes)++;

    (*quantidade)--;
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Removido o nó do fim com sucesso... Nome: %s e RG: %ld\n",remover.nome,remover.rg);
    printf("C(n) = %d comparações \n", *comparacoes);
    printf("M(n) = %d movimentações \n", *movimentacoes);
    printf("Tempo de execução = %.6f", tempo_execucao);
    printf("\n");

}
void removerPessoaNPosicao(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes)
{
    int posicao;
    clock_t inicio, fim;
    double tempo_execucao;
    int i;

    inicio = clock();

    printf("Digite a posição (1 a %d) onde deseja remover: ", *quantidade);
    scanf("%d", &posicao);
    posicao-=1;

    if (posicao < 0 || posicao >= *quantidade) {
        printf("Posição inválida!\n");
        return;
    }
       inicio = clock();

    Pessoa remover = (lista)[posicao];
    (*movimentacoes)++;

    for (i = posicao; i < *quantidade-1; i++) {
        (*comparacoes)++;
        (lista)[i] = (lista)[i+1];
        (*movimentacoes)++;
    }




    (*quantidade)--;
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Removido o nó da posicao %d com sucesso... Nome: %s e RG: %ld\n", posicao+1,remover.nome,remover.rg);
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("\n");

}
void procurarPessoa(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes)
{
    long int rgPessoa = 0;
    char nomePessoa[TAM_MAX_NOME];
    int encontrou = 0;
    clock_t inicio, fim;
    double tempo_execucao;
    if(*quantidade == 0)
    {
        printf("Não nenhum dado.");
        return;
    }

    inicio = clock();

    printf("Digite o nome da pessoa que busca procurar: ");
    getchar();
    fgets(nomePessoa, TAM_MAX_NOME, stdin);
    nomePessoa[strcspn(nomePessoa, "\n")] = '\0';

    printf("Digite o RG de quem busca procurar: ");
    scanf("%ld",&rgPessoa);


    for (int i = 0; i < *quantidade; i++) {
        (*comparacoes)++;
        if (lista[i].rg == rgPessoa && strcmp(lista[i].nome, nomePessoa) == 0)
            {
                printf("Encontrado na posição %d: Nome: %s | RG: %ld\n", i+1, lista[i].nome, lista[i].rg);
                encontrou = 1;
            }
        }

        if(!encontrou)
        {
            printf("Pessoa não encontrada!\n");
        }
        fim = clock();

        tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
        printf("C(n) = %d comparações\n", *comparacoes);
        printf("M(n) = %d movimentações\n", *movimentacoes);
        printf("Tempo de execução = %.6f segundos\n", tempo_execucao);



}

void salvarPessoas(const char* nomeArquivo, Pessoa* lista, int quantidade, int *comparacoes, int* movimentacoes) {
    clock_t inicio, fim;
    double tempo_execucao;

    if (quantidade == 0) {
        printf("Lista vazia!\n");
        return;
    }

    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar %s\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        (*comparacoes)++;
        fprintf(arquivo, "%s,%ld\n", lista[i].nome, lista[i].rg);
    }

    fclose(arquivo);
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Salvo: %d registros em %s\n", quantidade, nomeArquivo);
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
}
void selectionSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes)
{
    int i,j;
    clock_t inicio,fim;
    double tempo_execucao;

    inicio = clock();
    for(i = 0; i < quantidade - 1; i++)
    {
        int indice_menor = i; // indece que vai ser verificado por todos elementos a frente dele


        for(j = i + 1;j < quantidade; j++)
        {
            (*comparacoes)++;
            if(lista[j].rg < lista[indice_menor].rg)//comparação do menor RG
            {
                (*comparacoes)++;
                indice_menor = j;

            }
        }

        if(indice_menor != i)
        {
            (*comparacoes)++;
            Pessoa copia = lista[i];
            lista[i] = lista[indice_menor];
            lista[indice_menor] = copia;
            (*movimentacoes) += 3;

        }


    }
    fim = clock();



    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Ordenação feita por Selection Sort com sucesso!!\n");
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("Impressão da lista alterada segue a seguir!!\n ");

}
void insertionSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;
    int i, j;
    Pessoa copia;
    inicio = clock();
    for(i = 1; i < quantidade; i++)
    {
        copia = lista[i];
        (*movimentacoes)++;

        j = i - 1;

        while(j >= 0 && lista[j].rg > copia.rg)
        {
            (*comparacoes)++;
            lista[j + 1] = lista[j];
            (*movimentacoes)++;
            j--;
        }
        if(j >= 0) (*comparacoes)++;

        lista[j+1] = copia;
        (*movimentacoes)++;

    }
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Ordenação feita por Insertion Sort com sucesso!!\n");
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("Impressão da lista alterada segue a seguir!!\n ");


}
void mergeSortRecursivo(Pessoa* lista, int inicio, int fim,int* comparacoes, int* movimentacoes)
{

    double tempo_execucao;

    clock_t inicioT,fimT;
    inicioT = clock();
    int meio;
    if(inicio < fim)
    {
        (*comparacoes)++;
        meio = floor((inicio+fim)/2);
        mergeSortRecursivo(lista,inicio, meio,comparacoes, movimentacoes);
        mergeSortRecursivo(lista,meio+1,fim,comparacoes, movimentacoes);

        fimT = clock();
        tempo_execucao = (double)(fimT - inicioT) / CLOCKS_PER_SEC;
        merge(lista, inicio, meio, fim,comparacoes, movimentacoes,tempo_execucao);
    }




}
void mergeSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes)
{
    clock_t inicioT, fimT;
    double tempo_execucao;

    inicioT = clock();

    mergeSortRecursivo(lista, 0, quantidade - 1, comparacoes, movimentacoes);

    fimT = clock();
    tempo_execucao = (double)(fimT - inicioT) / CLOCKS_PER_SEC;

    printf("\nOrdenação feita por Merge Sort com sucesso!!\n");
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("Impressão da lista alterada segue a seguir!!\n");
}
void merge(Pessoa* lista, int inicio, int meio, int fim,int* comparacoes, int* movimentacoes, double temp_execucao)
{
    clock_t inicioT,fimT;
    double parte2_temp_execucao;
    int p1, p2, tamanho, i,j,k;
    Pessoa* temp;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (Pessoa *) malloc(tamanho*sizeof(Pessoa));
    if(temp != NULL)
    {
        for(i = 0; i< tamanho;i++)
        {
            (*comparacoes)++;
            if(!fim1 && !fim2)
            {
                if(lista[p1].rg < lista[p2].rg)
                {
                    temp[i] = lista[p1++];
                    (*comparacoes)++;
                    (*movimentacoes)++;

                }
                else
                {
                    temp[i] = lista[p2++];
                    (*movimentacoes)++;
                }


                if(p1>meio)
                {
                    (*comparacoes)++;
                    fim1=1;
                }

                if(p2>fim)
                {
                    (*comparacoes)++;
                    fim2=1;
                }
            }
            else
            {
                if(!fim1)
                {
                    (*comparacoes)++;
                    temp[i] = lista[p1++];
                    (*movimentacoes)++;
                }
                else
                {
                    (*comparacoes)++;
                    temp[i] = lista[p2++];
                    (*movimentacoes)++;
                }


            }

        }
        for(j = 0, k = inicio; j < tamanho; j++,k++)
        {
            (*comparacoes)++;
            lista[k] = temp[j];
            (*movimentacoes)++;
        }

    }
    free(temp);



}

void buscaBinaria(Pessoa* lista,long int encontrarRG,int quantidade, int* comparacoes, int* movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;
    int esquerda = 0,direita = quantidade-1;

    while(esquerda <= direita)
    {
        (*comparacoes)++;
        int media = (esquerda+ direita)/2;

        if(lista[media].rg == encontrarRG )
        {
            (*comparacoes)++;
            printf("Achamos %s do RG %ld na posição %d \n",lista[media].nome,lista[media].rg, media+1);
            break;
        }



        if (lista[media].rg < encontrarRG) {
            (*comparacoes)++;
            esquerda = media + 1;
        } else {
            (*comparacoes)++;
            direita = media - 1;
        }
    }
    tempo_execucao = ((double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("Busca binária feita com sucesso!!\n");
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);

}

void bubbleSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes)
{
    int i,j;
    Pessoa copia;
    int trocou;
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    for(i = 0; i < quantidade - 1;i++)
    {
        trocou = 0;

        for(j = 0;j < quantidade - i - 1;j++)
        {
            (*comparacoes)++;
            if(lista[j].rg > lista[j+1].rg)
            {
                (*comparacoes)++;
                copia = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = copia;
                (*movimentacoes)+=3;
                trocou = 1;
            }
        }

        if (trocou == 0) {
            break;
        }
    }
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Ordenação feita por Bubble Sort com sucesso!!\n");
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("Impressão da lista alterada segue a seguir!!\n ");

}

void ShellSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes)
{
    clock_t inicio,fim;
    double tempo_execucao;

    inicio = clock();
    for (int gap = quantidade / 2; gap > 0; gap /= 2) {
        (*comparacoes)++;
        for (int i = gap; i < quantidade; i++) {
            (*comparacoes)++;

            Pessoa copia = lista[i];
            (*movimentacoes)++;

            int j;
            for (j = i; j >= gap && lista[j - gap].rg > copia.rg; j -= gap) {
                (*comparacoes)++;
                lista[j] = lista[j - gap];
                (*movimentacoes)++;
            }


            lista[j] = copia;
            (*movimentacoes)++;
        }
    }
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Ordenação feita por Shell Sort com sucesso!!\n");
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("Impressão da lista alterada segue a seguir!!\n ");

}


void trocar(Pessoa* elemento1, Pessoa* elemento2, int* comparacoes, int* movimentacoes)
{
    Pessoa temporario = *elemento1;
    *elemento1 = *elemento2;
    *elemento2 = temporario;
    (*movimentacoes) += 3;
}

int particao(Pessoa* lista, int inicio, int fim, int* comparacoes, int* movimentacoes)
{
    Pessoa pivo = lista[fim];
    int i = inicio - 1;

    for (int j = inicio; j <= fim - 1; j++)
    {
        (*comparacoes)++;
        if (lista[j].rg < pivo.rg)
        {
            i++;
            trocar(&lista[i], &lista[j], comparacoes, movimentacoes);
        }
    }

    trocar(&lista[i + 1], &lista[fim], comparacoes, movimentacoes);
    return (i + 1);
}

void quickSortRecursivo(Pessoa* lista, int inicio, int fim, int* comparacoes, int* movimentacoes)
{
    if (inicio < fim)
    {
        (*comparacoes)++;
        int pi = particao(lista, inicio, fim, comparacoes, movimentacoes);

        quickSortRecursivo(lista, inicio, pi - 1, comparacoes, movimentacoes);
        quickSortRecursivo(lista, pi + 1, fim, comparacoes, movimentacoes);
    }
}

void quickSort(Pessoa* lista, int quantidade, int* comparacoes, int* movimentacoes)
{
    clock_t inicioTempo, fimTempo;
    double tempo_execucao;

    inicioTempo = clock();

    quickSortRecursivo(lista, 0, quantidade - 1, comparacoes, movimentacoes);

    fimTempo = clock();
    tempo_execucao = (double)(fimTempo - inicioTempo) / CLOCKS_PER_SEC;

    printf("\nOrdenação feita por Quick Sort com sucesso!!\n");
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("Impressão da lista alterada segue a seguir!!\n");
}

