# Atividade6_ED1_ABB.c

Árvores Binárias de Busca (ABB) em C
====================================

Este projeto implementa uma árvore binária de busca (ABB) em linguagem C, permitindo operações básicas como inserção, remoção, impressão, busca por valores e cálculos diversos sobre os nós da árvore.

Objetivo
--------
O objetivo é praticar a manipulação de estruturas dinâmicas em C, utilizando uma ABB para armazenar números inteiros, e oferecer ao usuário um menu interativo para diversas operações sobre a árvore.

Funcionalidades
---------------
O programa apresenta um menu com as seguintes opções:

1. Inserir um valor: Insere um número inteiro na ABB respeitando as regras da ordenação.
2. Imprimir: Exibe os elementos da árvore em ordem crescente (percurso in-ordem).
3. Mostrar dados: Mostra:
   - A soma de todos os elementos da árvore
   - O maior valor armazenado
   - O menor valor armazenado
   - A quantidade de números pares na árvore
4. Remover menor valor: Remove o nó com o menor valor da árvore.
5. Contar valores maiores que X: Informa quantos nós possuem valores maiores que um número informado pelo usuário.
6. Remover árvore: Libera toda a memória alocada pela árvore.

Estrutura dos Dados
-------------------
A árvore é composta por nós da seguinte estrutura:

typedef struct No {
    int valor;
    struct No *esq;  // Filho à esquerda
    struct No *dir;  // Filho à direita
} No;

Compilação
----------
Para compilar e executar o programa em um terminal Linux ou via terminal no Windows com compilador GCC:

gcc -o arvore arvore.c
./arvore

Substitua 'arvore.c' pelo nome do arquivo em que você salvou o código.

Funções principais
------------------
- No* Inserir(No *raiz, int num): Insere um valor na ABB.
- void imprimir(No *raiz): Imprime a árvore in-ordem.
- int soma(No *raiz): Retorna a soma de todos os valores.
- int maiorValor(No *raiz): Retorna o maior valor armazenado.
- int menorValor(No *raiz): Retorna o menor valor armazenado.
- int calculaPar(No *raiz): Conta os nós com valores pares.
- No* removerMenorValor(No *raiz): Remove o menor valor da árvore.
- int valoresMaiores(No *raiz, int x): Conta quantos valores são maiores que x.
- void removerArvore(No *raiz): Libera todos os nós da memória.

Exemplo de uso
--------------
1 - Inserir
Digite um valor: 50

1 - Inserir
Digite um valor: 30

1 - Inserir
Digite um valor: 70

2 - Imprimir
30 50 70

3 - Mostrar dados
Soma = 150
Maior Valor = 70
Menor Valor = 30
Numeros de pares = 3

Licença
-------
Este projeto é de uso acadêmico e livre para modificações e aprendizado.
