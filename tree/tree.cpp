#include <iostream>
#include <queue>

using namespace std;

class Node{
	public:
		int data;
		Node *left; Node *right;
};

class Tree{
	public:
		void insert(Node **node, int data);
		void insertNonRecur(Node **node, int data);	
		void inorder(Node *node);
		void delNode(Node *root, int data);
		int findMax(Node *root);
		int findMaxRecur(Node *root);
		int findElement(Node *root, int data);
		int size(Node *root);
		void delTree(Node *root);
		int depth(Node *root);
		Node *deepestNode(Node *root);
		Node *lca(Node *root, Node *a, Node *b);
};

Node *Tree::lca(Node *root, Node *a, Node *b){
	if (root == NULL) return root;
	if (root == a || root == b) return root;
	Node *left = lca(root->left, a, b);
	Node *right = lca(root->right, a, b);
	if (left && right){
		return root;
	}else{
		return left ? left : right;
	}
}

void Tree::delNode(Node *root, int data){
	if (root == NULL)	return;
	Tree *tree = new Tree();
	int found = tree->findElement(root, data);
	if (found){
		Node *temp = deepestNode(root);
		int tempNode = temp->data;
		temp->data = data;
		data = tempNode;
		delete temp;
	}
}

Node *Tree::deepestNode(Node *root){
	if (root == NULL)return NULL;
	queue <Node *> q;
	Node *temp ;
	q.push(root);
	
	while (!q.empty()){
		temp = q.front();
		if (temp->left){
			q.push(temp->left);
		}
		if (temp->right){
			q.push(temp->right);	
		}
		q.pop();
	}
	return temp;
}

int Tree::depth(Node *root){
	if (root == NULL)return 0;
	int leftH = depth(root->left);
	int rightH = depth(root->right);
	if (leftH > rightH) return leftH + 1;
	else return rightH + 1;
}

void Tree::delTree(Node *root){
	if (root == NULL){
		return ;
	}
	delTree(root->left);
	delTree(root->right);
	delete root;
}

int Tree::size(Node *root){

	Node *temp = root;
	queue <Node *> q;
	q.push(temp);
	int count = 0;

	while (!q.empty()){
		Node *node = q.front();
		count++;
		if (node->left){
			q.push(node->left);
		}		
		if (node->right){
			q.push(node->right);
		}
		q.pop();
	}	
	return count;
}

void Tree::insertNonRecur(Node **root, int data){
	Node *parent = NULL;
	Node *temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	if (*root == NULL){
		parent = temp;
		*root = temp;
		return;	
	}
	if ( (*root)->data == data ){
		cout << "Data exist " << endl;
	}
	else if ( (*root)->data > data ){
		
		(*root)->left = temp;
	}else{
		(*root)->right = temp;
	}
}

int Tree::findElement(Node *root, int data){
	int temp = 0;
	if (root == NULL){
		return 0;
	}
	else{
		if (data == root->data){
			return 1;
		}
		temp = findElement(root->left, data);
		if (temp != 0)return temp;
		else return findElement(root->right, data);	
	}
}

int Tree::findMaxRecur(Node *root){
	int root_val, left, right, max = 0;
	if (root != NULL){	
		root_val = root->data;	
		left = findMaxRecur(root->left);
		right = findMaxRecur(root->right);
		
		if (left > right){
			max = left;
		}else {
			max = right;
		}
		if (root_val > max){
			max = root_val;
		}
	}
	return max;
}

int Tree::findMax(Node *root){
	if (root == NULL){return 1;}
	Node *temp = root;
	queue <Node *> q;
	q.push(temp);
	int max = 0;	
	
	while (!q.empty()){
		Node *node = q.front();
		if (node->data > max){
			max = node->data;
		}
		if (node->left){
			q.push(node->left);
		}
		if (node->right){
			q.push(node->right);
		}
		q.pop();
	}
	return max;
}

void Tree::insert(Node **root, int data){
	if ( *root == NULL ){
		Node *temp = new Node();
		temp->data = data;
		temp->left = temp->right = NULL;
		*root = temp;
		return;	
	}
	if ( (*root)->data == data ){
		cout << "Node exist " << endl;
		return;
	}
	else if ( (*root)->data > data ){
		insert (&(*root)->left,data);	
		return;
	}
	else {
		insert(&(*root)->right, data);
		return;
	}
}

void Tree::inorder(Node *root){
	Node *temp = root;
	if (temp != NULL){
		inorder(temp->left);
		cout << temp->data  << " ";	
		inorder(temp->right);
	}	
}

int main(){
	Tree *tree = new Tree();
	Node *node = NULL;
	tree->insert(&node, 10);
	tree->insert(&node, 20);
	tree->insert(&node, 2);
	tree->insert(&node, 1);
	/*tree->insertNonRecur(&node, 10);
	tree->insertNonRecur(&node, 20);
	tree->insertNonRecur(&node, 2);
	tree->insertNonRecur(&node, 1);*/
	tree->inorder(node);
	cout << endl;
	cout << tree->lca(node, node->left, node->right)->data << endl;
	//cout << "depth is " << tree->depth(node);
	//cout << "deepest Node " << tree->deepestNode(node)->data ;
	//tree->delNode(node, 20);
	//cout << endl;
	//tree->inorder(node);
	//cout << endl;
	//tree->delTree(node);
	//tree->inorder(node);
	//cout << endl;
	//int size = tree->size(node);
	//cout << "size is " << size; 
	//int max = tree->findMax(node);
	//int max = tree->findMaxRecur(node);
	//cout << "max is " << max;
	//int temp = tree->findElement(node, 2);
	//cout << "Data found " << temp; 
	cout << endl;
	return 0;
}	
