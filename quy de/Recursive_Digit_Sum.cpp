#include <bits/stdc++.h>

using namespace std;

int superDigit(string n, int k) {
    if (n.length() < 2 ) return stoi(n);
    long total = 0;
    for (auto c:n ){
        total += c -'0';
    }
    total *= k;
    return superDigit(to_string(total), 1);
}



int main(){
	string s;
	int k;
	cin >> s >> k;
	cout << superDigit(s, k);
}