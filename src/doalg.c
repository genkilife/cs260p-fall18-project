
void Swap(int* a, int*b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int Partition(int* indexArray, int left, int right, int pivotPos, int k) {
	int pivot = indexArray[pivotPos];
	int largerIndex = left;
	int i;
	Swap(&indexArray[pivotPos], &indexArray[right]);
	for (i=left; i<right; i++) {
		if (COMPARE(indexArray[i], pivot) == 1) {
			Swap(&indexArray[largerIndex], &indexArray[i]);
			largerIndex++;
		}
	}
	Swap(&indexArray[right], &indexArray[largerIndex]);	
	return largerIndex;
}

void QuickSort(int* indexArray, int left, int right, int k) {
	if (left >= right)
		return;
	int pivotPos = (left+right)/2;
	int newPivotPos = Partition(indexArray, left, right, pivotPos, k);
	// if the size of larger subset is larger than k, then do QS on it only
	if (newPivotPos >= k) {
		QuickSort(indexArray, left, newPivotPos - 1, k);
	}
	else {
		QuickSort(indexArray, left, newPivotPos - 1, k);
		QuickSort(indexArray, newPivotPos + 1, right, k);
	}
}

int doalg(int n, int k, int* Best){
	int* indexArray = (int*)malloc(sizeof(int)*n);
	int i;
	for (i=0; i<n; i++) {
		indexArray[i] = i + 1;
	}

	QuickSort(indexArray, 0, n-1, k);
	
	for (i=0; i<k; i++)
		Best[i] = indexArray[i];

	free(indexArray);
    return 1;
}

