#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int lonelyinteger(vector <int> a) {
	int size = a.size();
	map <int, int> ma;
	map<int,int>::iterator it = ma.begin();
	ma.insert(std::pair<int,int>(a[0],1));
	for(int i=1;i<size;i++){
		//cout << a[i];
		it = ma.find(a[i]);
		if (it != ma.end()){
			//cout << "h1 ";
			it->second +=1;
		}else{
			//cout << "h2 ";
			ma.insert(std::pair<int,int>(a[i],1));
		}
		
	}	
	map<int,int>::iterator it1 = ma.begin();
	map<int,int>::iterator et1 = ma.end();
	while(it1 != et1){
		//cout << it1->first << " " << it1->second << " ";
		if (it1->second == 1){
			//cout << it1->first << " " << endl;
			return it1->first;
		}
		it1++;
	}
}

int main() {
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a.push_back(_a_item);
    }
    
    res = lonelyinteger(_a);
    cout << res;
    
    return 0;
}
