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
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2) {
    istringstream r("1 1000000\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ( 1000000, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("999999 999999\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 999999, i);
    ASSERT_EQ( 999999, j);}

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
    const int v = collatz_eval(1, 999999);
    ASSERT_EQ(525, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(999999, 999999);
    ASSERT_EQ(259, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(912784, 473823);
    ASSERT_EQ(525, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(792485, 35);
    ASSERT_EQ(509, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(123456, 789101);
    ASSERT_EQ(509, v);}

// -----
// print
// -----

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 912784, 473823, 525);
    ASSERT_EQ("912784 473823 525\n", w.str());}

TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 900, 1000, 174);
    ASSERT_EQ("900 1000 174\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}


TEST(CollatzFixture, solve_2) {
    istringstream r("1 999999\n999999 999999\n1 1\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 999999 525\n999999 999999 259\n1 1 1\n", w.str());}


TEST(CollatzFixture, solve_3) {
    istringstream r("912784 473823\n792485 35\n123456 789101\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("912784 473823 525\n792485 35 509\n123456 789101 509\n", w.str());}
