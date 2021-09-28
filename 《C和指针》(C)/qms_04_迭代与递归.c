#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


//�ݹ�汾fibonacci
//�ݹ�������������ܿ���ƫ��
unsigned long fib_rec(int n) {
	if (n <= 2) return 1;
	else return fib_rec(n - 1) + fib_rec(n - 2);
}


//�����汾fibonacci
//�Ը��ӣ�������ֵ��
unsigned long fib_iter(int n) {
	unsigned long result, father_result, grandfa_result;
	result = father_result = 1;
	while (n > 2) {
		--n;
		grandfa_result = father_result;
		father_result = result;
		result = grandfa_result + father_result;
	}
	return result;
}


int main4() {
	int n;
	printf("please input a number(�Ƽ�ֵ42):");
	int i = scanf("%d", &n);
	printf("�����汾fibonacci��ʼ����...\n");
	printf("�����汾fibonacci( %d ) = %d\n", n, fib_iter(n));
	printf("�ݹ�汾fibonacci��ʼ����...\n");
	printf("�ݹ�汾fibonacci( %d ) = %d\n", n, fib_rec(n));
	
	return 0;
}