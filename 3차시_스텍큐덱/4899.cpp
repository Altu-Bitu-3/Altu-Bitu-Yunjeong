#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string s;
    int cnt=0;
    int num=1;
    stack<char> st;
    //입력
    while(true){
        cin>>s;
        if(s=="-") break;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='}' && st.top()=='{' && !st.empty()) st.pop();
            else st.push(s[i]);
        }
        while(!st.empty()){
            char c = st.top();
            st.pop();
            if(c!=st.top()) cnt+=2;
            else cnt+=1;

        }


        //출력
        cout<<num++<<"."<<cnt<<'\n';
    }
}