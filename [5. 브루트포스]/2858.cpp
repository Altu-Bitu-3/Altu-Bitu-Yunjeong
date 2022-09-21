#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int R, B, L, W;
    //입력
    cin>>R>>B;

    for(int i=3;i<5000;i++){
        for(int j=3; j<5000; j++){
            if(R==(2*(i+j)-4) && i*j==(R+B)){
                cout<<max(i,j)<<' '<<min(i,j)<<endl;return 0;
            }
        }
    }



}