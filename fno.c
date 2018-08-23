#include <stdio.h>

// NOTE: The absence of a file named zap.c will cause a segmentation fault.
// So please create a file named 'zap.c' to see results
int main() {
	printf("file number of %s: %d\n", "stdout", fileno(stdout));
	printf("file number of %s: %d\n", "stdin", fileno(stdin));
	printf("file number of %s: %d\n", "stderr", fileno(stderr));
	FILE *zap = fopen("zap.c","r");
	printf("file number of %s: %d\n", "zap", fileno(zap));
	return 0;
}
