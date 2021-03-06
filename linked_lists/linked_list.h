void insert(int x, int i, elem* &lista)
{
  if(i >= 1) // if valid element index
  {
		elem* nowy = new elem; // instantiate new element
		nowy -> dane = x; // apply x as data for that element
    if (i == 1) // if first list element;
    {
      nowy -> nast = lista; // point towards the old list as next element
      lista = nowy; // replace old list with new one
    }
    else // if not first element
    {
      elem* poprz = lista; // init old list as previous element

      for (int c = 0; c != (i-2); c++) // loop for applying previous element pointer to each element of the list
      {
        poprz = poprz -> nast;
        if (poprz == NULL) // if previous element to point to doesn't exist, throw a fit and insult the user's mother
          throw runtime_error("Za krotka lista"); // or you know, just show an error. Either works
      }

      nowy -> nast = poprz -> nast; // Ordering Element Pointers Vol II: Return of the Jedi
      poprz -> nast = nowy; // yup still at it. It's the last line tho
    }
  }
  else throw runtime_error("Bledne dane"); // throw an error if target element index is <0
}

void remove(int i, elem* &lista) {
	if(lista != 0) {
		if(i == 1) {
			elem* stary = lista;
			lista = lista->nast;
			delete stary;
		}
		else if(i > 1) {
			elem* poprz = lista;
			for(int j = 0; j < i - 2; ++j) {
				poprz = poprz->nast;
				if(poprz == 0)
					throw runtime_error("Za krotka lista");
			}
			elem* stary = poprz->nast;
			if(stary == 0)
				throw runtime_error("Brak elementu do usuniecia");
			poprz->nast = stary->nast;
			delete stary;
		}
		else
			throw runtime_error("Bledne dane");
	}
	else
		throw runtime_error("Pusta lista");
}

int read(int i, elem* lista) {
	if(lista != 0) {
		if(i >= 1) {
			elem* wyn = lista;
			for(int c = 0; c < i - 1; ++c) {
				wyn = wyn->nast;
				if(wyn == 0)
					throw runtime_error("Za krotka lista");
			}
			return wyn->dane;
		}
		else
			throw runtime_error("Bledne dane");
	}
	else
		throw runtime_error("Pusta lista");
}

int size(elem* lista) {
	int wynik = 0;
	if(lista != 0) {
		for(wynik; lista != 0; lista = lista->nast)
			++wynik;
	}
	return wynik;
}

int size_rec(elem* lista) {
	return lista? 1 + size(lista->nast) : 0;
}

void print(elem* lista) {
	if(lista == 0)
		cout << "Lista jest pusta.\n";
	else {
		while(lista != 0) {
			cout << lista->dane << endl;
			lista = lista->nast;
		}
	}
}

void print_reversed_with_stack(elem* lista) {
	elem* stack = 0;
	int n = size(lista);
	for(int i = 1; i <= n; ++i)
		push(stack, read(i, lista));
	while(stack != 0)
		cout << pop(stack) << endl;
}

void print_reversed(elem* lista) {
	int n = size(lista);
	for(int i = n; i > 0; --i)
		cout << read(i, lista) << endl;
}

void print_reversed_rec(elem* lista) {
	if(lista) {
		print_reversed_rec(lista->nast);
		cout << lista->dane << endl;
	}
}

void destroy(elem* &lista) {
	int n = size(lista);
	for(int i = n; i > 0; --i)
		remove(1, lista);
}

elem* search(int x, elem* lista) {
	while(lista != 0) {
		if(lista->dane == x)
			return lista;
		lista = lista->nast;
	}
	return 0;
}

elem* search_rec(int x, elem* lista) {
	return lista? (lista->dane == x)? lista : search(x, lista->nast) : 0;
}
