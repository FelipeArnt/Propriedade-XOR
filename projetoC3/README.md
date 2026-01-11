# ProjetoC3 – XOR FindDuplicates

## O que faz o programa
Localiza o **único número duplicado** em um vetor que deveria conter todos os inteiros de 1 a 100 exatamente uma vez, **exceto** pelo repetido.  
O algoritmo roda em O(n) tempo, O(1) espaço e **sem ordenar** – apenas com o truque do XOR.

## Compilação & execução (Arch Linux / qualquer distro com C3)
```bash
sudo pacman -S c3c          # ou build a partir do repo oficial
git clone <url-do-repo>
cd projetoC3
c3c compile-run src/main.c3
```
Saída esperada:
```
Duplicado: 1
```

## Como o XOR encontra o duplicado
1. `contador` começa valendo 0.
2. Faz XOR com **todos os números de 1..100** → `contador` fica igual ao XOR da lista “certa”.
3. Faz XOR com **cada elemento real do vetor** → os valores que aparecem 1× se cancelam, sobra:
   ```
   contador = (valor_duplicado) ^ (valor_faltante)
   ```
4. Como sabemos que **apenas um número foi repetido e nenhum foi perdido**, o resultado do passo 3 é exatamente o valor duplicado (ou seu inverso).  
   *(Se quisesse o faltante, faríamos outro scan.)*

## Por que fazer isso em C3?
- **Compatibilidade total com C** – poderíamos linkar essa função num projeto C existente sem wrappers.  
- **Módulos e `foreach`** – código fica mais curto e legível que o equivalente C puro, mas sem o custo de exceções ou RTTI.  
- **Compile-time seguro** – bounds-check em debug, mas nenhum custo em release (`-O3`).  
- **Syntax familiarity** – qualquer desenvolvedor C lê o fonte em 5 s; não precisa aprender ownership ou lifetimes.  
- **Performance idêntica a C** – o assembly gerado é literalmente o mesmo loop `xor eax, [rdi]`.

## Estrutura do repo
```
projetoC3/
├─ src/
│  └─ main.c3        # único arquivo; não precisa de header
└─ README.md
```

## Brincando com o código
- Troque o vetor `ys` para outro range ou múltiplos duplicados e veja o resultado.  
- Descomente `io::println("ticks: ", clock());` para medir tempo (precisa `import std::time`).  
- Compile com `c3c compile -O3 --emit-asm src/main.c3` e abra `main.s` para conferir que não há overhead.

