#include<stdio.h>
#include<stdlib.h>

struct stack {
	int *arr;
	int top;
	int size;
};

struct stack * createStack(int cap){
	struct stack *s = (struct stack*)malloc(cap*sizeof(struct stack));
	s->arr = (int*)malloc(sizeof(int));
	s->top = -1;
	s->size = cap;
	return s;
}
int isFull(struct stack *s){
	return s->top == s->size;
}

int isEmpty(struct stack *s){
	return s->top == -1;
}
void push(struct stack *s,int data){
	if (isFull(s)){
		return;
	}
	s->arr[++s->top] = data;
	printf(" Pushed %d ",data);
}
int pop(struct stack *s){
	if (isEmpty(s)){
		return;	
	}
	int data = s->arr[s->top--];
	return data;
}
int peek(struct stack *s){
	if (isEmpty(s)){
		return;
	}
	return s->arr[s->top];
}

int main(){
	struct stack *s = createStack(10);
	push(s,10);
	push(s,20);
	push(s,30);
	push(s,40);
	printf("\n After pop %d\n",pop(s));
	printf("\n Peek element %d\n",peek(s));
	return  0;
}
