#include <stdio.h>

int main(void) {
	int run = 1; /* flag to determine when to exit program */

	while (run)	{
		printf("shell>");
		fflush(stdout);
		run = 0;
	}

	return 0;
}
