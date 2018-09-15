#include <stdio.h>
#include <cs50.h>

int main(void){
	int height = get_int("Height: ");
	while(height < 0 || height > 23) {
		height = get_int("Height: ");
	}

	int block = height;
	for(int line = 1; line <= height;line++) { //go down on the col line
		for(int row = block-1; row > 0;row--) {
			printf(" ");
		}
		for(int time = 0;time < line;time++) {
			printf("#");
		}
		printf("  ");
		for(int time = 0;time < line;time++) {
			printf("#");
		}
		printf("\n");
		block--;
	}
}
