#include "shapes.h"

#include "gtest/gtest.h"

class ShapeTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}

 protected:
};

class RectangleTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}

 protected:
};

class CircleTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}

 protected:
};

class EquilateralTriangleTest : public ::testing::Test {
 public:
  void SetUp() {}
  void TearDown() {}

 protected:
};

TEST(RectangleTest, Area) {
  Rectangle rect(4.0, 2.0);
  EXPECT_EQ(rect.CalculateArea(), 8.0);
}

TEST(RectangleTest, Perimeter) {
  Rectangle rect(4.0, 2.0);
  EXPECT_EQ(rect.CalculatePerimeter(), 12.0);
}

TEST(RectangleTest, Scale) {
  Rectangle rect(4.0, 2.0);
  rect.Scale(2.0);
  EXPECT_EQ(rect.GetWidth(), 8.0);
  EXPECT_EQ(rect.GetHeight(), 4.0);
}

TEST(CircleTest, Area) {
  Circle circle(3.0);
  EXPECT_EQ(circle.CalculateArea(), 9.0 * PI);
}

TEST(CircleTest, Perimeter) {
  Circle circle(3.0);
  EXPECT_EQ(circle.CalculatePerimeter(), 6.0 * PI);
}

TEST(CircleTest, Scale) {
  Circle circle(3.0);
  circle.Scale(2.0);
  EXPECT_EQ(circle.GetRadius(), 6.0);
}

TEST(TriangleTest, Area) {
  EquilateralTriangle triangle(4.0);
  EXPECT_EQ(triangle.CalculateArea(), 4.0 * sqrt(3.0));
}

TEST(TriangleTest, Perimeter) {
  EquilateralTriangle triangle(4.0);
  EXPECT_EQ(triangle.CalculatePerimeter(), 12.0);
}

TEST(TriangleTest, Scale) {
  EquilateralTriangle triangle(4.0);
  triangle.Scale(2.0);
  EXPECT_EQ(triangle.GetWidth(), 8.0);
  EXPECT_EQ(triangle.GetHeight(), 4.0 * sqrt(3.0));
}

TEST(ShapesTest, RectangleAreaTest) {
  Rectangle r("rectangle", 5, 10);
  EXPECT_DOUBLE_EQ(r.CalculateArea(), 50);
}

TEST(ShapesTest, RectanglePerimeterTest) {
  Rectangle r("rectangle", 5, 10);
  EXPECT_DOUBLE_EQ(r.CalculatePerimeter(), 30);
}

TEST(ShapesTest, RectangleScaleTest) {
  Rectangle r("rectangle", 5, 10);
  r.Scale(2);
  EXPECT_DOUBLE_EQ(r.GetWidth(), 10);
  EXPECT_DOUBLE_EQ(r.GetHeight(), 20);
}

TEST(ShapesTest, CircleAreaTest) {
  Circle c("circle", 5);
  EXPECT_DOUBLE_EQ(c.CalculateArea(), 25 * PI);
}

TEST(ShapesTest, CirclePerimeterTest) {
  Circle c("circle", 5);
  EXPECT_DOUBLE_EQ(c.CalculatePerimeter(), 10 * PI);
}

TEST(ShapesTest, CircleScaleTest) {
  Circle c("circle", 5);
  c.Scale(2);
  EXPECT_DOUBLE_EQ(c.GetRadius(), 10);
}

TEST(ShapesTest, EquilateralTriangleAreaTest) {
  EquilateralTriangle t("triangle", 5);
  EXPECT_DOUBLE_EQ(t.CalculateArea(), (sqrt(3) / 4) * 25);
}

TEST(ShapesTest, EquilateralTrianglePerimeterTest) {
  EquilateralTriangle t("triangle", 5);
  EXPECT_DOUBLE_EQ(t.CalculatePerimeter(), 15);
}

TEST(ShapesTest, EquilateralTriangleScaleTest) {
  EquilateralTriangle t("triangle", 5);
  t.Scale(2);
  EXPECT_DOUBLE_EQ(t.GetWidth(), 10);
  EXPECT_DOUBLE_EQ(t.GetHeight(), (sqrt(3) / 2) * 10);
}
