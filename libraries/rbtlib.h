/**
* Red Black Tree
*/
#include <vector>
using namespace std;
#define NIL -1
#define RED 0
#define BLACK 1

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
		void createNode(int);
		void leftRotate(int);
		void rightRotate(int);
};
