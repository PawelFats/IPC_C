#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100 // Максимальная длина команды
#define MAX_ARGUMENTS 10 // Максимальное количество аргументов

int main() {
    char command[MAX_COMMAND_LENGTH]; // Буфер для хранения команды
    char *arguments[MAX_ARGUMENTS]; // Массив указателей на аргументы
    char *token; // Указатель на текущий токен
    int num_arguments; // Количество аргументов

    while (1) {
        printf("Введите команду: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Удаляем символ новой строки

        // Разбиваем команду на аргументы по пробелам
        token = strtok(command, " ");
        num_arguments = 0;

        while (token != NULL && num_arguments < MAX_ARGUMENTS - 1) {
            arguments[num_arguments++] = token;
            token = strtok(NULL, " ");
        }
        arguments[num_arguments] = NULL; // Завершаем массив аргументов нулевым указателем

        if (strcmp(arguments[0], "exit") == 0) {
            // Если введена команда "exit", завершаем программу
            exit(0);
        } else {
            // Выполняем введенную команду
            execvp(arguments[0], arguments);
        }
    }

    return 0;
}
