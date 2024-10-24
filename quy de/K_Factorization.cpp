#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(str.substr(start)); 
    return tokens;
}

vector<int> kFactorization(int n, vector<int> A) {

    sort(A.begin(), A.end());

    vector<int> ans;

    int i = A.size() - 1;
    while (n != 1 && i >= 0){
        while (n % A[i] == 0){
            ans.push_back(n);
            n = n / A[i];
        }
        i--;
    }

    if (n != 1){
        ans.clear();
        ans.push_back(-1);
        return ans;
    }
    ans.push_back(1);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp); 

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);
    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp); 

    vector<string> A_temp = split(rtrim(A_temp_temp));
    vector<int> A(k);

    for (int i = 0; i < k; i++) {
        A[i] = stoi(A_temp[i]); 
    }

    vector<int> result = kFactorization(n, A);
    if (result.size() == 1 && result[0] == -1) {
        cout << "-1" << endl; 
    } else {
        for (size_t i = 0; i < result.size(); i++) {
            cout << result[i]; 
            if (i != result.size() - 1) {
                cout << " "; 
            }
        }
        cout << endl; 
    }
    
    return 0;
}
