#include "../elem.h"
#include "stack.h"

void sort(elem* &stack) {
	int x = sPeek(stack), count = 0, temp;
	elem* helper = 0;

	while(!sIsEmpty(stack)) {
		if((temp = pop(stack)) < x)
			x = temp;
		push(helper, temp);
	}

	while(!sIsEmpty(helper)) {
		if((temp = pop(helper)) == x)
			break;
		else {
			push(stack, temp);
			count++;
		}
	}

	for(int i = 0; i < count; ++i)
		push(helper, pop(stack));

	push(stack, x);
}
