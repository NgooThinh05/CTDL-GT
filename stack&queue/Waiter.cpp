#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */

vector <int> nto(int q) {
    vector <int> nt;
    nt.push_back(2);
    for (int i = 3;;i++) {
        bool check = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if(i % j == 0) {
                check = false;
                break;
            }
        }
        if (check == true) {
            nt.push_back(i);
            q--;
        }
        if(q == 0){
            break;
        }
    }
    return nt;
}

vector<int> waiter(vector<int> number, int q) {
    vector <int> nt = nto(q);
    vector <int> ans;
    stack <int> temp;
    for(int i = 0;i < q;i++) {
        for ( int j = 0; j < number.size() ; j++) {
            if (number[j] % nt[i] == 0){
                ans.push_back(number[j]);
                number.erase(number.begin() + j);
                j--;
            }
            else {
                temp.push(number[j]);
            }
        }
        for (int i = 0;i < number.size() ; i++){
            number[i] = temp.top();
            temp.pop();
        }
    }
    for (int i = number.size() - 1; i >= 0;i--) {
        ans.push_back(number[i]);
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

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
