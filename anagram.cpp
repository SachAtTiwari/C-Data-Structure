#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int t;
    cin >> t;
    string s;
    for(int i=0;i<t;i++){
        cin >> s;
        if(s.length()%2 != 0){
            cout << "-1" << endl;
        }else{
            int k=s.length()-1,j;
            //cout << "k " << s[k] << endl;
            map <char, int> ma;
            map <char, int> mb;
            ma.insert(std::pair<char, int> (s[0], 1));
            mb.insert(std::pair<char, int> (s[k], 1));
            map <char, int>:: iterator it1 = ma.begin();
            map <char, int>:: iterator it2 = mb.begin();
            for(j=1,k=s.length()-2;j<k;j++,k--){
                //cout << "k " << s[k] << " s[i] " << s[j] << endl;
                it1 = ma.find(s[j]);
                if (it1 != ma.end()){
                    it1->second += 1;
                }else{
                    ma.insert(std::pair<char, int> (s[j], 1));
                }
                it2 = mb.find(s[k]);
                if (it2 != mb.end()){
                    it2->second += 1;
                }else{
                    mb.insert(std::pair<char, int> (s[k], 1));
                }
            }
            map <char, int>:: iterator et1 = ma.begin();
            map <char, int>:: iterator et2 = ma.end();
            map <char, int>:: iterator mt1 = mb.begin();
            int sum = 0;
            while(et1 != et2){
                //cout << " et1->first " << et1->first << " et1->second " << et1->second << endl;
                sum += et1->second;
                et1++;
            }
            map <char, int>:: iterator st1 = mb.begin();
            map <char, int>:: iterator st2 = mb.end();
            map <char, int>:: iterator mt2 = ma.begin();
            int sum1 = 0;
            //cout << endl;
            while (st1 != st2){
                //cout << " st1->first " << st1->first << " st1->second " << st1->second << endl;
                mt2 = ma.find(st1->first);
                if (mt2->second == 0){
                    sum1 += st1->second;
                }
                else if ( mt2->second < st1->second ){
                    sum1 += st1->second - mt2->second;
                }
                st1++;
            }
            //cout << "sum " << sum << " sum1 " << sum1 << endl;
            //int shift = sum - sum1;
            //cout << shift << endl;
            cout << sum1 << endl;
        }
    }

}


