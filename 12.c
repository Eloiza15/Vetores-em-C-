#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
//#include <windows.h>

int main() {
    setlocale(LC_ALL, "Portuguese");

    printf("Carregando o sistema, por favor aguarde...\n");
    sleep(3);
    //Sleep(500);

    int opcao = 0;

    float notas[5][4];
    float soma, media;

    do {
        system("cls");
        printf("\nMENU:\n");
        printf("------\n");
        printf("1- Cadastro de Notas (Suporta 5 alunos)\n ");
        printf("2- Alteração de Notas\n");
        printf("3- Sair\n\n");
        printf("Escolha uma opção:\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                system("cls");
                printf("\nCadastro de Notas (Suporta 5 alunos)\n\n\n");
                printf("Digite as 4 notas de cada aluno (elas devem ser de 0 a 10)\n");

                for (int i = 0; i < 5; i++) {
                    soma = 0;
                    printf("\n\nAluno %d: \n", i + 1);
                    for (int j = 0; j < 4; j++) {
                        do {
                            printf("Nota %d: ", j + 1);
                            scanf("%f", &notas[i][j]);

                            if (notas[i][j] < 0 || notas[i][j] > 10) {
                                printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                            }
                        } while (notas[i][j] < 0 || notas[i][j] > 10);

                        soma += notas[i][j];
                    }

                    media = soma / 4;

                    printf("Soma das notas: %.2f\n", soma);
                    printf("Média das notas: %.2f\n", media);

                    if (media >= 6) {
                        printf("Situação: APROVADO\n");
                    } else if (media < 4) {
                        printf("Situação: REPROVADO\n");
                    } else {
                        printf("Situação: RECUPERAÇÃO\n");
                    }
                }

                break;

            case 2:
                system("cls");
                printf("\nAlteração de Notas\n\n\n");

                int aluno;
                printf("Digite o número do aluno que deseja alterar as notas (1 a 5):\n\n ");
                scanf("%d", &aluno);

                if (aluno < 1 || aluno > 5) {
                    printf("Número de aluno inválido.\n\n");
                    break;
                }

                printf("Digite as novas notas do aluno %d:\n\n", aluno);

                soma = 0;
                for (int j = 0; j < 4; j++) {
                    do {
                        printf("Nota %d: ", j + 1);
                        scanf("%f", &notas[aluno - 1][j]);

                        if (notas[aluno - 1][j] < 0 || notas[aluno - 1][j] > 10) {
                            printf("Nota inválida! Insira uma nota entre 0 e 10.\n");
                        }
                    } while (notas[aluno - 1][j] < 0 || notas[aluno - 1][j] > 10);

                    soma += notas[aluno - 1][j];
                }

                media = soma / 4;

                printf("\nNova soma das notas: %.2f\n", soma);
                printf("Nova média das notas: %.2f\n", media);

                if (media >= 6) {
                    printf("Nova Situação: APROVADO\n");
                } else if (media < 4) {
                    printf("Nova Situação: REPROVADO\n");
                } else {
                    printf("Nova Situação: RECUPERAÇÃO\n");
                }

                break;

            case 3:
                printf("Você Saiu do Programa!\n");
                break;

            default:
                printf("Opção Inválida!\n");
        }

    } while (opcao != 3);

    return 0;
}
