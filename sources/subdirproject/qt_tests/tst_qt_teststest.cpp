#include <QString>
#include <QtTest>

class Qt_testsTest : public QObject
{
    Q_OBJECT

public:
    Qt_testsTest();

private Q_SLOTS:
    void testCase1();
};

Qt_testsTest::Qt_testsTest()
{
}

void Qt_testsTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(Qt_testsTest)

#include "tst_qt_teststest.moc"
