#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
     int n; cin >> n;
     string s = "";
     stack<string> history;
     vector<char> v;
     for(int i=0 ; i<n ; i++)
     {
         int index; cin >> index;
         if(index == 1)
         {
             string w; cin >> w;
             history.push(s);
             s += w;
             
         }
         if(index == 2)
         {
             int k; cin >> k;
             history.push(s);
             s = s.substr(0, s.length() - k);
         }
         if(index == 3)
         {
             int pos; cin >> pos;
             v.push_back(s[pos - 1]);
         }
         if(index == 4)
        {
            if(!history.empty())
            {
                s = history.top();
                history.pop();
            }
        }
     }
     for(char it : v)
     {
         cout << it << endl;
     }
    return 0;
}
