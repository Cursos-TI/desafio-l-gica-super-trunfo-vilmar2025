#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da estrutura da carta do Super Trunfo
typedef struct {
    char estado[3];
    char codigo[10];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int num_pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Função para cadastrar os dados de uma carta
Carta cadastrarCarta() {
    Carta carta;

    printf("Digite o Estado (sigla - ex: SP): ");
    fgets(carta.estado, sizeof(carta.estado), stdin);
    carta.estado[strcspn(carta.estado, "\n")] = 0; // Remover a quebra de linha

    printf("Digite o Código da Carta:\n");
    fgets(carta.codigo, sizeof(carta.codigo), stdin);
    carta.codigo[strcspn(carta.codigo, "\n")] = 0;

    printf("Digite o Nome da Cidade: ");
    fgets(carta.nome_cidade, sizeof(carta.nome_cidade), stdin);
    carta.nome_cidade[strcspn(carta.nome_cidade, "\n")] = 0;

    printf("Digite a População: ");
    scanf("%d", &carta.populacao);
    getchar(); // Limpar o buffer do teclado

    printf("Digite a Área (em km²): ");
    scanf("%f", &carta.area);
    getchar();

    printf("Digite o PIB (em milhões de R$): ");
    scanf("%f", &carta.pib);
    getchar();

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta.num_pontos_turisticos);
    getchar();

    // Calcular Densidade Populacional
    if (carta.area > 0) {
        carta.densidade_populacional = (float)carta.populacao / carta.area;
    } else {
        carta.densidade_populacional = 0;
    }

    // Calcular PIB per capita
    if (carta.populacao > 0) {
        carta.pib_per_capita = carta.pib * 1000000.0 / carta.populacao;
    } else {
        carta.pib_per_capita = 0;
    }

    return carta;
}

int main() {
    // Declaração das duas cartas
    Carta carta1, carta2;

    printf("--- Cadastro da Primeira Carta ---\n");
    carta1 = cadastrarCarta();

    printf("\n--- Cadastro da Segunda Carta ---\n");
    carta2 = cadastrarCarta();

    // Escolha do atributo para comparação (modifique aqui para alterar o atributo)
    // Opções: 1 - População, 2 - Área, 3 - PIB, 4 - Densidade Populacional, 5 - PIB per capita
    int atributo_escolhido = 1; // Comparando por População

    printf("\n--- Comparação de Cartas ---\n");

    switch (atributo_escolhido) {
        case 1: // Comparar por População
            printf("Comparação de cartas (Atributo: População):\n");
            printf("Carta 1 - %s (%s): %d\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
            printf("Carta 2 - %s (%s): %d\n", carta2.nome_cidade, carta2.estado, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: As cartas empataram!\n");
            }
            break;
        case 2: // Comparar por Área
            printf("Comparação de cartas (Atributo: Área):\n");
            printf("Carta 1 - %s (%s): %.2f\n", carta1.nome_cidade, carta1.estado, carta1.area);
            printf("Carta 2 - %s (%s): %.2f\n", carta2.nome_cidade, carta2.estado, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: As cartas empataram!\n");
            }
            break;
        case 3: // Comparar por PIB
            printf("Comparação de cartas (Atributo: PIB):\n");
            printf("Carta 1 - %s (%s): %.2f\n", carta1.nome_cidade, carta1.estado, carta1.pib);
            printf("Carta 2 - %s (%s): %.2f\n", carta2.nome_cidade, carta2.estado, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: As cartas empataram!\n");
            }
            break;
        case 4: // Comparar por Densidade Populacional
            printf("Comparação de cartas (Atributo: Densidade Populacional):\n");
            printf("Carta 1 - %s (%s): %.2f\n", carta1.nome_cidade, carta1.estado, carta1.densidade_populacional);
            printf("Carta 2 - %s (%s): %.2f\n", carta2.nome_cidade, carta2.estado, carta2.densidade_populacional);
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: As cartas empataram!\n");
            }
            break;
        case 5: // Comparar por PIB per capita
            printf("Comparação de cartas (Atributo: PIB per capita):\n");
            printf("Carta 1 - %s (%s): %.2f\n", carta1.nome_cidade, carta1.estado, carta1.pib_per_capita);
            printf("Carta 2 - %s (%s): %.2f\n", carta2.nome_cidade, carta2.estado, carta2.pib_per_capita);
            if (carta1.pib_per_capita > carta2.pib_per_capita) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome_cidade);
            } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome_cidade);
            } else {
                printf("Resultado: As cartas empataram!\n");
            }
            break;
        default:
            printf("Atributo de comparação inválido!\n");
            break;
    }

    return 0;
}