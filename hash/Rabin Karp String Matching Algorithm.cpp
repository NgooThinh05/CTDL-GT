#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int countS(string a, string b) {
    int len = a.length();
    int len2 = b.length();
    int cnt = 0;
    for(int i = 0; i < len2 - len + 1;i++) {
        if (b[i] == a[0]){
            if (a == b.substr(i, len)) {
                cnt++;
            }
        }
        
    }
    return cnt;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        string a;
        string b;
        cin >> a >> b;
        cout << countS(a, b) << endl;
    }
    return 0;
}
