#include <QString>
#include <QtTest>
#include <iostream>
#include <new>

#include "exchange.h"
#include "queens.h"
#include "longDivision.h"
#include "matrix.h"
#include "text.h"

class TestCpp : public QObject
{
    Q_OBJECT

public:
    TestCpp();

private Q_SLOTS:
    void testCase1();
    void testExchange();
    void testQueens();
    void testLongDivision();
    void testMatrix();
    void testText();
};

TestCpp::TestCpp()
{
}

void TestCpp::testCase1()
{
}

void TestCpp::testExchange()
{
    Exchange app;
    Coins coins;

    coins = app.exchangeMoney(12);
    QCOMPARE(coins.fives, 2);
    QCOMPARE(coins.twos, 1);
    QCOMPARE(coins.ones, 0);

    coins = app.exchangeMoney(98);
    QCOMPARE(coins.fives, 19);
    QCOMPARE(coins.twos, 1);
    QCOMPARE(coins.ones, 1);

    coins = app.exchangeMoney(99);
    QCOMPARE(coins.fives, 19);
    QCOMPARE(coins.twos, 2);
    QCOMPARE(coins.ones, 0);

    coins = app.exchangeMoney(6);
    QCOMPARE(coins.fives, 1);
    QCOMPARE(coins.twos, 0);
    QCOMPARE(coins.ones, 1);
}

void TestCpp::testQueens()
{
    Queens app;
    Queen q1, q2, q3;

    q1 = {1, 2};
    q2 = {3, 4};
    q3 = {5, 6};
    QCOMPARE(app.getResult(q1, q2, q3), (int) EVERYONE);

    q1 = {1, 2};
    q2 = {2, 4};
    q3 = {5, 5};
    QCOMPARE(app.getResult(q1, q2, q3), (int) NO_ONE);

    q1 = {1, 8};
    q2 = {1, 4};
    q3 = {8, 1};
    QCOMPARE(app.getResult(q1, q2, q3), (int) OneTwo_OneThree);
}

void TestCpp::testLongDivision()
{
    LongDivision app;
    const char* expected;
    char* actual;

    actual = new char[37];
    app.putResultToArray(actual, 128, 2);
    expected = "128|2\n12  64\n--\n 08\n  8\n --\n  0";
    QCOMPARE((std::string) actual == (std::string) expected, true);
    delete[] actual;
}

void TestCpp::testMatrix()
{
    Matrix app;
    int** actual = new int* [5];
    for (int i = 0; i < 5; ++i)
    {
        actual[i] = new int[5];
        for (int j = 0; j < 5; ++j)
        {
            actual[i][j] = i * j + 1;
        }
    }

    actual[0][3] = 0; actual[1][1] = 0; actual[2][4] = 0; actual[3][0] = 0; actual[4][2] = 0;

    app.sortNullsToTheMainDiagonal(actual, 5);

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
        delete[] actual[i];
    }

    delete[] actual;
}

void TestCpp::testText()
{
    Text app;
    string finalLine;
    string initialLine = "hfsdfsg deq";
    app.symmetrizeLine(finalLine, initialLine, 25);
    string expected = "       hfsdfsg deq";
    QCOMPARE(finalLine == expected, 1);
}

QTEST_APPLESS_MAIN(TestCpp)

#include "testcpp.moc"
