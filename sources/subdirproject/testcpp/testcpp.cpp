#include <QString>
#include <QtTest>
#include <iostream>
#include <new>
#include <fstream>
#include <vector>


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
            set1.putAmount(12);
            SetOfCoins set2(0, -1, 2, 12);
            QCOMPARE(set1.exchange() == set2, true);
        }
        catch (AmountException& e)
        {
            cout << e.getError() << endl;
        }
        catch (CoinException& e)
        {
            cout << e.getError() << endl;
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
    try
    {
        Queen q1(-1, 4), q2(B, 5);
        QCOMPARE(q1.amIBeat(q2), true);
    }
    catch (CoordinatesException& e)
    {
        cout << e.getError() << endl;
    }

    vector<Queen> queens(3);

    Queen q1(A, 4);
    queens[0] = q1;
    Queen q2(B, 5);
    queens[1] = q2;
    Queen q3(A, 2);
    queens[2] = q3;

    QCOMPARE(ThreeQueens::whoBeats(queens) == OneTwo_OneThree, true);
}

void TestCpp::testLongDivision()
{
    LongDivision longDivision;
    const char* expected;
    char* actual;

    actual = new char[37];
    longDivision.putResultToArray(actual, 128, 2);
    expected = "128|2\n12  64\n--\n 08\n  8\n --\n  0";
    QCOMPARE((string) actual == (string) expected, true);
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
