#include <QString>
#include <QtTest>
#include <stdlib.h>
//#include "exchange_change.h"
#include "exchange_structures_declaration.h"
#include "queens_operands_declaration.h"
#include "queens_result.h"
#include "queens_check_for_beating.h"

//если раскомментить //#include "exchange_change.h" и закоментить функцию ниже, то undefined reference у change_by_coins(int)
struct purse change_by_coins(int amount)
{
    struct purse coins;
    coins.fives = amount / 5;
    coins.twos = (amount - (coins.fives * 5)) / 2;
    if (amount % 5 == 3)
        coins.ones = 1;
    else
        coins.ones = 0;
    return coins;
}

//такая же проблема. пока не знаю, как решить
int queens_result(struct coordinate x, struct coordinate y)
{
    int result = no_one;
    if (check_for_beating(x.first, y.first, x.second, y.second))
    {
        if (check_for_beating(x.first, y.first, x.third, y.third))
        {
            if (check_for_beating(x.third, y.third, x.second, y.second))
            {
                result = everyone;
            }
            else
            {
                result = OneTwo_OneThree;
            }
        }
        else
        {
            if (check_for_beating(x.third, y.third, x.second, y.second))
            {
                result = OneTwo_TwoThree;
            }
            else
            {
                result = OneTwo;
            }
        }
    }
    else if (check_for_beating(x.first, y.first, x.third, y.third))
    {
        if (check_for_beating(x.third, y.third, x.second, y.second))
        {
            result = OneThree_TwoThree;
        }
        else
        {
            result = OneThree;
        }
    }
    else if (check_for_beating(x.third, y.third, x.second, y.second))
    {
        result = TwoThree;
    }
    return result;
}

int check_for_beating(int a, int b, int c, int d)
{
    return (a == c || b == d) || (abs(a-c) == abs(b-d));

}

class Qt_testsTest : public QObject
{
    Q_OBJECT

public:
    Qt_testsTest();

private Q_SLOTS:
    void exchange_test();
    void queens_test();
    /*void quotient_test();
    void matrix_test();
    void lines_simmetrization_test();*/
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
    struct purse coins1_real = change_by_coins(28);

    QCOMPARE(coins1_real.fives, coins1_expected.fives);
    QCOMPARE(coins1_real.twos, coins1_expected.twos);
    QCOMPARE(coins1_real.ones, coins1_expected.ones);

    struct purse coins2_expected;
    coins2_expected.fives = 8;
    coins2_expected.twos = 2;
    coins2_expected.ones = 0;
    struct purse coins2_real = change_by_coins(44);

    QCOMPARE(coins2_real.fives, coins2_expected.fives);
    QCOMPARE(coins2_real.twos, coins2_expected.twos);
    QCOMPARE(coins2_real.ones, coins2_expected.ones);

}

void Qt_testsTest::queens_test()
{
    struct coordinate x_real, y_real;
    x_real.first = 1;
    y_real.first = 2;
    x_real.second = 2;
    y_real.second = 3;
    x_real.third = 3;
    y_real.third = 4;
    QCOMPARE(queens_result(x_real, y_real), 1);
}

QTEST_APPLESS_MAIN(Qt_testsTest)

#include "tst_qt_teststest.moc"
