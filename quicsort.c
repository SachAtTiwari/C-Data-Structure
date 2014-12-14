#include<stdio.h>

int partition(int a[], int start, int end);
void quicksort(int a[],int start,int end);
void swap(int *a,int *b);
void printArray(int a[]);
int randomizedPartition(int a[],int start,int end);


int randomizedPartition(int a[],int start,int end){
	int pIndex = rand()%end+start;
	swap(&a[pIndex],&a[end]);
	partition(a,start,end);
	return pIndex;
}

int partition(int a[], int start, int end){
	
	int pivot = a[end];
	int pIndex = start;
	printf("In partition %d %d\n",a[end], pIndex);
	int i;
	for(i=start;i<end;i++){
		if(a[i] <= pivot){
			printf("In if swapping\n");
			swap(&a[i],&a[pIndex]);
			pIndex++;
		}
	}
	swap(&a[pIndex],&a[end]);
	return pIndex;
}

void quicksort(int a[],int start,int end){
	if (start < end){
		printf("in quicksort %d %d\n",start,end);
		//int pIndex = partition(a,start,end);
		int pIndex = randomizedPartition(a,start,end);
		quicksort(a,start,pIndex-1);
		quicksort(a,pIndex+1,end);
	}
}

void swap(int *a,int *b){
	int temp = *a;	
	*a = *b;
	*b = temp;
}
void printArray(int a[]){
	int i;
	for(i=0;i<7;i++){
		printf("%d ", a[i]);	
	}
	printf("\n");
}
int main(){
	int a[7] = {8,2,1,9,3,10,6};
	printArray(a);
	quicksort(a,0,6);
	printf("After sorting\n");
	printArray(a);
	return 0;
}
