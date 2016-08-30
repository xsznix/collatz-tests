// --------------------------------
// xz4493-TestCollatz.c++
// Copyright (C) 2016
// Xuming Zeng
// --------------------------------

// --------
// includes
// --------

#include <iostream>		// cout, endl
#include <sstream>		// istringtstream, ostringstream
#include <string>		// string

#include "gtest/gtest.h"

#include "../Collatz.h"

using namespace std;

// --------
// features
// --------

// Uncomment the following line ONLY IF your solution uses longs internally to
// calculate cycles; otherwise, some of the tests will overflow 32-bit int. This
// is NOT a project requirement.

// #define ENABLE_LARGE_NUMBER_TESTS

// ----
// read
// ----

TEST(CollatzFixture, read_zero)
{
	istringstream r("");
	int i;
	int j;
	bool b;

	b = collatz_read(r, i, j);
	ASSERT_FALSE(b);
}

TEST(CollatzFixture, read_one)
{
	istringstream r("1 1\n");
	int i;
	int j;
	bool b;

	b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(1, i);
	ASSERT_EQ(1, j);

	b = collatz_read(r, i, j);
	ASSERT_FALSE(b);
}

TEST(CollatzFixture, read_two)
{
	istringstream r("1 20\n93 155\n");
	int i;
	int j;
	bool b;

	b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(1, i);
	ASSERT_EQ(20, j);

	b = collatz_read(r, i, j);
	ASSERT_TRUE(b);
	ASSERT_EQ(93, i);
	ASSERT_EQ(155, j);

	b = collatz_read(r, i, j);
	ASSERT_FALSE(b);
}

// ----
// eval
// ----

TEST(CollatzFixture, eval_small_numbers_single)
{
	// Source: https://oeis.org/A006577
	const int answers[] = {
		0, 1, 7, 2, 5, 8, 16, 3, 19, 6, 14, 9, 9, 17, 17, 4, 12, 20, 20, 7, 7,
		15, 15, 10, 23, 10, 111, 18, 18, 18, 106, 5, 26, 13, 13, 21, 21, 21, 34,
		8, 109, 8, 29, 16, 16, 16, 104, 11, 24, 24, 24, 11, 11, 112, 112, 19,
		32, 19, 32, 19, 19, 107, 107, 6, 27, 27, 27, 14, 14, 14, 102, 22};
	for (unsigned i = 0; i < sizeof(answers) / sizeof(int); i++) {
		const int v = collatz_eval(i + 1, i + 1);
		ASSERT_EQ(answers[i] + 1, v);
	}
}

TEST(CollatzFixture, eval_large_numbers_single)
{
	int v;

	v = collatz_eval(9, 9);
	ASSERT_EQ(20, v);

	v = collatz_eval(97, 97);
	ASSERT_EQ(119, v);

	v = collatz_eval(871, 871);
	ASSERT_EQ(179, v);

	v = collatz_eval(6171, 6171);
	ASSERT_EQ(262, v);

	v = collatz_eval(77031, 77031);
	ASSERT_EQ(351, v);

#ifdef ENABLE_LARGE_NUMBER_TESTS
	v = collatz_eval(837799, 837799);
	ASSERT_EQ(525, v);

	v = collatz_eval(8400511, 8400511);
	ASSERT_EQ(686, v);
#endif
}

TEST(CollatzFixture, eval_large_numbers_range)
{
	int v;

	v = collatz_eval(1, 10);
	ASSERT_EQ(20, v);

	v = collatz_eval(1, 100);
	ASSERT_EQ(119, v);

	v = collatz_eval(1, 1000);
	ASSERT_EQ(179, v);

	v = collatz_eval(1, 10000);
	ASSERT_EQ(262, v);

	v = collatz_eval(1, 100000);
	ASSERT_EQ(351, v);

#ifdef ENABLE_LARGE_NUMBER_TESTS
	v = collatz_eval(1, 1000000);
	ASSERT_EQ(525, v);

	v = collatz_eval(1, 10000000);
	ASSERT_EQ(686, v);
#endif
}

// -----
// print
// -----

TEST(CollatzFixture, print_one)
{
	ostringstream w;
	collatz_print(w, 123, 456, 789);
	ASSERT_EQ("123 456 789\n", w.str());
}

TEST(CollatzFixture, print_two)
{
	ostringstream w;
	collatz_print(w, 13, 24, 35);
	collatz_print(w, 46, 57, 68);
	ASSERT_EQ("13 24 35\n46 57 68\n", w.str());
}

// -----
// solve
// -----

TEST(CollatzFixture, solve_one)
{
	istringstream r("1 1\n");
	ostringstream w;
	collatz_solve(r, w);
	ASSERT_EQ("1 1 1\n", w.str());
}

TEST(CollatzFixture, solve_small)
{
	istringstream r("1 1\n2 2\n3 3\n4 4\n5 5\n6 6\n");
	ostringstream w;
	collatz_solve(r, w);
	ASSERT_EQ("1 1 1\n2 2 2\n3 3 8\n4 4 3\n5 5 6\n6 6 9\n", w.str());
}

TEST(CollatzFixture, solve_large_single)
{
	istringstream r("77031 77031\n");
	ostringstream w;
	collatz_solve(r, w);
	ASSERT_EQ("77031 77031 351\n", w.str());
}

TEST(CollatzFixture, solve_large_range)
{
	istringstream r("1 6171\n6172 106238\n");
	ostringstream w;
	collatz_solve(r, w);
	ASSERT_EQ("1 6171 262\n6172 106238 351\n", w.str());
}
