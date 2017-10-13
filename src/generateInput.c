#include <stdio.h>
#include <stdlib.h>
#define SZ 32

/* Create a string of binary digits based on the input value.
   Input:
       val:  value to convert.
       buff: buffer to write to must be >= sz+1 chars.
       sz:   size of buffer.
   Returns address of string or NULL if not enough space provided.
*/
static char *binrep (unsigned long int val, char *buff, int sz) {
    char *pbuff = buff;

    /* Must be able to store one character at least. */
    if (sz < 1) return NULL;

    /* Special case for zero to ensure some output. */
    if (val == 0) {
        *pbuff++ = '0';
        *pbuff = '\0';
        return buff;
    }

    /* Work from the end of the buffer back. */
    pbuff += sz;
    *pbuff-- = '\0';

    /* For each bit (going backwards) store character. */
    while (val != 0) {
        if (sz-- == 0) return NULL;
        *pbuff-- = ((val & 1) == 1) ? '1' : '0';

        /* Get next bit. */
        val >>= 1;
    }
    return pbuff+1;
}




unsigned long int power(int base, int exp){
	if(exp == 0)return 1;
	
	unsigned long int result = base;

	for (int i = 1; i < exp; ++i){
		result = result * base;
	}

	return result;
}

int main(int argc, char const *argv[]){
	int bits = atoi(argv[argc-1]);
	int j = 0;
	char buff[SZ+1];
	if(argc == 1){
		printf("Please tell power.\n");
		return 0;
	}
	
	unsigned long int total = power(2, bits);
	long int intsize = power(2,16);
	for(unsigned long int i = 0, j = 0; i < total; i++, j++){
		if(j == intsize -1){
			j = 0;
		}
		printf("%.16s %ld\n", binrep(i,buff,SZ), j);
	}
	return 0;
}
