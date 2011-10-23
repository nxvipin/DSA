/**
* Integer Queue Implementation 
*/
class queue{
	private:
		int front,rear,*q,size;
	public:
		queue(int);
		~queue();
		void enque(int);
		int deque();
		int isQueueFull();
		int isQueueEmpty();
		int getQueueSize();
};
