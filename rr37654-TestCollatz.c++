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
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
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
    const int v = collatz_eval(1000, 2000);
    ASSERT_EQ(182, v);
}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(1250, 1750);
    ASSERT_EQ(180, v);
}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(1750, 1250);
    ASSERT_EQ(180, v);
}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(837, 837);
    ASSERT_EQ(42, v);
}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(1, 30000);
    ASSERT_EQ(308, v);
}

// ----
// cycle_length
// ----

TEST(CollatzFixture, cycle_length_1) {
    const int v = collatz_cycle_length(837);
    ASSERT_EQ(42, v);
}

TEST(CollatzFixture, cycle_length_2) {
    const int v = collatz_cycle_length(9);
    ASSERT_EQ(20, v);
}

TEST(CollatzFixture, cycle_length_3) {
    const int v = collatz_cycle_length(2071);
    ASSERT_EQ(126, v);
}

TEST(CollatzFixture, cycle_length_4) {
    const int v = collatz_cycle_length(1474);
    ASSERT_EQ(141, v);
}

TEST(CollatzFixture, cycle_length_5) {
    const int v = collatz_cycle_length(1);
    ASSERT_EQ(1, v);
}

TEST(CollatzFixture, cycle_length_6) {
    const int v = collatz_cycle_length(2);
    ASSERT_EQ(2, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());
}

TEST(CollatzFixture, print2) {
    ostringstream w;
    collatz_print(w, 900, 1000, 174);
    ASSERT_EQ("900 1000 174\n", w.str());
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
