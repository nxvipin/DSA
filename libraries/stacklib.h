class stack{
	private:
		int *data;
		int size;
		int top;
	public:
		stack(int);
		void push(int);
		int pop();
		int isStackFull();
		int isStackEmpty();
};
