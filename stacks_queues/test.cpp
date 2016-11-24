#include <iostream>
#include "zad8.h"

using namespace std;

int main() {
	elem* start = 0;
	elem* end = 0;
	elem* stack = 0;
	/*
	cout << "Empty? " << qIsEmpty(start, end) << endl;
	cout << "Adding 1 to the queue.\n";
	add(start, end, 1);
	cout << "Adding 2 to the queue.\n";
	add(start, end, 2);
	cout << "First element: " << qPeek(start, end) << endl;
	cout << "Popped value: " << next(start, end) << endl;
	cout << "Popped value: " << next(start, end) << endl;

	for(int i = 1; i <= 100; ++i) {
		add(start, end, i);
	}

	int i = 1;

	while(!qIsEmpty(start, end)) {
		if(i % 25 == 0)
			add(start, end, i + 100);
		cout << next(start,end) << endl;
		++i;
	}
	return 0;
	for(int i = 1; i <= 5; ++i)
		push(stack, i);

	reverse_with_queue(stack);
	reverse_with_stack(stack);

	while(!sIsEmpty(stack))
		cout << pop(stack) << endl;
	*/
	push(stack, 4);
	push(stack, 1);
	push(stack, 6);
	push(stack, 2);
	push(stack, 5);
	push(stack, 3);

	sort(stack);

	while(!sIsEmpty(stack))
		cout << pop(stack) << endl;

	return 0;
}
