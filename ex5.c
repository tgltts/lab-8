#include <stdio.h>
#include <string.h>

#define MAX 100
#define TAM 101

typedef struct {
    char s1[TAM];
    char s2[TAM];
    char s3[TAM];
} Entrada;

int main() {
    int n;
    printf("Digite o número de entradas: ");
    scanf("%d", &n);
    getchar(); // consome o \n

    Entrada entradas[MAX];

    // leitura das entradas
    for (int i = 0; i < n; i++) {
        printf("\nEntrada %d:\n", i + 1);
        fgets(entradas[i].s1, TAM, stdin);
        entradas[i].s1[strcspn(entradas[i].s1, "\n")] = '\0';
        fgets(entradas[i].s2, TAM, stdin);
        entradas[i].s2[strcspn(entradas[i].s2, "\n")] = '\0';
        fgets(entradas[i].s3, TAM, stdin);
        entradas[i].s3[strcspn(entradas[i].s3, "\n")] = '\0';
    }

    // ordenação lexicográfica (Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            int cmp1 = strcmp(entradas[j].s1, entradas[min].s1);
            if (cmp1 < 0) {
                min = j;
            } else if (cmp1 == 0) {
                int cmp2 = strcmp(entradas[j].s2, entradas[min].s2);
                if (cmp2 < 0) {
                    min = j;
                } else if (cmp2 == 0) {
                    if (strcmp(entradas[j].s3, entradas[min].s3) < 0) {
                        min = j;
                    }
                }
            }
        }
        if (min != i) {
            Entrada temp = entradas[i];
            entradas[i] = entradas[min];
            entradas[min] = temp;
        }
    }

    // saída
    printf("\nEntradas ordenadas:\n");
    for (int i = 0; i < n; i++) {
        printf("%s, %s, %s\n", entradas[i].s1, entradas[i].s2, entradas[i].s3);
    }

    return 0;
}
