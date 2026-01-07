#include "bigint.h"
#include "bdsctest.h"

main() {
  START_TESTING("biginttd.c");

  TEST_CASE("Read and write bigint 1234567") {
    struct bigint bi;
    set_bigint("1234567", &bi);
    ASSERT_STR(get_bigint(bi), "1234567");
  }

  END_TESTING();
}
