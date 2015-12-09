#include <QString>
#include <QtTest>
#include <iostream>
#include <new>

#include "exchange.h"
#include "queens.h"
#include "long_division.h"
#include "matrix.h"

class Unit_tests_cpp : public QObject
{
    Q_OBJECT

public:
    Unit_tests_cpp();

private Q_SLOTS:
    void testCase1();
    void test_Exchange();
    void test_Queens();
    void test_Long_division();
    void test_Matrix();
};

Unit_tests_cpp::Unit_tests_cpp()
{
}

void Unit_tests_cpp::testCase1()
{
}

void Unit_tests_cpp::test_Exchange()
{
    Exchange app;
    Coins coins;

    coins = app.exchange_money(12);
    QCOMPARE(coins.fives, 2);
    QCOMPARE(coins.twos, 1);
    QCOMPARE(coins.ones, 0);

    coins = app.exchange_money(98);
    QCOMPARE(coins.fives, 19);
    QCOMPARE(coins.twos, 1);
    QCOMPARE(coins.ones, 1);

    coins = app.exchange_money(99);
    QCOMPARE(coins.fives, 19);
    QCOMPARE(coins.twos, 2);
    QCOMPARE(coins.ones, 0);

    coins = app.exchange_money(6);
    QCOMPARE(coins.fives, 1);
    QCOMPARE(coins.twos, 0);
    QCOMPARE(coins.ones, 1);
}

void Unit_tests_cpp::test_Queens()
{
    Queens app;
    Queen q1, q2, q3;

    q1 = {1, 2};
    q2 = {3, 4};
    q3 = {5, 6};
    QCOMPARE(app.get_result(q1, q2, q3), (int) everyone);

    q1 = {1, 2};
    q2 = {2, 4};
    q3 = {5, 5};
    QCOMPARE(app.get_result(q1, q2, q3), (int) no_one);

    q1 = {1, 8};
    q2 = {1, 4};
    q3 = {8, 1};
    QCOMPARE(app.get_result(q1, q2, q3), (int) OneTwo_OneThree);
}

void Unit_tests_cpp::test_Long_division()
{
    Long_division app;
    const char* expected;
    char* actual;

    actual = new char[37];
    app.put_result_to_array(actual, 128, 2);
    expected = "128|2\n12  64\n--\n 08\n  8\n --\n  0";
    QCOMPARE((std::string) actual == (std::string) expected, true);
    delete[] actual;
}

void Unit_tests_cpp::test_Matrix()
{
//    Matrix app;
//    int** actual;

//    actual = new int* [5];
//    for (int i = 0; i < 5; ++i)
//    {
//        actual[i] = new int[5];
//        for (int j = 0; j < 5; ++j)
//        {
//            actual[i][j] = i * j + 1;
//    }

//    actual[0][3] = 0; actual[1][1] = 0; actual[2][4] = 0; actual[3][0] = 0; actual[4][2] = 0;

//    app.sort_nulls_to_the_main_diagonal(actual, 5);

//    int expected[5][5] = {{0, 4, 7, 10, 13},
//                          {1, 0, 3,  4,  5},
//                          {1, 5, 0, 13, 17},
//                          {1, 1, 1,  0,  1},
//                          {1, 3, 5,  7,  0}};


//    for (int i = 0; i < 5; ++i)
//    {
//        for(int j = 0; j < 5; j++)
//        {
//            QCOMPARE(actual[i][j], expected[i][j]);
//        }
//        delete[] actual[i];
//    }

//    delete[] actual;
}

QTEST_APPLESS_MAIN(Unit_tests_cpp)

#include "unit_tests_cpp.moc"
