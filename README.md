
# Jogo de Batalha Naval em C

Este repositório contém a implementação de um jogo de Batalha Naval em C para dois jogadores. O jogo é simples e estratégico, onde os jogadores posicionam barcos em um campo e tentam destruí-los enquanto acumulam pontos.

## Funcionalidades do Jogo

1. **Leitura de Apelidos**: Cada jogador informa seu apelido no início do jogo.
2. **Posicionamento de Barcos**: Cada jogador posiciona 4 barcos em uma matriz 4x4.
3. **Valor dos Barcos**: Cada barco possui um valor de pontuação entre 1 e 4.
4. **Realização de Jogadas**: Cada jogador faz 4 jogadas tentando acertar os barcos do adversário.
5. **Cálculo do Placar**: Ao final, o programa exibe o placar e declara o vencedor ou empate.

## Como Rodar o Código

- Compile o arquivo com um compilador como `gcc`.
- Exemplo:
  ```bash
  gcc batalha_naval.c -o batalha_naval
  ./batalha_naval
  ```

## Regras do Jogo

1. O campo de batalha é uma matriz 4x4 onde:
   - `0` indica espaço vazio.
   - Valores de `1` a `4` indicam barcos com suas respectivas pontuações.
2. Cada jogador posiciona 4 barcos, escolhendo linha, coluna e o valor do barco.
3. Durante as jogadas:
   - Jogadas fora do campo são inválidas.
   - Acertar um barco dá pontos equivalentes ao seu valor.
   - Acertar um espaço vazio não pontua.
4. Ao final, o jogador com maior pontuação vence.

## Estrutura do Projeto

1. **Inicialização do Campo**: O campo de batalha é preenchido com zeros.
2. **Posicionamento de Barcos**: Jogadores escolhem posições para seus barcos.
3. **Realização de Jogadas**: Cada jogador faz 4 jogadas, informando linha e coluna para atacar.
4. **Exibição do Placar**: O programa calcula e exibe o placar final.
