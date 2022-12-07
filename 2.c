#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 1 */
int
who_wins(char *elf, char *me)
{
	/*
	   A -> ROCK
	   B -> PAPER
	   C -> SCISSORS

	   X -> ROCK
	   Y -> PAPER
	   Z -> SCISSORS
   */
	if (!strcmp(elf, "A")) {
		if (!strcmp(me, "X"))
			return 1 + 3;
		if (!strcmp(me, "Y"))
			return 2 + 6;
		if (!strcmp(me, "Z"))
			return 3 + 0;
	}
	if (!strcmp(elf, "B")) {
		if (!strcmp(me, "X"))
			return 1 + 0;
		if (!strcmp(me, "Y"))
			return 2 + 3;
		if (!strcmp(me, "Z"))
			return 3 + 6;
	}
	if (!strcmp(elf, "C")) {
		if (!strcmp(me, "X"))
			return 1 + 6;
		if (!strcmp(me, "Y"))
			return 2 + 0;
		if (!strcmp(me, "Z"))
			return 3 + 3;
	}

	return 0;
}

/* 2 */
int
who_really_wins(char *elf, char *me)
{
	/*
	   A -> ROCK
	   B -> PAPER
	   C -> SCISSORS

	   X -> ROCK
	   Y -> PAPER
	   Z -> SCISSORS
   */

	if (!strcmp(elf, "A")) {
		if (!strcmp(me, "X"))
			return 3 + 0;
		if (!strcmp(me, "Y"))
			return 1 + 3;
		if (!strcmp(me, "Z"))
			return 2 + 6;
	}
	if (!strcmp(elf, "B")) {
		if (!strcmp(me, "X"))
			return 1 + 0;
		if (!strcmp(me, "Y"))
			return 2 + 3;
		if (!strcmp(me, "Z"))
			return 3 + 6;
	}
	if (!strcmp(elf, "C")) {
		if (!strcmp(me, "X"))
			return 2 + 0;
		if (!strcmp(me, "Y"))
			return 3 + 3;
		if (!strcmp(me, "Z"))
			return 1 + 6;
	}

	return 0;
}

int
main()
{

	FILE *f;
	int i;
	char *me = malloc(sizeof(char));
	char *elf = malloc(sizeof(char));
	char line[10];
	char *tokens = malloc(sizeof(char) * 4);
	int score = 0;
	int real_score = 0;

	f = fopen("2.txt", "rb");
	while (fgets(line, sizeof(line), f) != NULL) {

		elf = strtok(line, " ");
		me = strtok(NULL, "\n");

		score += who_wins(elf, me);
		real_score += who_really_wins(elf, me);

	}

	printf("%d\n", score);
	printf("THE REAL SCORE IS %d\n", real_score);

	return 0;

}

