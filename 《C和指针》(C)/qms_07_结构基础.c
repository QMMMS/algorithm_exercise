#include<stdio.h>


struct SIMPLE_1 {
	int a;
	char b;
	float c;
};


//��һ�ֽṹ���巽ʽ
typedef struct  {
	int a;
	char b;
	float c;
}SIMPLE_2;


struct COMPLEX {
	float f;
	int a[10];
	long* lp;
	struct SIMPLE_1 s;
	SIMPLE_2 sa[10];
	SIMPLE_2* sp;
};


//�ṹ�������ã�ע��ָ��
struct SELF_REF {
	int a;
	struct SELF_REF *b;
	int c;
};


/*
����ʾ����EXAMPLEֱ�������ж��壡
typedef struct {
	int a;
	EXAMPLE* b;
	int c;
}EXAMPLE;
*/


//��ȷʾ��
typedef struct EXAMPLE_TAG {
	int a;
	struct EXAMPLE_TAG* b;
	int c;
}EXAMPLE;


//�ṹ�������
struct b;

struct a {
	struct b* partner_b;
};

struct b {
	struct a* partner_a;
};


int main7() {
	struct SIMPLE_1 sim;
	SIMPLE_2 sim2;
	struct COMPLEX comp;

	//���ݽṹ�ļ���
	struct SELF_REF sel00 = { 200,NULL,100 };
	struct SELF_REF sel0 = { 20,&sel00,10 };
	struct SELF_REF sel = { 2,&sel0,1 };


	comp.sa[4].c = 1.2;
	printf("comp.sa[4].c = %g\n", comp.sa[4].c);


	struct COMPLEX* cp = &comp;
	printf("cp->sa[4].c = %g\n", cp->sa[4].c);


	printf("sel.b->b->a = %d\n", sel.b->b->a);

	return 0;
}