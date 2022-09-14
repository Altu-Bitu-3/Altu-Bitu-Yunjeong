#include <iostream>
#include <stack>

using namespace std;
int n;
stack<int> st;
int F[1000003], cnt[1000003], num[1000003];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num[i];
        F[num[i]]++;
    }
    for(int i=n-1; i>=0; i--){
        int number = num[i];
        int stk = F[number];

        while(!st.empty()){
            int tNum = num[st.top()];
            int tStk = F[tNum];
            if(stk>=tStk)
                st.pop();
            else break;
        }
        cnt[i]=-1;
        if(!st.empty()){
            cnt[i]=num[st.top()];
        }
        st.push(i);
    }

    //출력
    for(int i=0; i<n; i++){
        cout<<cnt[i];
    }
}

