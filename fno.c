#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	printf("file number of %s: %d\n", "stdout", fileno(stdout));
	printf("file number of %s: %d\n", "stdin", fileno(stdin));
	printf("file number of %s: %d\n", "stderr", fileno(stderr));
	int fd1 = creat("fnotmp1",0644);
	int fd2 = creat("fnotmp2",0644);
	FILE *f1 = fopen("fnotmp1","r");
	FILE *f2 = fopen("fnotmp2","r");
	printf("file number of %s: %d\n", "file1:", fileno(f1));
	printf("file number of %s: %d\n", "file2:", fileno(f2));
	unlink("fnotmp1");
	unlink("fnotmp2");
	return 0;
}
