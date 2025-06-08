#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR_SET 100
#define MAX_PASSWORD_LENGHT 128

void build_charset(char *charset, int use_upper, int use_lower, int use_numbers, int use_special) {
    if (use_upper) strcat(charset, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if (use_lower) strcat(charset, "abcdefghijklmnopqrstuvwxyz");
    if (use_numbers) strcat(charset, "0123456789");
    if (use_special) strcat(charset, "!@#$%^&*()-_=+[]{}|;:,.<>?");
}

void shuffle(char *array, int length) {
    for (int i = length - 1; i > 0; i--){
        int j = rand() % (i + 1);
        char temp = array[i];
        array[i] = array[i];
        array[j] = temp;
    }
}

void generate_password(char *charset, int length, char *password) {
    int charset_length = strlen(charset);

    if (length > charset_length) {
        printf("Erro: Número de caracteres únicos disponíveis é menor que o tamanho da senha!\n");
        exit(1);
    }

    char temp_charset[MAX_CHAR_SET];
    strcpy(temp_charset, charset);
    shuffle(temp_charset, charset_length);

    strncpy(password, temp_charset, length);
    password[length] = '\0';
}

int main() {
    srand(time(NULL));

    int length, use_upper, use_lower, use_numbers, use_special, num_passwords;
    char charset[MAX_CHAR_SET] = "";
    char password[MAX_PASSWORD_LENGHT];

    printf("Tamanho da senha: ");
    scanf("%d", &length);
    printf("Incluir letras maiúsculas? (1 = Sim, 0 = Não): ");
    scanf("%d", &use_upper);
    printf("Incluir letras minúsculas? (1 = Sim, 0 = Não): ");
    scanf("%d", &use_lower);
    printf("Incluir números? (1 = Sim, 0 = Não): ");
    scanf("%d", &use_numbers);
    printf("Incluir caracteres especiais? (1 = Sim, 0 = Não): ");
    scanf("%d", &use_special);
    printf("Quantas senhas deseja gerar?: ");
    scanf("%d", &num_passwords);

    build_charset(charset, use_upper, use_lower, use_numbers, use_special);

    if (strlen(charset) == 0) {
    printf("Nenhuma opção de caractere fpo selecionada. Encerrando.\n");
    return 1;
    }

    for (int i = 0; i < num_passwords; i++) {
        generate_password(charset, length, password);
        printf("Senha %d: %s\n", i + 1, password);
    }

    printf("\nPressione Enter para sair...");
    getchar();
    getchar();

    return 0;
}