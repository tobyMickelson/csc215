#include "bigint.h"
#include "bdsctest.h"

main() {
  START_TESTING("biginttd.c");

  TEST_CASE("Read and write bigint 1234567") {
    bigint bi;
    set_bigint(&bi, "1234567");
    ASSERT_STR(get_bigint(bi), "1234567");
  }

  TEST_CASE("Add two bigints (321 + 987 = 1308)") {
    bigint a;
    bigint b;
    set_bigint(&a, "321");
    set_bigint(&b, "987");
    add_bigints(a, b);
    ASSERT_STR(get_bigint(a), "1308");
  }

  END_TESTING();
}
