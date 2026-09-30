# algoritmos-ordenacao

O código é uma lista sequencial que lê nome e RG dos usuários em lista. 

## Tecnologias
- IDE: codeblocks
- NomeRG10000.txt para leitura dos nomes e RG

## Descrição

O programa serve para implementar meios de ordenação de dados, a fim de uma análise crítica. Fazendo comparação de início e fim de tempo de execução, comparações e movimentações, assim é possível ter um estudo sobre qual algoritmo de ordenação é melhor para cada situação. 

Dessa forma, foi implementado um menu de opções e o usuário poderia decidir a ação que escolheria. Como: inserção, remoção, salvar, ordenar...

- O código possui implementação de inserção de inicio, meio e fim de dados novos
```
void inserirPessoaInicio(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade);
void inserirPessoaFim(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade);
void inserirPessoaNPosicao(Pessoa** lista, int* quantidade, int* comparacoes, int* movimentacoes, int* capacidade);
```
- O código possui implementação de remoção de inicio, meio e fim de dados novos
```
void removerPessoaInicio(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes);
void removerPessoaFim(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes);
void removerPessoaNPosicao(Pessoa* lista,int* quantidade, int* comparacoes, int* movimentacoes);
```
- Algoritmos de ordenação:
```
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
```
