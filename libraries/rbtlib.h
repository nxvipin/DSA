/**
* Red Black Tree
*/
#include <vector>
using namespace std;
#define NIL 0
#define RED 1
#define BLACK 2

class rbt{
	public:
		class rbtNode{
			public:
				int color, key, left, right, parent;
				rbtNode(int);
		};
		int root;
		vector <rbtNode> node;
		rbt();
		~rbt();
		int createNode(int);
		void insert(int);
		void insertFix(int);
		void leftRotate(int);
		void rightRotate(int);
};
