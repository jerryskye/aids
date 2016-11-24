int size(elem* lista) {
	int wynik = 0;
	if(lista != 0) {
		for(wynik; lista != 0; lista = lista->nast)
			++wynik;
	}
	return wynik;
}
