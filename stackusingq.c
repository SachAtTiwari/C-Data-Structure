#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct queue {
	struct node *front, *rear;	
};

struct stack {
	struct queue *q1;
	struct queue *q2;
};

void enque(struct queue *q1, int data);
void switchName(struct queue **q1, struct queue **q2);

struct node *makeNode(int data){
	struct node *node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->next = NULL;
	return node;
}

struct stack *createStack(){
	//printf("in stack\n");
	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	if (!s){
		printf("Mem Error");
	}
	//printf("stack created\n");
    //s->q1 = s->q2 = NULL;
	s->q1 = (struct queue*)malloc(sizeof(struct queue));
	s->q1->front = s->q1->rear = NULL;
	s->q2 = (struct queue*)malloc(sizeof(struct queue));
	s->q2->front = s->q2->rear = NULL;

	//printf("returning stack ptr\n");
	return s;
}
int size(struct queue *q){
	int count = 0;
	printf("in size\n");
	struct node *temp = q->front;
	while (temp != NULL){
		//printf("in loop %d\n", temp->data);
		temp = temp->next;
		count++;
	}
	return count;
}
void push(struct stack *s, int data){
	//printf("in push\n");
	enque(s->q1,data);	
}

void enque(struct queue *q, int data){
	//printf("in enque\n");
	struct node *temp = makeNode(data);
	//printf("node created\n");
	if (q->rear == NULL){
	    printf("Initiating queue\n");
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
	printf("Node enqued %d\n ",data);
}

int pop(struct stack *s){
	//printf("In pop\n");
	if (s->q1 == NULL && s->q2 == NULL ) {
		printf("stack empty\n");
		return -1;
	}
	int size_q = size(s->q1);
	printf("size is %d\n",size_q);
	int i;
	struct node *temp = s->q1->front;
	//if (s->q1 != NULL)
	for(i=0;i<size_q-1;i++){
		//printf("data in pop %d\n",temp->data);		
		int data = deque(s->q1);
		//printf("data after deque %d\n",data);
		enque(s->q2,data);
		temp = temp->next;
	} 	

	int data = deque(s->q1);
	printf("data is %d\n ",data);
	switchName(&s->q1,&s->q2);
	return data;
	
}
void switchName(struct queue **q1, struct queue **q2){
	struct queue *temp = *q1;
	*q1 = *q2;
	*q2 = temp;	
}

int deque(struct queue *q){
	//printf("In deque\n");
	if (q->front == NULL)return;
	struct node *temp = q->front;
	int data = temp->data;
	//printf("data in deque %d\n", data);
	q->front = q->front->next;
	if (q->front == NULL){
		q->rear == NULL;
	}
	free(temp);
	return data;
}
void printQueue(struct queue *q){
	if (!q){
		return;
	}
	struct node *temp = q->front;
	int i;
	printf("\nPrinting queue");
	while(temp != NULL){
		scanf("%d", &i);
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");

}
int main(){
	struct stack *s = createStack();
	push(s,10);
	printQueue(s->q1);	
	//printQueue(s->q2);	
	push(s,20);
	//printQueue(s->q1);	
	//printQueue(s->q2);	
	push(s,30);
	//printQueue(s->q1);	
	//printQueue(s->q2);	
	push(s,40);
	push(s,12);
	printQueue(s->q1);	
	//printQueue(s->q2);	
	printf("popped %d\n", pop(s));
	printf("popped %d\n", pop(s));
	printf("popped %d\n", pop(s));
	push(s,50);
	//printQueue(s->q1);	
	//printQueue(s->q2);	
	printf("popped %d\n", pop(s));
	//printQueue(s->q1);	
	//printQueue(s->q2);	
	push(s,12);
	//printQueue(s->q1);	
	//printQueue(s->q2);	
	printf("popped %d\n", pop(s));
	//printQueue(s->q1);	
	//printQueue(s->q2);	
	//push(s,70);
	//printQueue(s->q1);	
	//printQueue(s->q2);	
	//printf("popped %d\n", pop(s));
	//printQueue(s->q1);	
	//printQueue(s->q2);	
	return 0;
}	
