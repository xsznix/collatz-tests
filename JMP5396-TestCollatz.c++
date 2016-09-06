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

// Professor Downing's tests
TEST(CollatzFixture, read_1) {
  istringstream r("1 10\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(10, j);
}

// My tests
TEST(CollatzFixture, read_2) {
  istringstream r("1618 1618\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1618, i);
  ASSERT_EQ(1618, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("32 8\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(32, i);
  ASSERT_EQ(8, j);
}

TEST(CollatzFixture, read_4) {
  istringstream r("1 2147483647\n");
  int i;
  int j;
  const bool b = collatz_read(r, i, j);
  ASSERT_TRUE(b);
  ASSERT_EQ(1, i);
  ASSERT_EQ(2147483647, j);
}

// ----
// eval
// ----

// Professor Downing's tests
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

// My tests
TEST(CollatzFixture, eval_5) {
  const int v = collatz_eval(10, 10);
  ASSERT_EQ(7, v);
}

TEST(CollatzFixture, eval_6) {
  const int v = collatz_eval(73268, 49460);
  ASSERT_EQ(340, v);
}

TEST(CollatzFixture, eval_7) {
  const int v = collatz_eval(101912, 105882);
  ASSERT_EQ(341, v);
}

TEST(CollatzFixture, eval_8) {
  const int v = collatz_eval(35505, 35566);
  ASSERT_EQ(187, v);
}

// -----
// print
// -----

// Professor Downing tests.
TEST(CollatzFixture, print_1) {
  ostringstream w;
  collatz_print(w, 1, 10, 20);
  ASSERT_EQ("1 10 20\n", w.str());
}

// My tests.
TEST(CollatzFixture, print_2) {
  ostringstream w;
  collatz_print(w, 1, 1, 1);
  ASSERT_EQ("1 1 1\n", w.str());
}

TEST(CollatzFixture, print_3) {
  ostringstream w;
  collatz_print(w, 191, 161, 125);
  ASSERT_EQ("191 161 125\n", w.str());
}

TEST(CollatzFixture, print_4) {
  ostringstream w;
  collatz_print(w, 33, 34, 27);
  ASSERT_EQ("33 34 27\n", w.str());
}

// -----
// solve
// -----

// Professor Downing's test.
TEST(CollatzFixture, solve_1) {
  istringstream r("1 10\n100 200\n201 210\n900 1000\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());
}

// My tests.
TEST(CollatzFixture, solve_2) {
  istringstream r("76375 48336\n16280 111039\n52055 71389\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("76375 48336 340\n16280 111039 354\n52055 71389 340\n", w.str());
}

TEST(CollatzFixture, solve_3) {
  istringstream r("943557 943770\n599361 601660\n343376 349718\n96923 "
                  "42534\n807874 808895\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("943557 943770 277\n599361 601660 403\n343376 349718 441\n96923 "
            "42534 351\n807874 808895 331\n",
            w.str());
}

TEST(CollatzFixture, solve_4) {
  istringstream r("34371 52637\n");
  ostringstream w;
  collatz_solve(r, w);
  ASSERT_EQ("34371 52637 340\n", w.str());
}

/*
% g++-4.8 -pedantic -std=c++11 -Wall -fprofile-arcs -ftest-coverage Collatz.c++
TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -pthread
% valgrind ./TestCollatz                                           >
TestCollatz.tmp 2>&1
% gcov-4.8 -b Collatz.c++     | grep -A 5 "File 'Collatz.c++'"     >>
TestCollatz.tmp
% gcov-4.8 -b TestCollatz.c++ | grep -A 5 "File 'TestCollatz.c++'" >>
TestCollatz.tmp
*/
