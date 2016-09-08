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
  const int v = collatz_eval(3324, 3324);
  ASSERT_EQ(137, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(1, 9);
  ASSERT_EQ(20, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(1, 99);
  ASSERT_EQ(119, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(1, 999);
  ASSERT_EQ(179, v);
}

TEST(CollatzFixture, eval_9) {
  const int v = collatz_eval(12, 345);
  ASSERT_EQ(144, v);
}

TEST(CollatzFixture, eval_10) {
  const int v = collatz_eval(678, 910);
  ASSERT_EQ(179, v);
}

// ------------
// corner cases
// ------------

TEST(CollatzFixture, eval_11) {
  const int v = collatz_eval(3324, 3324);
  ASSERT_EQ(137, v);
}

TEST(CollatzFixture, eval_12) {
  const int v = collatz_eval(400, 100);
  ASSERT_EQ(144, v);
}

TEST(CollatzFixture, eval_13) {
  const int v = collatz_eval(1, 99999);
  ASSERT_EQ(351, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print_1) {
  ostringstream w;
  collatz_print(w, 32, 159, 122);
  ASSERT_EQ("32 159 122\n", w.str());
}

TEST(CollatzFixture, print_2) {
  ostringstream w;
  collatz_print(w, 31744, 456, 308);
  ASSERT_EQ("31744 456 308\n", w.str());
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

TEST(CollatzFixture, solve_1) {
  istringstream r("43 123\n346 3271\n5478 2478\n13781 47173\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("43 123 119\n346 3271 217\n5478 2478 238\n13781 47173 324\n",
            w.str());
}

TEST(CollatzFixture, solve_2) {
  istringstream r("901 12938\n4810 34812\n1 2\n480 234\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("901 12938 268\n4810 34812 311\n1 2 2\n480 234 144\n", w.str());
}