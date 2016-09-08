// --------------------------------
// projects/collatz/TestCollatz.c++
// Fernando E. Mendoza-Olivares
// --------------------------------

// --------
// includes
// --------

#include <iostream>		// cout, endl
#include <sstream>		// istringtstream, ostringstream
#include <string>		// string

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// ----
// read
// ----

TEST(CollatzFixture, read_hundred) {
	istringstream r("1 100\n");
	int i;
	int j;
	const bool b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(1, i);
    ASSERT_EQ(100, j);
}

TEST(CollatzFixture, read_large) {
	istringstream r("888888 999999\n");
	int i;
	int j;
	const bool b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(888888, i);
    ASSERT_EQ(999999, j);
}

TEST(CollatzFixture, read_negative) {
	istringstream r("100 -100\n");
	int i;
	int j;
	const bool b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(100, i);
    ASSERT_EQ(-100, j);
}

TEST(CollatzFixture, read_empty) {
	istringstream r("");
	int i;
	int j;
	const bool b = collatz_read(r, i, j);
	ASSERT_FALSE(b);
}

TEST(CollatzFixture, read_multiple) {
	istringstream r("677 877777\n1 5\n");
	int i;
	int j;
	bool b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(677, i);
    ASSERT_EQ(877777, j);

    b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(1, i);
    ASSERT_EQ(5, j);
}

TEST(CollatzFixture, read_multiple_empty) {
	istringstream r("677 877777\n1 5\n");
	int i;
	int j;
	bool b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(677, i);
    ASSERT_EQ(877777, j);

    b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(1, i);
    ASSERT_EQ(5, j);

    b = collatz_read(r, i, j);
    ASSERT_FALSE(b);
}

TEST(CollatzFixture, read_single) {
	istringstream r("677");
	int i;
	int j;
	const bool b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(677, i);
}
// ----
// eval
// ----

TEST(CollatzFixture, eval_range_1) {
    const int v = collatz_eval(100500, 950000);
    ASSERT_EQ(525, v);
}

TEST(CollatzFixture, eval_range_2) {
    const int v = collatz_eval(250000, 750000);
    ASSERT_EQ(509, v);
}

TEST(CollatzFixture, eval_equality_1) {
    const int v = collatz_eval(70000, 70000);
    ASSERT_EQ(82, v);
}

TEST(CollatzFixture, eval_equality_2) {
    const int v = collatz_eval(1000000, 1000000);
    ASSERT_EQ(153, v);
}

TEST(CollatzFixture, eval_range_backwards) {
    const int v = collatz_eval(750999, 689001);
    ASSERT_EQ(504, v);
}

// -----
// print
// -----

TEST(CollatzFixture, print) {
	ostringstream w;
	collatz_print(w, 50, 100, 200);
	ASSERT_EQ("50 100 200\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_range_small_multiple) {
	istringstream r("1 10\n45 50\n100 300\n100 1800\n");
	ostringstream w;
	collatz_solve(r, w);
	ASSERT_EQ("1 10 20\n45 50 105\n100 300 128\n100 1800 182\n", w.str());
}

TEST(CollatzFixture, solve_range_backwards) {
	istringstream r("100 1\n877 366\n5000 3000\n130000 1\n376000 369000\n");
	ostringstream w;
	collatz_solve(r, w);
	ASSERT_EQ("100 1 119\n877 366 179\n5000 3000 238\n130000 1 354\n376000 369000 392\n", w.str());
}

TEST(CollatzFixture, solve_range_large_multiple) {
	istringstream r("77031 770310\n500000 1000000\n364522 652212\n");
	ostringstream w;
	collatz_solve(r, w);
	ASSERT_EQ("77031 770310 509\n500000 1000000 525\n364522 652212 509\n", w.str());
}

TEST(CollatzFixture, solve_large_range) {
	istringstream r("1 1000000\n377681 855349\n");
	ostringstream w;
	collatz_solve(r, w);
	ASSERT_EQ("1 1000000 525\n377681 855349 525\n", w.str());
}

// -----
// cycle
// -----

TEST(CollatzFixture, cycle_1) {
    const int v = collatz_cycle(100);
    ASSERT_EQ(26, v);
}

TEST(CollatzFixture, cycle_2) {
    const int v = collatz_cycle(80000);
    ASSERT_EQ(33, v);
}

TEST(CollatzFixture, cycle_3) {
    const int v = collatz_cycle(350000);
    ASSERT_EQ(167, v);
}

TEST(CollatzFixture, cycle_4) {
    const int v = collatz_cycle(650000);
    ASSERT_EQ(186, v);
}

// ---------
// naive_max
// ---------

TEST(CollatzFixture, naive_max_small_1) {
    const int v = collatz_naive_max(1, 10);
    ASSERT_EQ(20, v);
}

TEST(CollatzFixture, naive_max_small_2) {
    const int v = collatz_naive_max(200, 1500);
    ASSERT_EQ(182, v);
}

TEST(CollatzFixture, naive_max_small_3) {
    const int v = collatz_naive_max(899999, 900001);
    ASSERT_EQ(225, v);
}

TEST(CollatzFixture, naive_max_large_1) {
    const int v = collatz_naive_max(50000, 200000);
    ASSERT_EQ(383, v);
}

TEST(CollatzFixture, naive_max_large_2) {
    const int v = collatz_naive_max(150750, 450800);
    ASSERT_EQ(449, v);
}

TEST(CollatzFixture, naive_max_backwards) {
    const int v = collatz_naive_max(200000, 50000);
    ASSERT_EQ(383, v);
}
