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
  istringstream r("100 10000\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(100, i);
  ASSERT_EQ(10000, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("999 1\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(999, i);
  ASSERT_EQ(1, j);
}

// ------------
// cycle_length
// ------------

TEST(CollatzFixture, cycle_length_1) {
  const int v = collatz_cycle_length(1);
  ASSERT_EQ(1, v);
}

TEST(CollatzFixture, cycle_length_2) {
  const int v = collatz_cycle_length(90);
  ASSERT_EQ(18, v);
}

TEST(CollatzFixture, cycle_length_3) {
  const int v = collatz_cycle_length(138370);
  ASSERT_EQ(176, v);
}

TEST(CollatzFixture, cycle_length_4) {
  const int v = collatz_cycle_length(204010);
  ASSERT_EQ(205, v);
}

TEST(CollatzFixture, cycle_length_5) {
  const int v = collatz_cycle_length(900000);
  ASSERT_EQ(158, v);
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
  // testing to make sure optimization works
  const int v = collatz_eval(100, 1000);
  const int j = collatz_eval(501, 1000);
  ASSERT_EQ(179, v);
  ASSERT_EQ(179, j);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(1000, 10000);
  const int j = collatz_eval(5001, 10000);
  ASSERT_EQ(262, v);
  ASSERT_EQ(v, j);
}

TEST(CollatzFixture, eval_7) {
  // testing for i > j
  const int v = collatz_eval(10, 1);
  const int j = collatz_eval(1, 10);
  ASSERT_EQ(20, v);
  ASSERT_EQ(20, j);
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
  collatz_print(w, 100, 1000, 179);
  ASSERT_EQ("100 1000 179\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 100, 19999, 279);
  ASSERT_EQ("100 19999 279\n", w.str());
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
  istringstream r("1 100\n 1000 179\n200 4000\n4000 200\n500 10000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ(
      "1 100 119\n1000 179 179\n200 4000 238\n4000 200 238\n500 10000 262\n",
      w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("201 101\n220 210\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("201 101 125\n220 210 115\n", w.str());
}
