
void Heapify(int* heap, int k, int i) {
	// minHeap heapify
	int Parent = i;
	int leftChild = i*2 + 1;
	int rightChild = i*2 + 2;
	int tmp, newChild;

	if (rightChild < k) {
		if (COMPARE(heap[leftChild], heap[rightChild]) == 1)
			tmp = rightChild;
		else
			tmp = leftChild;
	}	
	else if (leftChild < k)
		tmp = leftChild;
	else 
		tmp = Parent;

	if (tmp != Parent && COMPARE(heap[Parent], heap[tmp]) == 1)
		Parent = tmp;

	if (Parent != i) {
		newChild = heap[i];
		heap[i] = heap[Parent];
		heap[Parent] = newChild;
		Heapify(heap, k, Parent);
	}

}

void HeapInit(int* heap, int k) {
	int i;
	for (i=k/2; i>0; i--) {
		Heapify(heap, k, i-1);
	}
}

int Pop(int* heap, int* size) {
	int result = heap[0];
	(*size)--;
	heap[0] = heap[*size];
	Heapify(heap, *size, 0);
	return result;
}

int doalg(int n, int k, int* Best){
	// allocate a memory, which k-int size, to store the minHeap
	int* heap = (int*)malloc(sizeof(int)*k);
	int size = k;
	int i;
	for (i=0; i<k; i++) {
		heap[i] = i + 1;
	}

	// initialize a minHeap for the first k numbers
	HeapInit(heap, size);
	
	for (i=k+1; i<=n; i++) {
		if (COMPARE(i, heap[0]) == 1) {
			heap[0] = i;
			Heapify(heap, k , 0);
		}
	}

	for (i=k-1; i>=0; i--) {
		Best[i] = Pop(heap, &size);
		//printf("%d\n", Best[i]);
	}

	free(heap);
    return 1;
}

