#include <iostream>
#include<vector>
#include<algorithm>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

// Function to check if a string is a C++ keyword
bool isKeyword(const string& word) {
    static unordered_set<string> keywords = {
        "auto", "break", "case", "char", "const", "continue",
        "double", "else", "float", "for", "if", "int",
        "long", "return", "static", "while"
    };
    return keywords.find(word) != keywords.end();
}

// Function to check if a string is a C++ operator
bool isOperator(const string& word) {
    static unordered_set<string> operators = {
        "+", "-", "*", "/", "==", "=", "<", ">", "&", "|", "!", "?", ":", "%", "^"
    };
    return operators.find(word) != operators.end();
}

bool check_identifier(string &w){
    vector<char> a = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    vector<char> b = {';', '(', ')'};

    
    if (find(a.begin(), a.end(), w[0]) != a.end() || find(b.begin(), b.end(), *(w.end()-1)) != b.end())
    {
        return false;
    }

    return true;
    
}

int main() {
    cout << "Enter multiple lines of input. Press Ctrl+D (Unix-like) or Ctrl+Z then Enter (Windows) to finish input:" << endl;

    string line;
    int totalKeywordCount = 0;
    int totalOperatorCount = 0;
    int totalIdentifierCount = 0;
    int totalNewlineCount = 0;

    while (getline(cin, line)) {
        stringstream ss(line);
        string word;
        int keywordCount = 0;
        int operatorCount = 0;
        int identifierCount = 0;

        while (ss >> word) {
            if (isKeyword(word)) {
                keywordCount++;
            } else if (isOperator(word)) {
                operatorCount++;
            }
            else if(check_identifier(word)){
                identifierCount++;
            }
            
        }

        totalKeywordCount += keywordCount;
        totalOperatorCount += operatorCount;
        totalIdentifierCount += identifierCount;
        totalNewlineCount++;
    }

    cout << "Total summary:" << endl;
    cout << "Total Keywords: " << totalKeywordCount << endl;
    cout << "Total Operators: " << totalOperatorCount << endl;
    cout << "Total Identifiers: " << totalIdentifierCount << endl;
    cout << "Total Newlines: " << totalNewlineCount << endl;

    return 0;
}
