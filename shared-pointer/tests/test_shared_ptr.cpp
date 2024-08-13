#include <gtest/gtest.h>

#include "shared_ptr.h"

// Define a simple class for testing
class TestClass
{
public:
    int value;
    TestClass(int v = 0) : value(v) {}
    int getValue() const
    {
        return value;
    }
};

// Test default constructor
TEST(SharedPointerTest, DefaultConstructor)
{
    SharedPointer<TestClass> ptr;
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.useCount(), 0);
}

// Test parameterized constructor
TEST(SharedPointerTest, ParameterizedConstructor)
{
    SharedPointer<TestClass> ptr(new TestClass(10));
    EXPECT_NE(ptr.get(), nullptr);
    EXPECT_EQ(ptr->getValue(), 10);
    EXPECT_EQ(ptr.useCount(), 1);
}

// Test copy constructor
TEST(SharedPointerTest, CopyConstructor)
{
    SharedPointer<TestClass> ptr1(new TestClass(20));
    SharedPointer<TestClass> ptr2 = ptr1;
    EXPECT_EQ(ptr1.useCount(), 2);
    EXPECT_EQ(ptr2.useCount(), 2);
    EXPECT_EQ(ptr1->getValue(), 20);
    EXPECT_EQ(ptr2->getValue(), 20);
}

// Test move constructor
TEST(SharedPointerTest, MoveConstructor)
{
    SharedPointer<TestClass> ptr1(new TestClass(30));
    SharedPointer<TestClass> ptr2 = std::move(ptr1);
    EXPECT_EQ(ptr1.get(), nullptr);
    EXPECT_EQ(ptr1.useCount(), 0);
    EXPECT_NE(ptr2.get(), nullptr);
    EXPECT_EQ(ptr2->getValue(), 30);
}

// Test copy assignment operator
TEST(SharedPointerTest, CopyAssignment)
{
    SharedPointer<TestClass> ptr1(new TestClass(40));
    SharedPointer<TestClass> ptr2;
    ptr2 = ptr1;
    EXPECT_EQ(ptr1.useCount(), 2);
    EXPECT_EQ(ptr2.useCount(), 2);
    EXPECT_EQ(ptr1->getValue(), 40);
    EXPECT_EQ(ptr2->getValue(), 40);
}

// Test move assignment operator
TEST(SharedPointerTest, MoveAssignment)
{
    SharedPointer<TestClass> ptr1(new TestClass(50));
    SharedPointer<TestClass> ptr2;
    ptr2 = std::move(ptr1);
    EXPECT_EQ(ptr1.get(), nullptr);
    EXPECT_EQ(ptr1.useCount(), 0);
    EXPECT_NE(ptr2.get(), nullptr);
    EXPECT_EQ(ptr2->getValue(), 50);
    EXPECT_EQ(ptr2.useCount(), 1);
}

// Test reset method
TEST(SharedPointerTest, ResetMethod)
{
    SharedPointer<TestClass> ptr(new TestClass(60));
    ptr.reset(new TestClass(70)); // Reset with a new resource
    EXPECT_EQ(ptr->getValue(), 70);
    EXPECT_EQ(ptr.useCount(), 1);
}

// Test resetting to nullptr
TEST(SharedPointerTest, ResetToNullptr)
{
    SharedPointer<TestClass> ptr(new TestClass(80));
    ptr.reset();
    EXPECT_EQ(ptr.get(), nullptr);
    EXPECT_EQ(ptr.useCount(), 0);
}

// Test comparison operators
TEST(SharedPointerTest, ComparisonOperators)
{
    SharedPointer<TestClass> ptr1(new TestClass(90));
    SharedPointer<TestClass> ptr2(new TestClass(90));
    SharedPointer<TestClass> ptr3(ptr1); // ptr3 and ptr1 point to the same resource

    EXPECT_NE(ptr1, ptr2);
    EXPECT_EQ(ptr1, ptr3);
}

// Test dereference operator
TEST(SharedPointerTest, DereferenceOperator)
{
    SharedPointer<TestClass> ptr(new TestClass(100));
    EXPECT_EQ((*ptr).getValue(), 100);
}

// Test arrow operator
TEST(SharedPointerTest, ArrowOperator)
{
    SharedPointer<TestClass> ptr(new TestClass(110));
    EXPECT_EQ(ptr->getValue(), 110);
}

// Test boolean conversion operator
TEST(SharedPointerTest, BooleanConversionOperator)
{
    SharedPointer<TestClass> ptr1(new TestClass(120));
    SharedPointer<TestClass> ptr2;
    EXPECT_TRUE(static_cast<bool>(ptr1));
    EXPECT_FALSE(static_cast<bool>(ptr2));
}

// Test copying after moving
TEST(SharedPointerTest, CopyAfterMove)
{
    SharedPointer<TestClass> ptr1(new TestClass(130));
    SharedPointer<TestClass> ptr2 = std::move(ptr1);
    EXPECT_EQ(ptr1.get(), nullptr);
    EXPECT_EQ(ptr2.useCount(), 1);
    EXPECT_EQ(ptr2->getValue(), 130);

    SharedPointer<TestClass> ptr3 = ptr2;
    EXPECT_EQ(ptr2.useCount(), 2);
    EXPECT_EQ(ptr3.useCount(), 2);
    EXPECT_EQ(ptr3->getValue(), 130);
}

// Test resetting after move
TEST(SharedPointerTest, ResetAfterMove)
{
    SharedPointer<TestClass> ptr1(new TestClass(140));
    SharedPointer<TestClass> ptr2 = std::move(ptr1);
    EXPECT_EQ(ptr1.get(), nullptr);
    ptr2.reset(new TestClass(150));
    EXPECT_EQ(ptr2->getValue(), 150);
    EXPECT_EQ(ptr2.useCount(), 1);
}

// Test resource release with multiple references
TEST(SharedPointerTest, ResourceReleaseOnLastReference)
{
    SharedPointer<TestClass> ptr1(new TestClass(10));
    {
        SharedPointer<TestClass> ptr2 = ptr1;
        EXPECT_EQ(ptr1.useCount(), 2);
        EXPECT_EQ(ptr2.useCount(), 2);
    }

    EXPECT_EQ(ptr1.useCount(), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}