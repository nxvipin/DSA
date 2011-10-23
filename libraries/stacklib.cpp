#include "stacklib.h"
stack::stack(int n){
	size=n;
	data = new int[size];
	top=-1;	
}
int stack::isStackEmpty(){
	if(top==-1){
		return 1;
	}
	return 0;
}
int stack::isStackFull(){
	if(top==size-1){
		return 1;
	}
	return 0;
}
void stack::push(int n){
	if(!isStackFull()){
		data[++top]=n;
	}	
}
int stack::pop(){
	if(!isStackEmpty()){
		return data[top--];
	}
}
