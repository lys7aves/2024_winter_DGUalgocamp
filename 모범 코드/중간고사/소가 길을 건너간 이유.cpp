#include <iostream>
#include <string>

using namespace std;

//bool chk1['Z'+1], chk2['Z'+1];
int s['Z'+1], e['Z'+1];

int main()
{
    int i, j, cnt=0;
    string arr;
    
    cin >> arr;
    for(i=0; i<arr.size(); i++){
        if(s[arr[i]] == 0) s[arr[i]] = i+1;
        else e[arr[i]] = i+1;
    }
    
    for(i='A'; i<='Z'; i++){
        for(j='A'; j<='Z'; j++){
            if(s[i] < s[j] && s[j] < e[i] && e[i] < e[j]) cnt++;
        }
    }
    
    cout << cnt;
}