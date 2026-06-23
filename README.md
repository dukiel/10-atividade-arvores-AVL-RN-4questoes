# Árvores AVL e Rubro-Negras — Lista de Exercícios

Implementação em C++ dos exercícios de árvores AVL e rubro-negras da disciplina de Estruturas de Dados.

## Arquivos do projeto

| Arquivo | Função |
|---|---|
| `main.cpp` | Executa os testes dos exercícios |
| `arvore.h` | Declara as structs e funções |
| `arvore.cpp` | Implementa as funções de AVL e rubro-negra |
| `CMakeLists.txt` | Configuração para compilar com CMake |

## Exercícios implementados

### 1) Verificar se uma árvore é AVL

A função `ehAVL` verifica se, em todos os nós, a diferença entre a altura da subárvore esquerda e da direita é no máximo 1.

### 2) Inserções em árvore AVL

Foram inseridos os valores:

```cpp
40, 20, 60, 10, 30, 50, 70, 5
```

Após cada inserção, o programa imprime a árvore e o fator de balanceamento de cada nó.

### 3) Remoção em árvore AVL

Foi montada a árvore do enunciado e removido o nó `60`. Depois da remoção, o programa imprime a árvore resultante e verifica se houve desbalanceamento.

### 4) Inserções em árvore rubro-negra

Foram inseridos os valores:

```cpp
10, 20, 30, 15
```

O programa imprime a árvore com as cores dos nós:

- `V` = vermelho
- `P` = preto

Também mostra o caso de correção aplicado e verifica a altura preta da raiz.

## Compilação com g++

```bash
g++ main.cpp arvore.cpp -o arvores_avl_rn
./arvores_avl_rn
```

## Compilação com CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
./arvores_avl_rn
```
