#include <bits/stdc++.h>

using namespace std;

int longestSubstring(string s, int k) {
    int len = s.length();
    int cnt = 0;
    for (int j = 0; j < len;j++) {
        unordered_map<char, int> mp;
        for (int i = j; i < len;i++) {
            mp[s[i]]++;
            bool check = 0;
            for (auto x : mp) {
                if (x.second < k) {
                    check = 1;
                    break;
                }
            }
            if (check == 0) {
                cnt = max(cnt, i - j + 1);
            }
        }
    }
    return cnt;
}

int main() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	cout << longestSubstring(s, k);
}