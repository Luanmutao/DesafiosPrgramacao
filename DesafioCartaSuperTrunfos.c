#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados das cartas
typedef struct {
    char estado[30];
    char codigo[10];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional; // Calculado
    float pibPerCapita;          // Calculado
} Carta;

// Função para calcular densidade populacional e PIB per capita
void calcularDados(Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib / carta->populacao;
}

// Função para exibir os resultados da comparação
void compararCartas(Carta carta1, Carta carta2, const char *atributo) {
    printf("\nComparação de cartas (Atributo: %s)\n", atributo);

    if (strcmp(atributo, "População") == 0) {
        printf("Carta 1 - %s: %d\n", carta1.nomeCidade, carta1.populacao);
        printf("Carta 2 - %s: %d\n", carta2.nomeCidade, carta2.populacao);
        if (carta1.populacao > carta2.populacao)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else if (strcmp(atributo, "Densidade Populacional") == 0) {
        printf("Carta 1 - %s: %.2f\n", carta1.nomeCidade, carta1.densidadePopulacional);
        printf("Carta 2 - %s: %.2f\n", carta2.nomeCidade, carta2.densidadePopulacional);
        if (carta1.densidadePopulacional < carta2.densidadePopulacional)
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
        else
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }
    // Você pode adicionar mais comparações (Área, PIB, etc.)
}

int main() {
    // Definindo duas cartas
    Carta carta1 = {"São Paulo", "SP01", "São Paulo", 12300000, 1521.11, 687000000000.0, 15};
    Carta carta2 = {"Rio de Janeiro", "RJ01", "Rio de Janeiro", 6000000, 1200.27, 362000000000.0, 12};

    // Calculando os valores adicionais
    calcularDados(&carta1);
    calcularDados(&carta2);

    // Escolhendo o atributo para comparação
    const char *atributo = "População"; // Alterar para outros atributos conforme necessário

    // Comparando as cartas
    compararCartas(carta1, carta2, atributo);

    return 0;
}