#include "rbtlib.h";
#include <iostream>
using namespace std;
rbt::rbt(){
	root=NIL;
	createNode(root);
	node[root].parent=NIL;
	node[root].left=NIL;
	node[root].right=NIL;
	node[root].key=NIL;
}

rbt::~rbt() {}

rbt::rbtNode::rbtNode(int key){
	this->key = key;
}

int rbt::createNode(int key){
	node.push_back(key);
	return node.size()-1;
}

void rbt::insert(int key){
	int x,y,z;
	z=createNode(key);
	y = NIL;
	x = root;
	while(x != NIL){
		y=x;
		if(node[z].key < node[x].key){
			x=node[x].left;
		}
		else{
			x=node[x].right;
		}
	}
	node[z].parent=y;
	if(y == NIL){
		root = z;
	}
	else if(node[z].key < node[y].key){
		node[y].left = z;
	}
	else{
		node[y].right = z;
	}
	node[z].left = NIL;
	node[z].right = NIL;
	node[z].color = RED;
	insertFix(z);
}

void rbt::insertFix(int z){
	int y;
	char tmp;
	while(node[node[z].parent].color == RED && node[z].parent != NIL ){
		if(node[z].parent == node[node[node[z].parent].parent].left){
			y = node[node[node[z].parent].parent].right;
			if(node[y].color == RED){
				node[node[z].parent].color = BLACK;
				node[y].color = BLACK;
				node[node[node[z].parent].parent].color = RED;
				z = node[node[z].parent].parent;
			}
			else if(z = node[node[z].parent].right){
				z = node[z].parent;
				leftRotate(z);
			}
			if(node[z].parent != NIL){
				node[node[z].parent].color = BLACK;
			}
			if(node[node[z].parent].parent != NIL){
				node[node[node[z].parent].parent].color = RED;
				rightRotate(node[node[z].parent].parent);
			}
			node[root].color=BLACK;
		}
		else{
			y = node[node[node[z].parent].parent].left;
			if(node[y].color == RED){
				node[node[z].parent].color = BLACK;
				node[y].color = BLACK;
				if(node[node[z].parent].parent != NIL){
				node[node[node[z].parent].parent].color = RED;
				}
				z = node[node[z].parent].parent;
			}
			else if(z = node[node[z].parent].left){
				z = node[z].parent;
				rightRotate(z);
			}
			if(node[z].parent != NIL){
				node[node[z].parent].color = BLACK;
			}
			if(node[node[z].parent].parent != NIL){
				node[node[node[z].parent].parent].color = RED;
				leftRotate(node[node[z].parent].parent);
			}
		}
	}
	node[root].color = BLACK;
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

