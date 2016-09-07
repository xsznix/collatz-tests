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

// ----------
// read tests
// ----

TEST(CollatzFixture, read_1) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2) { istringstream r("109 999999\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 109, i);
    ASSERT_EQ(999999, j);}

// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(6996, 7281);
    ASSERT_EQ(195, v);} 

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(9383, 886);
    ASSERT_EQ(262, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(540, 3426);
    ASSERT_EQ(217, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(3346, 4302);
    ASSERT_EQ(238, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(17630, 104812);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(34307, 4251);
    ASSERT_EQ(311, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(345318, 356264);
    ASSERT_EQ(441, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n999998 999999\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n999998 999999 259\n201 210 89\n900 1000 174\n", w.str());}
