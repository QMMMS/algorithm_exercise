//�治���ף�������

#include <stdio.h>
#include "alloc.h"
#undef malloc//?????

//���׷���������ڴ������
void* alloc(size_t size) {
	void* new_mem;

	new_mem = malloc(size);
	if (new_mem == NULL) {
		printf("out of memery!");
		exit(1);
	}
	return new_mem;
}


void function() {
	int* new_memery;
	new_memery = MALLOC(25, int);
}


int main9() {
	/*.....�治���ף�������....*/
	return 0;
}