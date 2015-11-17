#include <stdio.h>
#include "help_further_help.h"

#define put_equally puts("================================================================================");
#define put_exch puts("Параметр --exchange:\n--exchange                        запуск программы Размен в автоматическом режиме\n --exchange number                запуск программы Размен с аргументом number (number - натуральное число)");
#define put_quens puts("Параметр --queens:\n--queens                          запуск программы Ферзи в автоматическом режиме\n--queens x1 y1 x2 y2 x3 y3        запуск программы Ферзи с аргументами x1, y1, x2, y2, x3, y3 (натуральные числа)");
#define put_quot puts("Параметр --quotient:\n--quotient                        запуск программы Деление уголком в автоматическом режиме\n--quotient dividend divider       запуск программы Деление уголком, где dividend - делимое, а divider - делитель");
#define put_matr puts("Параметр --matrix:\n--matrix                          запуск программы Матрица в автоматическом режиме\n--matrix <input> <output>         запуск программы Матрица с входными данными из файла input и с выводом в файл output");
#define put_str puts("Параметр --centered_lines:\n--lines_symmetrization            запуск программы Симметрирование строк в автоматическом режиме\n--lines_symmetrization <input> <output> запуск программы Симметрирование строк с входными данными из файла input и с выводом в файл output");


void help_exchange(void)
{
    put_equally;
    put_exch;
    put_equally;
}

void help_queens(void)
{
    put_equally;
    put_quens;
    put_equally;
}
void help_matrix(void)
{
    put_equally;
    put_matr;
    put_equally;
}

void help_quotient(void)
{
    put_equally;
    put_quot;
    put_equally;
}

void help_lines_symmetrization(void)
{
    put_equally;
    put_str;
    put_equally;
}

void help(void)
{
    put_equally;
    puts("Информация о параметрах командной строки\n"
         "Параметр --interactive:\n"
         "--interactive                     запуск приложения в интерактивном режиме");
    puts("Параметр --help:\n"
         "--help                            помощь");
    put_exch;
    put_quens;
    put_quot;

    put_matr;
    put_str;
    put_equally;
}
