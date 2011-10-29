/**
* Red Black Tree
*/

class rbt{
	private:
		//Number of keys
		int n;
	public:
		class rbtNode{
			public:
				int color, key, left, right, parent;
		};
		rbtNode *node;
		rbt(int);
		~rbt();
};
