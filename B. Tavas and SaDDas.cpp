#include <bits/stdc++.h>
using namespace std;


vector<int> lucky;
bool checkBit(int val, int pos){ return val&(1<<pos); }

void createLucky(int n){
    for(int i = 0; i < (1<<n); i++){
        int t = 1, val = 0;
        for(int j = 0; j < n; j++){
            if(checkBit(i, j)) val += 7*t;
            else val += 4*t;
            t *= 10;
        }
        lucky.push_back(val);
    }
}

int main(){
    int n;
    for(int i = 1; i <= 9; i++)createLucky(i);
    cin>>n;
    int pos = lower_bound(lucky.begin(), lucky.end(), n) - lucky.begin();

    cout<<(pos+1)<<'\n';
}
