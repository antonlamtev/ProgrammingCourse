#include <QString>
#include <QtTest>
#include <iostream>
#include <new>

#include "exchange.h"
#include "queens.h"
#include "long_division.h"

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
}

QTEST_APPLESS_MAIN(Unit_tests_cpp)

#include "unit_tests_cpp.moc"
