#include "stdio.h"

#include "bdsctest.h"
#include "bigint.h"

main() {
  START_TESTING("biginttd.c");
  char *s;

  TEST_CASE("Read and write bigint 1234567") {
    bigint bi;
    set_bigint(&bi, "1234567");
    s = get_bigint(&bi);
    ASSERT_STR(s, "1234567");
    free(s);
  }

  TEST_CASE("Add two bigints (321 + 987 = 1308)") {
    bigint a;
    bigint b;
    bigint res;
    set_bigint(&a, "321");
    set_bigint(&b, "987");
    printf("a and b set\n");
    add_bigints(&a, &b, &res);
    s = get_bigint(&res);
    ASSERT_STR(s, "1308");
    free(s);
  }

  END_TESTING();
}
