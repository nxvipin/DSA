/**
* Integer min-heap class
*/
class heap{
	private:
		int heapSize, length, *HEAP, *HEAPLABEL;
		void swap(int*,int*);
	public:
		heap(int);
		~heap();
		int parent(int);
		int left(int);
		int right(int);
		void heapInput(int,int);
		bool isHeapEmpty();
		void minHeapify(int);
		void buildMinHeap();
		int heapExtractMin();
};
