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
