#include <stdio.h>
#include <string.h>

#define TAMANHO_CAMPO 4
#define NUM_BARCOS 4
#define JOGADAS 4

// Função para inicializar o campo de jogo
void inicializar_campo(int campo[TAMANHO_CAMPO][TAMANHO_CAMPO]) {
    for (int i = 0; i < TAMANHO_CAMPO; i++) {
        for (int j = 0; j < TAMANHO_CAMPO; j++) {
            campo[i][j] = 0; // 0 representa espaço vazio
        }
    }
}

// Função para exibir o campo
void exibir_campo(int campo[TAMANHO_CAMPO][TAMANHO_CAMPO]) {
    printf("\nCampo de jogo:\n");
    for (int i = 0; i < TAMANHO_CAMPO; i++) {
        for (int j = 0; j < TAMANHO_CAMPO; j++) {
            printf("%d ", campo[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar barcos no campo
void posicionar_barcos(int campo[TAMANHO_CAMPO][TAMANHO_CAMPO], char *jogador) {
    int x, y, valor_barco;
    printf("\n%s, posicione seus barcos (4 no total):\n", jogador);
    for (int i = 0; i < NUM_BARCOS; i++) {
        do {
            printf("Posicione o barco %d (valor entre 1 e 4):\n", i + 1);
            printf("Informe linha (0-3) e coluna (0-3): ");
            scanf("%d %d", &x, &y);
            if (x < 0 || x >= TAMANHO_CAMPO || y < 0 || y >= TAMANHO_CAMPO || campo[x][y] != 0) {
                printf("Posição inválida ou já ocupada! Tente novamente.\n");
            } else {
                printf("Informe o valor do barco (1-4): ");
                scanf("%d", &valor_barco);
                if (valor_barco < 1 || valor_barco > 4) {
                    printf("Valor inválido! Deve ser entre 1 e 4.\n");
                } else {
                    campo[x][y] = valor_barco;
                    break;
                }
            }
        } while (1);
    }
}

// Função para processar jogadas
int realizar_jogadas(int campo[TAMANHO_CAMPO][TAMANHO_CAMPO], char *jogador) {
    int x, y, pontos = 0;
    printf("\n%s, realize suas 4 jogadas:\n", jogador);
    for (int i = 0; i < JOGADAS; i++) {
        printf("Jogada %d - Informe linha (0-3) e coluna (0-3): ", i + 1);
        scanf("%d %d", &x, &y);
        if (x < 0 || x >= TAMANHO_CAMPO || y < 0 || y >= TAMANHO_CAMPO) {
            printf("Jogada inválida! Posição fora do campo. Sem pontos.\n");
        } else if (campo[x][y] > 0) {
            printf("Acertou! Barco de valor %d destruído.\n", campo[x][y]);
            pontos += campo[x][y];
            campo[x][y] = 0; // Remove o barco após o acerto
        } else {
            printf("Errou! Espaço vazio.\n");
        }
    }
    return pontos;
}

int main() {
    char jogador1[50], jogador2[50];
    int campo1[TAMANHO_CAMPO][TAMANHO_CAMPO], campo2[TAMANHO_CAMPO][TAMANHO_CAMPO];
    int pontos1, pontos2;

    // Leitura dos apelidos dos jogadores
    printf("Informe o apelido do Jogador 1: ");
    scanf("%s", jogador1);
    printf("Informe o apelido do Jogador 2: ");
    scanf("%s", jogador2);

    // Inicializar os campos de jogo
    inicializar_campo(campo1);
    inicializar_campo(campo2);

    // Posicionar barcos para cada jogador
    posicionar_barcos(campo1, jogador1);
    posicionar_barcos(campo2, jogador2);

    // Realizar jogadas
    pontos1 = realizar_jogadas(campo2, jogador1);
    pontos2 = realizar_jogadas(campo1, jogador2);

    // Exibir o placar final
    printf("\n=== Placar Final ===\n");
    printf("%s: %d pontos\n", jogador1, pontos1);
    printf("%s: %d pontos\n", jogador2, pontos2);

    if (pontos1 > pontos2) {
        printf("Parabéns, %s! Você venceu!\n", jogador1);
    } else if (pontos2 > pontos1) {
        printf("Parabéns, %s! Você venceu!\n", jogador2);
    } else {
        printf("Empate! Ambos jogaram bem.\n");
    }
}
