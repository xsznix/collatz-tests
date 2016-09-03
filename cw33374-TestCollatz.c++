// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <cassert>  // assert
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

TEST(CollatzFixture, read_stop) {
  istringstream r("");
  int i, j;
  const bool b = collatz_read(r, i, j);
  ASSERT_FALSE(b);
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

TEST(CollatzFixture, eval_reverse) {
  const int v = collatz_eval(10, 1);
  ASSERT_EQ(20, v);
}

// ------------
// cycle_length
// ------------

TEST(CollatzFixture, cycle_1) {
  const int v = cycle_length(1);
  ASSERT_EQ(1, v);
}

TEST(CollatzFixture, cycle_2) {
  const int v = cycle_length(2);
  ASSERT_EQ(2, v);
}

TEST(CollatzFixture, cycle_3) {
  const int v = cycle_length(5);
  ASSERT_EQ(6, v);
}

TEST(CollatzFixture, cycle_4) {
  ASSERT_DEATH(cycle_length(-1), "Assertion `n > 0' failed");
}

TEST(CollatzFixture, cycle_5) {
  const int v = cycle_length(999699);
  ASSERT_EQ(184, v);
}

#if CACHE_OPT
TEST(CollatzFixture, cycle_cache_1) {
  fill_n(collatz_cache, 1000000, 0);
  cycle_length(5);
  ASSERT_EQ(1, collatz_cache[1]);
  ASSERT_EQ(2, collatz_cache[2]);
  ASSERT_EQ(3, collatz_cache[4]);
  ASSERT_EQ(4, collatz_cache[8]);
  ASSERT_EQ(6, collatz_cache[5]);
  ASSERT_EQ(0, collatz_cache[3]);
}

TEST(CollatzFixture, cycle_cache_2) {
  fill_n(collatz_cache, 1000000, 0);
  collatz_cache[1] = 42;
  collatz_cache[2] = 43;
  collatz_cache[4] = 3;
  const int v = cycle_length(5);
  ASSERT_EQ(6, v);
  ASSERT_EQ(42, collatz_cache[1]);
}
#endif

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

TEST(CollatzFixture, solve) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve_empty) {
  istringstream r("");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("", w.str());
}