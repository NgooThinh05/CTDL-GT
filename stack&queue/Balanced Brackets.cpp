bool isopen(char c){
    return c == '(' || c == '{' || c == '[';
}

bool match(char a, char b){
    return b - a <= 2;
}

string isBalanced(string s) {
    stack<char> st;
    vector <char> oper;
    
    for (auto c : s){
        if (isopen(c)) {
            st.push(c);
        }
        else {
            if (st.empty()) return "NO";
            if (!match(st.top(), c)) return "NO";
            st.pop();
        }
    }
    if (st.empty()) return "YES";
    return "NO";
}