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

// ------------
// cycle_length
// ------------
TEST(CollatzFixture, cycle_length_1) {
    const int cycle = collatz_cycle_length(1);
    ASSERT_EQ(1, cycle);}

TEST(CollatzFixture, cycle_length_2) {
    const int cycle = collatz_cycle_length(3);
    ASSERT_EQ(8, cycle);}

TEST(CollatzFixture, cycle_length_3) {
    const int cycle = collatz_cycle_length(5);
    ASSERT_EQ(6, cycle);}

TEST(CollatzFixture, cycle_length_4) {
    const int cycle = collatz_cycle_length(6);
    ASSERT_EQ(9, cycle);}

TEST(CollatzFixture, cycle_length_5) {
    const int cycle = collatz_cycle_length(7);
    ASSERT_EQ(17, cycle);}

TEST(CollatzFixture, cycle_length_6) {
    const int cycle = collatz_cycle_length(10);
    ASSERT_EQ(7, cycle);}

TEST(CollatzFixture, cycle_length_7) {
    const int cycle = collatz_cycle_length(50);
    ASSERT_EQ(25, cycle);}

TEST(CollatzFixture, cycle_length_8) {
    const int cycle = collatz_cycle_length(99);
    ASSERT_EQ(26, cycle);}

TEST(CollatzFixture, cycle_length_9) {
    const int cycle = collatz_cycle_length(100);
    ASSERT_EQ(26, cycle);}

TEST(CollatzFixture, cycle_length_10) {
    const int cycle = collatz_cycle_length(125);
    ASSERT_EQ(109, cycle);}

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
    const int v = collatz_eval(1, 20);
    ASSERT_EQ(21, v);}

TEST(CollatzFixture, eval_6) {
    const int v = collatz_eval(20, 1);
    ASSERT_EQ(21, v);}

TEST(CollatzFixture, eval_7) {
    const int v = collatz_eval(1, 2);
    ASSERT_EQ(2, v);}

TEST(CollatzFixture, eval_8) {
    const int v = collatz_eval(50, 500);
    ASSERT_EQ(144, v);}

TEST(CollatzFixture, eval_9) {
    const int v = collatz_eval(9, 99);
    ASSERT_EQ(119, v);}

TEST(CollatzFixture, eval_10) {
    const int v = collatz_eval(12, 112);
    ASSERT_EQ(119, v);}

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
