#include <bdsctest.h>
#include <linklist.h>
#include <stdio.h>

int main() {
  TEST_CASE("mknode") {
    linklist *a1, *b1, *c1;
    a1 = mknode(0);
    ASSERT(a1->num == 0);
    b1 = mknode(12345);
    ASSERT(b1->num == 12345);
    c1 = mknode(-12345);
    ASSERT(c1->num == -12345);
    free(a1);
    free(b1);
    free(c1);
  }

  TEST_CASE("mkempty") {
    linklist *a2;
    a2 = mkempty();
    ASSERT(a2 == NULL);
  }

  /*
   *  In loving memory of test 2. You will be dearly missed.
   *  
   *  (I realized there was no way to test dellst but already
   *  numbered them and dont feel like renumbering them.)
   */

  TEST_CASE("isempty") {
    linklist *a4, *b4, *c4, *d4, *e4;
    a4 = mkempty();
    b4 = mknode(-1);
    c4 = mknode(1);
    d4 = mknode(2);
    e4 = mknode(3);
    c4->next = d4;
    d4->next = e4;
    ASSERT(isempty(a4) == 1);
    ASSERT(isempty(b4) == 0);
    ASSERT(isempty(c4) == 0);
    dellst(a4);
    dellst(b4);
    dellst(c4);
  }

  TEST_CASE("lsize") {
    linklist *a5, *b5, *c5, *d5, *e5;
    a5 = mkempty();
    b5 = mknode(-1);
    c5 = mknode(1);
    d5 = mknode(2);
    e5 = mknode(3);
    c5->next = d5;
    d5->next = e5;
    ASSERT(lsize(a5) == 0);
    ASSERT(lsize(b5) == 1);
    ASSERT(lsize(c5) == 3);
    dellst(a5);
    dellst(b5);
    dellst(c5);
  }
  
  TEST_CASE("prnlist") {

    /* Broken, not sure why though,
    problem for later me */
    
    FAIL();/*
    linklist *a6, *b6, *c6, *d6, *e6;
    char *x6, *y6, *z6;
    a6 = mkempty();
    b6 = mknode(-1);
    c6 = mknode(1);
    d6 = mknode(2);
    e6 = mknode(3);
    c6->next = d6;
    d6->next = e6;
    ASSERT_STR(prnlist(a6, x6), "");
    free(x6);
    dellst(a6);
    ASSERT_STR(prnlist(b6, y6), "-1");
    free(y6);
    dellst(b6);
    ASSERT_STR(prnlist(c6, z6), "1->2->3");
    free(z6);
    dellst(c6);*/
  }

  TEST_CASE("getnode") {
    linklist *a7, *b7, *c7, *d7, *e7;
    a7 = mkempty();
    b7 = mknode(-1);
    c7 = mknode(1);
    d7 = mknode(2);
    e7 = mknode(3);
    c7->next = d7;
    d7->next = e7;
    ASSERT(getnode(a7, 0) == a7);
    ASSERT(getnode(b7, 0) == b7);
    ASSERT(getnode(c7, 0) == c7);
    ASSERT(getnode(c7, 1) == d7);
    ASSERT(getnode(c7, 2) == e7);
    dellst(a7);
    dellst(b7);
    dellst(c7);
  }
  
  TEST_CASE("getnode") {
    linklist *a8, *b8, *c8, *d8, *e8;
    a8 = mkempty();
    b8 = mknode(-1);
    c8 = mknode(1);
    d8 = mknode(2);
    e8 = mknode(3);
    c8->next = d8;
    d8->next = e8;
    ASSERT(getnum(b8, 0) == -1);
    ASSERT(getnum(c8, 0) == 1);
    ASSERT(getnum(c8, 1) == 2);
    ASSERT(getnum(c8, 2) == 3);
    dellst(a8);
    dellst(b8);
    dellst(c8);
  }

  TEST_CASE("insert") {
    FAIL(); /* TODO */
  }

  TEST_CASE("remove") {
    FAIL(); /* TODO */
  }
}
