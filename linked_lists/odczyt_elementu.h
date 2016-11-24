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
		else cout << "Bledne dane\n";
	}
	else cout << "Pusta lista\n";
	return 0xdeadbeef;
}
