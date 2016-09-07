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
  istringstream r("10 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(10, i);
  ASSERT_EQ(10, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("1000000 1000000\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1000000, i);
  ASSERT_EQ(1000000, j);
}

TEST(CollatzFixture, read_4) {
  istringstream r("600 500\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(600, i);
  ASSERT_EQ(500, j);
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

// test case where the values are the same
TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(99, 99);
  ASSERT_EQ(26, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(1, 2000);
  ASSERT_EQ(182, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(50, 20);
  ASSERT_EQ(112, v);
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
  collatz_print(w, 500, 100000, 1);
  ASSERT_EQ("500 100000 1\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 258208, 268757, 407);
  ASSERT_EQ("258208 268757 407\n", w.str());
}

TEST(CollatzFixture, print_4) {
  ostringstream w;
  collatz_print(w, 1, 1, 1);
  ASSERT_EQ("1 1 1\n", w.str());
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
  istringstream r("604714 606846\n806279 806282\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("604714 606846 341\n806279 806282 75\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("1 1\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 1 1\n", w.str());
}

TEST(CollatzFixture, solve_4) {
  istringstream r("1 10\n999168 1000000\n151178 159486\n50 65\n206 100\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n999168 1000000 396\n151178 159486 383\n50 65 113\n206 "
            "100 125\n",
            w.str());
}
