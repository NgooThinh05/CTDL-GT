#include <bits/stdc++.h>

using namespace std;

unordered_map<long, long> save;

long solve (long size, vector<long>& s)
{
    if (save.count(size)) return save[size];
   
    long res = 0;
    for (long div : s)
    {
        if (size % div == 0 && size != div)
        {
            long temp = 1 + (size / div) * solve(div, s);
            res = max(res, temp);
        }
    }
    if (res>0) save[size] = res;
    return res;
}
long stoneDivision(long n, vector<long> s) {
    sort(s.begin(), s.end(), greater<long>());
    save.clear();
    return solve(n, s);
}

int main(){
		int q,n,m;
		cin >> q >> n >>m;		
        vector<long> s(m);

        for (int i = 0; i < m; i++) {
            cin >> s[i];
        }

        long result = stoneDivision(n, s);

        cout << result << "\n";

    	return 0;
}