#include<stdio.h>
#include<stdlib.h>

//Estrutura de um nó em uma árvore binária de busca
typedef struct No{
    int valor;
    struct No *esq;
    struct No *dir;
} No;
// Questão 1-a): Inserir um nó na árvore
No* Inserir(No *raiz, int num){
    if(raiz == NULL){
        No *aux = malloc(sizeof(No));
        aux->valor = num;
        aux->dir = NULL;
        aux->esq = NULL;
        return aux;
    }else{
        if(num < raiz->valor){
            raiz->esq = Inserir(raiz->esq, num);
        }else{
            raiz->dir = Inserir(raiz->dir, num);
        }
        return raiz;
    }
}
// Questão 1-c): Imprimir a árvore(InOrder)
void imprimir(No *raiz){
    if(raiz){
        imprimir(raiz->esq);
        printf("%d ", raiz->valor);
        imprimir(raiz->dir);
    }
}
// Questão 1-b): Soma o conteúdo dos nós da árvore
int soma(No *raiz){
    if(raiz==NULL){
       return 0;
    }
    return raiz ->valor + soma(raiz->esq) + soma(raiz->dir);
}
//Questão 1-d): Liberar e remover a arvore!!
void removerArvore(No *raiz){
    if(raiz){
        removerArvore(raiz->esq);
        removerArvore(raiz->dir);
        free(raiz);
    }
}

int maiorValor(No * raiz){
    if(raiz==NULL) return 0;
    No *atual = raiz;
    while(atual->dir != NULL){
        atual = atual ->dir;
    }
    return atual ->valor;
}

int menorValor(No * raiz){
    if(raiz==NULL) return 0;
    No *atual = raiz;
    while(atual->esq != NULL){
        atual = atual ->esq;
    }
    return atual ->valor;
}
int calculaPar(No * raiz){
    if(raiz==NULL) return 0;
    int xp = 0;
        if((raiz->valor)%2 == 0){
            xp++;
        }
    return xp + calculaPar(raiz->esq) + calculaPar(raiz->dir);
}
No* removerMenorValor(No *raiz){
    if(raiz==NULL) return NULL;
    if(raiz ->esq == NULL){
        No* temp = raiz ->dir;
        printf("menor valor removido!!!\nvalor: %d\n", raiz->valor);
        free(raiz);
        return temp;
    }
    raiz->esq = removerMenorValor(raiz->esq);
    return raiz;
}
int valoresMaiores(No *raiz, int x){
    if(raiz==NULL) return 0;
    int qtdx = 0;
    if((raiz->valor)>x){
        qtdx++;
    }
    return qtdx + valoresMaiores(raiz->esq, x) + valoresMaiores(raiz->dir,x);
}

int main(){
    No *raiz = NULL;
    int opt, valor;
    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Imprimir\n3 - Mostrar dados\n4 - Remover menor valor\n5 - Ver qtd de valores maiores que X valor\n6 - Remover Arvores\n");
        scanf("%d", &opt);
        switch(opt){
            case 1:
                printf("Digite um valor");
                scanf("%d",&valor);
                raiz = Inserir(raiz,valor);
                break;
            case 2:
                imprimir(raiz);
                printf("\n");
                break;
            case 3:
                printf("Soma = %d\n",soma(raiz));
                printf("Maior Valor = %d\n", maiorValor(raiz));
                printf("Menor Valor = %d\n",menorValor(raiz));
                printf("Numeros de pares = %d\n", calculaPar(raiz)); 
                break;
             case 4:
                raiz = removerMenorValor(raiz);
                break;
            case 5:
                printf("Digite um valor");
                scanf("%d", &valor);
                printf("A quantidade de valores maiores eh %d\n", valoresMaiores(raiz, valor));  
                break;
            case 6:
                if(raiz!=NULL){
                    removerArvore(raiz);
                    raiz = NULL;
                    printf("Arvore removida!!\n");
                }else
                    printf("Nao contem arvore!!\n");
                break;
            default:
            if(opt!=0)
                printf("\nOpcao invalida!!!!!!!!!!\n");
        }
    }while(opt!=0);
return 0;
}