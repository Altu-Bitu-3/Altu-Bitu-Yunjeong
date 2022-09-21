#include<iostream>

using namespace std;

int n;
int ans_min=1e9+1, ans_max=-1e9+1;
int num[12];
int op[4];

void calc(int res, int arr){
    if(arr ==n){
        if(res>ans_max){
            ans_max = res;
        }else if(res<ans_min){
            ans_min = res;
        }
        return;
    }

    for(int i=0;i<4; i++){
        if(op[i]>0){
            continue;
        }
        op[i]--;
        if(i==0) {
            calc(res + num[arr], arr + 1);
        }else if(i==1){
            calc(res - num[arr], arr + 1);
        }else if(i==2){
            calc(res * num[arr], arr + 1);
        }else {
            calc(res / num[arr], arr + 1);
            op[i]++;
        }
    }
}

int main(){
    //입력
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>num[i];
    }
    for(int i=0; i<4; i++){
        cin>>op[i];
    }
    //식 만들어 계산
    calc(num[0], 1);
    //출력
    cout<<ans_max<<'\n'<<ans_min;


    return 0;

}