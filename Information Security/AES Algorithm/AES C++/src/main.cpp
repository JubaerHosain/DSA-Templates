#include "helper_functions.h"

/*****helper functions*****/
void print_2d(vector<vector<uchar>> &messages, int size) {
	for(int i = 0; i < messages.size(); i++) {
		for(int j = 0; j < messages[i].size(); j++) {
			if(size < 1)
				break;
			else 
				cout << messages[i][j];
			size--;
		}
	}
	cout << endl;
}

vector<vector<uchar>> adjust_message(string &message) {
	int orginal_length = message.length();
	int padded_length = orginal_length;

	// make multiple of 16 character if not 
	// bcz every time we send 128 bit or 16 character
	if(padded_length%16 != 0) 
		padded_length = (padded_length/16 + 1) * 16;

	int pos = 0;
	vector<vector<uchar>> message_blocks(padded_length/16);
	for(int i = 0; i < message_blocks.size(); i++) {
		vector<uchar> current;
		for(int j = 0; j < 16; j++) {
			if(pos >= orginal_length)
				current.push_back('0');
			else 
				current.push_back(message[pos++]);
		}
		message_blocks[i] = current;
	}
	
	return message_blocks;
}

vector<vector<uchar>> aes_encryption(vector<vector<uchar>> &message_blocks, vector<vector<uchar>> &expanded_keys) {
	int total_block = message_blocks.size();
	vector<vector<uchar>> encrypted_blocks(total_block);

	// aes_encrypt defined in custom header
	for(int i = 0; i < total_block; i++) 
		encrypted_blocks[i] = aes_encrypt(message_blocks[i], expanded_keys);

	
	return encrypted_blocks;
}

vector<vector<uchar>> aes_decryption(vector<vector<uchar>> &encrypted_blocks, vector<vector<uchar>> &expanded_keys) {
	int total_block = encrypted_blocks.size();
	vector<vector<uchar>> decrypted_blocks(total_block);

	for(int i = 0; i < total_block; i++) 
		decrypted_blocks[i] = aes_decrypt(encrypted_blocks[i], expanded_keys);

	return decrypted_blocks;
}


/*****main function*****/
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
 
    // read input message
	string input_message;
	cin >> input_message;

	// condition inside assert should be true 
	assert(input_message.size() != 0);
    
	// read 128 bit/16 character key
	string key;
	cin >> key;

	cout << "Input Message: " << endl;
	cout  << input_message << endl;
	cout << "Input Key: " << endl;
	cout << key << endl;

	// condition inside assert should be true
	assert(key.size() == 16);

	// adjust message with multiple of 16 byte or character
	vector<vector<uchar>> message_blocks = adjust_message(input_message);

	
	// key_expansion function is declared in helper_functions header
	vector<vector<uchar>> expanded_keys = key_expansion(key);

	

	vector<vector<uchar>> encrypted_blocks = aes_encryption(message_blocks, expanded_keys);
	vector<vector<uchar>> decrypted_blocks = aes_decryption(encrypted_blocks, expanded_keys);

	cout << "Encrypted Message: ";
	print_2d(encrypted_blocks, input_message.length());

	cout << "Decrypted Message: ";
	print_2d(decrypted_blocks, input_message.length());

	
    return 0;
}