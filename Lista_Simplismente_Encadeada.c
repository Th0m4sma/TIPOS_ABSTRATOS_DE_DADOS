/*A lista é um tipo abstrato de dados, onde o processo de inserção e de remoção podem ser realizados em qualquer posição da minha sequência de nós*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura típica dos nós que pertencem a uma lista:
typedef struct no{
  int info;
  struct no *prox;
}No;

/*(1)*/No* inserir_inicio(No *p,int valor);
// Função que inseri os elementos no inicio da minha sequência de nós.

/*(2)*/No* inserir_final(No *p,int valor);
// Função que inseri os elementos no final da minha sequência de nós.

/*(3)*/No* inserir_ordenado(No *p,int valor);
// Função que inseri os elementos de forma ordenada na minha sequência de nós.

/*(4)*/No* remover_inicio(No *p,int *removido);
// Função que remove os elementos do inicio da minha sequência de nós.

/*(5)*/No* remover_final(No *p,int *removido);
// Função que remove os elementos do final da minha sequência de nós.

/*(6)*/No* remover_elemento(No *p,int valor);
// Função que remove um elemento passado como parâmetro da minha função.

/*(7)*/void liberar(No *p);
// Função que desaloca todos os nós alocados de uma lista.

/*(8)*/void imprimir(No *p);
// Função que imprimi os elementos da lista.

/*(9)*/No* buscar1(No *p,int valor_procurado);
// Função que busca um nó com um determinado elemento, se encontrado o retorna, se não retorna NULL.

/*(10)*/int buscar2(No *p,int valor_procurado);
// Função que busca um nó com um determinado elemento, se encontrado retorna 1, se não retorna 0.

/*(11)*/int quant_elementos(No *p);
// Função que conta a quantidade de elementos dentro da minha lista.


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
        printf("Digite o elemento que deseja procurar na lista: ");
        scanf("%d",&valor);
        
        achou_elemento = buscar2(lista,valor);
        if(achou_elemento == 1) {
          printf("O elemento pertence a lista\n");  
        }else{
          printf("O elemento nao pertence a lista\n");
        }
        
        break;
      case 5:
        quantidade = quant_elementos(lista);
        printf("Na lista temos %d elementos.\n",quantidade);
        
        break;
      case 6:
        printf("Saindo\n");
        sair = true;
        break;
    
      }
    }
}

/*(1)*///FUNÇÃO DE INSERÇÃO NO INÍCIO:
No* inserir_inicio(No *p,int valor) {
  No *novo = (No *)malloc(sizeof(No));
  novo->info = valor;
  novo->prox = p;
  p = novo;
  return p;
}

/*(2)*///FUNÇÃO DE INSERÇÃO NO FINAL:
No* inserir_final(No *p,int valor) {
  No *aux,*novo = (No *)malloc(sizeof(No));
  novo->info = valor;
  novo->prox = NULL;

  if(p==NULL) {
    p = novo;
  }else{
    for(aux=p;aux->prox != NULL;aux=aux->prox);
    aux->prox = novo;
  }
  return p;
}

/*(3)*///FUNÇÃO DE INSERÇÃO ORDENADA:
No* inserir_ordenado(No *p,int valor) {
  No *aux,*ant,*novo = (No *)malloc(sizeof(No));
  novo->info = valor;

  if(p==NULL) {
    novo->prox = NULL;
    p = novo;
  }else{
    for(aux=p,ant = NULL;aux->prox != NULL && aux->info < valor;ant = aux,aux=aux->prox);
    if(ant==NULL) {
      novo->prox = aux;
      p = novo;
      return p;
    }else if(aux->prox == NULL && aux->info < valor) {
      novo->prox = aux->prox;
      aux->prox = novo;
    }else{
      novo->prox = ant->prox;
      ant->prox = novo;
    }
  }
  return p;
}

/*(4)*///FUNÇÃO DE REMOÇÃO NO INÍCIO:
No* remover_inicio(No *p,int *removido) {
  No *remover;
  
  if(p == NULL) {
    return NULL;
  }else{
    remover = p;
    p = remover->prox;
    *removido = remover->info;
    free(remover);
  }
  return p;
}

/*(5)*///FUNÇÃO DE REMOÇÃO NO FINAL:
No* remover_final(No *p,int *removido) {
  No *remover,*ant;

  if(p==NULL) {
    return NULL;
  }else{
    for(remover=p,ant=NULL;remover->prox != NULL;ant=remover,remover=remover->prox);
    if(ant != NULL) {
     ant->prox = NULL;
    }
    *removido = remover->info;
    free(remover);
  }
  return p;
}

/*(6)*///FUNÇÃO DE REMOÇÃO:
No* remover_elemento(No *p,int valor) {
  No  *remover,*ant;

  if(p == NULL) {
    return NULL;
  }else{
    for(remover=p,ant=NULL;remover != NULL && remover->info != valor;ant=remover,remover=remover->prox);
    if(remover != NULL) {
      if(ant !=NULL) {
        ant->prox = remover->prox;
      }else{
        p = remover->prox;
      }
      free(remover);
    }
  }
  return p;
}

/*(7)*///FUNÇÃO DE LIBERAÇÃO:
void liberar(No *p) {
  No *aux = p;
  while(aux != NULL) {
    p = aux->prox;
    free(aux);
    aux = p;
  }
}

/*(8)*///FUNÇÃO DE IMPRESSÃO:
void imprimir(No *p) {
  No *aux;

  for(aux=p;aux != NULL;aux=aux->prox) {
    printf("%d",aux->info);
  }
}

/*(9)*///FUNÇÃO DE BUSCA(retorna ponteiro):
No* buscar1(No *p,int valor_procurado) {
    No *aux;

    for(aux=p;aux != NULL && aux->info != valor_procurado;aux=aux->prox);

    if(aux != NULL) return aux;
    return NULL;
}

/*(10)*///FUNÇÃO DE BUSCA(retorna inteiro):
int buscar2(No *p,int valor_procurado) {
  No *aux;
    
    for(aux=p;aux != NULL && aux->info != valor_procurado;aux=aux->prox);

    if(aux != NULL) return 1;
    return 0;
}

/*(11)*///FUNÇÃO DE CONTAGEM DE ELEMENTOS:
int quant_elementos(No *p) {
    int quant=0;
    No *aux;

    for(aux=p;aux != NULL;aux=aux->prox,quant++);
    return quant;
}
