#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no{
    int info;
    struct no *prox;
    struct no *ant;
}No;


int main(void) {

}


No* inserir_inicio(No *l,int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->info = valor;

    novo->ant = NULL;
    novo->prox = l;
    l = novo;
    return l;
}


No* inserir_final(No *l,int valor) {
    No *aux,*novo = (No *)malloc(sizeof(No));
    novo->info = valor;
    novo->prox = NULL;

    if(l==NULL) {
        novo->ant = NULL;
        l = novo;
        return l;
    }else{
        for(aux=l;aux->prox != NULL;aux=aux->prox);
        novo->ant = aux;
    }
    return l;
}


No* inserir_ordenado(No *l,int valor) {

    No *aux,*novo = (No *)malloc(sizeof(No));
    novo->info = valor;

    if(l==NULL) {
        novo->prox = NULL;
        novo->ant = NULL;
        l  = novo;
    }else{
        for(aux=l;aux->prox != NULL && aux->info < valor;aux=aux->prox);
        if(aux->ant==NULL) {
        novo->prox = aux;
        aux->ant = novo;
        novo->ant = NULL;
        l = novo;
        return l;
        }else if(aux->prox == NULL && aux->info < valor) {
        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox = novo;
        }else{
        novo->prox = aux->ant->prox;
        novo->ant = aux->ant;
        aux->ant->prox = novo;
        aux->ant = novo;
        }
    }
    return l;
}



void imprimir(No *l) {
  No *aux;

  for(aux=l;aux != NULL;aux=aux->prox) {
    printf("%d",aux->info);
  }
}


No* buscar1(No *l,int valor_procurado) {
    No *aux;

    for(aux=l;aux != NULL && aux->info != valor_procurado;aux=aux->prox);

    if(aux != NULL) return aux;
    return NULL;
}


int buscar2(No *l,int valor_procurado) {
  No *aux;
    
    for(aux=l;aux != NULL && aux->info != valor_procurado;aux=aux->prox);

    if(aux != NULL) return 1;
    return 0;
}


int quant_elementos(No *l) {
    int quant=0;
    No *aux;

    for(aux=l;aux != NULL;aux=aux->prox,quant++);
    return quant;
}
