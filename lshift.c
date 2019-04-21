#include <stdio.h>
typedef unsigned char *bitpointer;
void showbits(bitpointer bitchunk, size_t bytenum) {
	size_t bytecount = 0;
	while (bytecount++ < bytenum) {
		int bitcount;
		unsigned char bits = *bitchunk;
		bitchunk++;
		// printf("%x ", bits);
		for (bitcount = 0; bitcount < 8; bitcount++) {
			printf("%1d", bits%2);
			bits /= 2;
		}
		printf(" ");
	}
	printf("\n");
}
int main() {
	int x = 128;
	showbits((bitpointer) &x, sizeof(int));
	int a,b;
	a = (int) ~(((unsigned) ~0x0) >> 3) | 1; // Tmin+1, 10000000.....000001
	b = ~0x0; // -1, 1111111...1111111
	printf("Size of int: %lu\n", sizeof(int));
	printf("num: %d, num << 1: %d\n", a, a<<3);
	printf("num: %d, num * 2: %d\n", a, a*8);
	showbits((bitpointer) &a, sizeof(int));
	printf("num: %d, num << 1: %d\n", b, b<<1);
	showbits((bitpointer) &b, sizeof(int));
	return 0;
}
