#include<iostream>
#include<string>
using namespace std;
// Function to generate all subsets of a string using recursion
void solve(string input, string output){
    // Base case: if the input string is empty, print the output string
    if (input.empty()) {
        cout << output << endl;
        return;
    }
    
    string op1 = output; 
    string op2 = output ;
    op2.push_back(input[0]); // Include the first character of input in output
    input.erase(input.begin()); // Remove the first character from input

    // Recursive calls: one including the first character and one excluding it
    solve(input, op1); // Exclude the first character
    solve(input, op2); // Include the first character
}

int main() {
    string input = "abc";
    string output = "";
    
    cout << "Subsets of the string \"" << input << "\":" << endl;
    solve(input, output);
    
    return 0;
}