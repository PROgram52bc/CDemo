#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	// change the offset (0-26) and observe the difference
	long offset, currPos;
	offset = 11;

	creat("lseektmp.txt", 0644);
	int fd = open("lseektmp.txt", 2);
	int result;
	if (write(fd, "abcdefghijklmnopqrstuvwxyz", 26) == -1)
		return -1;
	if (lseek(fd, 0L, 0) == -1)
		return -1;
	char buf[30];
	int nr = read(fd, buf, 26);
	buf[nr] = '\0';
	printf("Contents:\n%s\n", buf);
	currPos = lseek(fd, 0L, 1);
	printf("currPos: %ld\n", currPos);
	if (lseek(fd, offset, 0) == -1)
		return -1;
	printf("Reading from offset %ld...\n", offset);
	nr = read(fd, buf, 26);
	buf[nr] = '\0';
	fputs(buf, stdout);

	close(fd);
	unlink("lseektmp.txt");
	return 0;


}
