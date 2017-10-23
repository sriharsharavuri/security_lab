#include<gmp.h>
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	srand(unsigned(time(0)));
	int i;
	for(int j=0;j<20;j++){
		cout<<rand()%26<<" ";
	}
}
