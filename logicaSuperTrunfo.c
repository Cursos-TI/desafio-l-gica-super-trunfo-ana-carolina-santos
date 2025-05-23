#include <stdio.h>

// Estrutura da carta
struct Carta {
    char estado[3];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

// Função para exibir uma linha separadora
void linha() {
    printf("--------------------------------------------------\n");
}

int main() {
    // Cadastro das duas cartas
    struct Carta carta1 = {
        "SP", "C01", "São Paulo",
        12300000, 1521.11, 2300000.0, 25
    };

    struct Carta carta2 = {
        "RJ", "C02", "Rio de Janeiro",
        6000000, 1182.30, 1500000.0, 20
    };

    // Cálculos adicionais
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // 1. Comparação por População
    linha();
    printf("Comparação: População\n");
    printf("Carta 1 - %s: %d\n", carta1.nome, carta1.populacao);
    printf("Carta 2 - %s: %d\n", carta2.nome, carta2.populacao);
    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: %s venceu!\n", carta1.nome);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: %s venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    // 2. Comparação por Área
    linha();
    printf("Comparação: Área\n");
    printf("Carta 1 - %s: %.2f km²\n", carta1.nome, carta1.area);
    printf("Carta 2 - %s: %.2f km²\n", carta2.nome, carta2.area);
    if (carta1.area > carta2.area) {
        printf("Resultado: %s venceu!\n", carta1.nome);
    } else if (carta2.area > carta1.area) {
        printf("Resultado: %s venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    // 3. Comparação por PIB
    linha();
    printf("Comparação: PIB\n");
    printf("Carta 1 - %s: R$ %.2f milhões\n", carta1.nome, carta1.pib);
    printf("Carta 2 - %s: R$ %.2f milhões\n", carta2.nome, carta2.pib);
    if (carta1.pib > carta2.pib) {
        printf("Resultado: %s venceu!\n", carta1.nome);
    } else if (carta2.pib > carta1.pib) {
        printf("Resultado: %s venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    // 4. Comparação por Densidade Populacional (menor valor vence!)
    linha();
    printf("Comparação: Densidade Populacional (menor vence)\n");
    printf("Carta 1 - %s: %.2f hab/km²\n", carta1.nome, carta1.densidadePopulacional);
    printf("Carta 2 - %s: %.2f hab/km²\n", carta2.nome, carta2.densidadePopulacional);
    if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
        printf("Resultado: %s venceu!\n", carta1.nome);
    } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
        printf("Resultado: %s venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    // 5. Comparação por PIB per capita
    linha();
    printf("Comparação: PIB per capita\n");
    printf("Carta 1 - %s: R$ %.2f\n", carta1.nome, carta1.pibPerCapita);
    printf("Carta 2 - %s: R$ %.2f\n", carta2.nome, carta2.pibPerCapita);
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Resultado: %s venceu!\n", carta1.nome);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Resultado: %s venceu!\n", carta2.nome);
    } else {
        printf("Resultado: Empate!\n");
    }

    linha();
    return 0;
}