#include <gtest/gtest.h>
#include <sstream> // for testing of function print()

#include "dummy/testClass.hpp"

// GIVEN: --
// WHEN: Calling default constructor
// THEN: Member of class has correct value
TEST(TestingTestClass, TestClassDefaultConstructor)
{
    // WHEN
    Dummy::TestClass test;

    // THEN
    EXPECT_EQ(0, test.getMember());
}

// GIVEN: --
// WHEN: Calling constructor which sets member
// THEN: Member of class has correct value
TEST(TestingTestClass, TestClassConstructorSettingMember)
{
    // WHEN
    Dummy::TestClass test(2);

    // THEN
    EXPECT_EQ(2, test.getMember());
}

// GIVEN: Instance of TestClass
// WHEN: Calling setter of member with value different from before
// THEN: Member of class has correct value
TEST(TestingTestClass, TestClassGetterSetter)
{
    // GIVEN
    int iStart = 3;
    int iEnd = 4;
    Dummy::TestClass test(iStart);

    // WHEN
    test.setMember(iEnd);

    // THEN
    EXPECT_EQ(iEnd, test.getMember());
    EXPECT_NE(iStart, test.getMember());
}

// GIVEN: Instance of TestClass
// WHEN: Calling member function print()
// THEN: Correct message is printed to cout
TEST(TestingTestClass, TestClassPrint)
{
    std::ostringstream oss;
    std::streambuf *p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    // GIVEN
    Dummy::TestClass test;

    // WHEN
    test.print();

    // THEN
    std::cout.rdbuf(p_cout_streambuf); // restore

    // Testing the oss content
    ASSERT_TRUE(oss);
    ASSERT_EQ("Test\n", oss.str());
    std::cout << oss.str();
}