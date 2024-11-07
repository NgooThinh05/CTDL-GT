class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 1;
        int j = 0;
        int len = 1;
        if (s == "") {
            return 0;
        }
        for (i;i < s.length();i++) {
            for (int k = j;k < i;k++) {
                if (s[k] == s[i]) {
                    if (len < i - j ) {
                        len = i - j;
                    }
                    j = k+1;

                }
            }
        }
        if (i-j > len) {
            len = i - j;
        }
        return len;
    }
};