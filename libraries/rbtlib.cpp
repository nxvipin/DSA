#include "rbtlib.h";
#include <iostream>
using namespace std;
rbt::rbt(){
	root=NIL;
}

rbt::~rbt() {}

rbt::rbtNode::rbtNode(int key){
	this->key = key;
	this->color = RED;
}

void rbt::createNode(int key){
	node.push_back(key);
}

void rbt::leftRotate(int x){
	int y;
	y = node[x].right;
	node[x].right = node[y].left;
	if(node[y].left != NIL){
		node[node[y].left].parent = x;
	}
	node[y].parent=node[x].parent;
	if(node[x].parent == NIL){
		root = y;
	}
	else if(x == node[node[x].parent].left){
		node[node[x].parent].left = y;
	}
	else{
		node[node[x].parent].right = y;
	}
	node[y].left = x;
	node[x].parent = y;
}

void rbt::rightRotate(int x){
	int y;
	y = node[x].left;
	node[x].left = node[y].right;
	if(node[y].right != NIL){
		node[node[y].right].parent = x;
	}
	node[y].parent=node[x].parent;
	if(node[x].parent == NIL){
		root = y;
	}
	else if(x == node[node[x].parent].right){
		node[node[x].parent].right = y;
	}
	else{
		node[node[x].parent].left = y;
	}
	node[y].right = x;
	node[x].parent = y;
}

