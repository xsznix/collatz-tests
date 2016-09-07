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
  const int v = collatz_eval(200093, 197734);
  ASSERT_EQ(329, v);
}

// ------------
// cycle_length
// ------------

TEST(CollatzFixture, cycle_length_1) {
  const int v = collatz_cycle_length(1);
  ASSERT_EQ(1, v);
}

TEST(CollatzFixture, cycle_length_2) {
  const int v = collatz_cycle_length(5);
  ASSERT_EQ(6, v);
}

TEST(CollatzFixture, cycle_length_3) {
  const int v = collatz_cycle_length(10);
  ASSERT_EQ(7, v);
}

TEST(CollatzFixture, cycle_length_4) {
  const int v = collatz_cycle_length(999999);
  ASSERT_EQ(259, v);
}

TEST(CollatzFixture, cycle_length_5) {
  const int v = collatz_cycle_length(895131);
  ASSERT_EQ(189, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
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
  istringstream r("1 1\n999999 999999\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 1 1\n999999 999999 259\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("", w.str());
}
