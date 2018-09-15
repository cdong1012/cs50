#include <cs50.h>
#include <string.h>
#include <stdio.h>

// Bubble sort O(n^2), worst case in reverse order, bubble up n values n times through the loop
int* bbSort(int* arr, int len) {
	int sortCounter = -1; //sortCounter, break loops if sortCounter == 0 when no swap is made
	while(sortCounter != 0) {
		sortCounter = 0; //reset sortCounter
		for(int i = 0; i < len - 1; i++) {
			// comparing two values next to each other again and again
			if(arr[i] > arr[i+1]){
				int a = arr[i+1];
				arr[i+1] = arr[i];
				arr[i] = a;
				sortCounter++;
			}
		}
		len--; // reduce the length as we bubble up more and more values to the end
	}
	return arr;
}

//Insertion sort O(n^2) worst case reverse order, insert the nth terms through the sorted list(n times)
int* insrtSort(int* arr, int len) {
	for(int i = 1;i < len;i++) {
		while(arr[i] < arr[i-1]) { //
			int a = arr[i-1];
			arr[i-1] = arr[i];
			arr[i] = a;
			if(i - 1 == 0){
				break;
			}
			i--;
		}
	}
	return arr;
}


int main(void){
	int arr[10] = {2,6,5,6,7,9,14,2,3,12};
	int len = sizeof(arr)/sizeof(arr[0]);
	insrtSort(arr, len);
	for(int i = 0;i < sizeof(arr)/sizeof(arr[0]);i++){
		printf("%i\n", arr[i]);
	}
}

