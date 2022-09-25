#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


int main(){
    int n;
    string l;
    stack <char> st, tmp;

    //입력
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>l;
        for(int i=0; i<l.length(); i++){
            if (l[i] == '>') { //<이 입력
                if (!tmp.empty()) {
                    st.push(tmp.top());
                    tmp.pop();
                }
            } else if (l[i] == '<') { //> 입력 시
                if (!st.empty()) {
                    tmp.push(st.top());
                    st.pop();
                }
            } else if (l[i] == '-') { //-백스페이스 입력 시
                if (!st.empty()) st.pop();
            } else st.push(l[i]); //문자 입력시 그대로 push
        }
        while(!tmp.empty()){
            st.push(tmp.top());
            tmp.pop();
        }
        string ans; //ans에 꺼내 넣기
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        //출력
        reverse(ans.begin(), ans.end()); //반대로 들어갔으므로 reverse 해주기~
        cout<<ans<<'\n'; //출력
        }

    return 0;
}