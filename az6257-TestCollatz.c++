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
  istringstream r("200 100\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(200, i);
  ASSERT_EQ(100, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("50000 100000\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(50000, i);
  ASSERT_EQ(100000, j);
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
  const int v = collatz_eval(8000, 9000);
  ASSERT_EQ(247, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(10000, 15000);
  ASSERT_EQ(276, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(50000, 60000);
  ASSERT_EQ(340, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(100000, 110000);
  ASSERT_EQ(354, v);
}

TEST(CollatzFixture, eval_9) {
  const int v = collatz_eval(110000, 100000);
  ASSERT_EQ(354, v);
}

TEST(CollatzFixture, eval_10) {
  const int v = collatz_eval(60000, 50000);
  ASSERT_EQ(340, v);
}

TEST(CollatzFixture, eval_11) {
  const int v = collatz_eval(15000, 10000);
  ASSERT_EQ(276, v);
}

TEST(CollatzFixture, eval_12) {
  const int v = collatz_eval(200000, 201000);
  ASSERT_EQ(342, v);
}

TEST(CollatzFixture, eval_13) {
  const int v = collatz_eval(900000, 901000);
  ASSERT_EQ(401, v);
}

TEST(CollatzFixture, eval_14) {
  const int v = collatz_eval(950000, 951000);
  ASSERT_EQ(414, v);
}

TEST(CollatzFixture, eval_15) {
  const int v = collatz_eval(300000, 302300);
  ASSERT_EQ(371, v);
}

TEST(CollatzFixture, eval_16) {
  const int v = collatz_eval(400000, 403000);
  ASSERT_EQ(387, v);
}

TEST(CollatzFixture, eval_17) {
  const int v = collatz_eval(500000, 502000);
  ASSERT_EQ(364, v);
}

TEST(CollatzFixture, eval_18) {
  const int v = collatz_eval(600000, 604500);
  ASSERT_EQ(403, v);
}

TEST(CollatzFixture, eval_19) {
  const int v = collatz_eval(800000, 803000);
  ASSERT_EQ(406, v);
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
  collatz_print(w, 5, 6, 7);
  ASSERT_EQ("5 6 7\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 200, 100, 200);
  ASSERT_EQ("200 100 200\n", w.str());
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
  istringstream r("1000 1100\n1100 1200\n1200 1300\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1000 1100 169\n1100 1200 182\n1200 1300 177\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("1300 1400\n1400 1500\n20000 15000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1300 1400 177\n1400 1500 172\n20000 15000 279\n", w.str());
}
