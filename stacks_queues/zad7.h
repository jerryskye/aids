#include "../elem.h"
#include "stack.h"
#include "queue.h"

void reverse_with_stack(elem* &stack) {
	elem* helper = 0;
	while(!sIsEmpty(stack))
		push(helper, pop(stack));
	stack = helper;
}

void reverse_with_queue(elem* &stack) {
	elem* start = 0;
	elem* end = 0;
	while(!sIsEmpty(stack))
		add(start, end, pop(stack));
	while(!qIsEmpty(start, end))
		push(stack, next(start, end));
}
