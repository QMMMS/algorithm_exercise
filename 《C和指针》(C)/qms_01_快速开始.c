#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000


//�������ж�ȡ�ַ���
int read_column_numbers(int columns[], int max) {
	int num = 0;
	int ch;/*��ֹ������ַ����ⱻ���ͳ�EOF��������int����*/
	while (num < max && scanf("%d", &columns[num]) == 1 
		&& columns[num] >= 0) {
		//����scanf,ʧ�ܷ���0���ɹ�����1
		num++;
	}
		if (num % 2 != 0) {
			puts("Last column number is not paired.");//from stdio.h
			exit(EXIT_FAILURE);//from stdlib.h
			/*ֱ���˳��޷���ֵ*/
		}
	
		while ((ch = getchar()) != EOF && ch != '\n');/*�ҵ���β�����˵������������*/
		//getchar�������ж�ȡһ��ֵ���������ڣ�����EOF����ʾ�ļ�ĩβ
		return num;
}


//����������ַ���
void rearrange(char* output, char* const input, 
	int const columns[], int num_column) {
	int length = strlen(input);//string.h
	int output_column = 0;     /*output������±�*/
	for (int column = 0; column < num_column; column += 2) {
		//�ڶ�������ÿ��ѭ��֮ǰִ��
		 //����������ÿ��ѭ��֮��ִ��
		int nchars = columns[column + 1] - columns[column] + 1;
		if (output_column == MAX_INPUT - 1 || columns[column] >= length) break;
		if (nchars + output_column > MAX_INPUT - 1) {
			//���������Ŀռ䲻�����ܴ���پʹ����
			nchars = MAX_INPUT - output_column - 1;
		}
		strncpy(output + output_column, input + columns[column], nchars);
		output_column += nchars;
	}
	output[output_column] = '\0';/*�ַ�������NUL*/
	
		

}



int main1() {
	int columns[MAX_COLS];
	char input[MAX_INPUT];
	char output[MAX_INPUT];

	int num = read_column_numbers(columns, MAX_COLS);

	while (fgets(input, sizeof(input), stdin) != NULL && input[0] != '\n')
	{
		printf("�����ַ�����%s\n", input);
		rearrange(output, input, columns, num);
		printf("����ַ�����%s\n", output);
	}
	return EXIT_SUCCESS;
}

