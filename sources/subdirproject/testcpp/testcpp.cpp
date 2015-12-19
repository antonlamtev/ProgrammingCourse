#include <QString>
#include <QtTest>
#include <iostream>
#include <new>
#include <fstream>


#include "setOfCoins.h"
#include "queens.h"
#include "longDivision.h"
#include "matrix.h"
#include "text.h"
#include "table.h"

class TestCpp : public QObject
{
    Q_OBJECT

public:
    TestCpp();

private Q_SLOTS:
    void testCase1();
    void testSetOfCoins();
    void testQueens();
    void testLongDivision();
    void testMatrix();
    void testText();
    void testTable();
};

TestCpp::TestCpp()
{
}

void TestCpp::testCase1()
{
}

void TestCpp::testSetOfCoins()
{
    {
        SetOfCoins set1;
        try
        {
            SetOfCoins set2(0, 1, 2, 12);
            set1.putAmount(-2); // : -2 рубля 0_o, что же делать?
            QCOMPARE(set1.exchange() == set2, true);
        }
        catch(const char* e) // : все под контролем!
        {
            cout << e << endl;
        }
    }

    {
    SetOfCoins set1;
    SetOfCoins set2(1, 1, 19, 98);
    set1.putAmount(98);
    QCOMPARE(set1.exchange() == set2, true);
    }

    {
    SetOfCoins set1;
    SetOfCoins set2(0, 2, 19, 99);
    set1.putAmount(99);
    QCOMPARE(set1.exchange() == set2, true);
    }

    {
    SetOfCoins set1;
    SetOfCoins set2(1, 0, 1, 6);
    set1.putAmount(6);
    QCOMPARE(set1.exchange() == set2, true);
    }
}

void TestCpp::testQueens()
{
    Queens queens;
    Queen q1, q2, q3;

    q1 = {1, 2};
    q2 = {3, 4};
    q3 = {5, 6};
    QCOMPARE(queens.getResult(q1, q2, q3), (int) EVERYONE);

    q1 = {1, 2};
    q2 = {2, 4};
    q3 = {5, 5};
    QCOMPARE(queens.getResult(q1, q2, q3), (int) NO_ONE);

    q1 = {1, 8};
    q2 = {1, 4};
    q3 = {8, 1};
    QCOMPARE(queens.getResult(q1, q2, q3), (int) OneTwo_OneThree);
}

void TestCpp::testLongDivision()
{
    LongDivision longDivision;
    const char* expected;
    char* actual;

    actual = new char[37];
    longDivision.putResultToArray(actual, 128, 2);
    expected = "128|2\n12  64\n--\n 08\n  8\n --\n  0";
    QCOMPARE((std::string) actual == (std::string) expected, true);
    delete[] actual;
}

void TestCpp::testMatrix()
{
    Matrix matrix;
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

    matrix.sortNullsToTheMainDiagonal(actual, 5);

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
    Text text;
    string finalLine;
    string initialLine = "hfsdfsg deq";
    text.symmetrizeLine(finalLine, initialLine, 25);
    string expected = "       hfsdfsg deq";
    QCOMPARE(finalLine == expected, 1);
}

void TestCpp::testTable()
{
    Table table;
    table.put("hello world!", 128);
    table.put("dfsdg", 256);
    QCOMPARE(table[128] == "hello world!", true);
    QCOMPARE(table.getLastElement() == "dfsdg", true);
    QCOMPARE(table.getKeyOfLastElement() == 256, true);
}

QTEST_APPLESS_MAIN(TestCpp)

#include "testcpp.moc"
