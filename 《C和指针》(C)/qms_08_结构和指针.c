#include<stdio.h>

typedef struct {
	int a;
	short b[2];
}Ex2;


typedef struct Ex_tag{
	int a;
	char b[3];
	Ex2 c;
	struct Ex_tag* d;
}Ex;


int main8() {
	Ex x = { 10,"hi",{5,{-1,25}},NULL };
	Ex* px;

	//px
	px = &x;//��px��ָ���Լ���ַ
	int address = px;//��px��ʾx��ַ
	printf("address = %d\n", address);

	//px+1
	//��px+1��ʾx��һ���ĵ�ַ���Ƿ�
	//��px+1�����ǵ�ַ���Ƿ�

	//*px
	Ex y = *px;//��*px��ʾ����x�ṹ
	printf("(*px).a = %d\n", y.a);
	(*px).a = 10;//��*px��x�ĵ�ַ

	//*px+1��*(px+1)
	//���ʽ*px+1�Ƿ����ṹ�����ͼӷ�δ����
	//���ʽ*(px+1)��ʾx��һ���ṹ���Ƿ�

	//px,&px->a
	//��px,&px->a��ʾͬһ����ַ,�����Ͳ�ͬ
	int* ip = &px->a;//ע������
	Ex* px_2 = px;//ע������
	int address1 = ip;
	int address2 = px_2;
	printf("ip = %d\npx_2 = %d\n", address1, address2);

	//*(px->b),px->b[1],*((px->b)+1)
	//˵����
	char c1 = *(px->b), c2 = px->b[1], c3 = *((px->b) + 1);
	printf("*(px->b) = %c\n", c1);
	printf("px->b[1] = %c\n", c2);
	printf("*((px->b)+1) = %c\n", c3);

	//px->c.a
	//˵����
	int i1 = px->c.a;
	printf("px->c.a = %d\n", i1);

	//*px->c.b
	//�൱��*((px->c).b)
	int i2 = *px->c.b;
	printf("*px->c.b = %d\n", i2);

	//*px->d
	Ex z = { 100,"by",{50,{-10,250}},NULL };
	x.d = &z;
	Ex z_2 = *px->d;//��*px->d��ʾһ���ṹ
	printf("z_2.a = %d\n", z_2.a);

	//px->d->c.b[1]
	int i3 = px->d->c.b[1];
	printf("*px->d->c.b[1] = %d\n", i3);

	return 0;
}