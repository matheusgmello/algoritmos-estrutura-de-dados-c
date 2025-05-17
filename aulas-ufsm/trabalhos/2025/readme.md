# 🎯 Caça ao Número

## 📌 Descrição

**Caça ao Número** é um jogo simples feito em linguagem C onde o jogador precisa descobrir **5 números escondidos (valor 9)** em uma matriz 5x5. O projeto foi desenvolvido como trabalho acadêmico da disciplina de Programação (2025/1), com foco em lógica, uso de matrizes, controle de fluxo e entrada de dados.

---

## 🕹️ Regras do Jogo

- A matriz começa oculta, preenchida apenas com o número `0`.
- O programa insere **cinco números 9** em posições aleatórias da matriz.
- O jogador tem **10 tentativas** para acertar o máximo possível dessas posições.
- A cada tentativa:
  - O jogador informa a linha e a coluna (valores de 1 a 5).
  - Se acertar uma posição com `9`, ganha 1 ponto.
  - Se errar, a posição escolhida é marcada como `-1`.

---

## 🧾 O que o jogo exibe no final

- A matriz final com:
  - `9` nas posições corretas encontradas;
  - `-1` nos erros;
  - `0` nas posições ainda não reveladas.
- Número total de acertos.
- Número de tentativas utilizadas.
- Porcentagem de acertos com a fórmula:

```c
(acertos / tentativas) * 100%
```

## Autores

**Matheus E Isaac**