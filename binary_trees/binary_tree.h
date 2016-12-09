struct node {
	int data;
	node* left;
	node* right;
};

bool search(node* tree, int x) {
	return tree? (tree->data == x || search(tree->left, x) || search(tree->right, x)) : false;
}

int leaves(node* tree) {
	return tree? (leaves(tree->right) + leaves(tree->left) + 1) : 0;
}

int height(node* tree) {
	return tree? 1 + max(height(tree->left), height(tree->right)) : -1;
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
		for(int i = 0; i < p; ++i)
			cout << " ";
		cout << tree->data << endl;
		print(tree->left, p + 1);
		print(tree->right, p + 1);
	}
}

bool balanced(node* tree) {
	if(tree == 0)
		return true;
	switch(heigth(tree->left) - height(tree->right)) {
		case -1, 0, 1:
			return balanced(tree->left) && balanced(tree->right);
		default:
			return false;
	}
}
