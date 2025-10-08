#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Digite o número de strings: ");
    scanf("%d", &n);
    getchar(); // consome o \n do scanf

    char strings[n][101]; // até 100 caracteres + '\0'

    // leitura das strings
    for (int i = 0; i < n; i++) {
        printf("Digite a string %d: ", i + 1);
        fgets(strings[i], 101, stdin);
        strings[i][strcspn(strings[i], "\n")] = '\0'; // remove o \n
    }

    // ordenação lexicográfica (Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(strings[j], strings[min]) < 0) {
                min = j;
            }
        }
        if (min != i) {
            char temp[101];
            strcpy(temp, strings[i]);
            strcpy(strings[i], strings[min]);
            strcpy(strings[min], temp);
        }
    }

    // saída das strings ordenadas
    printf("\nStrings ordenadas:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    return 0;
}
