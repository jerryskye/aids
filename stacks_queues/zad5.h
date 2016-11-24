#include "../elem.h"
#include "stack.h"

void move(elem* &source, elem* &destination) {
	while(!sIsEmpty(source))
		push(destination, pop(source));
}

bool qIsEmpty(elem* start, elem* end) {
	return sIsEmpty(start) && sIsEmpty(end);
}

void add(elem* &start, elem* &end, int x) {
	push(end, x);
}

int qPeek(elem* &start, elem* &end) {
	if(sIsEmpty(start))
		move(end, start);
	return getTop(start);
}

int next(elem* &start, elem* &end) {
	if(sIsEmpty(start))
		move(end, start);
	return pop(start);
}
