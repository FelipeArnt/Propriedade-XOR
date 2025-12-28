# Propriedade-XOR

Este repositório ilustra quatro usos criativos da propriedade fundamental do XOR:  

**a ^ b ^ b == a**  

Cada pasta contém um programa independente que compila e executa com:

```bash
./build.sh
```

--------------------------------------------------------------------
## 1. `XOR-LinkedList/` – Lista duplamente ligada “XOR”
-----------------------------------------
**Conceito**  
Armazena **apenas um ponteiro por nó** (`node->xored`) que é o XOR entre o endereço do nó anterior e do próximo.  
Com isso é possível percorrer a lista nos dois sentidos sem o campo `prev` tradicional.

**Como a propriedade é usada**  
- Ao inserir:  
  `novo->xored = endereço_do_fim`  
  `fim->xored ^= endereço_do_novo`  
- Ao navegar:  
  `próximo = (Node*)(atual->xored ^ anterior)`  
  O valor `anterior` é atualizado a cada passo, garantindo que o XOR “desfaca” o endereço correto.

--------------------------------------------------------------------
## 2. `XOR-Encoder/` – Troca de variáveis sem temporária
----------------------------------------------
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

--------------------------------------------------------------------
## 3. `XOR-FindDuplicate/` – Detecta o número duplicado
--------------------------------------
**Conceito**  
Dado um vetor que contém todos os inteiros de 1 a 100 **exceto um**, e **um valor duplicado no lugar do ausente**, encontra o duplicado em O(n) e O(1) de memória.

**Como a propriedade é usada**  

`xor_total = 1^2^3^…^100`  
`xor_vetor = xs[0]^xs[1]^…^xs[N]`  
`duplicado = xor_total ^ xor_vetor`  

Porque todos os números corretos aparecem duas vezes no XOR global e se anulam, restando apenas o duplicado.

--------------------------------------------------------------------
