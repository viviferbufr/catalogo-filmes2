
#include <stdio.h>
#include <string.h>

// ==========================================
// 1. STRUCT - ESTRUTURA DOS FILMES
// ==========================================

struct filme {
    char nome[50];
    float nota;
    int avaliado;
};

// ==========================================
// 2. PROTOTIPOS DAS FUNCOES
// ==========================================

void listarFilmes(struct filme filmes[]);
void avaliarFilme(struct filme filmes[]);
int buscarFilme(struct filme filmes[], char busca[]);
void exibirEstatisticas(struct filme filmes[]);

// ==========================================
// 3. FUNCAO PARA LISTAR OS FILMES
// ==========================================

void listarFilmes(struct filme filmes[]) {
    int i;

    printf("\n===== FILMES =====\n");

    for (i = 0; i < 10; i++) {
        printf("%d - %s\n", i + 1, filmes[i].nome);
    }
}

// ==========================================
// 4. FUNCAO PARA AVALIAR UM FILME
// ==========================================

void avaliarFilme(struct filme filmes[]) {
    int i;
    int filmeEscolhido;
    float nota;

    printf("\n===== AVALIAR FILMES =====\n");

    listarFilmes(filmes);

    printf("Escolha o filme: ");
    scanf("%d", &filmeEscolhido);

    if (filmeEscolhido >= 1 && filmeEscolhido <= 10) {

        printf("\nDigite uma nota de 0 a 10: ");
        scanf("%f", &nota);

        if (nota >= 0 && nota <= 10) {

            filmes[filmeEscolhido - 1].nota = nota;
            filmes[filmeEscolhido - 1].avaliado = 1;

            printf("\nFilme escolhido: %s\n",
                   filmes[filmeEscolhido - 1].nome);

            printf("Nota registrada: %.2f\n", nota);

        } else {
            printf("Nota invalida! Digite uma nota de 0 a 10.\n");
        }

    } else {
        printf("Filme invalido.\n");
    }
}

// ==========================================
// 5. FUNCAO PARA BUSCAR UM FILME
// ==========================================

int buscarFilme(struct filme filmes[], char busca[]) {
    int i;

    for (i = 0; i < 10; i++) {

        if (strcmp(filmes[i].nome, busca) == 0) {
            return i;
        }
    }

    return -1;
}

// ==========================================
// 6. FUNCAO PARA EXIBIR AS ESTATISTICAS
// ==========================================

void exibirEstatisticas(struct filme filmes[]) {
    int i;
    int quantidade = 0;
    float soma = 0;
    float media;
    float maior = 0;
    float menor = 10;

    for (i = 0; i < 10; i++) {

        if (filmes[i].avaliado == 1) {

            quantidade++;
            soma += filmes[i].nota;

            if (quantidade == 1) {
                maior = filmes[i].nota;
                menor = filmes[i].nota;
            }

            if (filmes[i].nota > maior) {
                maior = filmes[i].nota;
            }

            if (filmes[i].nota < menor) {
                menor = filmes[i].nota;
            }
        }
    }

    printf("\n===== ESTATISTICAS =====\n");

    if (quantidade > 0) {

        media = soma / quantidade;

        printf("Filmes avaliados: %d\n", quantidade);
        printf("Soma das notas: %.2f\n", soma);
        printf("Media das notas: %.2f\n", media);
        printf("Maior nota: %.2f\n", maior);
        printf("Menor nota: %.2f\n", menor);

    } else {
        printf("Nenhum filme foi avaliado ainda!\n");
    }
}

// ==========================================
// 7. FUNCAO PRINCIPAL - MAIN
// ==========================================

int main() {

    // Vetor de structs com os filmes
    struct filme filmes[10] = {
        {"O Rei Leao", 0, 0},
        {"Aladdin", 0, 0},
        {"A Pequena Sereia", 0, 0},
        {"Mulan", 0, 0},
        {"Tarzan", 0, 0},
        {"Lilo e Stitch", 0, 0},
        {"Enrolados", 0, 0},
        {"Frozen", 0, 0},
        {"Moana", 0, 0},
        {"Encanto", 0, 0}
    };

    // Variaveis principais
    int opcao;
    int posicao;
    char busca[50];

    // Menu principal
    do {

        printf("\n===== CATALOGO DE FILMES DA DISNEY =====\n");
        printf("1 - Listar filmes\n");
        printf("2 - Avaliar filme\n");
        printf("3 - Buscar filme\n");
        printf("4 - Ver estatisticas\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);

        // Opcao 1 - Listar filmes
        if (opcao == 1) {

            listarFilmes(filmes);
        }

        // Opcao 2 - Avaliar filme
        else if (opcao == 2) {

            avaliarFilme(filmes);
        }

        // Opcao 3 - Buscar filme
        else if (opcao == 3) {

            printf("\n===== BUSCAR FILME =====\n");
            printf("Digite o nome do filme: ");
            scanf(" %[^\n]", busca);

            posicao = buscarFilme(filmes, busca);

            if (posicao != -1) {

                if (filmes[posicao].avaliado == 1) {

                    printf("Filme encontrado: %s, sua nota e: %.2f\n",
                           filmes[posicao].nome,
                           filmes[posicao].nota);

                } else {

                    printf("Filme encontrado: %s, ainda nao foi avaliado.\n",
                           filmes[posicao].nome);
                }

            } else {

                printf("Filme nao encontrado!\n");
            }
        }

        // Opcao 4 - Exibir estatisticas
        else if (opcao == 4) {

            exibirEstatisticas(filmes);
        }

        // Verificar opcao invalida
        else if (opcao != 5) {

            printf("Opcao invalida!\n");
        }

    } while (opcao != 5);

    // Encerrar programa
    printf("\nAgradecemos por usar nosso programa! :)");

    return 0;
}
