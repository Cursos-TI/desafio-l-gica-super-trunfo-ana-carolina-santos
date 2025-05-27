#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    double pib;
    int pontos_turisticos;
    double area;
    double densidade;
} Cidade;

void mostrarCidade(Cidade c) {
    printf("CIDADE: %s\n", c.nome);
    printf("POPULACAO: %d\n", c.populacao);
    printf("PIB: %.2f\n", c.pib);
    printf("PONTOS TURISTICOS: %d\n", c.pontos_turisticos);
    printf("AREA: %.2f\n", c.area);
    printf("DENSIDADE: %.2f\n", c.densidade);
    printf("-----------------------------\n");
}

double obterValor(Cidade c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.pib;
        case 3: return c.pontos_turisticos;
        case 4: return c.densidade;
        default: return 0;
    }
}

const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "Populacao";
        case 2: return "PIB";
        case 3: return "Pontos Turisticos";
        case 4: return "Densidade Demografica";
        default: return "";
    }
}

int main() {
    Cidade carta1 = {"Sao Paulo", 2500, 52000.00, 30, 1521.11, 1.64};
    Cidade carta2 = {"Rio de Janeiro", 1700, 43000.00, 25, 1182.30, 1.44};

    printf(">>> CARTA 1 <<<\n");
    mostrarCidade(carta1);

    printf(">>> CARTA 2 <<<\n");
    mostrarCidade(carta2);

    // Já definidos: atributo 1 = Populacao, atributo 2 = PIB (você pode mudar)
    int opcao1 = 1;  // Populacao
    int opcao2 = 2;  // PIB

    printf("Comparando atributos automaticamente:\n");
    printf("Primeiro atributo: %s\n", nomeAtributo(opcao1));
    printf("Segundo atributo: %s\n\n", nomeAtributo(opcao2));

    double valor1_c1 = obterValor(carta1, opcao1);
    double valor1_c2 = obterValor(carta2, opcao1);

    double valor2_c1 = obterValor(carta1, opcao2);
    double valor2_c2 = obterValor(carta2, opcao2);

    printf(">>> RESULTADO DA COMPARACAO <<<\n");

    // Comparação do primeiro atributo
    printf("\n%s:\n", nomeAtributo(opcao1));
    printf("%s: %.2f\n", carta1.nome, valor1_c1);
    printf("%s: %.2f\n", carta2.nome, valor1_c2);

    int vencedor1;
    if (opcao1 == 4) {  // Densidade, menor vence
        vencedor1 = (valor1_c1 < valor1_c2) ? 1 : (valor1_c1 > valor1_c2) ? 2 : 0;
    } else {
        vencedor1 = (valor1_c1 > valor1_c2) ? 1 : (valor1_c1 < valor1_c2) ? 2 : 0;
    }

    printf("Vencedor no atributo 1: %s\n",
           (vencedor1 == 1) ? carta1.nome : (vencedor1 == 2) ? carta2.nome : "Empate");

    // Comparação do segundo atributo
    printf("\n%s:\n", nomeAtributo(opcao2));
    printf("%s: %.2f\n", carta1.nome, valor2_c1);
    printf("%s: %.2f\n", carta2.nome, valor2_c2);

    int vencedor2;
    if (opcao2 == 4) {  // Densidade, menor vence
        vencedor2 = (valor2_c1 < valor2_c2) ? 1 : (valor2_c1 > valor2_c2) ? 2 : 0;
    } else {
        vencedor2 = (valor2_c1 > valor2_c2) ? 1 : (valor2_c1 < valor2_c2) ? 2 : 0;
    }

    printf("Vencedor no atributo 2: %s\n",
           (vencedor2 == 1) ? carta1.nome : (vencedor2 == 2) ? carta2.nome : "Empate");

    // Soma dos atributos
    double soma1 = valor1_c1 + valor2_c1;
    double soma2 = valor1_c2 + valor2_c2;

    printf("\nSOMA DOS ATRIBUTOS:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);

    if (soma1 > soma2) {
        printf(">>> %s vence a rodada!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf(">>> %s vence a rodada!\n", carta2.nome);
    } else {
        printf(">>> Empate!\n");
    }

    return 0;
}
