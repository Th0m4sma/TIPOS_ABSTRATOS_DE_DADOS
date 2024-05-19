#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct no{
    int info;
    struct no *prox;
}No;


int main(void) {

}

No* inserir_inicio(No *l,int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->info = valor;

    if(l == NULL) {
        novo->prox = novo;
        l = novo;
        return l;
    }else{
        novo->prox = l->prox;
        l->prox = novo;
    }
    return l;
}

No* inserir_final(No *l,int valor) {
    No *aux,*novo = (No *)malloc(sizeof(No));
    novo->info = valor;

    if(l==NULL) {
        novo->prox = novo;
        l = novo;
        return l;
    }else{
        novo->prox = l->prox;
        l->prox = novo;
        l = novo;
    }
    return l;
}

No* inserir_ordenado(No *l,int valor) {
    
}
