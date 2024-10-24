#include <bits/stdc++.h>
using namespace std;
bool thuNgang(vector<string>& crossword, string word, int row, int col) {
    if (col + word.size() > 10) return false;
    for (int i = 0; i < word.size(); i++) {
        if (crossword[row][col + i] != '-' && crossword[row][col + i] != word[i]) {
            return false;
        }
    }
    return true;
}
bool thuDoc(vector<string>& crossword, string word, int row, int col) {
    if (row + word.size() > 10) return false;
    for (int i = 0; i < word.size(); i++) {
        if (crossword[row + i][col] != '-' && crossword[row + i][col] != word[i]) {
            return false;
        }
    }
    return true;
}
void datNgang(vector<string>& crossword, string word, int row, int col) {
    for (int i = 0; i < word.size(); i++) {
        crossword[row][col + i] = word[i];
    }
}
void datDoc(vector<string>& crossword, string word, int row, int col) {
    for (int i = 0; i < word.size(); i++) {
        crossword[row + i][col] = word[i];
    }
}
void xoaNgang(vector<string>& crossword, string word, int row, int col) {
    for (int i = 0; i < word.size(); i++) {
        crossword[row][col + i] = '-';
    }
}
void xoaDoc(vector<string>& crossword, string word, int row, int col) {
    for (int i = 0; i < word.size(); i++) {
        crossword[row + i][col] = '-';
    }
}
bool backtracking(vector<string>& crossword, vector<string>& words, int index) {
    if (index == words.size()) return true;
    string word = words[index];
    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            if (thuNgang(crossword, word, row, col)) {
                datNgang(crossword, word, row, col);
                if (backtracking(crossword, words, index + 1)) {
                    return true;
                }
                xoaNgang(crossword, word, row, col);
            }
            if (thuDoc(crossword, word, row, col)) {
                datDoc(crossword, word, row, col);
                if (backtracking(crossword, words, index + 1)) {
                    return true;
                }
                xoaDoc(crossword, word, row, col);
            }
        }
    }
    return false;
}
vector<string> crosswordPuzzle(vector<string> crossword, string words_str) {
    vector<string> words;
    size_t pos = 0;
    while ((pos = words_str.find(';')) != string::npos) {
        words.push_back(words_str.substr(0, pos));
        words_str.erase(0, pos + 1);
    }
    words.push_back(words_str);
    backtracking(crossword, words, 0);
    return crossword;
}

int main() {
    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string s;
        cin >> s;
        crossword[i] = s;
    }

    string words;
    cin >> words;

    vector<string> result = crosswordPuzzle(crossword, words);

    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}