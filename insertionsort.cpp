#include<iostream>
#include<stdio.h>

using namespace std;
void insertSort(int a[],int s);

int main(){
	int a[6] = {8,4,3,9,2,1};
	int s = 6;
	insertSort(a,s);
  	printf("After sorting: ");
  	for(int i=0;i<s;i++)
      	printf(" %d",a[i]);
	return 0;
}

void insertSort(int a[],int s){
	for(int i=1;i<s;i++){
      		int temp=a[i];
      		int j=i-1;
      		while((temp<a[j])&&(j>=0)){
    			a[j+1]=a[j];
          		j=j-1;
      		}
      		a[j+1]=temp;
  	}

}
