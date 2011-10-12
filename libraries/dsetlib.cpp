#include <iostream>
#include "dsetlib.h"
using namespace std;

dset::dset(int n){
	size=n;
	DSET = new int [size+1];
	int i;
}

dset::~dset(){
	delete [] DSET;
}

void dset::makeSet(int n){
	DSET[n] = -1;
}

int dset::findSet(int n){
	if(DSET[n]<0){
		return n;
	}
	else{
		DSET[n] = findSet(DSET[n]);
	}
}

int dset::rank(int n){
	return -1*DSET[n];
}

void dset::unionSet(int a,int b){
	int r,s;
	r=findSet(a);
	s=findSet(b);
	if(r!=s){
		if(rank(r)>rank(s)){
			DSET[s]=r;
		}
		else{
			if(rank(r)==rank(s)){
				--DSET[s];
			}
			DSET[r]=s;
		}
	}
}

void dset::displaySet(){
	int i,j,tmp;
	for(i=1;i<=size;i++){
		if(DSET[i]<0){
			cout<<"{ ";
			for(j=1;j<=size;j++){
				if(findSet(j)==i){
					cout<<j<<" ";
				}
			}cout<<"} "<<endl;
		}
	}
	
}
