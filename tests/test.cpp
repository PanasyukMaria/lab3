// Copyright by MaryMorgan

#include <gtest/gtest.h>
#include "ptr.hpp"

TEST(Example, Empty) {
  EXPECT_TRUE(true);
}
TEST(Test, Zer) {
  SharedPtr<int> sp;
  EXPECT_EQ((sp),0);
}
TEST(Test, UseCount) {
  int val = 5;
  SharedPtr<int> sp1 (&val);
  SharedPtr<int> sp2(sp1);
  EXPECT_EQ(sp1.use_count(),2);
}
TEST(Test, types) {
  class Values{
   public:
    int value;
  };
  Values value1;
  value1.value=20;
  SharedPtr<Values> sp5(&value1);
  EXPECT_EQ(sp5->value,20);
}
TEST(Test, Sznach) {
  int val1 = 6, val2 = 15;
  SharedPtr<int> sp1 (&val1);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> spoz(&val2);
  std::stringstream str;
  str<<*sp1<<" "<<*sp2<<" "<<*spoz;
  std::string stroka = "6 6 15";
  EXPECT_EQ(str.str(), stroka);
}
TEST(Test, Get) {
  int val1 = 6, val2 = 15;
  SharedPtr<int> sp1 (&val1);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> sp3(sp2);
  SharedPtr<int> spoz(&val2);
  std::stringstream str, str2;
  str<<*sp1.get()<<" "<<*sp2.get()<<" "<<*sp3.get()<<" "<<*spoz.get();
  std::string stroka = "6 6 6 15";
  EXPECT_EQ(str.str(), stroka);
}
TEST(Test, Reset) {
  int val1 = 6, val2 =15;
  SharedPtr<int> sp1 (&val1);
  SharedPtr<int> sp2(sp1);
  sp1.reset();
  sp2.reset(&val2);
  std::stringstream str;
  str<<(sp1)<<" "<<*sp2;
  std::string stroka = "0 15";
  EXPECT_EQ(str.str(), stroka);
}
TEST(Test, Swap) {
  int val1 = 6, val2 = 15;
  SharedPtr<int> sp1 (&val1);
  SharedPtr<int> sp2(sp1);
  SharedPtr<int> spoz(&val2);
  std::stringstream str;
  str<<*sp2<<" "<<*spoz;
  sp2.swapPtr(spoz);
  str<<" "<<*sp2<<" "<<*spoz;
  std::string stroka = "6 15 15 6";
  EXPECT_EQ(str.str(), stroka);
}