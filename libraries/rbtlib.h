/**
* Red Black Tree
*/

#define NIL -1
#define RED 0
#define BLACK 1

class rbt{
	private:
		//Number of keys
		int n;
	public:
		class rbtNode{
			public:
				int color, key, left, right, parent;
		};
		int root;
		rbtNode *node;
		rbt(int);
		~rbt();
		void leftRotate(int);
};
