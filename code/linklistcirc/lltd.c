#include <STDIO.H>

#include "LINKLIST.H"
#include "BDSCTEST.H"


int main() {
	START_TESTING("LINKLIST.C");
	struct node* n1;

	TEST_CASE("mknode"); {
		n1 = mknode(n1, 129);
		ASSERT(n1->num == 129);
		ASSERT(n1->next == NULL);
		free(n1);
	}

	TEST_CASE("lsize"); {
		n1 = mknode(n1, 5);
		n1->next = mknode(n1, 0);
		n1->next->next = mknode(n1, -3);
		ASSERT(lsize(n1) == 3);
		free(n1->next->next);
		free(n1->next);
		free(n1);
	}

	TEST_CASE("isempty"); {
		n1 = mknode(n1, 3);
		ASSERT(isempty(n1) == 0);
		dellst(n1);
        n1 = NULL;
		ASSERT(isempty(n1) == 1);
	}

    /*
     * Not quite sure how to test yet idk
	   * TODO: Test if the other pointers are actually freed by dellst
    */

	/* TODO: Test insert function */

	/* TODO: Test prnlist function */

	END_TESTING();

	return 0;
}
