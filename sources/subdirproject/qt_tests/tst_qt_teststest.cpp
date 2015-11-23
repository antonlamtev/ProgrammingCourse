#include <QString>
#include <QtTest>
#include <stdlib.h>
#include "exchange_change.h"
#include "exchange_structures_declaration.h"
#include "queens_operands_declaration.h"
#include "queens_result.h"
#include "queens_check_for_beating.h"
#include "quotient_process.h"
#include "lines_symmetrization_algorithms.h"

//int compare_files(char *file_name_1, char *file_name_2);

//если полностью не объявить функции в этом файле, то выскакивают undefined reference.
//и это несмотря на то, что подключены библиотеки

//struct purse change_by_coins(int amount);
//int queens_result(struct coordinate x, struct coordinate y);
//int check_for_beating(int x1, int y1, int x2, int y2);
//int determine_file_proportions(char *input_file_name, int *number_of_lines, int *max_length_of_line);
//void quotient_out(FILE *stream, int first_number, int second_number);
//void print_n_symbols(FILE *stream, int n, char symbol);
//int n_th_dig_of_num(int n, int num);
//int power(int a, int b);
//int numlen(int num);

class Qt_testsTest : public QObject
{
    Q_OBJECT

public:
    Qt_testsTest();

private Q_SLOTS:
//    void exchange_test();
//    void queens_test();
//    void quotient_test();
//    void matrix_test();
//    void lines_simmetrization_test();
};

Qt_testsTest::Qt_testsTest()
{
}

//void Qt_testsTest::exchange_test()
//{
//    struct purse coins1_expected;
//    coins1_expected.fives = 5;
//    coins1_expected.twos = 1;
//    coins1_expected.ones = 1;
//    struct purse coins1_actual = change_by_coins(28);

//    QCOMPARE(coins1_actual.fives, coins1_expected.fives);
//    QCOMPARE(coins1_actual.twos, coins1_expected.twos);
//    QCOMPARE(coins1_actual.ones, coins1_expected.ones);

//    struct purse coins2_expected;
//    coins2_expected.fives = 8;
//    coins2_expected.twos = 2;
//    coins2_expected.ones = 0;
//    struct purse coins2_actual = change_by_coins(44);

//    QCOMPARE(coins2_actual.fives, coins2_expected.fives);
//    QCOMPARE(coins2_actual.twos, coins2_expected.twos);
//    QCOMPARE(coins2_actual.ones, coins2_expected.ones);

//}

//void Qt_testsTest::queens_test()
//{
//    struct coordinate x_actual, y_actual;
//    x_actual.first = 1;
//    y_actual.first = 2;
//    x_actual.second = 2;
//    y_actual.second = 3;
//    x_actual.third = 3;
//    y_actual.third = 4;

//    QCOMPARE(queens_result(x_actual, y_actual), 1);
//}

//void Qt_testsTest::quotient_test()
//{
//    FILE *actual = fopen("actual", "w");
//    quotient_out(actual, 1234567, 89);
//    fclose(actual);
//    QCOMPARE(compare_files("actual", "expected"), 1);
//}

//int compare_files(char *file_name_1, char *file_name_2)
//{
//    int flag = 1;
//    int number_of_lines_1, number_of_lines_2;
//    int max_length_of_line_1, max_length_of_line_2;
//    determine_file_proportions(file_name_1, &number_of_lines_1, &max_length_of_line_1);
//    determine_file_proportions(file_name_2, &number_of_lines_2, &max_length_of_line_2);
//    FILE *actual, *expected;
//    actual = fopen(file_name_1, "r");
//    expected = fopen(file_name_2, "r");

//    char *str1, *str2;
//    str1 = (char *) calloc(max_length_of_line_1, sizeof(char));
//    str2 = (char *) calloc(max_length_of_line_2, sizeof(char));
//    if (number_of_lines_1 == number_of_lines_2)
//    {
//        int i;
//        for (i = 0; i <= number_of_lines_1; ++i)
//        {
//            fgets(str1, max_length_of_line_1, actual);
//            fgets(str2, max_length_of_line_2, expected);
//            //puts(str1);
//            //puts(str2);
//            if (strcmp(str1, str2))
//            {
//                flag = 0;
//                break;
//            }
//        }
//        free(str1);
//        free(str2);
//    }
//    else
//    {
//        flag = 0;
//    }
//    fclose(actual);
//    fclose(expected);
//    return flag;
//}

//struct purse change_by_coins(int amount)
//{
//    struct purse coins;
//    coins.fives = amount / 5;
//    coins.twos = (amount - (coins.fives * 5)) / 2;
//    if (amount % 5 == 3)
//        coins.ones = 1;
//    else
//        coins.ones = 0;
//    return coins;
//}

//int check_for_beating(int x1, int y1, int x2, int y2)
//{
//    return (x1 == x2 || y1 == y2) || (abs(x1-x2) == abs(y1-y2));

//}

//int queens_result(struct coordinate x, struct coordinate y)
//{
//    int result = no_one;
//    if (check_for_beating(x.first, y.first, x.second, y.second))
//    {
//        if (check_for_beating(x.first, y.first, x.third, y.third))
//        {
//            if (check_for_beating(x.third, y.third, x.second, y.second))
//            {
//                result = everyone;
//            }
//            else
//            {
//                result = OneTwo_OneThree;
//            }
//        }
//        else
//        {
//            if (check_for_beating(x.third, y.third, x.second, y.second))
//            {
//                result = OneTwo_TwoThree;
//            }
//            else
//            {
//                result = OneTwo;
//            }
//        }
//    }
//    else if (check_for_beating(x.first, y.first, x.third, y.third))
//    {
//        if (check_for_beating(x.third, y.third, x.second, y.second))
//        {
//            result = OneThree_TwoThree;
//        }
//        else
//        {
//            result = OneThree;
//        }
//    }
//    else if (check_for_beating(x.third, y.third, x.second, y.second))
//    {
//        result = TwoThree;
//    }
//    return result;
//}

//int determine_file_proportions(char *input_file_name, int *number_of_lines, int *max_length_of_line)
//{
//    const int maximum_length_of_line = 256;
//    FILE *in;
//    in = fopen(input_file_name, "r");
//    char *str;
//    str = (char *) calloc(maximum_length_of_line, sizeof(char));
//    int count = 0;
//    *max_length_of_line = 0;
//    while (!feof(in))
//    {
//        fgets(str, maximum_length_of_line, in);
//        if (strlen(str) > *max_length_of_line) //тут компилятор выдает странное предупреждение. по мне, так
//            *max_length_of_line = strlen(str); //вполне нормально сравнивать число со знаком и без
//        ++count;
//    }
//    *number_of_lines = count;
//    free(str);
//    fclose(in);
//    return 1;//пока так. потом сделаю нормально
//}

//void print_n_symbols(FILE *stream, int n, char symbol)
//{
//    int i;
//    for (i = 0; i < n; ++i)
//        fprintf(stream, "%c", symbol);
//}

//void quotient_out(FILE *stream, int first_number, int second_number)
//{
//    int dividend, residue, result, i, product;
//    result = first_number / second_number;
//    dividend = first_number / power(10, numlen(result) - 1);
//    residue = first_number % power(10, numlen(result) - 1);
//    int indent = dividend;
//    int  crutch = 1; //нужен для правильного числа черточек в случаях, когда разность равна 0 :)
//    for (i = 1; i <= numlen(result); ++i)
//    {
//        if (i == 1)
//        {
//            fprintf(stream, "%i", dividend);
//            if (residue != 0)
//                fprintf(stream, "%i", residue);
//            fprintf(stream, "|%i\n", second_number);
//        }

//        product = second_number * n_th_dig_of_num(i, result);
//        print_n_symbols(stream, numlen(indent) - numlen(product), ' ');
//        fprintf(stream, "%i", product);

//        if (i != 1)
//            fprintf(stream, "\n");

//        if (i == 1)
//        {
//            print_n_symbols(stream, numlen(first_number) - numlen(dividend) + 1, ' ');

//            fprintf(stream, "%i\n", result);
//        }

//        int num_of_additional_spaces;

//        if (i != 1)
//            print_n_symbols(stream, num_of_additional_spaces, ' ');

//        if (crutch == 0)
//            print_n_symbols(stream, numlen(dividend) + 1, '-');
//        else
//            print_n_symbols(stream, numlen(dividend), '-');

//        fprintf(stream, "\n");

//        print_n_symbols(stream, numlen(indent) - numlen(dividend - product), ' ');

//        num_of_additional_spaces = numlen(indent) - numlen(dividend - product);

//        fprintf(stream, "%i", dividend - product);
//        if (i == numlen(result))
//            fprintf(stream, "\n");

//        if (i != numlen(result))
//            fprintf(stream, "%i\n", n_th_dig_of_num(i, residue));

//        crutch = dividend - product;
//        dividend = (dividend - product) * 10 + n_th_dig_of_num(i, residue);
//        indent = indent * 10 + n_th_dig_of_num(i, residue);

//    }
//}

//int numlen(int num)
//{
//    int count;

//    if (num)
//    {
//        count = 0;
//        while (num)
//        {
//            ++count;
//            num /= 10;
//        }
//    }
//    else
//    {
//        count = 1;
//    }
//    return count;
//}

//int power(int a, int b)
//{
//    int i, result = 1;
//    for (i = 0; i < b; ++i)
//    {
//        result *= a;
//    }
//    return result;
//}

//int n_th_dig_of_num(int n, int num)
//{
//    return (num / power(10, numlen(num) - n)) % 10;
//}


QTEST_APPLESS_MAIN(Qt_testsTest)

#include "tst_qt_teststest.moc"
