


#include <cassert>
#include <iostream>

#include "Collatz.h"

using namespace std;

// -------
// collatz_read tests
// -------

TEST(CollatzFixture, read_1) {
  istringstream r(" \n");
  int i;
  int j;
  const bool b = collatz_read(r,i,j);
  ASSERT_TRUE(b);
  ASSERT_EQ( , );
  ASSERT_EQ( , );
}

TEST(CollatzFixture, read_1) {
  istringstream r(" \n");
  int i;
  int j;
  const bool b = collatz_read(r,i,j);
  ASSERT_FALSE(b);
  ASSERT_EQ( , );
  ASSERT_EQ( , );
}

TEST(CollatzFixture, read_1) {
  istringstream r(" \n");
  int i;
  int j;
  const bool b = collatz_read(r,i,j);
  ASSERT_TRUE(b);
  ASSERT_EQ( , );
  ASSERT_EQ( , );
}
// ------
// collatz_eval tests
// ------

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(23737, 61824);
  ASSERT_EQ(340, v);
}

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(99476, 112058);
  ASSERT_EQ(354 , v);
}

TEST(CollatzFixture, eval_1) {
  const int v = collatz_eval(591451, 600784);
  ASSERT_EQ(403 , v);
}
// ------
// collatz_print tests
// ------

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}

TEST(CollatzFixture, print) {
    ostringstream w;
    collatz_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}


// ------
// collatz_solve
// ------

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}

TEST(CollatzFixture, solve) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_EQ("1 10 20\n100 200 125\n201 210 89\n900 1000 174\n", w.str());}
