#include <stdio.h>
#include <string.h>

void bubbleSortComSentinela(char str[]) {
    int n = strlen(str);
    int i;
    int trocou;  // Sentinela

    do {
        trocou = 0;  // No início da iteração, nenhuma troca foi feita
        for (i = 0; i < n - 1; i++) {
            if (str[i] > str[i + 1]) {
                // Troca os caracteres
                char temp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = temp;
                trocou = 1;  // Marca que houve troca
            }
        }
        // Após cada iteração, o maior elemento vai para o fim
        // Então podemos diminuir o tamanho da verificação
        n--;
    } while (trocou);
}

int main() {
    char str[100];

    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remove o caractere de nova linha (\n), se presente
    str[strcspn(str, "\n")] = '\0';

    bubbleSortComSentinela(str);

    printf("String ordenada: %s\n", str);

    return 0;
}
