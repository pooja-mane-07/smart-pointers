#include <gtest/gtest.h>

#include "unique_ptr.h"

// Define a simple class for testing
class TestClass {
 public:
  int value;
  TestClass(int v = 0) : value(v) {}
  int getValue() const { return value; }
};

// Utility to check if a type has a copy assignment operator
template <typename T>
class HasCopyAssignmentOperator {
 private:
  template <typename U>
  static auto check(int) -> decltype(std::declval<U&>() = std::declval<const U&>(), std::true_type{});

  template <typename U>
  static std::false_type check(...);

 public:
  static constexpr bool value = decltype(check<T>(0))::value;
};

// Utility to check if a type has a copy constructor
template <typename T>
class HasCopyConstructor {
 private:
  template <typename U>
  static auto check(int) -> decltype(U(std::declval<const U&>()), std::true_type{});

  template <typename U>
  static std::false_type check(...);

 public:
  static constexpr bool value = decltype(check<T>(0))::value;
};

// Test default constructor
TEST(UniquePointerTest, DefaultConstructor) {
  UniquePointer<TestClass> ptr;
  EXPECT_EQ(ptr.get(), nullptr);
}

// Test parameterized constructor
TEST(UniquePointerTest, ParameterizedConstructor) {
  UniquePointer<TestClass> ptr(new TestClass(10));
  EXPECT_NE(ptr.get(), nullptr);
  EXPECT_EQ(ptr->getValue(), 10);
}

// Test case for checking if the copy assignment operator is deleted
TEST(UniquePointerTest, CopyAssignmentOperatorIsDeleted) {
  static_assert(!HasCopyAssignmentOperator<UniquePointer<int>>::value,
                "UniquePointer should not have a copy assignment operator.");
}

// Test case for checking if the copy constructor is deleted
TEST(UniquePointerTest, CopyConstructorIsDeleted) {
  static_assert(!HasCopyConstructor<UniquePointer<int>>::value,
                "UniquePointer should not have a copy constructor.");
}

// Test move constructor
TEST(UniquePointerTest, MoveConstructor) {
  UniquePointer<TestClass> ptr1(new TestClass(20));
  UniquePointer<TestClass> ptr2(std::move(ptr1));
  EXPECT_EQ(ptr1.get(), nullptr);
  EXPECT_NE(ptr2.get(), nullptr);
  EXPECT_EQ(ptr2->getValue(), 20);
}

// Test move assignment
TEST(UniquePointerTest, MoveAssignment) {
  UniquePointer<TestClass> ptr1(new TestClass(30));
  UniquePointer<TestClass> ptr2;
  ptr2 = std::move(ptr1);
  EXPECT_EQ(ptr1.get(), nullptr);
  EXPECT_NE(ptr2.get(), nullptr);
  EXPECT_EQ(ptr2->getValue(), 30);
}

// Test reset
TEST(UniquePointerTest, Reset) {
  UniquePointer<TestClass> ptr(new TestClass(40));
  ptr.reset(new TestClass(50));
  EXPECT_EQ(ptr->getValue(), 50);
}

// Test dereference operator
TEST(UniquePointerTest, DereferenceOperator) {
  UniquePointer<TestClass> ptr(new TestClass(60));
  EXPECT_EQ((*ptr).getValue(), 60);
}

// Test arrow operator
TEST(UniquePointerTest, ArrowOperator) {
  UniquePointer<TestClass> ptr(new TestClass(70));
  EXPECT_EQ(ptr->getValue(), 70);
}

// Test the move assignment of an empty UniquePointer
TEST(UniquePointerTest, MoveAssignmentFromEmpty) {
  UniquePointer<TestClass> ptr1;
  UniquePointer<TestClass> ptr2(new TestClass(80));
  ptr1 = std::move(ptr2);
  EXPECT_EQ(ptr2.get(), nullptr);
  EXPECT_NE(ptr1.get(), nullptr);
  EXPECT_EQ(ptr1->getValue(), 80);
}

// Test case for checking the explicit operator bool()
TEST(UniquePointerTest, OperatorBool) {
  UniquePointer<TestClass> ptr1(new TestClass(10));
  EXPECT_TRUE(static_cast<bool>(ptr1));

  UniquePointer<TestClass> ptr2;
  EXPECT_FALSE(static_cast<bool>(ptr2));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
