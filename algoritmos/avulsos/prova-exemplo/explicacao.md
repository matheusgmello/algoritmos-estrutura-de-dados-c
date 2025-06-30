
# 📘 Exemplo de Remoção de Livro em Vetor – Linguagem C

## 🧾 Estrutura de dados

```c
struct Livros {
  int codigo;
  char titulo[50];
  int quantidade;
};
```

---

## 🧠 Situação inicial

Suponha que temos o seguinte vetor com 3 livros:

| Índice | Código | Título   | Quantidade |
|--------|--------|----------|------------|
| 0      | 1      | Livro A  | 5          |
| 1      | 2      | Livro B  | 3 ← queremos remover esse |
| 2      | 3      | Livro C  | 7          |

---

## 🎯 Objetivo

Remover o livro com `codigo = 2`.

---

## 🔁 Loop de deslocamento

A função `removerLivro` localiza o livro e desloca os elementos à frente uma posição para trás:

```c
for (int j = i; j < n - 1; j++) {
  livros[j] = livros[j + 1];
}
```

---

## 📊 Vetor **depois do deslocamento**

| Índice | Código | Título   | Quantidade |
|--------|--------|----------|------------|
| 0      | 1      | Livro A  | 5          |
| 1      | 3      | Livro C  | 7          |
| 2      | 3      | Livro C  | 7 (duplicado, será limpo) |

> Ainda temos um "duplicado" na última posição, pois ela não foi apagada ainda.

---

## 🧹 Limpeza da última posição (opcional)

```c
livros[n - 1].codigo = 0;
livros[n - 1].titulo[0] = '\0';
livros[n - 1].quantidade = 0;
```

---

## 📦 Resultado final (com `n = n - 1`)

| Índice | Código | Título     | Quantidade |
|--------|--------|------------|------------|
| 0      | 1      | Livro A    | 5          |
| 1      | 3      | Livro C    | 7          |
| 2      | 0      | "" (vazio) | 0          |

---

## ✅ Atualização no `main`

Lembre-se de atualizar o número total de livros no `main`:

```c
n = removerLivro(livros, n, 2);
```
