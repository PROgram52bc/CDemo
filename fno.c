#include <stdio.h>

int main() {
	printf("file number of %s: %d\n", "stdout", fileno(stdout));
	printf("file number of %s: %d\n", "stdin", fileno(stdin));
	printf("file number of %s: %d\n", "stderr", fileno(stderr));
	FILE *zap = fopen("zap.c","r");
	printf("file number of %s: %d\n", "zap", fileno(zap));
	return 0;
}
