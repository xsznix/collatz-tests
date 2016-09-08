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
    ASSERT_EQ(10, j);}

TEST(CollatzFixture, read_2) {
    istringstream r("1 11\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(11, j);}

TEST(CollatzFixture, read_3) {
    istringstream r("1 12\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(12, j);}

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
    const int v = collatz_eval(19, 84);

    ASSERT_EQ(116, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(30, 53);
    ASSERT_EQ(110, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(902, 1000);
    ASSERT_EQ(174, v);}


// ----
// switch
// ----

TEST(CollatzFixture, switch_1) {
    int i = 7;
    int j = 5;
    const bool v = collatz_switch_inputs (i, j);
    ASSERT_EQ(true, v);
}

TEST(CollatzFixture, switch_2) {
    int i = 1;
    int j = 3;
    const bool v = collatz_switch_inputs (i, j);
    ASSERT_EQ(false, v);
}

TEST(CollatzFixture, switch_3) {
    int i = 10;
    int j = 5;
    const bool v = collatz_switch_inputs (i, j);
    ASSERT_EQ(true, v);
}

TEST(CollatzFixture, switch_4) {
    int i = 2;
    int j = 5;
    const bool v = collatz_switch_inputs (i, j);
    ASSERT_EQ(false, v);
}


// ----
// cycle calculator
// ----

TEST(CollatzFixture, cycle_count_1) {
    const int v = cycle_calculator (984);
    ASSERT_EQ(50, v);
}

TEST(CollatzFixture, cycle_count_2) {
    const int v = cycle_calculator (999999);
    ASSERT_EQ(259, v);
}

TEST(CollatzFixture, cycle_count_3) {
    const int v = cycle_calculator (1);
    ASSERT_EQ(1, v);
}


TEST(CollatzFixture, cycle_count_4) {
    const int v = cycle_calculator (2);
    ASSERT_EQ(2, v);
}

TEST(CollatzFixture, cycle_count_5) {
    const int v = cycle_calculator (9);
    ASSERT_EQ(20, v);
}



// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 100, 200, 125);
    ASSERT_EQ("100 200 125\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
