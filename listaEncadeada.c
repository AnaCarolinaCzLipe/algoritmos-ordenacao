#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define TAM_MAX_NOME 100
#define TAMANHO_MAX_RG_STR  15
#define TAMANHO_MAX_LINHA   128
#define TAM_MAX_ARQUIVO 10000
#define CAPACIDADE_INICIAL 10

typedef struct Pessoa{
    char nome[TAM_MAX_NOME];
    long int rg;
    struct Pessoa* prox;
} Pessoa;
void inserirPessoaInicio(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes);
void inserirPessoaFim(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes);
void inserirPessoaNPosicao(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes);
void removerPessoaInicio(Pessoa **lista, int *quantidade, int *comparacoes, int *movimentacoes);
void removerPessoaFim(Pessoa **lista, int *quantidade, int *comparacoes, int *movimentacoes);
void removerPessoaNPosicao(Pessoa** lista,int *quantidade,int posicao, int* comparacoes, int* movimentacoes);
void procurarPessoa(const char* nomeArquivo,Pessoa* lista, int* comparacoes, int* movimentacoes);
void salvarPessoas(const char* nomeArquivo, Pessoa* lista, int* comparacoes, int* movimentacoes);
void imprimirPessoas(Pessoa* lista, int quant, int* comparacoes, int* movimentacoes);
Pessoa* carregarPessoas(const char* nomeArquivo, int* quantidade, int* comparacoes, int* movimentacoes);
void selectionSort(Pessoa* lista, int* comparacoes, int* movimentacoes);
void liberarLista(Pessoa* lista);


int main()
{
    setlocale(LC_ALL, "Portuguese");

    int num_comparacoes = 0,num_movimentacoes = 0;

    int opcao = 0;
    int capacidade = CAPACIDADE_INICIAL;
    char nomeArquivo[TAM_MAX_ARQUIVO];
    Pessoa* minhaLista;
    int quantidade = 0;
    int posicao = 0;

    minhaLista = NULL;




    while(opcao!= 12 ){

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
        printf(" 8 - Mostrar a lista na tela. \n");
        printf(" 9 - Salvar a lista em um arquivo \n");
        printf(" 10 - Ler um arquivo. \n");
        printf(" 11 - Ordenar em Selection sort. \n");
        printf(" 12 - Sair do sistema. \n");

        printf("-----------------------------------\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                inserirPessoaInicio(&minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes);
                break;
            case 2:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                inserirPessoaFim(&minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes);
                break;
            case 3:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                inserirPessoaNPosicao(&minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes);
                break;
            case 4:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                removerPessoaInicio(&minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes);
                break;
            case 5:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                removerPessoaFim(&minhaLista,&quantidade,&num_comparacoes,&num_movimentacoes);

                break;
            case 6:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                printf("Digite a posição que deseja remover: posicão de 1 a %d ",quantidade);
                scanf("%d",&posicao);
                removerPessoaNPosicao(&minhaLista,&quantidade,posicao,&num_comparacoes,&num_movimentacoes);

                break;
            case 7:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                procurarPessoa(nomeArquivo,minhaLista,&num_comparacoes,&num_movimentacoes);
                break;

            case 8:
                num_comparacoes = 0;
                num_movimentacoes = 0;

                imprimirPessoas(minhaLista,quantidade,&num_comparacoes,&num_movimentacoes);
                break;
            case 9:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                printf("Digite o nome do arquivo para salvar: ");
                getchar();
                fgets(nomeArquivo, TAM_MAX_ARQUIVO, stdin);
                nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

                salvarPessoas(nomeArquivo, minhaLista, &num_comparacoes, &num_movimentacoes);
                printf("Lista salva com sucesso!\n");
                break;
            case 10:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                printf("Digite o nome do arquivo para ser lido: ");
                getchar();
                fgets(nomeArquivo, TAM_MAX_ARQUIVO, stdin);
                nomeArquivo[strcspn(nomeArquivo, "\n")] = '\0';

                minhaLista = carregarPessoas(nomeArquivo, &quantidade,&num_comparacoes,&num_movimentacoes);

                if (minhaLista != NULL) {
                    printf("Arquivo carregado com sucesso!\n");
                }
                break;
            case 11:
                num_comparacoes = 0;
                num_movimentacoes = 0;
                selectionSort(minhaLista, &num_comparacoes, &num_movimentacoes);
                imprimirPessoas(minhaLista, quantidade, &num_comparacoes, &num_movimentacoes);

                break;
            case 12:
                liberarLista(minhaLista);
                exit(0);
                break;
        }
    }

    return 0;
}
Pessoa* carregarPessoas(const char* nomeArquivo, int* quantidade, int* comparacoes, int* movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();

    FILE *ponteiroDoArquivo = fopen(nomeArquivo, "r");

    if (ponteiroDoArquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return NULL;
    }

    Pessoa* lista = NULL;
    Pessoa* ultimo = NULL;
    char linha[TAMANHO_MAX_LINHA];
    int cont = 0;

    while (fgets(linha, sizeof(linha), ponteiroDoArquivo)) {
        (*comparacoes)++;
        char nome_temp[TAM_MAX_NOME];
        char rg_string_temp[TAMANHO_MAX_RG_STR];

        if (sscanf(linha, "%99[^,],%14s", nome_temp, rg_string_temp) == 2) {
            (*comparacoes)++;
            Pessoa* novo = (Pessoa*) malloc(sizeof(Pessoa));
            if (novo == NULL)
            {
                perror("Erro ao alocar memória");
                fclose(ponteiroDoArquivo);
                liberarLista(lista);
                return NULL;
            }
            strcpy(novo->nome, nome_temp);
            novo->rg = atol(rg_string_temp);
            novo->prox = NULL;
            (*movimentacoes)++;

            if (lista == NULL) {
                (*comparacoes)++;
                lista = novo;
                (*movimentacoes)++;
            } else {
                ultimo->prox = novo;
                (*movimentacoes)++;

            }
            ultimo = novo;
            (*movimentacoes)++;
            cont++;
        }
    }

    fclose(ponteiroDoArquivo);
    *quantidade = cont;

    fim= clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Carregados %d registros de %s\n", cont, nomeArquivo);
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);

    return lista;
}

void imprimirPessoas(Pessoa* lista, int quant, int* comparacoes, int* movimentacoes) {
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();
    printf("--- Lista de Pessoas ---\n\n");
    if (quant == 0) {
        printf("Nenhuma pessoa para exibir.\n");
        return;
    }

    int i = 1;
    for (Pessoa* aux = lista; aux != NULL; aux = aux->prox){
        (*comparacoes)++;
        printf("%d Nome: %s\n", i, aux->nome);
        printf("RG:   %ld\n", aux->rg);
        printf("-----------------------------------\n");
        i++;
    }
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
}

void liberarLista(Pessoa* lista) {
    Pessoa* aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}
void inserirPessoaInicio(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;
    int i;

    inicio = clock();


    Pessoa *novaPessoa;
    novaPessoa = malloc(sizeof(Pessoa));
    if(novaPessoa)
    {
        printf("Digite o nome: ");
        getchar();
        fgets(novaPessoa->nome, TAM_MAX_NOME, stdin);
        novaPessoa->nome[strcspn(novaPessoa->nome, "\n")] = '\0';

        printf("Digite o RG: ");
        scanf("%ld", &novaPessoa->rg);


        novaPessoa->prox = *lista;
        *lista = novaPessoa;
        (*movimentacoes)++;

        (*quantidade)++;

    }else
    {
        printf("Erro de alocar na memória");
    }

    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nFoi inserido %s, RG %ld na posição %d da lista.\n", novaPessoa->nome, novaPessoa->rg, 1);
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("\n");
}
void inserirPessoaFim(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();


    Pessoa *novaPessoa,*copia;
    novaPessoa = malloc(sizeof(Pessoa));

    if(novaPessoa)
    {
        printf("Digite o nome: ");
        getchar();
        fgets(novaPessoa->nome, TAM_MAX_NOME, stdin);
        novaPessoa->nome[strcspn(novaPessoa->nome, "\n")] = '\0';

        printf("Digite o RG: ");
        scanf("%ld", &novaPessoa->rg);

        (*comparacoes)++;
        novaPessoa->prox = NULL;
        if(*lista == NULL)
        {
            (*comparacoes)++;
            *lista = novaPessoa;
            (*movimentacoes)++;
        }
        else
        {
            copia = *lista;
            (*movimentacoes)++;
            while(copia->prox)
            {
                (*comparacoes)++;
                copia = copia->prox;
                (*movimentacoes)++;
            }

            copia->prox = novaPessoa;
            (*movimentacoes)++;

        }
    }
    else
    {
        printf("Erro de alocar na memória");
    }

    (*quantidade)++;
    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nFoi inserido a pessoa: %s, RG: %ld na posição %d da lista.\n", novaPessoa->nome, novaPessoa->rg, *quantidade);
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("\n");

}
void inserirPessoaNPosicao(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes)
{
    int posicao;
    clock_t inicio, fim;
    double tempo_execucao;
    int i;

    inicio = clock();


    printf("Digite a posição (1 a %d) onde deseja inserir: ", *quantidade);
    scanf("%d", &posicao);


    if (posicao < 1 || posicao > (*quantidade) + 1) {
        printf("Posição inválida!\n");
        return;
    }

    if (posicao == 1) {
        inserirPessoaInicio(lista, quantidade, comparacoes, movimentacoes);
        return;
    }


    if (posicao == (*quantidade) + 1) {
        inserirPessoaFim(lista, quantidade, comparacoes, movimentacoes);
        return;
    }

    Pessoa *novaPessoa,*copia;
    novaPessoa = malloc(sizeof(Pessoa));
    if(novaPessoa)
    {
        (*comparacoes)++;
        printf("Digite o nome: ");
        getchar();
        fgets(novaPessoa->nome, TAM_MAX_NOME, stdin);
        novaPessoa->nome[strcspn(novaPessoa->nome, "\n")] = '\0';

        printf("Digite o RG: ");
        scanf("%ld", &novaPessoa->rg);

        if(*lista == NULL)
        {
            (*comparacoes)++;
            novaPessoa->prox = NULL;
            *lista = novaPessoa;
            (*movimentacoes)++;
        }
        else
        {
            copia = *lista;
            (*movimentacoes)++;
            for (int i = 1; i <= posicao - 2; i++) {
                copia = copia->prox;
                (*movimentacoes)++;
                (*comparacoes)++;
                if (copia == NULL) { // cheque de segurança
                    printf("Erro: posição inválida durante percurso.\n");
                    free(novaPessoa);
                    return;
                }
            }



            novaPessoa->prox = copia->prox;
            copia->prox = novaPessoa;
            (*movimentacoes)++;
            (*quantidade)++;
        }
    }
    else
    {
        printf("Erro de alocar na memória");

    }

    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("C(n) = %d comparações\n", *comparacoes);
    printf("M(n) = %d movimentações\n", *movimentacoes);
    printf("Foi inserido a pessoa: %s, RG:  %ld na posição %d da lista.\n", novaPessoa->nome, novaPessoa->rg, posicao);
    printf("Tempo de execução = %.6f segundos\n", tempo_execucao);
    printf("\n");

}
void removerPessoaInicio(Pessoa **lista, int *quantidade, int *comparacoes, int *movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;
    int i;

    inicio = clock();

    if(*lista == NULL)
    {
        printf("Erro: Lista vazia!\n");
        return;
    }

    Pessoa *remover = *lista;
    *lista = remover->prox;
    (*movimentacoes)++;

    printf("Removido o nó do início com sucesso... Nome: %s e RG: %ld\n",remover->nome,remover->rg);

    free(remover);
    (*quantidade)--;

    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("C(n) = %d comparações \n", *comparacoes);
    printf("M(n) = %d movimentações \n", *movimentacoes);
    printf("Tempo de execução = %.6f", tempo_execucao);
    printf("\n");


}
void removerPessoaFim(Pessoa **lista, int *quantidade, int *comparacoes, int *movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;
    int i;

    inicio = clock();

    if(*lista == NULL)
    {
        (*comparacoes)++;
        printf("Lista vazia, não tem o que remover. \n");
        return;
    }

    if((*lista)->prox == NULL)
    {
        printf("Removido o nó do fim com sucesso... Nome: %s e RG: %ld\n",(*lista)->nome,(*lista)->rg);
        (*comparacoes)++;
        free(*lista);
        *lista = NULL;
        (*movimentacoes)++;
        return;
    }

    Pessoa *copia = *lista;
    (*movimentacoes)++;
    while(copia->prox->prox != NULL)
    {
        (*comparacoes)++;
        copia = copia->prox;
        (*movimentacoes)++;
    }

    printf("Removido o nó do fim com sucesso... Nome: %s e RG: %ld\n",copia->prox->nome,copia->prox->rg);
    free(copia->prox);
    copia->prox = NULL;
    (*quantidade)--;
    (*movimentacoes)++;

    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;


    printf("C(n) = %d comparações \n", *comparacoes);
    printf("M(n) = %d movimentações \n", *movimentacoes);
    printf("Tempo de execução = %.6f", tempo_execucao);
    printf("\n");

}
void removerPessoaNPosicao(Pessoa** lista,int *quantidade,int posicao, int* comparacoes, int* movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;

    inicio = clock();

    if (*lista == NULL) {
        printf("Lista vazia, não há nada a remover!\n");
        return;
    }

    if (posicao < 1 || posicao > *quantidade) {
        printf("Posição inválida!\n");
        return;
    }


    if (posicao == 1) {
        removerPessoaInicio(lista, quantidade, comparacoes, movimentacoes);
        return;
    }


    if (posicao == *quantidade) {
        removerPessoaFim(lista, quantidade, comparacoes, movimentacoes);
        return;
    }


    Pessoa *anterior = *lista;
    (*movimentacoes)++;

    for (int i = 1; i <= posicao - 2; i++) {
        if (anterior == NULL) {
            printf("Posição inválida durante percurso.\n");
            return;
        }
        anterior = anterior->prox;
        (*movimentacoes)++;
        (*comparacoes)++;
    }

    if (anterior == NULL || anterior->prox == NULL) {
        printf("Posição inválida.\n");
        return;
    }

    Pessoa *remover = anterior->prox;
    anterior->prox = remover->prox;
    printf("Removido o nó da posição %d com sucesso... Nome: %s e RG: %ld\n", posicao, remover->nome, remover->rg);

    free(remover);
    (*quantidade)--;
    (*movimentacoes)++;

    fim = clock();
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("C(n) = %d comparações \n", *comparacoes);
    printf("M(n) = %d movimentações \n", *movimentacoes);
    printf("Tempo de execução = %.6f\n", tempo_execucao);
}

void procurarPessoa(const char* nomeArquivo,Pessoa* lista, int* comparacoes, int* movimentacoes)
{
    long int rgPessoa = 0;
    char nomePessoa[TAM_MAX_NOME];
    int encontrou = 0;
    clock_t inicio, fim;
    double tempo_execucao;
    int pos = 1;

    inicio = clock();

    printf("Digite o nome da pessoa que busca procurar: ");
    getchar();
    fgets(nomePessoa, TAM_MAX_NOME, stdin);
    nomePessoa[strcspn(nomePessoa, "\n")] = '\0';

    printf("Digite o RG de quem busca procurar: ");
    scanf("%ld",&rgPessoa);

    Pessoa *atual = lista;
    (*movimentacoes)++;

    while(atual != NULL)
    {
        (*comparacoes)++;
        if(atual->rg == rgPessoa && strcmp(atual->nome, nomePessoa) == 0)
        {
            (*comparacoes)++;
            printf("Encontrado na posição %d: Nome: %s | RG: %ld\n", pos, atual->nome, atual->rg);
            encontrou = 1;
        }
        atual = atual->prox;
        (*movimentacoes)++;
        pos++;
    }

    fim = clock();

    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;


    printf("C(n) = %d comparações \n", *comparacoes);
    printf("M(n) = %d movimentações \n", *movimentacoes);
    printf("Tempo de execução = %.6f", tempo_execucao);
    printf("\n");


}
void salvarPessoas(const char* nomeArquivo, Pessoa* lista, int *comparacoes, int *movimentacoes)
{
    clock_t inicio, fim;
    double tempo_execucao;
    inicio = clock();
    FILE *ponteiroDoArquivo = fopen(nomeArquivo, "w");

    if (ponteiroDoArquivo == NULL) {
        (*comparacoes)++;
        perror("Erro ao abrir arquivo para escrita");
        return;
    }

    Pessoa *atual = lista;
    (*movimentacoes)++;
    while(atual != NULL)
    {
        (*comparacoes)++;
        fprintf(ponteiroDoArquivo, "%s,%ld\n", atual->nome, atual->rg);
        atual = atual->prox;
        (*movimentacoes)++;

    }

    fclose(ponteiroDoArquivo);
    fim = clock();
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Lista salva no arquivo '%s'\n", nomeArquivo);
    printf("C(n) = %d comparações \n", *comparacoes);
    printf("M(n) = %d movimentações \n", *movimentacoes);
    printf("Tempo de execução = %.6f", tempo_execucao);
    printf("\n");

}
void selectionSort(Pessoa* lista, int* comparacoes, int* movimentacoes)
{
    Pessoa *i,*j,*menor;
    clock_t inicio,fim;
    double tempo_execucao;





    inicio = clock();
    for(i = lista; i != NULL && i->prox != NULL; i = i->prox)
    {

        menor = i;

        for(j = i->prox; j != NULL; j = j->prox)
        {
            (*comparacoes)++;
            if(j->rg < menor->rg)
            {

                menor = j;
            }

        }

        if(menor != i)
        {
            (*comparacoes)++;
            char tempNome[TAM_MAX_NOME];
            long int tempRg;

            strcpy(tempNome,i->nome);
            tempRg = i->rg;

            strcpy(i->nome, menor->nome);
            i->rg = menor->rg;

            strcpy(menor->nome, tempNome);
            menor->rg = tempRg;
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



