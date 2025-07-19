#include<iostream>
#include<vector>
using namespace std;

void solve(string str, string output, int index, vector<string> &result) {
    // Base case
    if(index>=str.length()) {
        result.push_back(output);
        return;
    }
    //exclude
    solve(str, output, index + 1, result);

    //include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index + 1, result);
}

int main(){
    string str;
    cout << "Enter a string: ";
    cin >> str;

    vector<string> result;
    solve(str, "", 0, result);

    cout << "Subsequences are: " << endl;
    for(const string &s : result) {
        cout << s << endl;
    }

    return 0;
}