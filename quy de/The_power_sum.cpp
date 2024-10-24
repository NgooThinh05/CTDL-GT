#include <iostream>
#include <cmath>

using namespace std;

int tongluythua(int x,int n, int m){
    if(x < 0) return 0;
    if(x == 0) return 1;
    int ans = 0;
    for(int i = m +1; i <= pow(x,(double) 1/n)+1;i++)
    ans += tongluythua(x - pow(i, n),n, i);
    return ans;
}

int main(){
    int x;
    int n = 2;
    cin >> x ;
    cout << tongluythua(x, n, 0);
}