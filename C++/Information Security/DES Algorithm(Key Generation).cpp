#include<bits/stdc++.h>
using namespace std;
#define endl    '\n'
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;

/*****Key Generation Part*****/
string round_keys[16];

// Function to do a circular left shift by 1
string shift_left_once(string key_chunk){ 
    string shifted = "";  
    for(int i = 1; i < 28; i++){ 
        shifted += key_chunk[i]; 
    } 
    shifted += key_chunk[0];   
    return shifted; 
} 

// Function to do a circular left shift by 2
string shift_left_twice(string key_chunk){ 
    string shifted = ""; 
    for(int j = 2; j < 28; j++){ 
        shifted += key_chunk[j]; 
    } 
    shifted += key_chunk[0];
    shifted += key_chunk[1];
    key_chunk = shifted; 
    return key_chunk; 
}
 
void generate_keys(string key) {
    // The PC1 table 
    // every 8 th character is not present here
	int pc1[56] = {
        57,49,41,33,25,17,9, 
        1,58,50,42,34,26,18, 
        10,2,59,51,43,35,27, 
        19,11,3,60,52,44,36,		 
        63,55,47,39,31,23,15, 
        7,62,54,46,38,30,22, 
        14,6,61,53,45,37,29, 
        21,13,5,28,20,12,4 
	};

    // The PC2 table
	int pc2[48] = { 
        14,17,11,24,1,5, 
        3,28,15,6,21,10, 
        23,19,12,4,26,8, 
        16,7,27,20,13,2, 
        41,52,31,37,47,55, 
        30,40,51,45,33,48, 
        44,49,39,56,34,53, 
        46,42,50,36,29,32 
	};

    // 1. Compressing the key using the PC1 table
    // pc1[i]-1 is used bcz of 0 indexing key
	string perm_key =""; 
	for(int i = 0; i < 56; i++){ 
		perm_key+= key[pc1[i]-1]; 
	} 

    // 2. Dividing the result into two equal halves
	string left = perm_key.substr(0, 28); 
	string right = perm_key.substr(28, 28); 

    // Generating 16 keys
	for(int i = 0; i < 16; i++){ 
		// 3.1. For rounds 1, 2, 9, 16 the key_chunks are shifted by one.
		if(i == 0 || i == 1 || i==8 || i==15 ){
			left = shift_left_once(left); 
			right = shift_left_once(right);
		} 
		// 3.2. For other rounds, the key_chunks are shifted by two
		else{
			left = shift_left_twice(left); 
			right = shift_left_twice(right);
		}
        // 4. The chunks are combined
        string combined_key = left + right;
        // 5. Finally, the PC2 table is used to transpose the key bits
        // Each round key is 48 bit key, pc2[i]-1 is used for 0 indexing
        string round_key = ""; 
        for(int i = 0; i < 48; i++){ 
            round_key += combined_key[pc2[i]-1]; 
        }   
        round_keys[i] = round_key;
	} 
}

/*****main function*****/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    cout << fixed << showpoint;
    cout << setprecision(16);
 
    // 64 bit key, where 56 bit wiil be used and finally 48 bit
    string key = "1010101010111011000010010001100000100111001101101100110011011101";

    generate_keys(key);

    for(int i = 0; i < 16; i++)
        cout << round_keys[i] << endl;
 
    return 0;
} 
