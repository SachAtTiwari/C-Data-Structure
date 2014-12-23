#include<iostream>

using namespace std;

class node{
	public:
		int data;
		node *next;
		node(int data){
			this->data = data;
			this->next = NULL;
		}
};

class queue{
	public:
		node *front, *rear;
		queue* createQ();
		void enque(queue *q, int data);
		int deque(queue *q);
		queue(){
			this->front = this->rear = NULL;	
		}
};


void queue::enque(queue *q, int data){
	node *temp = new node(data);
	if (q->rear == NULL){
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
	cout << "enqued " << data << endl;
	
}

int queue::deque(queue *q){
	if(q->front == NULL){
		return 0;
	}
	node *temp = q->front;
	int data = q->front->data;
	q->front = q->front->next;
	if (q->front == NULL){
		q->rear = NULL;
	}
	cout << "popped: " << data << endl;	
	return data;
}

int main(){
	queue *q = new queue();
	q->enque(q,10);
	q->enque(q,20);
	q->enque(q,30);
	q->enque(q,40);
	cout << "dequed " << q->deque(q) << endl ;
	return 0;
}
