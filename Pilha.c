/* A pilha(LIFO) é um tipo abstrado de dados, onde tanto a sua inserção, quanto sua remoção é feita no inicio da sequência de nós. */

#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

// Definição da estrutura típica dos nós que pertencem a uma pilha:
typedef struct no{
  int info; 
  struct no *prox; 
}No;

/*(1)*/No* push(No *topo,int valor); 
// Função de inserção de um elemento na pilha.

/*(2)*/No* pop(No *topo,int *valor_removido);
// Função de remoção de um elemento da pilha. 

/*(3)*/void liberar_pilha(No *topo);
// Função que desaloca todos os nós alocados de uma pilha.

/*(4)*/void imprimir_pilha(No *topo);
// Função que imprimi os elementos da pilha.

/*(5)*/No* buscar_No_1(No *topo,int valor_procurado);
// Função busca um nó com um determinado elemento, se encontrado o retorna, se não retorna NULL.

/*(6)*/int buscar_No_2(No *topo,int valor_procurado);
// Função busca um nó com um determinado elemento, se encontrado retorna 1, se não retorna 0.

/*(7)*/int quant_elementos(No *topo);
// Função que conta a quantidade de elementos dentro da minha pilha.

int main(void) {
  No *pilha = NULL;
  bool sair = false;
  int opcao,valor,valor_removido,quantidade,achou_elemento;
  
  while(!sair) {
    printf("========================\n");
    printf("]|[==-[-1-INSERIR-]==]|[\n");
    printf("]|[==-[-2-REMOVER-]==]|[\n");
    printf("]|[==-[-3-IMPRIMIR]==]|[\n");
    printf("]|[==-[-4-BUSCAR-]-==]|[\n");
    printf("]|[==-[-5-QUANT-]--==]|[\n");
    printf("]|[==-[-6-SAINDO-]-==]|[\n");
    printf("========================\n");

    printf("Digite: ");
    scanf("%d",&opcao);

    switch(opcao) {
      case 1:
        printf("Digite o valor que deseja inserir: ");
        scanf("%d",&valor);
        
        pilha = push(pilha,valor);
        break;
      case 2:
        pilha = pop(pilha,&valor_removido);
        printf("O numero %d foi removido\n",valor_removido);
        
        break;
      case 3:
        imprimir_pilha(pilha);
        printf("\n");
        break;
      case 4:
        printf("Digite o elemento que deseja procurar na pilha: ");
        scanf("%d",&valor);
        achou_elemento = buscar_No_2(pilha,valor);
        
        if(achou_elemento == 1) {
          printf("O elemento pertence a pilha\n");  
        }else{
          printf("O elemento nao pertence a pilha\n");
        }
        
        break;
      case 5:
        quantidade = quant_elementos(pilha);
        printf("Na pilha temos %d elementos.\n",quantidade);
        
        break;
      case 6:
        printf("Saindo\n");
        sair = true;
        break;
    }
  }

  liberar_pilha(pilha);
}


/*(1)*///FUNÇÃO DE INSERÇÃO:
No* push(No *topo,int valor) {
  No *novo = (No *)malloc(sizeof(No));
  novo->info = valor;
  novo->prox = topo;
  topo = novo;
  return topo;
}

/*(2)*///FUNÇÃO DE REMOÇÃO:
No* pop(No *topo,int *valor_removido) {
  No *remover;

  if(topo == NULL) {
    return NULL;
  }else{
    remover = topo;
    topo = remover->prox;
    *valor_removido = remover->info;
    free(remover);
  }
  return topo;
}

/*(3)*///FUNÇÃO DE LIBERAÇÃO:
void liberar_pilha(No *topo) {
  No *aux = topo;
  
  while(aux != NULL) {
    topo = aux->prox;
    free(aux);
    aux = topo;
  }
}

/*(4)*///FUNÇÃO DE IMPRESSÃO:
void imprimir_pilha(No *topo) {
  No *aux;

  printf("Imprimindo Elementos: |");
  for(aux = topo;aux != NULL;aux=aux->prox) {
    printf("%d|",aux->info);
  }
}

/*(5)*///FUNÇÃO DE BUSCA(retorna ponteiro):
No* buscar_No_1(No *topo,int valor_procurado) {
  No *aux;

  for(aux = topo;aux != NULL && aux->info != valor_procurado;aux=aux->prox);

  if(aux != NULL) return aux;
  else return NULL;
} 

/*(6)*///FUNÇÃO DE BUSCA(retorna inteiro):
int buscar_No_2(No *topo,int valor_procurado) {
  No *aux;

  for(aux = topo;aux != NULL && aux->info != valor_procurado;aux=aux->prox);

  if(aux != NULL) return 1;
  else return 0;
}

/*(7)*///FUNÇÃO DE CONTAGEM DE ELEMENTOS:
int quant_elementos(No *topo) {
  int quantidade = 0;
  No *aux;

  for(aux=topo;aux != NULL;aux =aux->prox,quantidade++);
  return quantidade;
}
