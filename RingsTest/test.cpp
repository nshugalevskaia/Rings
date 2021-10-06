#include "pch.h"
#include "Rings.h"

TEST(TestRings, Test1) {
  EXPECT_EQ(build_chain("10, 32, 45, 4"), 3);

}
TEST(TestRings, Test2) {

	EXPECT_EQ(build_chain("8, 2, 14, 5"), 2);

}
TEST(TestRings, Test3) {
	ASSERT_THROW(build_chain("ggggg"), InputException);
}

TEST(TestRings, Test4) {

	EXPECT_EQ(build_chain("1,1,1,1,1"), 2);

}

TEST(TestRings, Test5) {

	EXPECT_EQ(build_chain("6,10,10,10,10"), 4);

}