#include<bits/stdc++.h>
using namespace std;
char a[26][26];
char decrypt(char cipher[], char key[]){
	int keylen=strlen(key);
	for(int i=0;i<strlen(cipher);i++){
		int j=0;
		while(a[key[i%keylen]-'a'][j]!=cipher[i])j++;
		cout<<(char)('a'+j);
	}
}
void encrypt(){
	cout<<"Enter the text and the key \n";
	char val[100],key[100];	
	cin>>val;
	cin>>key;
	char cipher[100];
	int keylen = strlen(key);
	for(int i=0;i<strlen(val);i++){
		cipher[i]=a[val[i]-'a'][key[i%keylen]-'a'];
	}
	cipher[strlen(val)]='\0';
	cout<<cipher<<endl;
	decrypt(cipher, key);
}
int main(){
	for(int i=0;i<26;i++){
		char check='a'+i;
		for(int j=0;j<26;j++){
			a[i][j]=check;
			if(check=='z')check='a';
			else check++;
		}
	}
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
	encrypt();
}