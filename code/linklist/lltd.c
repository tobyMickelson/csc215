#include <STDIO.H>
#include "LINKLIST.H"
#include "BDSCTEST.H"


int main() {
	START_TESTING("LINKLIST.C");

	TEST_CASE("mknode"); {
		struct node* n1;
		n1 = mknode(129);
		ASSERT(n1->num == 129);
		ASSERT(n1->next == NULL);
		free(n1);
	}

	TEST_CASE("lsize"); {
		n1 = mknode(5);
		n1->next = mknode(0);
		n1->next->next = mknode(-3);
		ASSERT(lsize(n1) == 3);
		free(n1->next->next);
		free(n1->next);
		free(n1);
	}

	TEST_CASE("isempty"); {
		n1 = mknode(3);
		ASSERT(isempty(n1) == 0);
		dellst(n1);
        n1 = NULL;
		ASSERT(isempty(n1) == 1);
	}

    /* Not quite sure how to test yet idk
	TEST_CASE("dellst"); {
		n1 = mknode(4);
		n1->next = mknode(6);
		n1->next->next = mknode(5);
		dellst(n1->next);
		ASSERT(n1->next == NULL);
		ASSERT(n1 != NULL);
		free(n1);

		*//* TODO: Test if the other pointers are actually freed by dellst *//*
	}
    */

	/* TODO: Test insert function */

	/* TODO: Test prnlist function */

	END_TESTING();

	return 0;
}
