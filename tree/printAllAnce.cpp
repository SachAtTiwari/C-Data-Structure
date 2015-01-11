#include <iostream>
#include <stack>

using namespace std;

class tnode{
	public:
		int data;
		tnode *left;
		tnode *right;
		tnode(){
			this->left = this->right = NULL;
		}
		tnode(int data) {
			this->data = data;
			this->left = this->right = NULL;
		}
};

class tree{
	public:
		void insert(tnode **root, int data);
		void inOrderNonRecursive(tnode *root);
		int printAllAncestor(tnode *root, tnode *node);
		void delNode(tnode **root, int data);
		tnode *findMax(tnode *root);
		tnode *lca(tnode *root, tnode *a, tnode *b);
		tnode *findMin(tnode *root);
};

tnode *tree::findMin(tnode *root){
	tnode *temp = root;
	if (temp == NULL) return temp;
	if (temp->left == NULL) return temp;
	while (temp->left != NULL){
		temp = temp->left;
	}	
	return temp;
}

tnode *tree::lca(tnode *root, tnode *a, tnode *b){
	if (root == NULL) return root;
	while (1){
		if (root->data > a->data && root->data < b->data || 
				a->data > root->data && b->data < root->data){
			return root;
		}	
		if (root->data > a->data) root = root->left;
		else root = root->right;
	}
}

tnode *tree::findMax(tnode *root){
	tnode *temp = root;
	if (temp == NULL) return temp;
	if (temp->right == NULL ) return temp;
	while (temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

void tree::delNode(tnode **root, int data){
	tnode *temp;
	if (*root == NULL) return;
	else if (data < (*root)->data){
		delNode(&(*root)->left, data);
	}
	else if (data > (*root)->data){
		delNode (&(*root)->right, data);
	}
	else { 
		//found element
		if ((*root)->left && (*root)->right){
			//replace with largest element in left subtree
			temp = findMax((*root)->left);
			(*root)->data = temp->data;
			delNode(&(*root)->left, (*root)->data);
		}else {
			//one child	
			temp = *root;
			if ((*root)->left == NULL){	
				*root = (*root)->right;
			}
			if ((*root)->right == NULL){
				*root = (*root)->left;
			}
			delete temp;
		}
	}
}

int tree::printAllAncestor(tnode *root, tnode *node){
	if (root == NULL)  return 0;
	if (root->left == node || root->right == node || printAllAncestor(root->left, node) || 
				printAllAncestor(root->right, node)){
				cout <<  root->data << " ";
	}
}

void tree::inOrderNonRecursive(tnode *root){
	stack <tnode *> st;
	if (root == NULL){return;}
	tnode *temp = root;
	
	while (!st.empty() || temp){
		if (temp){
			st.push(temp);
			temp = temp->left;
		}else{
			temp = st.top();
			cout << temp->data << " ";
			temp = temp->right;
			st.pop();
		}
	}
}

void tree::insert(tnode **root, int data){
	if (*root == NULL){
		tnode *temp = new tnode(data);
		*root = temp;
	}
	else if ((*root)->data > data){
		insert (&(*root)->left, data);
	}
	else if ((*root)->data < data){
		insert (&(*root)->right, data);
	}
}

int main(){
	tree *t = new tree();
	tnode *temp = NULL; //new tnode();
	t->insert(&temp, 7);
	t->insert(&temp, 1);
	t->insert(&temp, 8);
	t->insert(&temp, 6);
	t->insert(&temp, 3);
	t->insert(&temp, 4);
	t->insert(&temp, 5);
	cout << "Non Recursive: ";
	t->inOrderNonRecursive(temp);
	cout << endl;
	//t->printAllAncestor(temp, temp->right->left);
	//cout << endl;
	//t->delNode(&temp, 3);
	//cout << endl;
	//t->inOrderNonRecursive(temp);
	//cout << endl;
	//cout << t->lca(temp, temp->left->right, temp->right)->data << endl;
	cout << t->findMin(temp->right)->data << endl;
	cout << endl;
	return 0;
}
