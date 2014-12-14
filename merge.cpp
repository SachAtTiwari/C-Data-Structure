#include<iostream>
#include<stdio.h>


using namespace std;
void mergesort(int a[],int size);
void merge(int a[],int left[],int nl,int right[],int nr);
void print(int a[],int size);

int main(){
	int a[6] = {8,4,1,3,6,7};
	int size = sizeof(a)/sizeof(a[0]);
	cout << "Before sorting: ";
	print(a,size);
	mergesort(a,size);
	cout << "After sorting: ";
	print(a,size);
}

void print(int a[],int size){
	for(int i=0;i<6;i++){
		cout << " " << a[i];	
	}
	cout << endl ;
}
void mergesort(int a[],int size){
	if (size<2) return;
	int mid = size/2;

	int left[mid];
	int right[size-mid];
	for(int i=0;i<mid;i++){
		left[i] = a[i];	
	}
	for(int i=mid;i<size;i++){
		right[i-mid] = a[i];
	}
	mergesort(left,mid);
	mergesort(right,size-mid);
	merge(a,left,mid,right,size-mid);
}

void merge(int a[],int left[],int nl,int right[],int nr){
	int i=0,j=0,k=0;
	while(i<nl && j<nr){
		if (left[i] < right[j]){
			a[k++] = left[i++];
		}
		else{
			a[k++] = right[j++];
		}
		//k++;
	}
	while(i<nl){
		a[k] = left[i];
		k++;
		i++;
	}
	while(j<nr){
		a[k] = right[j];
		k++;
		j++;
	}
}

