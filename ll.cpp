#include<iostream>

using namespace std;

class Node{
	public:
		int data;	
		Node *next;
		Node(){ next = NULL; };
		Node(int data){
			this->data = data;
			this->next = NULL;
		};

};

class List : public Node {
	public:
		void addNode(Node **head, int data);
		void print(Node *head);
		void delNode(Node **head, int data);
		void revList(Node **head);
};

void List::revList(Node **head){
	Node *temp = *head;
	Node *newList = NULL;
	Node *prev = NULL;
	while (temp != NULL){
		newList = temp->next;
		temp->next = prev;
		prev = temp;
		temp = newList;
	}
	*head = prev;

}

void List::addNode(Node **head, int data){
	Node *temp = new Node(data);
	//temp->data = data;
	if(*head == NULL){
		*head = temp;
		return;
	}
	temp->next = *head;
	*head = temp;
}

void List::print(Node *head){
	Node *temp = head;
	cout << " Printing List: " ; 
	while(temp!= NULL){
		cout << " " << temp->data;
		temp = temp->next;
	}
	cout << endl;
}

void List::delNode(Node **head, int data){
	if ( head == NULL ){
		return;	
	}
	Node *temp = *head;
	Node *prev = NULL;
	while( temp != NULL ){
		if ( temp->data ==  data ){
			if ( *head == temp ){
					*head = temp->next;
					delete temp;
					return;
			}
			else {
					prev->next = temp->next;
					delete temp;
					return;
			}
		}
		else{
			prev = temp;
			temp = temp->next;
		}
	}
}

int main(){
	List *list = new List();
	Node *node = NULL;
	list->addNode(&node, 10);
	list->addNode(&node, 20);
	list->addNode(&node, 30);
	list->print(node);
	//list->delNode(&node, 10);
	//list->print(node);
	list->addNode(&node, 40);
	list->print(node);
	list->revList(&node);
	list->print(node);
	return 0;
}
