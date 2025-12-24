# XOR-Linked-List — lista duplamente encadeada com meio ponteiro

Em desenvolvimento...  

- Cada nó guarda **um único endereço** (`prev ⊕ next`), mas ainda assim permite percorrer **para frente e para trás** sem manter ponteiro `prev` explícito.

---

## O que é a “propriedade XOR” e por que ela funciona?

A operação **ou-exclusivo (XOR, `^`)** 

1. `A ⊕ A = 0`  
2. `A ⊕ 0 = A`  

3. **Comutativa e associativa**: `A ⊕ B ⊕ B = A`

Ou seja, se guardarmos `endereço_anterior ⊕ endereço_posterior`, basta **conhecer um dos dois lados** para recuperar o outro:

`next = (prev ⊕ next) ⊕ prev`

`prev = (prev ⊕ next) ⊕ next`


Durante o percurso sempre sabemos **qual é o nó atual e qual foi o anterior**, então conseguimos desfazer o XOR e saltar para o próximo (ou para o anterior, se quisermos andar pra trás).  


**Resultado:** Economia de **50 % do espaço de ponteiros** em listas grandes e ainda mantemos complexidade O(1) para inserção.

---

## Compilação & execução

```bash
$ gcc -std=c -Wall -Wextra -pedantic ll.c -o ll

$ ./ll
[node] : [10]
[node] : [9]
...
[node] : [1]
```

## Verificação do código. 

Atualmente o comando abaixo identifica memory leaks no código.

`valgrind --leak-check=full`
