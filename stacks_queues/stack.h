bool sIsEmpty(elem* stack) {
	return stack == 0;
}

void push(elem* &stack, int x) {
	if(sIsEmpty(stack)) {
		stack = new elem;
		stack->dane = x;
		stack->nast = 0;
	}
	else {
		elem * new_elem = new elem;
		new_elem->dane = x;
		new_elem->nast = stack;
		stack = new_elem;
	}
}

int sPeek(elem* stack) {
	return sIsEmpty(stack)? -1 : stack->dane;
}

int pop(elem* &stack) {
	int result;
	if(sIsEmpty(stack))
		result = -1;
	else {
		result = stack->dane;
		delete stack;
		stack = stack->nast;
	}
	return result;
}
