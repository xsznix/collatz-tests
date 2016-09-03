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
#include <vector>

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
    ASSERT_EQ(10, j);}

// ------------
// cycle_length
// ------------

TEST(CollatzFixture, cycle_length_1) {
    vector<int> cache(1000001);
    const int v = cycle_length(1, cache);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, cycle_length_2) {
    vector<int> cache(1000001);
    const int v = cycle_length(999168, cache);
    ASSERT_EQ(184, v);}

TEST(CollatzFixture, cycle_length_3) {
    vector<int> cache(1000001);
    const int v = cycle_length(474844, cache);
    ASSERT_EQ(77, v);}

TEST(CollatzFixture, cycle_length_4) {
    vector<int> cache(1000001);
    const int v = cycle_length(125555, cache);
    ASSERT_EQ(132, v);}

TEST(CollatzFixture, cycle_length_5) {
    vector<int> cache(1000001);
    const int v = cycle_length(573534, cache);
    ASSERT_EQ(191, v);}

TEST(CollatzFixture, cycle_length_6) {
    vector<int> cache(1000001);
    const int v = cycle_length(107477, cache);
    ASSERT_EQ(93, v);}

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
    const int v = collatz_eval(474844, 475784);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, eval_4) {
    const int v = collatz_eval(1, 1);
    ASSERT_EQ(1, v);}

TEST(CollatzFixture, eval_5) {
    const int v = collatz_eval(191336, 201568);
    ASSERT_EQ(360, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(999168, 999999);
    ASSERT_EQ(396, v);}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
