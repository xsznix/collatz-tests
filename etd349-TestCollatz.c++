// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------
#include <cassert>
#include <iostream>
#include <string>
#include <utility>

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// -------
// collatz_read tests
// -------

TEST(CollatzFixture, read_1) {
  istringstream r("420 540\n");
  int i;
  int j;
  const bool b = collatz_read(r,i,j);
  ASSERT_TRUE(b);
  ASSERT_EQ( 420, i);
  ASSERT_EQ( 540, j);
}

TEST(CollatzFixture, read_2) {
  istringstream r("116 343\n");
  int i;
  int j;
  const bool b = collatz_read(r,i,j);
  ASSERT_TRUE(b);
  ASSERT_EQ( 116, i);
  ASSERT_EQ( 343, j);
}

TEST(CollatzFixture, read_3) {
  istringstream r("7890 8890\n");
  int i;
  int j;
  const bool b = collatz_read(r,i,j);
  ASSERT_TRUE(b);
  ASSERT_EQ( 7890, i);
  ASSERT_EQ( 8890, j);
}
// ------
// collatz_eval tests
// ------

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(23737, 61824);
  ASSERT_EQ(340, v);
}

TEST(CollatzFixture, eval_2) {
  const int v = collatz_eval(99476, 112058);
  ASSERT_EQ(354 , v);
}

TEST(CollatzFixture, eval_3) {
  const int v = collatz_eval(591451, 600784);
  ASSERT_EQ(403 , v);
}
// ------
// collatz_print tests
// ------

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 56155, 105256, 351);
    ASSERT_EQ("56155 105256 351\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 44947, 53383, 340);
    ASSERT_EQ("44947 53383 340\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 73880, 12979, 340);
    ASSERT_EQ("73880 12979 340\n", w.str());}


// ------
// collatz_solve
// ------

TEST(CollatzFixture, solve_1) {
    istringstream r("53624 80572\n323529 327284\n74717 81354\n746100 741538\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("53624 80572 351\n323529 327284 384\n74717 81354 351\n746100 741538 349\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("614069 616759\n56333 61083\n80967 96543\n72690 97427\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("614069 616759 447\n56333 61083 335\n80967 96543 333\n72690 97427 351\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("69747 108616\n421526 423698\n92166 56420\n81816 18083\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("69747 108616 354\n421526 423698 418\n92166 56420 351\n81816 18083 351\n", w.str());}
