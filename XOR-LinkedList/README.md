# XOR-Linked-List  
*Uma lista duplamente encadeada que usa **meio ponteiro por nó**.*

[![Build](https://img.shields.io/badge/build-passing-brightgreen)](https://github.com/seu-usuario/xor-linked-list)
[![Language](https://img.shields.io/badge/language-C99-blue)](https://en.cppreference.com/w/c)
[![License](https://img.shields.io/badge/license-MIT-lightgrey)](LICENSE)

---

## 🔍 Por que XOR?

Em uma lista duplamente clássica cada nó guarda **dois ponteiros**: `anterior` e `proximo`.  
Na *xor-list* guardamos **apenas um**:  

```
link = (uintptr_t)anterior ^ (uintptr_t)proximo
```

Aproveitando as propriedades do XOR:

| Propriedade | Consequência |
|-------------|--------------|
| `A ^ A = 0` |  ponteiro para o mesmo nó anula-se |
| `A ^ 0 = A` |  basta conhecer um dos lados para recuperar o outro |
| Comutativo / Associativo |  `(anterior ^ proximo) ^ anterior == proximo` |

Durante o percurso sabemos **onde estamos** e **de onde viemos**; assim, deciframos o terceiro endereço em **O(1)** sem armazená-lo.

**Economia**: ‑50 % de bytes em ponteiros para listas grandes, cache mais amigável e **mesma complexidade** de inserção/remoção.

---

## 🚀 Começando

```bash
# Clone ou baixe os arquivos
git clone https://github.com/felipearnt/Propriedades-XOR.git
cd Propriedades-XOR/XOR-LinkedList

# Compile
chmod +x build.sh && ./build.sh         # ou: gcc -std=c99 -Wall -Wextra -g ll.c -o ll

# Execute
./run
```

Saída esperada:
```
[node] : [10]
[node] : [9]
...
[node] : [1]
```

---

## 🧪 Testando & Valgrind

```bash
# Memory-leak check
valgrind --leak-check=full --show-leak-kinds=all ./run
```

Resultado limpo:
```
==12345== HEAP SUMMARY:
==12345==     in use at exit: 0 bytes in 0 blocks
==12345==   total heap usage: 11 allocs, 11 frees, 384 bytes allocated
==12345== All heap blocks were freed -- no leaks are possible
```

---

## 📌 API rápida

| Função | Descrição | Complexidade |
|--------|-----------|--------------|
| `XorList *xl_new(void)` | Cria lista vazia | O(1) |
| `int xl_append(XorList *l, int valor)` | Insere no fim | O(1) |
| `void xl_print_reverso(const XorList *l)` | Imprime do fim ao início | O(n) |
| `void xl_free(XorList *l)` | Libera toda memória | O(n) |

---

## 🧠 Curiosidades

* A técnica aparece no **Art of Computer Programming** (Knuth) como "doubly linked list using one pointer".  
* Funciona **apenas em linguagens que permitem aritmética de ponteiros** (C, C++, Assembly).  
* Não é thread-safe: o caminho de ida e volta **deve ser sequencial**.

---

## 📄 Licença

MIT © 2024 Seu Nome
