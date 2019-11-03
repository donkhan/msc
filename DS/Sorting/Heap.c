#include <stdio.h>
#include <conio.h>


void printArray(int arr[], int n){
    int i;
    for (i=0; i<n; ++i)
	printf(" %d ",arr[i]);
    printf("\n");
    //getch();
}


// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
	largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
	largest = r;

    // If largest is not root
    if (largest != i){
	int t = arr[i];
	arr[i] = arr[largest];
	arr[largest] = t;
	// Recursively heapify the affected sub-tree
	heapify(arr, n, largest);
    }
    printArray(arr,n);
}

void heapSort(int arr[], int n){
    int i;
    // Build heap (rearrange array)
    for (i = n / 2 - 1; i >= 0; i--)
	heapify(arr, n, i);
      // One by one extract an element from heap
    for (i=n-1; i>=0; i--){
	// Move current root to end
	int t = arr[0];
	arr[0] = arr[i];
	arr[i] = t;
	  // call max heapify on the reduced heap

	heapify(arr, i, 0);
    }
}


int main(){
    int arr[] = {12,11,13,5,6,7,3,2,1,4,16,22};
    int n = 12;
    clrscr();
    printf("UnSorted Array ...\n");
    printArray(arr, n);
    heapSort(arr, n);
    printf("Sorted Array ....\n");
    printArray(arr, n);
    getch();
    return 1;
}