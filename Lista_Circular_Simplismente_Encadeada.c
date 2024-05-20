#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct no{
    int info;
    struct no *prox;
}No;


int main(void) {

}

/*(1)*///FUNÇÃO DE INSERÇÃO NO INÍCIO:
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

/*(2)*///FUNÇÃO DE INSERÇÃO NO FINAL:
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

/*(3)*///FUNÇÃO DE INSERÇÃO ORDENADA:
No* inserir_ordenado(No *l,int valor) {
    
}

/*(4)*///FUNÇÃO DE REMOÇÃO NO INÍCIO:
No* remover_inicio(No *l,int *valor_removido) {
    No *remover;
    
    if(l==NULL) {
        return NULL;
    }else{
        remover = l->prox;
        l->prox = remover->prox;
        *valor_removido = remover->info;
        free(remover);
    }
    return l;
}

/*(5)*///FUNÇÃO DE REMOÇÃO NO FINAL:
No* remover_final(No *l,int *valor_removido) {
    No *remover,*ant;

    if(l==NULL) {
        return NULL;
    }else{
        for(ant=l->prox;ant->prox != l;ant=ant->prox);
        ant->prox = l->prox;
        remover = l;
        *valor_removido = remover->info;
        free(remover);
    }
    return l;
}


/*(6)*///FUNÇÃO DE REMOÇÃO:
No* remover_elemento(No *l,int valor) {

}



/*(7)*///FUNÇÃO DE IMPRESSÃO:
void imprimir(No *l) {
  No *aux;

  for(aux=l;aux != NULL;aux=aux->prox) {
    printf("%d",aux->info);
  }
}

/*(8)*///FUNÇÃO DE BUSCA(retorna ponteiro):
No* buscar1(No *l,int valor_procurado) {
    No *aux;

    for(aux=l;aux != NULL && aux->info != valor_procurado;aux=aux->prox);

    if(aux != NULL) return aux;
    return NULL;
}

/*(9)*///FUNÇÃO DE BUSCA(retorna inteiro):
int buscar2(No *l,int valor_procurado) {
  No *aux;
    
    for(aux=l;aux != NULL && aux->info != valor_procurado;aux=aux->prox);

    if(aux != NULL) return 1;
    return 0;
}

/*(10)*///FUNÇÃO DE CONTAGEM DE ELEMENTOS:
int quant_elementos(No *l) {
    int quant=0;
    No *aux;

    for(aux=l;aux != NULL;aux=aux->prox,quant++);
    return quant;
}

/*(11)*///FUNÇÃO DE LIBERAÇÃO:
void liberar(No *p) {
  No *aux = p;
  while(aux != NULL) {
    p = aux->prox;
    free(aux);
    aux = p;
  }
}