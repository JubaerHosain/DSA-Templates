#include<iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    cout << "Argument count " << argc << endl;
    for(int i = 0; i < argc; i++) 
        cout << "Argument " << i+1 << " is: " <<  argv[i] << endl;
}
