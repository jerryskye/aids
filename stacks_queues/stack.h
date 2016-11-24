bool sIsEmpty(elem* stack) {
	return stack == 0;
}

void push(elem* &stack, int x) {
	if(sIsEmpty(stack)) {
		stack = new elem;
		stack->data = x;
		stack->next = 0;
	}
	else {
		elem * new_elem = new elem;
		new_elem->data = x;
		new_elem->next = stack;
		stack = new_elem;
	}
}

int sPeek(elem* stack) {
	return sIsEmpty(stack)? -1 : stack->data;
}

int pop(elem* &stack) {
	int result;
	if(sIsEmpty(stack))
		result = -1;
	else {
		result = stack->data;
		delete stack;
		stack = stack->next;
	}
	return result;
}
