#include "bdsctest.h"
#include "bigint.h"
#include "stdio.h"

main() {
  START_TESTING("biginttd.c");
  char *s;

  TEST_CASE("set and get bigint") {
    bigint bi;
    
    set_bigint(&bi, "1234567");
    s = get_bigint(&bi);
    ASSERT_STR(s, "1234567");
    free(s);
    
    set_bigint(&bi, "-123");
    s = get_bigint(&bi);
    ASSERT_STR(s, "-123");
    free(s);
  }

  TEST_CASE("add bigints") {
    bigint a, b, res;
    
    set_bigint(&a, "321");
    set_bigint(&b, "987");
    add_bigints(&a, &b, &res);
    s = get_bigint(&res);
    ASSERT_STR(s, "1308");
    free(s);

    /* thank you random.org for the following numbers <3 */
    
    set_bigint(&a, "21462");
    set_bigint(&b, "64971");
    add_bigints(&a, &b, &res);
    s = get_bigint(&res);
    ASSERT_STR(s, "86433");
    free(s);
    
    set_bigint(&a, "5847");
    set_bigint(&b, "32454");
    add_bigints(&a, &b, &res);
    s = get_bigint(&res);
    ASSERT_STR(s, "38301");
    free(s);
    
    set_bigint(&a, "13183");
    set_bigint(&b, "1911");
    add_bigints(&a, &b, &res);
    s = get_bigint(&res);
    ASSERT_STR(s, "15094");
    free(s);
    
    set_bigint(&a, "40412");
    set_bigint(&b, "54688");
    add_bigints(&a, &b, &res);
    s = get_bigint(&res);
    ASSERT_STR(s, "95100");
    free(s);
  }

  END_TESTING();
}
