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

TEST(CollatzFixture, read1) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

TEST(CollatzFixture, read2) {
  istringstream r("999999 999998\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(999999, i);
  ASSERT_EQ(999998, j);
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(1024, 2048);
  ASSERT_EQ(182, v);
}

TEST(CollatzFixture, eval_2) {
  const int v = collatz_eval(455513, 458130);
  ASSERT_EQ(356, v);
}

TEST(CollatzFixture, eval_3) {
  const int v = collatz_eval(569103, 573712);
  ASSERT_EQ(377, v);
}

TEST(CollatzFixture, simple_eval_1) {
  const int v = simple_eval(1024, 2048);
  ASSERT_EQ(182, v);
}

TEST(CollatzFixture, simple_eval_2) {
  const int v = simple_eval(975735, 975858);
  ASSERT_EQ(334, v);
}

TEST(CollatzFixture, simple_eval_3) {
  const int v = simple_eval(175659, 181398);
  ASSERT_EQ(365, v);
}

TEST(CollatzFixture, optimized_eval_1) {
  const int v = optimized_eval(1024, 2048);
  ASSERT_EQ(182, v);
}

TEST(CollatzFixture, optimized_eval_2) {
  const int v = optimized_eval(10, 17500);
  ASSERT_EQ(276, v);
}

TEST(CollatzFixture, optimized_eval_3) {
  const int v = optimized_eval(17750, 20000);
  ASSERT_EQ(274, v);
}

TEST(CollatzFixture, optimized_eval_4) {
  const int v = optimized_eval(13250, 17750);
  ASSERT_EQ(279, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print1) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print2) {
  ostringstream w;
  collatz_print(w, 999999, 999998, 259);
  ASSERT_EQ("999999 999998 259\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve1) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

TEST(CollatzFixture, solve2) {
  istringstream r("1000 10000\n50000 60000\n7500 8000\n100000 1\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1000 10000 262\n50000 60000 340\n7500 8000 252\n100000 1 351\n",
            w.str());
}

TEST(CollatzFixture, solve3) {
  istringstream r("25000 10\n201570 204014\n999999 999168\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("25000 10 282\n201570 204014 342\n999999 999168 396\n", w.str());
}

TEST(CollatzFixture, solve4) {
  istringstream r("250000 255000\n300000 300001\n625000 626000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("250000 255000 363\n300000 300001 190\n625000 626000 354\n", w.str());
}

TEST(CollatzFixture, solve5) {
  istringstream r("88888 10\n51200 51199\n1 2\n2 1\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("88888 10 351\n51200 51199 128\n1 2 2\n2 1 2\n",
            w.str());
}

TEST(CollatzFixture, solve6) {
  istringstream r("33333 22222\n99999 9999\n24816 3264\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("33333 22222 308\n99999 9999 351\n24816 3264 282\n", w.str());
}
