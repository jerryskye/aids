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
			cout << "Bledne dane\n";
	}
	else
		cout << "Pusta lista\n";
}
