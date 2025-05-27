#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int populacao;
    double pib;
    int pontos_turisticos;
    double area;
} Cidade;

void mostrarCidade(Cidade c) {
    printf("CIDADE: %s\n", c.nome);
    printf("POPULACAO: %d\n", c.populacao);
    printf("PIB: %.2f\n", c.pib);
    printf("PONTOS TURISTICOS: %d\n", c.pontos_turisticos);
    printf("AREA: %.2f\n", c.area);
    printf("-----------------------------\n");
}

int main() {
    Cidade carta1 = {"Sao Paulo", 2500, 52000.00, 30, 1521.11};
    Cidade carta2 = {"Rio de Janeiro", 1700, 43000.00, 25, 1182.30};

    double densidade1 = (double)carta1.populacao / carta1.area;
    double densidade2 = (double)carta2.populacao / carta2.area;

    int escolha = 1; // <<< escolha fixa: 1 = Populacao

    printf(">>> CARTA 1 <<<\n");
    mostrarCidade(carta1);

    printf(">>> CARTA 2 <<<\n");
    mostrarCidade(carta2);

    printf("Escolha fixa: %d\n\n", escolha);
    printf(">>> RESULTADO <<<\n");

    switch (escolha) {
        case 1:
            printf("Populacao: %s = %d, %s = %d\n", carta1.nome, carta1.populacao, carta2.nome, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("%s vence em Populacao!\n", carta1.nome);
            else if (carta1.populacao < carta2.populacao)
                printf("%s vence em Populacao!\n", carta2.nome);
            else
                printf("Empate em Populacao!\n");
            break;

        case 2:
            printf("PIB: %s = %.2f, %s = %.2f\n", carta1.nome, carta1.pib, carta2.nome, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("%s vence em PIB!\n", carta1.nome);
            else if (carta1.pib < carta2.pib)
                printf("%s vence em PIB!\n", carta2.nome);
            else
                printf("Empate em PIB!\n");
            break;

        case 3:
            printf("Pontos Turisticos: %s = %d, %s = %d\n", carta1.nome, carta1.pontos_turisticos, carta2.nome, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("%s vence em Pontos Turisticos!\n", carta1.nome);
            else if (carta1.pontos_turisticos < carta2.pontos_turisticos)
                printf("%s vence em Pontos Turisticos!\n", carta2.nome);
            else
                printf("Empate em Pontos Turisticos!\n");
            break;

        case 4:
            printf("Densidade Demografica: %s = %.2f, %s = %.2f\n", carta1.nome, densidade1, carta2.nome, densidade2);
            if (densidade1 < densidade2)
                printf("%s vence em Densidade Demografica!\n", carta1.nome);
            else if (densidade1 > densidade2)
                printf("%s vence em Densidade Demografica!\n", carta2.nome);
            else
                printf("Empate em Densidade Demografica!\n");
            break;

        default:
            printf("Opcao invalida!\n");
    }

    return 0;
}