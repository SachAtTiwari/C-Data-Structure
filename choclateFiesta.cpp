#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


void findSet(vector <int> a){
    int size = a.size();
    //cout << "size " << size << endl;
    vector <int> even;
    vector <int> odd;
    for(int i=0;i<size;i++){
        if (a[i]%2 == 0){
            even.push_back(a[i]);
        }else{
            odd.push_back(a[i]);
        }
    }
    int evenSize = even.size();
    int oddSize = odd.size();
    int setSizeInEven = pow(2, evenSize) -1;
	cout << setSizeInEven << endl;
	int setSizeInOdd = 0;
	if (oddSize%2 == 0){
    	setSizeInOdd = pow(2, oddSize-1) -1;
	}else{
    	setSizeInOdd = pow(2, oddSize-1) -2;
	}
	cout << setSizeInOdd << endl;
	int res = 0;
	if (setSizeInOdd == -1){	
    	res = setSizeInEven;
	}else{
    	res = setSizeInEven + setSizeInOdd;
		
	}
    res = res%1000000007;
    cout << res << endl;
}

int main(){
    int t;
    cin >> t;
    int a[t+1];
    vector <int> vec;
    for(int i=0;i<t;i++){
        cin >> a[i];
        vec.push_back(a[i]);

    }
    findSet(vec);
}

