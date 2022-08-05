#include <iostream>
using namespace std;

void printPermutations(string str, string asf){
    // write your code here
    if(str.length() == 0)
        cout << asf << endl;
    for(int i = 0; i < str.length(); i++) {
        string left = str.substr(0, i);
        string right = str.substr(i+1);
        printPermutations(left+right, asf + str[i]);
    }
}

int main(){
    string str;
    cin >> str;
    printPermutations(str, "");
}