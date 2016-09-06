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
    ASSERT_EQ(1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2) {
    istringstream r("999999 1\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(999999, i);
    ASSERT_EQ(1, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("213456 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(213456, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_4) {
    istringstream r("8 675309\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(8, i);
    ASSERT_EQ(675309, j);}

TEST(CollatzFixture, read_5) {
    istringstream r("1 1\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(1, i);
    ASSERT_EQ(1, j);}

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
<<<<<<< HEAD
    const int v = collatz_eval(999168, 999168);
    ASSERT_EQ(184, v);}
=======
    const int v = collatz_eval(999999, 836543);
    ASSERT_EQ(525, v);}
>>>>>>> ca789ea0bd5d3268949f434dad6cc1eca07536c6

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(999, 5040);
    ASSERT_EQ(238, v);}

TEST(CollatzFixture, eval_7) {
<<<<<<< HEAD
    const int v = collatz_eval(1000, 113382);
    ASSERT_EQ(354, v);}
=======
    const int v = collatz_eval(1000, 999999);
    ASSERT_EQ(525, v);}
>>>>>>> ca789ea0bd5d3268949f434dad6cc1eca07536c6

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 999999, 1, 86666);
    ASSERT_EQ("999999 1 86666\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 123456, 678910, 666777);
    ASSERT_EQ("123456 678910 666777\n", w.str());}

TEST(CollatzFixture, print_4) {
    ostringstream w;
    collatz_print(w, 1, 1, 1);
    ASSERT_EQ("1 1 1\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve_2) {
<<<<<<< HEAD
    istringstream r("999999 999999\n1 99999\n1 9999\n1 999\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("999999 999999 259\n1 99999 351\n1 9999 262\n1 999 179\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("8675 82999\n1 1\n7 1\n86753 9\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("8675 82999 351\n1 1 1\n7 1 17\n86753 9 351\n", w.str());}

TEST(CollatzFixture, solve_4) {
    istringstream r("1 99999\n99999 1\n999 1\n2 1\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 99999 351\n99999 1 351\n999 1 179\n2 1 2\n", w.str());}
=======
    istringstream r("1 999999\n1 99999\n1 9999\n1 999\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 999999 525\n1 99999 351\n1 9999 262\n1 999 179\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("8675 829999\n1 1\n7 1\n867530 9\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("8675 829999 509\n1 1 1\n7 1 17\n867530 9 525\n", w.str());}

TEST(CollatzFixture, solve_4) {
    istringstream r("999999 1\n99999 1\n999 1\n2 1\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("999999 1 525\n99999 1 351\n999 1 179\n2 1 2\n", w.str());}
>>>>>>> ca789ea0bd5d3268949f434dad6cc1eca07536c6

TEST(CollatzFixture, solve_5) {
    istringstream r("\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("", w.str());}
