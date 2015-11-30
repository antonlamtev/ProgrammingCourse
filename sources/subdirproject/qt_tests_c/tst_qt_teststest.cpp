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

class Qt_testsTest : public QObject
{
    Q_OBJECT

public:
    Qt_testsTest();

private Q_SLOTS:
    void exchange_test();
    void queens_test();
    void quotient_test();
    void matrix_test();
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

int compare_arrays(int* m1, int m2[], int size)
{
    int flag = 1;
    for (int i = 0; i < size; ++i)
        if (m1[i] != m2[i])
        {
            flag = 0;
            break;
        }
    return flag;
}

void Qt_testsTest::matrix_test()
{
    int i, j;

    int** actual = (int**) malloc(5 * sizeof(int*));
    for (i = 0; i < 5; ++i)
        actual[i] = (int*) malloc(5*sizeof(int));
    for (i = 0; i < 5; ++i)
    {
        for (j = 0; j < 5; ++j)
        {
            actual[i][j] = i * j + 1;
        }
    }
    actual[0][3] = 0; actual[1][1] = 0; actual[2][4] = 0; actual[3][0] = 0; actual[4][2] = 0;

    int* actual_1d = (int*) malloc(25 * sizeof(int));
    sort_nulls_to_the_main_diagonal(actual, 5);
    int ind = -1;
    for (i = 0; i < 5; ++i)
        for (j = 0; j < 5; ++j)
            actual_1d[++ind] = actual[i][j];

    for (i = 0; i < 5; ++i)
        free(actual[i]);
    free(actual);

    int expected[] = {0, 4, 7, 10, 13, 1, 0, 3, 4, 5, 1, 5, 0, 13, 17, 1, 1, 1, 0, 1 , 1, 3, 5, 7, 0};
    QCOMPARE(compare_arrays(actual_1d, expected, 25), 1);
    free(actual_1d);
}

void Qt_testsTest::lines_simmetrization_test()
{
    char str[] = "sdfjl sfvslk ! asdf";
    char* initial_line = (char*) calloc (20, sizeof(char));
    int i;
    for (i = 0; i < (int) strlen(str); ++i)
        initial_line[i] = str[i];
    char* actual = (char*) calloc (30, sizeof(char));
    symmetrize_line(actual, initial_line, 30);
    free(initial_line);

    char expected[] = "     sdfjl sfvslk ! asdf";

    QCOMPARE(strcmp(actual, expected), 0);
    free(actual);
}


QTEST_APPLESS_MAIN(Qt_testsTest)

#include "tst_qt_teststest.moc"
