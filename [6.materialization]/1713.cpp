#include <iostream>

using namespace std;

int rmd[105], tmp[105], cnt;

int main(){
    int n, r;
    cin >> n >> r;
    for (int i = 1; i <= r; ++i){
        int std;
        cin >> std;
        if(rmd[std]>0) rmd[std]++; //추천 받은 경우
        else{
            if(cnt<n) {
                rmd[std]++;
                tmp[std]=i;
                cnt++;
            }
            else{ //비지 않았을 경우
                int org;
                int reco = 1e3+1;
                for (int i = 1; i <= 100; ++i){
                    if(!rmd[i]) continue;
                    if(reco > rmd[i]){
                        org = i;
                        reco = rmd[i];
                    }
                    else if(reco == rmd[i]){
                    //오래된 사진 삭제
                        if(tmp[i] < tmp[org]) org = i;
                    }
                }
                //new 추천
                rmd[std]++;
                tmp[std]=i;
                //
                rmd[org]=0;
                tmp[org]=0;
            }
        }
    }
    for(int i=1;i<=100;++i)
        if(tmp[i]) cout<<i<<' ';

    return 0;
}