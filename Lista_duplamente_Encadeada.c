/*A lista duplamente encadeada é um tipo abstrato de dados, onde a inserção e a remoção podem ser realizadas em qualquer posição 
da minha sequência de nós. Nesse momento teremos dois ponteiros na nossa estrutura, sendo um ponteiro que a aponta para o próximo
nó, e um segundo ponteiro apontando para o nó anterior. Facilitando as operações de remoção e inserção.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura típica dos nós que pertencem a uma lista duplamente encadeada(com dois ponteiros):
typedef struct no{
    int info;
    struct no *prox;
    struct no *ant;
}No;


/*(1)*/No* inserir_inicio(No *l,int valor);
// Função que inseri os elementos no inicio da minha sequência de nós.

/*(2)*/No* inserir_final(No *l,int valor);
// Função que inseri os elementos no final da minha sequência de nós.

/*(3)*/No* inserir_ordenado(No *l,int valor);
// Função que inseri os elementos de forma ordenada na minha sequência de nós.

/*(4)*/No* remover_inicio(No *l,int *valor_removido);
// Função que remove os elementos do inicio da minha sequência de nós.

/*(5)*/No* remover_final(No *l,int *valor_removido);
// Função que remove os elementos do final da minha sequência de nós.

/*(6)*/No* remover_elemento(No *l,int valor);
// Função que remove um elemento passado como parâmetro da minha função.

/*(7)*/void imprimir(No *l);
// Função que imprimi os elementos da lista duplamente encadeada.

/*(8)*/No* buscar1(No *l,int valor_procurado);
// Função que busca um nó com um determinado elemento, se encontrado o retorna, se não retorna NULL.

/*(9)*/int buscar2(No *l,int valor_procurado);
// Função que busca um nó com um determinado elemento, se encontrado retorna 1, se não retorna 0.

/*(10)*/int quant_elementos(No *l);
// Função que conta a quantidade de elementos dentro da minha lista duplamente encadeada.

/*(11)*/void liberar(No *p);
// Função que desaloca todos os nós alocados de uma lista.

int main(void) {
  No *lista = NULL;
  int valor,op,quantidade,valor_removido,achou_elemento;
  bool sair = false;

  while(!sair) {
    printf("========================\n");
    printf("]|[==-[-1-INSERIR-]==]|[\n");
    printf("]|[==-[-2-REMOVER-]==]|[\n");
    printf("]|[==-[-3-IMPRIMIR]==]|[\n");
    printf("]|[==-[-4-BUSCAR-]-==]|[\n");
    printf("]|[==-[-5-QUANT-]--==]|[\n");
    printf("========================\n");

    printf("Digite: ");
    scanf("%d",&op);
    
     switch(op) {
      case 1:

        printf("Digite o valor que deseja inserir: ");
        scanf("%d",&valor);
        lista = inserir_ordenado(lista,valor);
        
        break;
      case 2:
        lista = remover_final(lista,valor);
        printf("O numero %d foi removido\n",valor_removido);
        
        break;
      case 3:
        imprimir(lista);
        printf("\n");
        break;
      case 4:
        printf("Digite o elemento que deseja procurar na pilha: ");
        scanf("%d",&valor);
        
        achou_elemento = buscar2(lista,valor);
        if(achou_elemento == 1) {
          printf("O elemento pertence a pilha\n");  
        }else{
          printf("O elemento nao pertence a pilha\n");
        }
        
        break;
      case 5:
        quantidade = quant_elementos(lista);
        printf("Na pilha temos %d elementos.\n",quantidade);
        
        break;
      case 6:
        printf("Saindo\n");
        sair = true;
        break;
    
      }
    }

}

/*(1)*///FUNÇÃO DE INSERÇÃO NO INÍCIO:
No* inserir_inicio(No *l,int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->info = valor;

    novo->ant = NULL;
    novo->prox = l;
    l = novo;
    return l;
}

/*(2)*///FUNÇÃO DE INSERÇÃO NO FINAL:
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

/*(3)*///FUNÇÃO DE INSERÇÃO ORDENADA:
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

/*(4)*///FUNÇÃO DE REMOÇÃO NO INÍCIO:
No* remover_inicio(No *l,int *valor_removido) {
    No* remover;

    if(l==NULL) return NULL;
    remover = l;
    l=remover->prox;
    l->ant = NULL;
    *valor_removido = remover->info;
    free(remover);
    return l;
}

/*(5)*///FUNÇÃO DE REMOÇÃO NO FINAL:
No* remover_final(No *l,int *valor_removido) {
    No *remover;
    
    if(l==NULL) return NULL;
    for(remover=l;remover->prox != NULL;remover=remover->prox);

    remover->ant->prox = NULL;
    *valor_removido = remover->info;
    free(remover);
    return l;
}

/*(6)*///FUNÇÃO DE REMOÇÃO:
No* remover_elemento(No *l,int valor) {
    No *remover;

    if(l==NULL) return NULL;
    for(remover=l;remover != NULL && remover->info != valor;remover=remover->prox);

    if(remover != NULL) {
        remover->ant->prox = remover->prox;
        remover->prox->ant = remover->ant;
        free(remover);
    }else{
        return NULL;
    }
    
    return l;
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