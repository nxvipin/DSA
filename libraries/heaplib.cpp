/*
* Integer min-heap library
*/
#include<iostream>
#include "heaplib.h"
using namespace std;

heap::heap(int n){
	HEAP = new int [n];
	HEAPLABEL= new int [n];
	heapSize=0;
	length=n;
}

heap::~heap(){
	delete [] HEAP;
	delete [] HEAPLABEL;
}

int heap::parent(int i){
	return i/2;
}

int heap::left(int i){
	return 2*i;
}

int heap::right(int i){
	return 2*i+1;
}

void heap::swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void heap::minHeapify(int i){
	int l,r,smallest;
	l=left(i);
	r=right(i);
	if(HEAP[l]<HEAP[i] && l<=heapSize){
		smallest=l;
	}
	else{
		smallest=i;
	}
	if(HEAP[r]<HEAP[smallest] && r<=heapSize){
		smallest=r;
	}
	if(smallest!=i && i<heapSize){
		swap(&HEAP[smallest],&HEAP[i]);
		swap(&HEAPLABEL[smallest],&HEAPLABEL[i]);
		minHeapify(smallest);
	}
}

void heap::buildMinHeap(){
	int i;
	for(i=heapSize/2;i>=1;i--){
		minHeapify(i);
	}
}

int heap::heapExtractMin(){
	int min,minlabel;
	if(heapSize>0){
		min=HEAP[1];
		minlabel=HEAPLABEL[1];
		HEAP[1]=HEAP[heapSize];
		HEAPLABEL[1]=HEAPLABEL[heapSize];
		HEAP[heapSize]=min;
		HEAPLABEL[heapSize]=minlabel;
		heapSize--;
		minHeapify(1);
		return minlabel;
	}
	else{
		cout<<"Heap Underflow!";
	}
}

bool isHeapEmpty(){
	if(heapSize>0)
		return false;
	else
		return true;
}

void heap::heapInput(int label, int weight){
	if(heapSize<length){
		++heapSize;
		HEAP[heapSize]=weight;
		HEAPLABEL[heapSize]=label;
	}
}

