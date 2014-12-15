//#include<iostream>
#include<stdio.h>

//using namespace std;
void heapSort(int arr[], int size);
void heapify(int arr[], int i, int size);
void swap(int *a,int *b);
void printArray(int a[], int n);

int main(){
	int arr[6] = {5,8,7,1,4,5};
	int size;
	size = sizeof(arr)/sizeof(arr[0]);
	int i;
	printArray(arr, size);	
	heapSort(arr, size);
	printArray(arr, size);	
	return 0;
}

void heapSort(int arr[], int size){
	int i;
 	//printf("\nsize %d\n",size);
	for(i=(size-1)/2;i>=0;i--){
 	        //printf("calling heapify\n");
		heapify(arr,i,size);
	}
	printArray(arr, size);	
	for(i=size-1;i>=0;i--){
 		//printf("in side sorting\n");
		printArray(arr, size);
		printf("swapping index %d\n", i);
		swap(&arr[0], &arr[i]);
		int customSize = i;
		printArray(arr, size);
		heapify(arr, 0, customSize);
	}

}	

void heapify(int arr[], int i, int size){
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	printf("Function begin largest , i , size %d  %d %d \n",largest, i ,size);
	if (l <= size-1 && arr[l] > arr[i]){
		largest = l;		
	}
	else{
		largest = i;
	}
	if (r <= size-1 && arr[r] > arr[largest])	{
		largest = r;
	}
	printf("largest , i , size %d  %d %d \n",largest, i ,size);
	if ( largest != i){
		printf("Inside if....\n");
		swap(&arr[i],&arr[largest]);
		heapify(arr,largest, size);
	}
}
void printArray(int a[], int size)
{
	int i;
	printf("\nArray is: ");
	for(i=0;i<size;i++){
		//cout << arr[i] << " " << endl;
		printf(" %d",a[i]);
	}
	printf("\n");
}
int left(int i) { return 2*i + 1;}
int right(int i) { return 2*i + 2;}
void  swap(int *a,int *b) 
{int temp = *a;*a=*b ; *b=temp;}
