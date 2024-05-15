/* A fila(FIFO) é um tipo abstrado de dados, onde a inserção é realizada no final e a remoção
é realizada no inicio. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura de um nó:
typedef struct no{
  int info;
  struct no *prox;
}No;

// Definição da estrutura de uma fila:
typedef struct fila{
  struct no *ini;
  struct no *fim;
}Fila;

/*(1)*/Fila* inicializacao();
// Função que cria uma estrutura do tipo fila, inicializando os ponteiros.

/*(2)*/Fila* enfileirar(Fila *p,int valor);
// Função de inserção de elementos na fila.

/*(3)*/Fila* desenfileirar(Fila *p,int *removido);
// Função de remoção de elementos na fila.

/*(4)*/void imprimir(Fila *p);
// Função que imprime todos os elementos da fila.

/*(5)*/void liberar(Fila *p);
// Função que desaloca todos os nós da fila.

/*(6)*/No* buscar1(Fila *p,int valor_procurado);
// Função de buscar elementos na fila, se encontrado retorna o nó, se não retorna NULL.

/*(7)*/int buscar2(Fila *p, int valor_procurado);
// Função de buscar elementos na fila, se encontrado retorna 1, se não retorna 0.

/*(8)*/int quant_elementos(Fila *p);
// Função que conta a quantidade de nós dentro de uma fila.

int main(void) {
  Fila* fila = inicializacao();
  int op,valor,valor_removido,quantidade,achou_elemento;
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
        fila = enfileirar(fila,valor);
        break;
      case 2:
        fila = desenfileirar(fila,&valor_removido);
        printf("O numero %d foi removido\n",valor_removido);
        
        break;
      case 3:
        imprimir(fila);
        printf("\n");
        break;
      case 4:
        printf("Digite o elemento que deseja procurar na pilha: ");
        scanf("%d",&valor);
        achou_elemento = buscar2(fila,valor);

        if(achou_elemento == 1) {
          printf("O elemento pertence a pilha\n");  
        }else{
          printf("O elemento nao pertence a pilha\n");
        }

        break;
      case 5:
        quantidade = quant_elementos(fila);
        printf("Na pilha temos %d elementos.\n",quantidade);
        
        break;
      case 6:
        printf("Saindo\n");
        sair = true;
        
        break;
    }
  }
  liberar(fila);
}

/*(1)*///FUNÇÃO DE INICIALIZAÇÃO:
Fila* inicializacao() {
  Fila *novo = (Fila *)malloc(sizeof(Fila));
  novo->ini = NULL;
  novo->fim = NULL;
  return novo;
}

/*(2)*///FUNÇÃO DE INSERÇÃO:
Fila* enfileirar(Fila *p,int valor) {
  No *novo=(No *)malloc(sizeof(No));
  novo->info = valor;
  novo->prox = NULL;

  if(p->ini == NULL) {
    p->ini = novo;
    p->fim = novo;
  }else{
    p->fim->prox = novo;
    p->fim = novo;
  }
  return p;
}

/*(3)*///FUNÇÃO DE REMOÇÃO:
Fila* desenfileirar(Fila *p,int *removido) {
  No *remover;

  if(p->ini == NULL) {
    return p;
  }else{
    remover = p->ini;
    *removido = remover->info;
    p->ini = remover->prox;
    free(remover);
  }
  return p;
}

/*(4)*///FUNÇÃO DE IMPRESSÃO:
void imprimir(Fila *p) {
  No *aux;

  printf("Imprimindo Elementos: |");
  for(aux=p->ini;aux != NULL;aux=aux->prox) {
    printf("%d|",aux->info);
  }
}

/*(5)*///FUNÇÃO DE LIBERAÇÃO:
void liberar(Fila *p) {
  No *aux = p->ini;

  while(aux != NULL) {
    p->ini = aux->prox;
    free(aux);
    aux = p->ini;
  }
}

/*(6)*///FUNÇÃO DE BUSCA(retorna ponteiros):
No* buscar1(Fila *p,int valor_procurado) {
  No *aux;

  for(aux=p->ini;aux != NULL && aux->info != valor_procurado;aux=aux->prox);
  
  if(aux != NULL) return aux;
  return NULL;
}

/*(7)*///FUNÇÃO DE BUSCA(retorna inteiros):
int buscar2(Fila *p, int valor_procurado) {
  No *aux;

  for(aux=p->ini;aux != NULL && aux->info != valor_procurado;aux=aux->prox);

  if(aux != NULL) return 1;
  return 0;
}

/*(8)*///FUNÇÃO DE CONTAGEM DE ELEMENTOS:
int quant_elementos(Fila *p) {
  int quant = 0;
  No *aux;

  for(aux=p->ini;aux != NULL;aux=aux->prox) {
    quant += 1;
  }

  return quant;
}