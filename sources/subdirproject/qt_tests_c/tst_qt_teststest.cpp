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
    struct purse coins_actual;

    coins_actual = change_by_coins(28);
    QCOMPARE(coins_actual.fives, 5);
    QCOMPARE(coins_actual.twos, 1);
    QCOMPARE(coins_actual.ones, 1);

    coins_actual = change_by_coins(44);
    QCOMPARE(coins_actual.fives, 8);
    QCOMPARE(coins_actual.twos, 2);
    QCOMPARE(coins_actual.ones, 0);

}

void Qt_testsTest::queens_test()
{
    struct queen q1, q2, q3;

    q1.x = 1;
    q1.y = 2;
    q2.x = 3;
    q2.y = 4;
    q3.x = 5;
    q3.y = 6;
    QCOMPARE(queens_result(q1, q2, q3), (int) everyone);

    q1.x = 1;
    q1.y = 6;
    q2.x = 2;
    q2.y = 6;
    q3.x = 1;
    q3.y = 3;
    QCOMPARE(queens_result(q1, q2, q3), (int) OneTwo_OneThree);

}

void Qt_testsTest::quotient_test()
{
    char* actual;
    const char* expected;

    actual = (char*) calloc(38, sizeof(char));
    put_result_to_array(actual, 128, 2);
    actual[37] = '\0';
    expected = "128|2\n12  64\n--\n 08\n  8\n --\n  0";
    QCOMPARE(strcmp(actual, expected), 0);
    free(actual);
}

void Qt_testsTest::matrix_test()
{
    int** actual = (int**) malloc(5 * sizeof(int*));
    for (int i = 0; i < 5; ++i)
    {
        actual[i] = (int*) malloc(5 * sizeof(int));
        for (int j = 0; j < 5; ++j)
        {
            i[actual][j] = i * j + 1; //по приколу так сделал :) Страуструп сказал, что так можно. А я решил проверить.
        }                             //Логично, если через оператор разыменовывания записать. Но в голову это не приходило
    }

    actual[0][3] = 0; actual[1][1] = 0; actual[2][4] = 0; actual[3][0] = 0; actual[4][2] = 0;

    sort_nulls_to_the_main_diagonal(actual, 5);

    int expected[5][5] = {{0, 4, 7, 10, 13},
                          {1, 0, 3,  4,  5},
                          {1, 5, 0, 13, 17},
                          {1, 1, 1,  0,  1},
                          {1, 3, 5,  7,  0}};


    for (int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; j++)
        {
            QCOMPARE(actual[i][j], expected[i][j]);
        }
        free(actual[i]);
    }

    free(actual);
}

void Qt_testsTest::lines_simmetrization_test()
{
    char str[] = "sdfjl sfvslk ! asdf";
    char* actual = (char*) calloc (30, sizeof(char));

    symmetrize_line(actual, str, 30);

    char expected[] = "     sdfjl sfvslk ! asdf";

    QCOMPARE(strcmp(actual, expected), 0);
    free(actual);
}


QTEST_APPLESS_MAIN(Qt_testsTest)

#include "tst_qt_teststest.moc"
