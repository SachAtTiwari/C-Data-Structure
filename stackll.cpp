#include<iostream>

using namespace std;

class node{
	public:
		int data;
		node *next;
		node(){this->next = NULL;}
		node(int data){
			this->data = data;
			this->next = NULL;
		}	
};

class stack {
	public:
		void push(node **s, int data);
		int pop(node **s);
		int peek(node *s);
};

void stack::push(node **s, int data){
	node *tempNode = new node(data);
	tempNode->next = *s;
	*s = tempNode;
	cout << "Pushed " << data << endl;
}

int stack::pop(node **s){
	if (*s == NULL){
		return 0;
	}
	node *temp = *s;
	int data = temp->data;
	*s = (*s)->next;
	delete temp;
	return data;
}

int stack::peek(node *s){
	if (!s){
		return 0;
	}
	return s->data;
}

int main(){
	stack *s = new stack();
	node *n = new node();
	s->push(&n,10);
	s->push(&n,20);
	s->push(&n,30);
	s->push(&n,40);
	cout << "Popped " << s->pop(&n) << endl;
	return 0;	
}
