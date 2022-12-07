#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *f;
int twice = 0;
size_t i;
size_t j;
size_t str_len;
char ch;
char priority_num;
int sum = 0;
char *second;
char line[1000];

void
part_1()
{

	while (fgets(line, sizeof(line), f) != NULL) {
		/* Each line */
		
		str_len = strlen(line);
		for (i = 0; i < str_len/2; i++) {
			ch = line[i];
			for (j = str_len/2; j < str_len; j++) {
				if (ch == line[j]) {
					goto mycock;
				}
			}
		}
mycock:
		sum += ch >= 'A' && ch <= 'Z' ? ch - 64 + 26 : ch - 65 - 31;
	}
	printf("The result is %d\n", sum);

}

void
part_2()
{
	char one[1000];
	char two[1000];
	char three[1000];
	char one_ch; char two_ch; char three_ch;
	size_t one_l = 0; size_t two_l = 0; size_t three_l = 0;
	size_t i = 0; size_t j = 0; size_t k = 0;
	int sum = 0;
	int count = 0;

	while (fgets(one, sizeof(one), f) != NULL) {
		fgets(two, sizeof(two), f);
		fgets(three, sizeof(three), f);

		one_l = strlen(one);
		two_l = strlen(two);
		three_l = strlen(three);

		for (i = 0; i < one_l;i++) {
			one_ch = one[i];
			for (j = 0; j < two_l; j++) {
				two_ch = two[j];
				for (k = 0; k < three_l; k++) {
					three_ch = three[k];
					if (one_ch == two_ch && two_ch == three_ch){
						goto mycockli;
						printf("%c %c %c\n", one_ch, two_ch, three_ch);
						exit(0);
					}
				}
			}

		}
mycockli:
		sum += one_ch >= 'A' && one_ch <= 'Z' ? one_ch - 64 + 26 : one_ch - 65 - 31;
	}
	printf("The result for part two is %d\n", sum);
}

int
main()
{
	f = fopen("3.txt", "rb");

	part_1();
	fclose(f);

	f = fopen("3.txt", "rb");
	part_2();
	fclose(f);

	return 0;

	
}
