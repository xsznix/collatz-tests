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

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

TEST(CollatzFixture, read_empty) {
  istringstream r("\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_FALSE(b);
}

TEST(CollatzFixture, read_multiple) {
  istringstream r("1 10\n10 1\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1_10) {
  const int v = collatz_eval(1, 10);
  ASSERT_EQ(20, v);
}

TEST(CollatzFixture, eval_100_200) {
  const int v = collatz_eval(100, 200);
  ASSERT_EQ(125, v);
}

TEST(CollatzFixture, eval_201_210) {
  const int v = collatz_eval(201, 210);
  ASSERT_EQ(89, v);
}

TEST(CollatzFixture, eval_900_1000) {
  const int v = collatz_eval(900, 1000);
  ASSERT_EQ(174, v);
}

TEST(CollatzFixture, eval_10_1) {
  const int v = collatz_eval(10, 1);
  ASSERT_EQ(20, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print_one_line) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print_two_lines) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  collatz_print(w, 100, 200, 125);
  ASSERT_EQ("1 10 20\n100 200 125\n", w.str());
}

TEST(CollatzFixture, print_line_reverse) {
  ostringstream w;
  collatz_print(w, 10, 1, 20);
  ASSERT_EQ("10 1 20\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_normal) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve_reverse) {
  istringstream r("10 1\n200 100\n210 201\n1000 900\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("10 1 20\n200 100 125\n210 201 89\n1000 900 174\n", w.str());
}

TEST(CollatzFixture, solve_mix) {
  istringstream r("1 10\n200 100\n201 210\n1000 900\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n200 100 125\n201 210 89\n1000 900 174\n", w.str());
}
