// Searching algorithms problem: Binary Search and Insertion Search

#include <stdio.h>
#include <cs50.h>

bool selectSearch(int* arr, int len, int target);
int* insrtSort(int* arr, int len);
bool binarySearch(int* arr, int len, int target);

int main(void) {
    int arr[] = {1,5,3,2,6,14,63,4,45,62,3,6,79};
    int len = sizeof(arr)/sizeof(arr[0]);
    if(binarySearch(arr, len, 0)) {
        printf("ending the program\n");
    } else {
        printf("the target does not exist in the array\n");
        printf("ending the program\n");
    }
}

bool selectSearch(int* arr, int len, int target){
    for(int i = 0;i < len;i++){
        if(target == arr[i]){
            printf("found %i at index %i in the array\n", target, i);
            return true;
        }
    }
    return false;
}

int* insrtSort(int* arr, int len) { //for binary search
	for(int i = 1;i < len;i++) {
		while(arr[i] < arr[i-1]) {
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

bool binarySearch(int* arr, int len, int target){
    int upper = len - 1;
    int lower = 0;
    int middle = (int)((upper + lower)/2);
    int* arr2 = insrtSort(arr, len);
    while(upper >= lower){
        middle = (int)((upper + lower)/2);
        if(target == arr2[middle]){
            printf("found %i at index %i in the array\n", target, middle);
            return true;
        } else if(target > arr2[middle]){
            lower = middle + 1;
        } else {
            upper = middle - 1;
        }
    }
    return false;
}
