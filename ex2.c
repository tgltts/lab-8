#include <stdio.h>
#include <string.h>

#define MAX_NOMES 100
#define TAM_NOME 100

int main() {
    char nomes[MAX_NOMES][TAM_NOME];
    int n;

    printf("Quantos nomes deseja inserir? ");
    scanf("%d", &n);
    getchar(); // Consome o '\n' deixado pelo scanf

    for (int i = 0; i < n; i++) {
        char nome[TAM_NOME];

        printf("Digite o nome %d: ", i + 1);
        fgets(nome, TAM_NOME, stdin);

        // Remove o '\n' do final se presente
        nome[strcspn(nome, "\n")] = '\0';

        // Inserção ordenada (estilo insertion sort)
        int j = i - 1;

        // Desloca os nomes maiores para frente
        while (j >= 0 && strcmp(nomes[j], nome) > 0) {
            strcpy(nomes[j + 1], nomes[j]);
            j--;
        }

        // Insere o nome na posição correta
        strcpy(nomes[j + 1], nome);
    }

    printf("\nNomes em ordem alfabetica:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }

    return 0;
}
