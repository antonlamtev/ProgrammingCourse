#include <QString>
#include <QtTest>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exchange.h"
#include "queens.h"
#include "quotient.h"
#include "matrix.h"
#include "lines_symmetrization.h"

int compare_files(char *file_name_1, char *file_name_2);

class Qt_testsTest : public QObject
{
    Q_OBJECT

public:
    Qt_testsTest();

private Q_SLOTS:
    void exchange_test();
    void queens_test();
    void quotient_test();
//    void matrix_test();
    void lines_simmetrization_test();
};

Qt_testsTest::Qt_testsTest()
{

}

void Qt_testsTest::exchange_test()
{
    struct purse coins1_expected;
    coins1_expected.fives = 5;
    coins1_expected.twos = 1;
    coins1_expected.ones = 1;
    struct purse coins1_actual = change_by_coins(28);

    QCOMPARE(coins1_actual.fives, coins1_expected.fives);
    QCOMPARE(coins1_actual.twos, coins1_expected.twos);
    QCOMPARE(coins1_actual.ones, coins1_expected.ones);

    struct purse coins2_expected;
    coins2_expected.fives = 8;
    coins2_expected.twos = 2;
    coins2_expected.ones = 0;
    struct purse coins2_actual = change_by_coins(44);

    QCOMPARE(coins2_actual.fives, coins2_expected.fives);
    QCOMPARE(coins2_actual.twos, coins2_expected.twos);
    QCOMPARE(coins2_actual.ones, coins2_expected.ones);

}

void Qt_testsTest::queens_test()
{
    struct coordinate x_actual, y_actual;
    x_actual.first = 1;
    y_actual.first = 2;
    x_actual.second = 2;
    y_actual.second = 3;
    x_actual.third = 3;
    y_actual.third = 4;

    QCOMPARE(queens_result(x_actual, y_actual), 1);
}

void Qt_testsTest::quotient_test()
{
    char* actual = (char*) calloc(33, sizeof(char));
    int index = -1;
    int count;
    put_result_to_array(actual, 128, 2, index, &count);
    actual[31] = '\0';

    char expected[] = "128|2\n12  64\n--\n 08\n  8\n --\n  0";

    QCOMPARE(strcmp(actual, expected), 0);
    free(actual);
}

//void Qt_testsTest::matrix_test()
//{
//    int n, i, j;

//    int** actual = (int **) malloc(5 * sizeof(int*));
//    sort_nulls_to_the_main_diagonal(actual, 5);

//    for (i = 0; i < n; ++i)
//        free(P[i]);
//    free(P);
//    fclose(in);
//    fclose(out);
//    int flag = compare_files("matrix_actual", "matrix_expected");
//    QCOMPARE(flag, 1);
//}

void Qt_testsTest::lines_simmetrization_test()
{
    FILE *in, *out;
    int number_of_lines, max_length_of_line;
    determine_file_proportions("lines.in", &number_of_lines, &max_length_of_line);

    char *initial_line = (char *) calloc (max_length_of_line, sizeof(char));
    char *final_line = (char *) calloc (max_length_of_line, sizeof(char));
    in = fopen("lines.in", "r");
    out = fopen("lines_actual", "w");

    int i;
    for (i = 0; i < number_of_lines; ++i)
    {
        fgets(initial_line, max_length_of_line, in);
        symmetrize_line(final_line, initial_line, max_length_of_line);
        fputs(final_line, out);
    }

    free(initial_line);
    free(final_line);
    fclose(in);
    fclose(out);
    int flag = compare_files("lines_actual", "lines_expected");
    QCOMPARE(flag, 1);
}

int compare_files(char *file_name_1, char *file_name_2)
{
    int flag = 1;
    int number_of_lines_1, number_of_lines_2;
    int max_length_of_line_1, max_length_of_line_2;
    determine_file_proportions(file_name_1, &number_of_lines_1, &max_length_of_line_1);
    determine_file_proportions(file_name_2, &number_of_lines_2, &max_length_of_line_2);
    FILE *actual, *expected;
    actual = fopen(file_name_1, "r");
    expected = fopen(file_name_2, "r");

    char *str1, *str2;
    str1 = (char *) calloc(max_length_of_line_1, sizeof(char));
    str2 = (char *) calloc(max_length_of_line_2, sizeof(char));
    if (number_of_lines_1 == number_of_lines_2)
    {
        int i;
        for (i = 0; i <= number_of_lines_1; ++i)
        {
            fgets(str1, max_length_of_line_1, actual);
            fgets(str2, max_length_of_line_2, expected);
            //puts(str1);
            //puts(str2);
            if (strcmp(str1, str2))
            {
                flag = 0;
                break;
            }
        }
        free(str1);
        free(str2);
    }
    else
    {
        flag = 0;
    }
    fclose(actual);
    fclose(expected);
    return flag;
}

QTEST_APPLESS_MAIN(Qt_testsTest)

#include "tst_qt_teststest.moc"
