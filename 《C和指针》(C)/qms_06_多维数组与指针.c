#include<stdio.h>
#include<string.h>
char const *keyword[] = {
	//ָ������
	"do",
	"for",
	"if",
	"return"
};
#define N_KEYWORD (sizeof(keyword)/sizeof(keyword[0]))
//�Զ���������Ԫ�ظ���


//����ά������Ϊ����
void print_test(int(*mat)[10], int num) {
	//�൱�� int mat[][10]
	for (int i = 0;i != num;++i) {
		int* np = *mat;
		for (int j = 0;j != 10;++j) {
			printf("%d\t", *np++);
		}
		printf("\n");
		mat++;
	}
}


//ָ����ϰ
int main61() {
	int matrix[3][10] = {
		{10},
		{1,2,3,4,5,6},
		{0},
	};
	print_test(matrix, 3);


	int (*p1)[10] = matrix + 1;//p1ָ��matrix�ڶ���������
	//��Ȼint* p1 = matrix + 1;���Ա���ͨ����VS���������Ͻ���p1ָ����int����ʵӦ��������
	printf("matrix[1][0] = %d\n", **p1);//ע��˫�����飬���matrix[1][0]


	int* p2 = *(matrix + 1);//p2ָ��matrix�ڶ����������Ԫ��
	//�൱��int* p2 = matrix[1];
	//�൱��int* p2 = &matrix[1][0];
	printf("matrix[1][0] = %d\n", *p2);


	int* p3 = *(matrix + 1) + 5;//+5���������ַ�н���
	printf("matrix[1][5] = %d\n", *p3);


	int num = *(*(matrix + 1) + 5);
	//�൱��*(matrix[1]+5)
	//�൱��matrix[1][5]
	printf("matrix[1][5] = %d\n", num);


	return 0;
}


//��ά�����ʼ��
void init_test() {
	int four_d[2][2][3][3] = {
		{
			{
				{1,2,3},
				{4,5,6},
				{7,8,9}
			},
			{
				{10,11,12},
				{13,14,15},
				{16,17,18}
			}
		},
		{
			{
				{1,2,3},
				{4,5,6},
				{7,8,9}
			},
			{
				{10,11,12},
				{13,14,15},
				{16,17,18}
			}
		}
	};

	int another_4d[2][2][3][3] = {
		{
			{
				{100}
			}
		},
		{
			{
				{200}
			}
		}
	};
}


int lookup_keyword(char const* const desired_word, 
	char const* keyword_table[], int const size) {
	char const** kwp;
	for (kwp = keyword_table;kwp < keyword_table + size;++kwp) {
		if (strcmp(desired_word, *kwp) == 0) {
			return kwp - keyword_table;
		}
	}
	return -1;
}


int main62() {
	init_test();
	printf("\"if\"����λ�ã�%d\n", lookup_keyword("if", keyword, N_KEYWORD));

	return 0;
}