#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main() 
{
	FILE *f;
	int i;
	int num = 0;
	int max = 0;
	int first = 0, second = 0, third = 0;
	char line[100];

	/* 1 */

	f = fopen("1.txt", "rb");
	while (fgets(line, sizeof(line), f) != NULL) {
		if (!strcmp(line, "\n")) {
			if (num > first) {
				third = second;
				second = first;
				first = num;
			} else if (num < first && num > second) {
				third = second;
				second = num;
			} else if (num < first && num < second && num > third) {
				third = num;
			}
			num = 0;
			continue;
		}
		num += atoi(line);
	}

	printf("The chadest elf is %d\n", first);
	printf("First elf is %d\n", first);
	printf("Second elf is %d\n", second);
	printf("Third elf is %d\n", third);
	printf("Total %d\n", first + second + third);

	return 0;

}
