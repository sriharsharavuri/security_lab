#include<bits/stdc++.h>
using namespace std;
int k;
char key[26];
char build(){
	char ch='a';
	for(int i=0;i<26;i++){
		key[i]=char(((int)ch-(int)('a')+k)%26)+int('a');
		ch = (char)((int)ch+1);	
	}
}
/* caeser cipher */
char encrypt(char ch[]){
	for(int i=0;ch[i]!='\0';i++){
		if(ch[i]==' ')continue;
		//int val = (((int)ch[i]-(int)('a')+k)%26)+int('a');
		ch[i] = key[ch[i]-'a'];//char(val);
	}
}

char decrypt(char ch[]){
	for(int i=0;ch[i]!='\0';i++){
		if(ch[i]==' ')continue;
		int val = ((((int)ch[i]-(int)('a')-k)%26 + 26)%26)+int('a');
		ch[i] = char(val);
	}	
}
/* caeser cipher */
int main(){
	cout<<"Enter k: ";
	cin>>k;
	char ch[100];
	cout<<"\n Enter the message: ";
	cin.ignore();
	cin.getline(ch,100,'\n');
	/* caeser cipher */	
	build();
	encrypt(ch);
	cout<<endl<<ch;
	decrypt(ch);
	cout<<endl<<ch;	
	/* caeser cipher */


}
