// DES
#include<stdlib.h>
//2501229023703295255 213123 312312

#include<iostream>
using namespace std;
int init_perm_key[] = {
	57,49,41,33,25,17,9,
	1,58,50,42,34,26,18,
	10,2,59,51,43,35,27,
	19,11,3,60,52,44,36,
	63,55,47,39,31,23,15,
	7,62,54,46,38,30,22,
	14,6,61,53,45,37,29,
	21,13,5,28,20,12,4
};

int sub_perm_key[] = {
	14,17,11,24,1,5,
	3,28,15,6,21,10,
	23,19,12,4,26,8,
	16,7,27,20,13,2,
	41,52,31,37,47,55,
	30,40,51,45,33,48,
	44,49,39,56,34,53,
	46,42,50,36,29,32
};

int key_shift[] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int init_perm[] = {
	58,50,42,34,26,18,10,2,
	60,52,44,36,28,20,12,4,
	62,54,46,38,30,22,14,6,
	64,56,48,40,32,24,16,8,
	57,49,41,33,25,17, 9,1,
	59,51,43,35,27,19,11,3,
	61,53,45,37,29,21,13,5,
	63,55,47,39,31,23,15,7
};

int e_table[] = {
	32, 1, 2, 3, 4, 5,
	4, 5, 6, 7, 8, 9,
	8, 9,10,11,12,13,
	12,13,14,15,16,17,
	16,17,18,19,20,21,
	20,21,22,23,24,25,
	24,25,26,27,28,29,
	28,29,30,31,32,1
};

int sBox[8][4][16] = {
  {
	{14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
	{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
	{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
	{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
  },
  {
	{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
	{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
	{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
 	{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
  },
  {
	{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
	{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
	{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
	{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
  },
  {
	{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
	{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
	{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
	{3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
  },
  {
	{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
	{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
	{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
	{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
  },
  {
	{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
	{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
	{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
	{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
  },
  {
	{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
	{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
	{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
	{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
  },
  {
	{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
	{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
	{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
	{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
  }
};

int r_perm [] = {
	16,7,20,21,
	29,12,28,17,
	1,15,23,26,
	5,18,31,10,
	2,8,24,14,
	32,27,3,9,
	19,13,30,6,
	22,11,4,25
};

int inv_perm[] = {
	40,8,48,16,56,24,64,32,
	39,7,47,15,55,23,63,31,
	38,6,46,14,54,22,62,30,
	37,5,45,13,53,21,61,29,
	36,4,44,12,52,20,60,28,
	35,3,43,11,51,19,59,27,
	34,2,42,10,50,18,58,26,
	33, 1,41,9,49,17,57,25
};

unsigned long long int initial_permutation_text(unsigned long long a){
	unsigned long long newtext=0;
	for(int i=0;i<64;i++){
		int b = init_perm[i];
		b=a>>(64-b) & 1;
		b=b<<i;
		newtext |= b;
	}
	return newtext;
}

unsigned long long int inverse_initial_permutation(unsigned long long a){
	unsigned long long newtext=0;
	for(int i=0;i<64;i++){
		int b = inv_perm[i];
		b=a<<(64-b) & 1;
		b=b<<i;
		newtext |= b;
	}
	return newtext;
}

unsigned long long int initial_permutation_key(unsigned long long a){
	unsigned long long newtext=0;
	for(int i=0;i<56;i++){
		int b = init_perm_key[i]-1;
		b=a>>b & 1;
		b=b<<i;
		newtext |= b;
	}
	return newtext;
}

unsigned long long int post_substitution_permutation(unsigned long long a){
	unsigned long long newtext=0;
	for(int i=0;i<32;i++){
		int b = r_perm[i]-1;
		b=a>>b & 1;
		b=b<<i;
		newtext |= b;
	}
	return newtext;
}

unsigned long long int expansion_permutation(unsigned long long int a){
	unsigned long long int expansion_text=0;
	for(int i=0;i<48;i++){
		int b = e_table[i]-1;
		b=a>>b & 1;
		b=b<<i;
		expansion_text |= b;
	}	
	return expansion_text;
}

unsigned long long contract_key(unsigned long long int a){
	unsigned long long int contracted_key=0;
	for(int i=0;i<48;i++){
		int b = sub_perm_key[i]-1;
		b=a>>b & 1;
		b=b<<i;
		contracted_key |= b;
	}
	return contracted_key;
}

unsigned long long int rotatekey(int round, unsigned long long int key){
	unsigned int mask_for_right=1;
	for(int i=0;i<27;i++){
		mask_for_right = (mask_for_right<<1) | 1;
	}
	unsigned long long int left, right;
	left = key>>28;
	right = mask_for_right & key;	
	left = (left<<1) | (left>>27);
	right = (right<<1) | (right>>27);
	if(key_shift[round]==2){
		left = (left<<1) | (left>>27);
		right = (right<<1) | (right>>27);
	}
	key = 0;
	key = key | right;
	key = key | (left<<28);
	return key;
}

unsigned int substitution_value(unsigned long long int presubstitution){
	unsigned int value=0;	
	for(int i=7;i>=0;i--){
		unsigned int row=0, column=0;
		for(int j=0;j<6;j++){
			//val = val | (presubstitution&1);
			if(j==0){
				row = row | (presubstitution&1);
				row = row<<1;
			}else if(j==5){
				row = row | (presubstitution&1);
			}else{
				column = column | (presubstitution&1);
				column = column<<1;	
			}			
			presubstitution=presubstitution>>1;
		}
		column = column>>1; // Since we want the column to be of 4 bits, but not five;
		unsigned int substituted_value = sBox[i][row][column];
		value = value | (substituted_value << (i*4));		
	}
	return value;
}

unsigned long long int DEScipher(unsigned long long int plaintext, unsigned long long int key){
	unsigned int mask_for_right=1;
	for(int i=0;i<31;i++){
		mask_for_right = (mask_for_right<<1) | 1;
	}	
	for(int i=0;i<16;i++){
		unsigned long long int left, right;
		left = plaintext>>32;
		right = mask_for_right & plaintext;
		
		key = rotatekey(i, key);
		unsigned long long int contracted_key = contract_key(key);
		unsigned long long int pre_substitution = contracted_key ^ expansion_permutation(right);
		unsigned long long int post_substitution = substitution_value(pre_substitution);
		post_substitution = post_substitution_permutation(post_substitution);
		post_substitution = post_substitution ^ left;
		plaintext = 0;
		if(i!=15)plaintext = (right<<32) ^ (post_substitution);
		else plaintext = (post_substitution<<32) ^ right; 
	}
	return inverse_initial_permutation(plaintext);
}

void print(unsigned int hexval){
	switch(hexval){
		case 0:cout<<"0";break;
		case 1:cout<<"1";break;
		case 2:cout<<"2";break;
		case 3:cout<<"3";break;
		case 4:cout<<"4";break;
		case 5:cout<<"5";break;
		case 6:cout<<"6";break;
		case 7:cout<<"7";break;
		case 8:cout<<"8";break;
		case 9:cout<<"9";break;
		case 10:cout<<"A";break;
		case 11:cout<<"B";break;
		case 12:cout<<"C";break;
		case 13:cout<<"D";break;
		case 14:cout<<"E";break;
		case 15:cout<<"F";break;
	}
}

void output(unsigned long long int a){
	while(a>0){
		cout<<a<<endl;		
		unsigned int hexval=0;
		hexval = a&15;
		cout<<hexval<<endl;		
		cout<<endl;
		a=a>>4;
		print(hexval);
	}
}

int main(){
	unsigned long long int pt, key, cipher;
	cout<<"Enter the plaintext and the key:";
	cin>>pt>>key;
	pt = initial_permutation_text(pt);
	key = initial_permutation_key(key);
	cipher = DEScipher(pt, key);
	cout<<cipher<<endl;
	output(cipher);
}
