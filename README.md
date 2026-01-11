# Propriedade-XOR

Repositório didático que mostra quatro aplicações criativas da propriedade fundamental do XOR:

```
a ^ b ^ b == a
```

Cada pasta é um programa independente; compile & execute com:

```bash
./build.sh
```

---

## 1. `XOR-LinkedList/` – Lista duplamente ligada “XOR”
--------------------------------------------------------
**Conceito**  
Cada nó guarda **um único campo** (`node->link`) que é o XOR entre o endereço do nó anterior e do próximo.  
Com isso percorremos **para frente e para trás** sem o ponteiro `anterior` tradicional, economizando 50 % de memória em ponteiros.
> n = novo; l = lista;


**Como a propriedade é usada**  
- Inserção no fim:  
  ```c
  n->link     = (uintptr_t)lista->tail;
  l->tail->link ^= (uintptr_t)n;
  l->tail     = n;
  ```

- Navegação reversa (do fim ao início):  
  ```c
  proximo = (Node*)(atual->link ^ anterior);
  anterior = atual;
  atual    = proximo;
  ```
  O valor `anterior` é atualizado a cada passo, garantindo que o XOR “desfaça” o endereço correto.

**Build & run**  
```bash
cd XOR-LinkedList
./build.sh          # gcc -std=c99 -Wall -Wextra -g xor_list.c main.c -o run
valgrind ./run      # 0 leaks, 0 errors
```

Saída esperada:  
```
[node] : [10]
[node] : [9]
...
[node] : [1]
```

---

## 2. `XOR-Encoder/` – Troca de variáveis sem temporária
----------------------------------------------------------
**Conceito**  
Troca dois inteiros **sem variável auxiliar** usando três XORs consecutivos.

**Como a propriedade é usada**  
```c
a ^= b;
b ^= a;   // b = b^(a^b) == a
a ^= b;   // a = (a^b)^a  == b
```
O script `swap.py` mostra o mesmo princípio com texto:  
`chr(ord(caractere) ^ chave) ^ chave == caractere`

---

## 3. `XOR-FindDuplicate/` – Detecta o número duplicado
-------------------------------------------------------
**Conceito**  
Dado um vetor que contém todos os inteiros de 1 a 100 **exceto um**, e **um valor duplicado no lugar do ausente**, encontra o duplicado em O(n) e O(1) de memória.

**Como a propriedade é usada**  
```c
xor_total = 1^2^3^…^100;
xor_vetor = xs[0]^xs[1]^…^xs[N];
duplicado = xor_total ^ xor_vetor;
```
Todos os números corretos aparecem duas vezes no XOR global e se anulam, restando apenas o duplicado.

---

## 4. `XOR-CTF-Trick/` – Ofuscação & Exploitation
-------------------------------------------------
**Conceito**  
Em CTFs a xor-list é usada **não para economizar memória**, mas como *gadget* de confusão:  
- Reverse/Pwn: esconde ponteiros (`anterior ^ proximo`) forçando o reverser a perceber o truque.  
- Heap-exploitation: overwrite do campo `link` gera **arbitrary-write** ou **redirect-flow** com um único valor controlado.

Exemplo clássico: off-by-one sobre `node->link` → XOR manipulado aponta para `__free_hook` ou `got.plt`.

---

## ✅ Cheatsheet da propriedade

| Propriedade | Consequência |
|-------------|--------------|
| `A ^ A = 0` | ponteiro para si mesmo anula-se |
| `A ^ 0 = A` | basta um lado para recuperar o outro |
| comutativo / associativo | `(anterior ^ proximo) ^ anterior == proximo` |

---
