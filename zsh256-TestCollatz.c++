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
    istringstream r("18983 82837\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 18983, i);
    ASSERT_EQ(82837, j);}
TEST(CollatzFixture, read_3) {
    istringstream r("11 10\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ(11, i);
    ASSERT_EQ(10, j);}
TEST(CollatzFixture, read_4) {
    istringstream r("");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_FALSE(b);}   
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
    const int v = collatz_eval(36917, 54585);
    ASSERT_EQ(340, v);}
TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}    
TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(1000000, 1000000);
    ASSERT_EQ(153, v);}
// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}
TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 95623, 86971, 333);
    ASSERT_EQ("95623 86971 333\n", w.str());}
TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 71035, 11153, 340);
    ASSERT_EQ("71035 11153 340\n", w.str());}
// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
TEST(CollatzFixture, solve_2) {
    istringstream r("999999 1000000\n99999 1\n2 1\n9135 3817\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("999999 1000000 259\n99999 1 351\n2 1 2\n9135 3817 262\n", w.str());}