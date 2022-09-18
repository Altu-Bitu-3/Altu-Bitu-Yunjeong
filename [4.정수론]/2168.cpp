#include <iostream>

using namespace std;

int gcdRecursion(int x, int y){
    if(y==0){
        return x;
    }
    return gcdRecursion(y, x%y);

}
int main(){
    long long int x,y;
    long long int diagonal;

    cin>>x>>y;
    diagonal=gcdRecursion(x,y);
    cout<<x+y-diagonal;

}