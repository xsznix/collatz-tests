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

TEST(CollatzFixture, read) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}


TEST(CollatzFixture, read_backwards) {
  istringstream r("50 1\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(50, i);
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

TEST(CollatzFixture, eval_i_gt_j) {
  const int v = collatz_eval(97467, 66601);
  ASSERT_EQ(351, v);
}

TEST(CollatzFixture, eval_same_num) {
  const int v = collatz_eval(491586, 491586);
  ASSERT_EQ(64, v);
}


// -----
// print
// -----

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print_out_of_order) {
  ostringstream w;
  collatz_print(w, 5, 4, 10);
  ASSERT_EQ("5 4 10\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve_large) {
  istringstream r("573317 570492\n741222 739299\n438469 440610\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("573317 570492 372\n741222 739299 393\n438469 440610 400\n",
            w.str());
}

TEST(CollatzFixture, solve_single) {
  istringstream r("991219 989960\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("991219 989960 321\n", w.str());
}