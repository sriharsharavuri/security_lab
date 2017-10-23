#include<gmp.h>
#include <gmpxx.h>
#include<iostream>
using namespace std;
int main(){
	mpz_class fx, gx, mx;
	cout<<"Enter the values of fx, gx in bit strings\n";
	char ch[100];cin>>ch;
	fx.set_str(ch, 2);
	cin>>ch;
	gx.set_str(ch, 2);
	mx.set_str("100011011", 2);
	cout<<fx<<endl<<gx<<endl<<mx<<endl;
	cout<<"Enter 1 for addition, 2 for multiplication, 3 for division \n";
	int choice;cin>>choice;
	switch(choice){
		case 1: cout<<fx^gx;break;
		case 2: cout<<fx^gx;break;
		case 3: mul(fx, gx, mx);break;
	}
}

mpz_class mul(mpz_class fx, mpz_class gx, mpz_class mx){
	
}
