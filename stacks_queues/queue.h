bool qIsEmpty(elem* start, elem* end) {
	return start == 0 || end == 0;
}

void add(elem* &start, elem* &end, int x) {
	if(qIsEmpty(start, end)) {
		start = new elem;
		start->data = x;
		start->next = 0;
		end = start;
	}
	else {
		elem* new_elem = new elem;
		new_elem->data = x;
		new_elem->next = 0;
		end->next = new_elem;
		end = new_elem;
	}
}

int qPeek(elem* start) {
	return start == 0 ? -1 : start->data;
}

int next(elem* &start, elem* &end) {
	int result;
	if(qIsEmpty(start, end))
		result = -1;
	else {
		result = start->data;
		delete start;
		start = start->next;
	}
	return result;
}
