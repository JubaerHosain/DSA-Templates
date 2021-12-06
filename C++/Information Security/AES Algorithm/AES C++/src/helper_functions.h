#include "main_header.h"


/***************Key Expansion***************/
void calculate_core(vector<uchar> &temp, int rcon_no) { 
	// Rotate left by one byte: shift left 
	temp.push_back(temp[0]);
	temp.erase(temp.begin());

	for(int i = 0; i < 4; i++)
		temp[i] = s_box[temp[i]];

	temp[0] ^= rcon[rcon_no];
}

/* The main KeyExpansion function Generates additional keys using
the original keyTotal of 11 128-bit keys generated, including the
original Keys are stored one after the other in expandedKeys */
vector<vector<uchar>> key_expansion(string &key) {
	vector<unsigned char> expanded_key(176);
	// first 16 byte or 126 bit is original key
	for(int i = 0; i < 16; i++)
		expanded_key[i] = key[i];

	int byte_no = 16; 						// Bytes we've generated so far
	int rcon_no = 1; 						// Keeps track of rcon value
	vector<uchar> temp_core(4); 	// Temp storage for core

	while(byte_no < 176) {
		// Read 4 bytes for the core, They are the previously generated 4 bytes
		// Initially, these will be the final 4 bytes of the original key
		for(int i = 0; i < 4; i++)
			temp_core[i] = expanded_key[i + byte_no-4];

		// Perform the core(g(w3)) once for each 16 byte key
		if(byte_no%16 == 0)
			calculate_core(temp_core, rcon_no++);

		for(int i = 0; i < 4; i++) {
			expanded_key[byte_no] = expanded_key[byte_no-16] ^ temp_core[i];
			byte_no++;
		}
	}

	int pos = 0;
	vector<vector<uchar>> expanded_keys(11);
	for(int i = 0; i < 11; i += 1) {
		for(int j = 0; j < 16; j++)
			expanded_keys[i].push_back(expanded_key[pos++]);
	}

	return expanded_keys;
}









/***************AES Encryption***************/

/* Serves as the initial round during encryption
AddRoundKey is simply an XOR of a 128-bit block with the 128-bit key.*/
void add_round_key(vector<uchar> &message, vector<uchar> &key) {
	for (int i = 0; i < 16; i++) {
		message[i] ^= key[i];
	}
}

// Perform substitution to each of the 16 bytes Uses S-box as lookup table 
void encryption_sub_bytes(vector<uchar> &message) {
	for (int i = 0; i < 16; i++) 
		message[i] = s_box[message[i]];
}

// Shift left, Adds diffusion
void encryption_shift_rows(vector<uchar> &message) {
	vector<uchar> temp(16);
	/* Column 1 */
	temp[0] = message[0];
	temp[1] = message[5];
	temp[2] = message[10];
	temp[3] = message[15];

	/* Column 2 */
	temp[4] = message[4];
	temp[5] = message[9];
	temp[6] = message[14];
	temp[7] = message[3];

	/* Column 3 */
	temp[8] = message[8];
	temp[9] = message[13];
	temp[10] = message[2];
	temp[11] = message[7];
	
	/* Column 4 */
	temp[12] = message[12];
	temp[13] = message[1];
	temp[14] = message[6];
	temp[15] = message[11];

	// copy temp to message 
	for (int i = 0; i < 16; i++) {
		message[i] = temp[i];
	}
}

 /* MixColumns uses mul2, mul3 look-up tables Source of diffusion*/
void encryption_mix_columns(vector<uchar> &message) {
	uchar temp[16];

	temp[0] = (unsigned char) mul2[message[0]] ^ mul3[message[1]] ^ message[2] ^ message[3];
	temp[1] = (unsigned char) message[0] ^ mul2[message[1]] ^ mul3[message[2]] ^ message[3];
	temp[2] = (unsigned char) message[0] ^ message[1] ^ mul2[message[2]] ^ mul3[message[3]];
	temp[3] = (unsigned char) mul3[message[0]] ^ message[1] ^ message[2] ^ mul2[message[3]];

	temp[4] = (unsigned char)mul2[message[4]] ^ mul3[message[5]] ^ message[6] ^ message[7];
	temp[5] = (unsigned char)message[4] ^ mul2[message[5]] ^ mul3[message[6]] ^ message[7];
	temp[6] = (unsigned char)message[4] ^ message[5] ^ mul2[message[6]] ^ mul3[message[7]];
	temp[7] = (unsigned char)mul3[message[4]] ^ message[5] ^ message[6] ^ mul2[message[7]];

	temp[8] = (unsigned char)mul2[message[8]] ^ mul3[message[9]] ^ message[10] ^ message[11];
	temp[9] = (unsigned char)message[8] ^ mul2[message[9]] ^ mul3[message[10]] ^ message[11];
	temp[10] = (unsigned char)message[8] ^ message[9] ^ mul2[message[10]] ^ mul3[message[11]];
	temp[11] = (unsigned char)mul3[message[8]] ^ message[9] ^ message[10] ^ mul2[message[11]];

	temp[12] = (unsigned char)mul2[message[12]] ^ mul3[message[13]] ^ message[14] ^ message[15];
	temp[13] = (unsigned char)message[12] ^ mul2[message[13]] ^ mul3[message[14]] ^ message[15];
	temp[14] = (unsigned char)message[12] ^ message[13] ^ mul2[message[14]] ^ mul3[message[15]];
	temp[15] = (unsigned char)mul3[message[12]] ^ message[13] ^ message[14] ^ mul2[message[15]];

	for (int i = 0; i < 16; i++) {
		message[i] = temp[i];
	}
}

/* Each round operates on 128 bits at a time The number of rounds is defined in aes_ncrypt()*/
vector<uchar> encryption_round(vector<uchar> &curr_message, vector<uchar> &curr_key) {
	encryption_sub_bytes(curr_message);
	encryption_shift_rows(curr_message);
	encryption_mix_columns(curr_message);
	add_round_key(curr_message, curr_key);
}

 // Same as round() except it doesn't mix columns
vector<uchar> final_round(vector<uchar> &curr_message, vector<uchar> &curr_key) {
	encryption_sub_bytes(curr_message);
	encryption_shift_rows(curr_message);
	add_round_key(curr_message, curr_key);
}

vector<uchar> aes_encrypt(vector<uchar> message, vector<vector<uchar>> &expanded_keys) {
	// initial round with actual key
	// that is first 16 byte
	add_round_key(message, expanded_keys[0]); 

	for (int i = 1; i <= 9; i++) {
		encryption_round(message, expanded_keys[i]);
	}

	// 11 th key 
	final_round(message, expanded_keys[10]);

	// return encrypted message
	return message;
}








/***************AES Decryption***************/

/* Used in Round() and serves as the final round during decryption SubRoundKey  is simply an XOR 
of a 128-bit block with the 128-bit key. So basically does the same as AddRoundKey in the encryption*/
void sub_round_key(vector<uchar> &message, vector<uchar> &key) {
	for (int i = 0; i < 16; i++) {
		message[i] ^= key[i];
	}
}

// Shifts rows right (rather than left) for decryption
void decryption_shift_rows(vector<uchar> &message) {
	vector<uchar> temp(16);

	/* Column 1 */
	temp[0] = message[0];
	temp[1] = message[13];
	temp[2] = message[10];
	temp[3] = message[7];

	/* Column 2 */
	temp[4] = message[4];
	temp[5] = message[1];
	temp[6] = message[14];
	temp[7] = message[11];

	/* Column 3 */
	temp[8] = message[8];
	temp[9] = message[5];
	temp[10] = message[2];
	temp[11] = message[15];

	/* Column 4 */
	temp[12] = message[12];
	temp[13] = message[9];
	temp[14] = message[6];
	temp[15] = message[3];

	for (int i = 0; i < 16; i++) {
		message[i] = temp[i];
	}
}

/* Perform substitution to each of the 16 bytes Uses inverse S-box as lookup table*/
void decryption_sub_bytes(vector<uchar> &message) {
	for (int i = 0; i < 16; i++) { 
		message[i] = inv_s[message[i]];
	}
}

/* InverseMixColumns uses mul9, mul11, mul13, mul14 look-up tables
 * Unmixes the columns by reversing the effect of MixColumns in encryption
 */
void inverse_mix_columns(vector<uchar> &message) {
	vector<uchar> temp(16);

	temp[0] = (uchar)mul14[message[0]] ^ mul11[message[1]] ^ mul13[message[2]] ^ mul9[message[3]];
	temp[1] = (uchar)mul9[message[0]] ^ mul14[message[1]] ^ mul11[message[2]] ^ mul13[message[3]];
	temp[2] = (uchar)mul13[message[0]] ^ mul9[message[1]] ^ mul14[message[2]] ^ mul11[message[3]];
	temp[3] = (uchar)mul11[message[0]] ^ mul13[message[1]] ^ mul9[message[2]] ^ mul14[message[3]];

	temp[4] = (uchar)mul14[message[4]] ^ mul11[message[5]] ^ mul13[message[6]] ^ mul9[message[7]];
	temp[5] = (uchar)mul9[message[4]] ^ mul14[message[5]] ^ mul11[message[6]] ^ mul13[message[7]];
	temp[6] = (uchar)mul13[message[4]] ^ mul9[message[5]] ^ mul14[message[6]] ^ mul11[message[7]];
	temp[7] = (uchar)mul11[message[4]] ^ mul13[message[5]] ^ mul9[message[6]] ^ mul14[message[7]];

	temp[8] = (uchar)mul14[message[8]] ^ mul11[message[9]] ^ mul13[message[10]] ^ mul9[message[11]];
	temp[9] = (uchar)mul9[message[8]] ^ mul14[message[9]] ^ mul11[message[10]] ^ mul13[message[11]];
	temp[10] = (uchar)mul13[message[8]] ^ mul9[message[9]] ^ mul14[message[10]] ^ mul11[message[11]];
	temp[11] = (uchar)mul11[message[8]] ^ mul13[message[9]] ^ mul9[message[10]] ^ mul14[message[11]];

	temp[12] = (uchar)mul14[message[12]] ^ mul11[message[13]] ^ mul13[message[14]] ^ mul9[message[15]];
	temp[13] = (uchar)mul9[message[12]] ^ mul14[message[13]] ^ mul11[message[14]] ^ mul13[message[15]];
	temp[14] = (uchar)mul13[message[12]] ^ mul9[message[13]] ^ mul14[message[14]] ^ mul11[message[15]];
	temp[15] = (uchar)mul11[message[12]] ^ mul13[message[13]] ^ mul9[message[14]] ^ mul14[message[15]];

	for (int i = 0; i < 16; i++) {
		message[i] = temp[i];
	}
}

// Same as round() but no InverseMixColumns
void initial_round(vector<uchar> &message, vector<uchar> &key) {
    sub_round_key(message, key);
    decryption_shift_rows(message);
    decryption_sub_bytes(message);
}

void decryption_round(vector<uchar> &message, vector<uchar> &key) {
    sub_round_key(message, key);
    inverse_mix_columns(message);
    decryption_shift_rows(message);
    decryption_sub_bytes(message);
}

vector<uchar> aes_decrypt(vector<uchar> message, vector<vector<uchar>> &expanded_keys) {
    // initial round with last key, reverse manner
    initial_round(message, expanded_keys[10]);

    for(int i = 9; i >= 1; i--)
        decryption_round(message, expanded_keys[i]);

    // final round
    sub_round_key(message, expanded_keys[0]);

    return message;
}