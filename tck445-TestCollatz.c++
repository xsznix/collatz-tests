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
  const int v = collatz_eval(171, 171);
  ASSERT_EQ(125, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(7031, 77031);
  ASSERT_EQ(351, v);
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
  collatz_print(w, 10, 1, 20);
  ASSERT_EQ("10 1 20\n", w.str());
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
  istringstream r("10 1\n200 100\n210 201\n1000 900\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("10 1 20\n200 100 125\n210 201 89\n1000 900 174\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("6160 6180\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("6160 6180 262\n", w.str());
}

// -----
// get_cycle_length
// -----

TEST(CollatzFixture, get_cycle_length_1) {
  const int v = get_cycle_length(1);
  ASSERT_EQ(1, v);
}

TEST(CollatzFixture, get_cycle_length_2) {
  const int v = get_cycle_length(2);
  ASSERT_EQ(2, v);
}

TEST(CollatzFixture, get_cycle_length_3) {
  const int v = get_cycle_length(3);
  ASSERT_EQ(8, v);
}

TEST(CollatzFixture, get_cycle_length_4) {
  const int v = get_cycle_length(4);
  ASSERT_EQ(3, v);
}

TEST(CollatzFixture, get_cycle_length_5) {
  const int v = get_cycle_length(5);
  ASSERT_EQ(6, v);
}

TEST(CollatzFixture, get_cycle_length_6) {
  const int v = get_cycle_length(6);
  ASSERT_EQ(9, v);
}

TEST(CollatzFixture, get_cycle_length_7) {
  const int v = get_cycle_length(7);
  ASSERT_EQ(17, v);
}

TEST(CollatzFixture, get_cycle_length_8) {
  const int v = get_cycle_length(8);
  ASSERT_EQ(4, v);
}

TEST(CollatzFixture, get_cycle_length_9) {
  const int v = get_cycle_length(9);
  ASSERT_EQ(20, v);
}

TEST(CollatzFixture, get_cycle_length_10) {
  const int v = get_cycle_length(10);
  ASSERT_EQ(7, v);
}

TEST(CollatzFixture, get_cycle_length_11) {
  const int v = get_cycle_length(22);
  ASSERT_EQ(16, v);
}

TEST(CollatzFixture, get_cycle_length_12) {
  const int v = get_cycle_length(27);
  ASSERT_EQ(112, v);
}

TEST(CollatzFixture, get_cycle_length_13) {
  const int v = get_cycle_length(77031);
  ASSERT_EQ(351, v);
}

TEST(CollatzFixture, get_cycle_length_14) {
  const int v = get_cycle_length(171);
  ASSERT_EQ(125, v);
}
