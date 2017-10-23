#include<iostream>
#include<stdio.h>
using namespace std;

int main(int argc, char* argv[]){
	int x,y;
	cin>>x>>y;
	while(x%y != 0){
		int r=x%y;x=y;y=r;
	}
	cout<<y;
}
