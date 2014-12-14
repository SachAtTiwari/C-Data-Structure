#include<stdio.h>
#include<stdlib.h>

struct stack{
	int data;
	struct stack *next;
};

struct advStack {
	struct stack *dataStack;
	struct stack *minStack;
};

void pushStack(struct stack **s, int data);

struct advStack *createStack(){
	struct advStack *s = (struct advStack*)malloc(sizeof(struct advStack));
	s->dataStack = s->minStack = NULL;
	return s;
}

void push(struct advStack *s, int data){
	pushStack(&s->dataStack,data);
	printf("Data pushed in data stack %d \n",data);
	if (s->minStack == NULL || peek(s->minStack) >= data){
	    printf("Data pushed in min stack %d \n",data);
		pushStack(&s->minStack,data);
	}
}

void pushStack(struct stack **s, int data){
	struct stack *temp = (struct stack*)malloc(sizeof(struct stack));
	temp->data = data;
	temp->next = *s;
	*s = temp;
}

int popStack(struct stack **s){
	if (*s == NULL){
		return;
	}		
	struct stack *temp = *s;
	int data = temp->data;
	*s = temp->next;
	free(temp);
	return data;
}

int pop(struct advStack *s){
	if (s == NULL){
		return;
	}
	int data = peek(s->dataStack);
	printf("Data popped from data stack %d \n",data);
	if (popStack(&s->dataStack) == peek(s->minStack)){
	    printf("Data popped from data stack %d \n",data);
		popStack(&s->minStack);
	}
	return data;
}

int peek(struct stack *s){
	return s->data;
}

int getMinimum(struct advStack *s){
	if (s->minStack == NULL)return;
	return s->minStack->data;
}

int main(){
	struct advStack *s = createStack();
	push(s,10);
	push(s,20);
	push(s,15);
	push(s,5);
	push(s,1);
	printf("minimun %d \n",getMinimum(s));
	pop(s);
	printf("minimun %d \n",getMinimum(s));
	return 0;
}
