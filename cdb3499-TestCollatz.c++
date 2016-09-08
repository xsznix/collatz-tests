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

TEST(CollatzFixture, cycle_1){
  const int v = cycle_length(1000000);
  ASSERT_EQ(153, v);}

TEST(CollatzFixture, cycle_2){
  const int v = cycle_length(1);
  ASSERT_EQ(1, v);}

TEST(CollatzFixture, cycle_3){
  const int v = cycle_length(999);
  ASSERT_EQ(50, v);}

// --------
// find_max
// --------

TEST(CollatzFixture, find_1){
  const int v = find_max(1, 999);
  ASSERT_EQ(179, v);}

TEST(CollatzFixture, find_2){
  const int v = find_max(1, 100000);
  ASSERT_EQ(351, v);}

TEST(CollatzFixture, find_3){
  const int v = find_max(12345,67890);
  ASSERT_EQ(340, v);}

// ------------
// range_length
// ------------

TEST(CollatzFixture, range_1) {
    const int v = range_length(1, 999, 1);
    ASSERT_EQ(179, v);}

TEST(CollatzFixture, range_2) {
    const int v = range_length(1, 100000, 1);
    ASSERT_EQ(351, v);}

TEST(CollatzFixture, range_3) {
    const int v = range_length(12345, 67890, 1);
    ASSERT_EQ(340, v);}


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
