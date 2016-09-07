// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read_1) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

TEST(CollatzFixture, read_2) {
  istringstream r("2 22\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(2, i);
  ASSERT_EQ(22, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("12345 67890\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(12345, i);
  ASSERT_EQ(67890, j);
}

TEST(CollatzFixture, read_4) {
  istringstream r("10 1\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(10, i);
  ASSERT_EQ(1, j);
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(1, 10);
  ASSERT_EQ(20, v);
}

TEST(CollatzFixture, eval_2) {
  const int v = collatz_eval(100, 200);
  ASSERT_EQ(125, v);
}

TEST(CollatzFixture, eval_3) {
  const int v = collatz_eval(201, 210);
  ASSERT_EQ(89, v);
}

TEST(CollatzFixture, eval_4) {
  const int v = collatz_eval(900, 1000);
  ASSERT_EQ(174, v);
}

TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(10, 10);
  ASSERT_EQ(7, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(12345, 67890);
  ASSERT_EQ(340, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(10, 1);
  ASSERT_EQ(20, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print_2) {
  ostringstream w;
  collatz_print(w, 12345, 67890, 340);
  ASSERT_EQ("12345 67890 340\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 10, 1, 20);
  ASSERT_EQ("10 1 20\n", w.str());
}

TEST(CollatzFixture, print_4) {
  ostringstream w;
  collatz_print(w, 10, 10, 7);
  ASSERT_EQ("10 10 7\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve_2) {
  istringstream r("1 10\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("10 1\n200 100\n210 201\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("10 1 20\n200 100 125\n210 201 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve_4) {
  istringstream r("12345 67890\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("12345 67890 340\n900 1000 174\n", w.str());
}
