#include "xor_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static Node *node_new(int valor){
  
  Node *n = malloc(sizeof *n);
  if (!n) return NULL;
  n->valor = valor;
  n->link = 0;
  return n;
}

XorList *xl_new(void)
{
  XorList *l = malloc(sizeof(*l));
  if (!l) return NULL;
  l->head = l->tail = NULL;
  l->len = 0;
  return l;               
}

void xl_free(XorList *l)
{
  if (!l) return;
  Node *anterior = NULL;
  Node *atual = l->head;

  while (atual) {
    Node *proximo = (Node *)(atual->link ^ (uintptr_t)anterior);
    free(atual);
    anterior = atual;
    atual = proximo;  
  }
  free(l);
}

int xl_append(XorList *l, int valor)
{
  if (!l) return -1;
  Node *n = node_new(valor);
  if (!n) return -1;        

  if (!l->tail){
    l->head = l->tail = n;
  } else {
    /* atualizando os links */
    n->link       = (uintptr_t) l->tail;
    l->tail->link ^= (uintptr_t) n;   
    l->tail       = n;
  }
  l->len++;
  return 0;
}

void xl_print_reverso(const XorList *l)
{
  if (!l || !l->tail) return;
  Node *anterior = NULL;
  for (Node *atual = l->tail; atual;) {
    printf("[node] : [%d]\n", atual->valor);
    Node *proximo = (Node *)(atual->link ^ (uintptr_t)anterior);
    anterior = atual;
    atual = proximo;
  }
}