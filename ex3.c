#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, min;
    
    printf("Quantos nomes deseja inserir? ");
    scanf("%d", &n);
    getchar(); // consome o \n deixado pelo scanf

    char nomes[n][100]; // matriz para armazenar até 100 caracteres por nome

    // leitura dos nomes
    for (i = 0; i < n; i++) {
        printf("Digite o nome %d: ", i + 1);
        fgets(nomes[i], 100, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0'; // remove o \n do final
    }

    // selection sort baseado no tamanho da string
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (strlen(nomes[j]) < strlen(nomes[min])) {
                min = j;
            }
        }
        if (min != i) {
            char temp[100];
            strcpy(temp, nomes[i]);
            strcpy(nomes[i], nomes[min]);
            strcpy(nomes[min], temp);
        }
    }

    // saída dos nomes ordenados
    printf("\nNomes ordenados pelo tamanho:\n");
    for (i = 0; i < n; i++) {
        printf("%s (%lu letras)\n", nomes[i], strlen(nomes[i]));
    }

    return 0;
}
