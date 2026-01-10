#ifndef XOR_LIST_H
#define XOR_LIST_H

#include <stdint.h>
#include <stddef.h>

typedef struct Node {
  int valor;
  uintptr_t link;
} Node;

typedef struct {
  Node *head;
  Node *tail;
  size_t len;
} XorList;

XorList *xl_new(void);
void xl_free(XorList *l);
int xl_append(XorList *l, int valor); // 0 = ok, -1 = falha
void xl_print_reverso(const XorList *l);

#endif
