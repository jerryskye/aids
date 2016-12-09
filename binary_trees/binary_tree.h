struct node {
	int data;
	node* left;
	node* right;
};

bool search(node* tree, int x) {
	return tree? (tree->data == x || search(tree->left, x) || search(tree->right, x)) : false;
}

int vertexes(node* tree) { //ilość wierzchołków
	return tree? (vertexes(tree->right) + vertexes(tree->left) + 1) : 0;
}

int leaves(node* tree) { //ilość liści
	//return tree? (leaves(tree->right) + leaves(tree->left)) : 0;
	//do poprawienia, ktoś kto ma niech napisze, moje jest źle
	return 0xdeadbeef;
}

int height(node* tree) {
	return tree? 1 + std::max(height(tree->left), height(tree->right)) : -1;
}

int right_children(node* tree) {
	int licznik = 0;
	if(tree != 0) {
		if(tree->right != 0)
			licznik++;
		licznik += right_children(tree->left) + right_children(tree->right);
	}
	return licznik;
}

void print(node* tree, int p = 0) {
	if(tree) {
		std::cout << std::string(p, ' '); //wypisz p spacji - specjalny konstruktor string(int, char)
		std::cout << tree->data << std::endl;
		print(tree->left, p + 1);
		print(tree->right, p + 1);
	}
}

bool balanced(node* tree) {
	if(tree == 0)
		return true;
	switch(height(tree->left) - height(tree->right)) {
		case -1:
		case 0:
		case 1:
			return balanced(tree->left) && balanced(tree->right);
		default:
			return false;
	}
}
