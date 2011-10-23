#include<iostream>
#include "queuelib.h"
using namespace std;
queue::queue(int n){
	size=n;
	q=new int[size];
	front=-1;
	rear=-1;
}
queue::~queue(){
	delete [] q;
}
void queue::enque(int n){
	if(!isQueueFull()){
		rear++;
		rear=rear%size;
		q[rear]=n;
	}
}
int queue::deque(){
	if(!isQueueEmpty()){
		front++;
		front=front%size;
		return q[front];
	}
}
int queue::isQueueEmpty(){
	if(rear==front){
		return 1;
	}
	else{
		return 0;
	}
}
int queue::isQueueFull(){
	if(front-rear==1 || rear-front==size){
		return 1;
	}
	else{
		return 0;
	}
}
