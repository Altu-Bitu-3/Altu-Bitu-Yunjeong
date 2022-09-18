#include <iostream>
#include <algorithm>

using namespace std;

int alphabet[27];

int main(){
    string s;
    int middleNum=-1;
    int odd=0;

    //입력
    cin>>s;
    for(int i=0; i<s.size(); i++){
        alphabet[s[i]-'A']++;
    }
    for(int i=0; i<26; i++){
        if(alphabet[i]>0){
            if (alphabet[i] % 2 == 1){
                middleNum = i;
                alphabet[i]--;
                odd++;
            }
        }
    }
    if(odd>1){
        cout<<"I'm Sorry Hansoo"<<'\n';
    }else{
        string a="";
        string tmp ="";
        for(int i=0; i<26; i++){
            if (alphabet[i]>0) {
                for(int j=0; j<alphabet[i]/2;j++) {
                    a+=i+'A';
                }
            }
        }
        tmp = a;
        reverse(tmp.begin(), tmp.end());
        if(middleNum!=-1){
            a+=middleNum+'A';
        }
        a+=tmp;
        cout<<a<<'\n';
    }

    return 0;
}