#include <stdio.h>

int main() {
	int numbers[5];
	printf("Enter 5 numbers: ");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &numbers[i]);
	}

	printf("You entered: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", numbers[i]);
	}

	return 0;
}
