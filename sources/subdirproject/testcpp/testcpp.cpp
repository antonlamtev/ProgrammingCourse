#include <QString>
#include <QtTest>

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

void TestCpp::testSetOfCoins()
{
    {
    SetOfCoins set(98);
    QCOMPARE(set.getOnes(), 1);
    QCOMPARE(set.getTwos(), 1);
    QCOMPARE(set.getFives(), 19);
    }

    {
    SetOfCoins set(99);
    QCOMPARE(set.getOnes(), 0);
    QCOMPARE(set.getTwos(), 2);
    QCOMPARE(set.getFives(), 19);
    }

    {
    SetOfCoins set(6);
    QCOMPARE(set.getOnes(), 1);
    QCOMPARE(set.getTwos(), 0);
    QCOMPARE(set.getFives(), 1);
    }

    QVERIFY_EXCEPTION_THROWN(SetOfCoins set2(-12), AmountException);
}

void TestCpp::testQueens()
{
    Queen q1(A, 4);
    Queen q2(B, 5);
    Queen q3(A, 2);

    QVERIFY_EXCEPTION_THROWN(Queen q1(-1, 4), CoordinatesException);
    QCOMPARE(ThreeQueens::whoBeats(q1, q2, q3) == OneTwo_OneThree, true);
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
    QVERIFY_EXCEPTION_THROWN(Matrix matrix(-5), BadDimensionException);

    Matrix matrix(5);
    int dimension = matrix.getDimension();
    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            matrix.put(i * j + 1, i, j);
        }
        matrix.put(0, i, dimension - i - 1);
    }

    matrix.sortNullsToTheMainDiagonal();

    int expected[5][5] = {{0, 5, 9, 13, 17},
                          {1, 0, 7, 10, 13},
                          {1, 3, 0, 7, 9},
                          {1, 2, 3, 0, 5},
                          {1, 1, 1, 1, 0}};

#include <iostream>
    using namespace std;
    for (int i = 0; i < dimension; ++i)
    {
        for(int j = 0; j < dimension; j++)
        {
            //QCOMPARE(matrix.get(i, j), expected[i][j]);
            cout << matrix.get(i, j) << ' ';
        }
        cout << endl;
    }

}

void TestCpp::testText()
{
    string finalLine;
    string initialLine = "hfsdfsg deq";
    Text::symmetrizeLine(finalLine, initialLine, 25);
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
    QVERIFY_EXCEPTION_THROWN(table[1], NonexistentKeyException);
}

QTEST_APPLESS_MAIN(TestCpp)

#include "testcpp.moc"
