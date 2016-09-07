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
  istringstream r("178 93483\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(178, i);
  ASSERT_EQ(93483, j);
}

TEST(CollatzFixture, read_2) {
  istringstream r("63461 71340\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(63461, i);
  ASSERT_EQ(71340, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("122684 128671\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(122684, i);
  ASSERT_EQ(128671, j);
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
  const int v = collatz_eval(681415, 684315);
  ASSERT_EQ(380, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(9809, 104619);
  ASSERT_EQ(351, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(19801, 84687);
  ASSERT_EQ(351, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
  ostringstream w;
  collatz_print(w, 2733, 89281, 351);
  ASSERT_EQ("2733 89281 351\n", w.str());
}

TEST(CollatzFixture, print_2) {
  ostringstream w;
  collatz_print(w, 9670, 37092, 324);
  ASSERT_EQ("9670 37092 324\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 3165, 12722, 268);
  ASSERT_EQ("3165 12722 268\n", w.str());
}

TEST(CollatzFixture, print_4) {
  ostringstream w;
  collatz_print(w, 39393, 58636, 340);
  ASSERT_EQ("39393 58636 340\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
  istringstream r("2733 89281\n9670 37092\n3165 12722\n39393 58636\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("2733 89281 351\n9670 37092 324\n3165 12722 268\n39393 58636 340\n",
            w.str());
}

TEST(CollatzFixture, solve_2) {
  istringstream r("42173 92718\n799815 803856\n31972 34684\n48279 80433\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ(
      "42173 92718 351\n799815 803856 406\n31972 34684 311\n48279 80433 351\n",
      w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("214530 219391\n4238 32356\n986567 990915\n91837 97978\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ(
      "214530 219391 386\n4238 32356 308\n986567 990915 396\n91837 97978 328\n",
      w.str());
}
