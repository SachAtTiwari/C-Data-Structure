#include <iostream>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;
	string s;
	for(int i=0;i<t;i++){
		cin >> s;
		map<char, int> ma;
		map<char, int> mb;
		int j,k;
		int shift = 0;
		if (s.length()%2 != 0){
			cout << "-1" << endl;
		}else{
			for(j=0,k=s.length()-1;j<k;j++,k--){
				ma.insert(std::pair<char, int>());			
			}
		}
	}	
}
