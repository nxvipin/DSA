#include "rbtlib.h";
#include <iostream>
using namespace std;
rbt::rbt(int n){
	this->n = n;
	this->node = new rbtNode[n];
}
rbt::~rbt(){
	delete [] this->node;
}

