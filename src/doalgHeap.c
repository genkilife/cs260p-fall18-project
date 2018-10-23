
void Heapify(int* heap, int k, int i) {
	int leftChild = i * 2 + 1;
	int rightChild = i * 2 + 2;
	int parent = i;

//	if (leftChild < k && rightChild < k) {
//		if (COMPARE(heap[leftChild], heap[rightChild]) == 1)
//			parent = rightChild;
//		else if (COMPARE(heap[leftChild], heap[rightChild]) == 2)
//			parent = leftChild;
//	}	
//	else if (leftChild < k && COMPARE(heap[leftChild], heap[parent]) == 2)
//		parent = leftChild;

	if (leftChild < k && COMPARE(heap[leftChild], heap[i]) != 1)
		parent = leftChild;
	if (rightChild < k && COMPARE(heap[rightChild], heap[parent]) != 1)
		parent = rightChild;

	if (i != parent) {
		int tmp = heap[i];
		heap[i] = heap[parent];
		heap[parent] = tmp;
		Heapify(heap, k, parent);
	}

}

void HeapInit(int* heap, int k) {
	int i = k/2;
	while (i-- > 0) {
		Heapify(heap, k, i);
	}
}

int Pop(int* heap, int* size) {
	int result = heap[0];
	heap[0] = heap[--(*size)];
	Heapify(heap, *size, 0);
	return result;
}

int doalg(int n, int k, int* Best){
	int* heap = (int*)malloc(sizeof(int)*k);
	int size = k;
	int i;
	for (i=0; i<k; i++) {
		heap[i] = i + 1;
	}

	HeapInit(heap, size);
	
	for (i=1; i<=n; i++) {
		if (COMPARE(heap[0], i) == 2) {
			heap[0] = i;
			Heapify(heap, k , 0);
		}
	}

	for (i=k-1; i>=0; i--) {
		Best[i] = Pop(heap, &size);
		printf("%d\n", Best[i]);
	}

	free(heap);
    return 1;
}

