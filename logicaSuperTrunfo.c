#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char codigoCarta[3];
    char estado[3];
    char nomeCidade[30];
    double populacao;
    double areaKm;
    double pib;
    int pontosTuristicos;
    double densidadeDemografica;
    double pibPercapita;
} dadosCidade;

dadosCidade cidade[2];

// Função para cálculo da densidade demográfica
double calculaDensidadeDemografica(double populacao, double areaKm) {
    return populacao / areaKm;
}

// Função para cálculo do PIB per capita
double calculoPibPercapita(double pib, double populacao) {
    return pib / populacao;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao, opcao2, opcao3;

    while (1) {
        printf("\n***Escolha uma Opção****\n");
        printf("1. Iniciar jogo Trufo de Cartas\n");
        printf("2. Sair do jogo\n");
        printf("Insira a opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("\n***Escolha a opção***\n");
            printf("1. Cadastrar Cartas\n");
            printf("2. Comparar Cartas\n");
            printf("Insira a opção: ");
            scanf("%d", &opcao2);

            switch (opcao2) {
            case 1:
                for (int i = 0; i < 2; i++) {
                    printf("\nCódigo da Carta: ");
                    scanf("%3s", cidade[i].codigoCarta);
                    getchar();

                    printf("Estado: ");
                    scanf("%3s", cidade[i].estado);
                    getchar();

                    printf("Cidade: ");
                    fgets(cidade[i].nomeCidade, 30, stdin);
                    cidade[i].nomeCidade[strcspn(cidade[i].nomeCidade, "\n")] = '\0';

                    printf("Insira População: ");
                    scanf("%lf", &cidade[i].populacao);

                    printf("Insira Área em Km²: ");
                    scanf("%lf", &cidade[i].areaKm);

                    printf("Insira o PIB em mil: ");
                    scanf("%lf", &cidade[i].pib);

                    printf("Insira Quantidade de Pontos Turísticos: ");
                    scanf("%d", &cidade[i].pontosTuristicos);
                    getchar();
                    printf("****Próxima Carta*****\n");
                }

                for (int i = 0; i < 2; i++) {
                    cidade[i].densidadeDemografica = calculaDensidadeDemografica(cidade[i].populacao, cidade[i].areaKm);
                    cidade[i].pibPercapita = calculoPibPercapita(cidade[i].pib, cidade[i].populacao);
                }

                for (int i = 0; i < 2; i++) {
                    printf("\n==================================");
                    printf("\nCódigo Carta: %s", cidade[i].codigoCarta);
                    printf("\nEstado: %s", cidade[i].estado);
                    printf("\nCidade: %s", cidade[i].nomeCidade);
                    printf("\nPopulação: %.2lf", cidade[i].populacao);
                    printf("\nÁrea em Km²: %.2lf", cidade[i].areaKm);
                    printf("\nPIB em mil: %.2lf", cidade[i].pib);
                    printf("\nQuantidade de Pontos Turísticos: %d", cidade[i].pontosTuristicos);
                    printf("\nDensidade Demográfica: %.2lf", cidade[i].densidadeDemografica);
                    printf("\nPIB per Capita: %.2lf", cidade[i].pibPercapita);
                    printf("\n==================================\n");
                }
                break;

            case 2:
                printf("\n***Escolha o que vai comparar***\n");
                printf("1. Comparar População\n");
                printf("2. Comparar Área Km²\n");
                printf("3. Comparar PIB\n");
                printf("4. Comparar Pontos Turísticos\n");
                printf("5. Comparar Densidade Demográfica\n");
                printf("6. Comparar PIB Percapita\n");
                printf("Insira a opção de comparação: ");
                scanf("%d", &opcao3);

                switch (opcao3) {
                    case 1:
                        printf("\nPopulação da cidade 1: %.2lf", cidade[0].populacao);
                        printf("\nPopulação da cidade 2: %.2lf\n", cidade[1].populacao);
                        if (cidade[0].populacao == cidade[1].populacao) {
                            printf("Empate!\n");
                        } else if (cidade[0].populacao > cidade[1].populacao) {
                            printf("Jogador 1 ganhou!\n");
                        } else {
                            printf("Jogador 2 ganhou!\n");
                        }
                        break;
                    case 2:
                        printf("\nÁrea Km² da cidade 1: %.2lf", cidade[0].areaKm);
                        printf("\nÁrea Km² da cidade 2: %.2lf\n", cidade[1].areaKm);
                         if (cidade[0].areaKm == cidade[1].areaKm) {
                            printf("Empate!\n");
                        } else if (cidade[0].areaKm > cidade[1].areaKm) {
                            printf("Jogador 1 ganhou!\n");
                        } else {
                            printf("Jogador 2 ganhou!\n");
                        }
                        break;
                    case 3:
                        printf("\nPIB da cidade 1: %.2lf", cidade[0].pib);
                        printf("\nPIB da cidade 2: %.2lf\n", cidade[1].pib);
                         if (cidade[0].pib == cidade[1].pib) {
                            printf("Empate!\n");
                        } else if (cidade[0].pib > cidade[1].pib) {
                            printf("Jogador 1 ganhou!\n");
                        } else {
                            printf("Jogador 2 ganhou!\n");
                        }
                        break;
                    case 4:
                        printf("\nPontos Turísticos da cidade 1: %d", cidade[0].pontosTuristicos);
                        printf("\nPontos Turísticos da cidade 2: %d\n", cidade[1].pontosTuristicos);
                         if (cidade[0].pontosTuristicos == cidade[1].pontosTuristicos) {
                            printf("Empate!\n");
                        } else if (cidade[0].pontosTuristicos > cidade[1].pontosTuristicos) {
                            printf("Jogador 1 ganhou!\n");
                        } else {
                            printf("Jogador 2 ganhou!\n");
                        }
                        break;
                    case 5:
                        printf("\nDensidade Demográfica da cidade 1: %.2lf", cidade[0].densidadeDemografica);
                        printf("\nDensidade Demográfica da cidade 2: %.2lf\n", cidade[1].densidadeDemografica);
                         if (cidade[0].densidadeDemografica == cidade[1].densidadeDemografica) {
                            printf("Empate!\n");
                        } else if (cidade[0].densidadeDemografica < cidade[1].densidadeDemografica) {
                            printf("Jogador 1 ganhou!\n");
                        } else {
                            printf("Jogador 2 ganhou!\n");
                        }
                        break;
                    case 6:
                        printf("\nPIB per capita da cidade 1: %.2lf", cidade[0].pibPercapita);
                        printf("\nPIB per capita da cidade 2: %.2lf\n", cidade[1].pibPercapita);
                         if (cidade[0].pibPercapita == cidade[1].pibPercapita) {
                            printf("Empate!\n");
                        } else if (cidade[0].pibPercapita > cidade[1].pibPercapita) {
                            printf("Jogador 1 ganhou!\n");
                        } else {
                            printf("Jogador 2 ganhou!\n");
                        }
                        break;
                    default:
                        printf("Opção Inválida!\n");
                        break;
                }
                break;

            default:
                printf("Opção inválida!\n");
                break;
            }
            break;

        case 2:
            printf("Saindo do Jogo...\n");
            return 0;

        default:
            printf("Opção Inválida!\n");
            break;
        }
    }

    return 0;
}
