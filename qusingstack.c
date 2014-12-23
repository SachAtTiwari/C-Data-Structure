#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *next;
};
	
struct queue{
	struct stack *s1;
	struct stack *s2;
};

void push(struct stack **s, int data);
struct stack *makeNode(int data){
	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	s->data = data;
	s->next = NULL;
	return s;
}

struct queue *createQ(){
	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->s1 = q->s2 = NULL;
	return q;
}

void enque(struct queue *q, int data){
	push(&(q->s1),data);
}
 
int deque(struct queue *q){
	int data;
	if (q->s1 == NULL && q->s2 == NULL){
		return;
	}
	if (q->s2 == NULL){
		while(q->s1 != NULL){
			 push(&q->s2,pop(&q->s1));
		}	
	}
	data = pop(&q->s2);
	return data;
}

void push(struct stack **s, int data){
	struct stack *node = (struct stack*)malloc(sizeof(struct stack));
	if (node == NULL){printf("Meemory Error");}
	node->data = data;
	node->next = NULL;
	*s = node;
}

int pop(struct stack **s){
	if (*s == NULL){
		return;
	}
	struct stack *temp = *s;
	int data = temp->data;
	*s = temp->next;
	free(temp);
	return data;
}
int main(){
	struct queue *q = createQ();
	enque(q,10);
	enque(q,20);
	enque(q,30);
	enque(q,40);
	printf("deque %d\n", deque(q));
	return 0;
}
