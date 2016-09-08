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

TEST(CollatzFixture, read_1) {
    istringstream r("1 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2) {
    istringstream r("2 6\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 2, i);
    ASSERT_EQ(6, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("1 9\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(9, j);}
// ----
// eval
// ----

TEST(CollatzFixture, eval_1) {
    const int v = collatz_eval(1, 10);
    ASSERT_EQ(20, v);}

TEST(CollatzFixture, eval_2) {
    const int v = collatz_eval(100, 200);
    ASSERT_EQ(125, v);}

TEST(CollatzFixture, eval_3) {
    const int v = collatz_eval(201, 210);
    ASSERT_EQ(89, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(900, 1000);
    ASSERT_EQ(174, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(54624, 7920);
    ASSERT_EQ(340, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(38501, 4948);
    ASSERT_EQ(324, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(49541, 7543);
    ASSERT_EQ(324, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(7079, 1727);
    ASSERT_EQ(262, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(12440, 5564);
    ASSERT_EQ(268, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(68889, 5966);
    ASSERT_EQ(340, v);}

TEST(CollatzFixture, eval_11) {
    const int v = collatz_eval(48812, 1972);
    ASSERT_EQ(324, v);}

TEST(CollatzFixture, eval_12) {
    const int v = collatz_eval(69298, 4620);
    ASSERT_EQ(340, v);}

TEST(CollatzFixture, eval_13) {
    const int v = collatz_eval(90406 1804);
    ASSERT_EQ(351, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 1, 1, 20);
    ASSERT_EQ("1 1 20\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 10, 1, 6);
    ASSERT_EQ("10 1 6\n", w.str());}
// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
    istringstream r("20 20\n9999 9999\n1 9999\n340 3000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("20 20 8\n9999 9999 92\n1 9999 262\n340 3000 217\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("3000 340\n500 101\n1 1\n9999 9998\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("3000 340 217\n500 101 144\n1 1 1\n9999 9998 92\n", w.str());}
