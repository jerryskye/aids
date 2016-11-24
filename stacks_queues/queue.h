bool qIsEmpty(elem* start, elem* end) {
	return start == 0 || end == 0;
}

void add(elem* &start, elem* &end, int x) {
	if(qIsEmpty(start, end)) {
		start = new elem;
		start->dane = x;
		start->nast = 0;
		end = start;
	}
	else {
		elem* new_elem = new elem;
		new_elem->dane = x;
		new_elem->nast = 0;
		end->nast = new_elem;
		end = new_elem;
	}
}

int qPeek(elem* start) {
	return start == 0 ? -1 : start->dane;
}

int next(elem* &start, elem* &end) {
	int result;
	if(qIsEmpty(start, end))
		result = -1;
	else {
		result = start->dane;
		delete start;
		start = start->nast;
	}
	return result;
}
