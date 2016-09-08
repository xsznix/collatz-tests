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
//My Tests
TEST(CollatzFixture, read_1) {
    istringstream r("2 2\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 2, i);
    ASSERT_EQ(2, j);
}
TEST(CollatzFixture, read_2) {
    istringstream r("1 99999\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 1, i);
    ASSERT_EQ(99999, j);
}
TEST(CollatzFixture, read_3) {
    istringstream r("48 2\n");
    int           i;
    int           j;
    const bool b = collatz_read(r, i, j);
    ASSERT_TRUE(b);
    ASSERT_EQ( 48, i);
    ASSERT_EQ(2, j);
}
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

//My Tests
TEST(CollatzFixture, eval_5){
    const int v = collatz_eval(9999,300);
    ASSERT_EQ(262,v);
}

TEST(CollatzFixture, eval_6){
    const int v = collatz_eval(37438, 662520);
    ASSERT_EQ(470, v);
}

TEST(CollatzFixture, eval_7){
    const int v = collatz_eval(2, 3);
    ASSERT_EQ(8, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

//My Tests

TEST(CollatzFixture, print_1) {
    ostringstream w;
    collatz_print(w, 700, 300, 1);
    ASSERT_EQ("700 300 1\n", w.str());}


TEST(CollatzFixture, print_2) {
    ostringstream w;
    collatz_print(w, 1, 1, 1);
    ASSERT_EQ("1 1 1\n", w.str());}


TEST(CollatzFixture, print_3) {
    ostringstream w;
    collatz_print(w, 99999, 99999, 99999);
    ASSERT_EQ("99999 99999 99999\n", w.str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}


//My Tests
TEST(CollatzFixture, solve_1) {
    istringstream r("2 3\n77865 4790\n47618 58312\n23013 62103\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("2 3 8\n77865 4790 351\n47618 58312 340\n23013 62103 340\n", w.str());}


TEST(CollatzFixture, solve_2) {
    istringstream r("109515 29952\n2 3\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("109515 29952 354\n2 3 8\n", w.str());}

TEST(CollatzFixture, solve_3) {
    istringstream r("28568 37345\n111462 54966\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("28568 37345 324\n111462 54966 354\n", w.str());}
