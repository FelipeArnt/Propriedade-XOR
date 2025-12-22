#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>

typedef struct{
  int value;
  uintptr_t xored; // é um int com o tamanho exato do endereço do pointer, ou seja, é especifico para armazenar o endereço do ponteiro.
} Node;

Node *node_create(int value)
{
  Node *node = malloc(sizeof(Node));
  memset(node, 0, sizeof(*node));
  node->value = value;
  return node;

}

typedef struct {
  Node *inicio;
  Node *fim;
} Linked_List;

void ll_append(Linked_List *ll, int value)
{
  if (ll->fim == NULL){
    assert(ll->inicio == NULL);
    ll->fim = node_create(value);
    ll->inicio = ll->fim;

  } else {
    Node *node = node_create(value);
    node->xored = (uintptr_t)ll->fim;
    ll->fim->xored ^= (uintptr_t)node;
    ll->fim = node;
  }
}

Node *node_next(Node *node, uintptr_t *anterior)
{

  Node *next = (Node*)(node->xored^(*anterior));
  *anterior = (uintptr_t)node;
  return next;

}

// Entry point do programa
int main()
{

  Linked_List xs = {0};
  for (int x = 1; x <= 10; x++){
    ll_append(&xs, x);
  }
  uintptr_t anterior = 0;
  // se xs for atribuido ao node de inicio , os nodes serao do menor ao maior, se xs for atribuido a fim, sera do maior ao menor.
  for(Node *iter = xs.inicio; iter; iter = node_next(iter, &anterior)){
    printf("[node] : [ %d ] \n", iter->value);
  }
  return 0;
}

