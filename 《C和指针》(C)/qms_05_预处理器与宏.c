#//��Чָ�ͻ������
#include<stdio.h>
#include<stdarg.h>
#

//�е�ţ��
#define reg register
#define do_forever for(;;)
#define CASE break;case


//д��б��������
//ע��define���ֲ�д�ֺţ�ʹ��ʱ��Ҫд�ֺţ���ȫд����ֿ����
#define DEBUG_PRINT printf("File %s \nline %d\ndate %s\ntime %s\n"\
											"x = %d,y = %d,z = %d\n",\
											__FILE__,__LINE__,__DATE__,__TIME__, \
											x,y,z)


int main() {
	int x = 12, y = 4, z = 3;
	x *= 2;
	y += x;
	z = y * x;
	DEBUG_PRINT;
	return 0;
}


#define BAD_SQUARE(x) x*x
#define SQUARE(x) (x)*(x)


int main52() {
	int a = 5;
	printf("6*6 = %d\n", BAD_SQUARE(a + 1));//���ʲô��
	//�൱��printf("6*6 = %d\n",a+1*a+1)
	printf("6*6 = %d\n", SQUARE(a + 1));//���ʲô��
	return 0;
}


#define BAD_DOUBLE(x) (x)+(x)
#define DOUBLE(x) ((x)+(x))


int main53() {
	int a = 5;
	printf("10*10 = %d\n", 10 * BAD_DOUBLE(5));//˵����
	printf("10*10 = %d\n", 10 * DOUBLE(5));

	return 0;
}


#define repeat do
#define until(x) while(!(x))


int main54() {
	int a = 0;

	//������������
	repeat{
		printf("I love C!\n");
		a++;
	}until(a == 10);

	return 0;
}


#define PRINT_1(FOMAT,VALUE) printf("the value is " FOMAT "\n",VALUE)
//#�������ת��Ϊһ���ַ���
#define PRINT_2(FOMAT,VALUE) printf("the value of "#VALUE" is "FOMAT"\n",VALUE)
//##�����ߵķ���ת����һ������
#define ADD_TO_SUM(sum_number,value) \
			sum ## sum_number += value


int main55() {
	int x = 3;
	PRINT_1("%d", x + 3);
	PRINT_2("%d", x + 3);

	int sum5 = 5;
	ADD_TO_SUM(5, 25);
	PRINT_2("%d", sum5);

	return 0;
}


//��������Ƶ����ʮ�ּ򵥵ļ���
//�ʵ��ĺ�Ⱥ����ڳ����ģ���ٶȷ��涼��ʤһ��
//���������޹أ��Ⱥ������������
#define MAX(a,b) ((a)>(b)?(a):(b))
//�����ʵ�ֺ����޷�ʵ�ֵĹ��ܣ����£�������type
#define MALLOC(num,type) (type*)alloc((num)*sizeof(type))
#define DEGUG 1


#if DEGUG==1
//��������
	#if defined(DEGUG)
		#ifdef DEGUG
		int main56() {
			int x = 5, y = 8;
			int z = MAX(x++, y++);
			printf("x = %d\ny = %d\nz = %d\n", x, y, z);//���ʲô��˵����

			return 0;
		}
		#endif//DEGUG
	#endif//defined(DEGUG)
#elif DEBUG==-1
int main() {
	printf("this can't be seen.");
	return 0;
}
#error DEBUG==-1!
//#errorָ���������ɴ�����Ϣ
#else
int main() {
	printf("this can't be seen,too.");
	return 0;
}
#error something went wrong!
#endif



//ʵ�ֲ��̶����������ĺ���
static float average(int n, ...) {
	va_list var_arg;
	float sum = 0;

	va_start(var_arg, n);//...ǰ���һ�������ֵĲ���

	for (int count = 0;count < n;count++) {
		//���ʲ���
		sum += va_arg(var_arg, int);//va_list�������б�����һ����������
		//va_arg�������������ֵ����ʹvar_argָ����һ���ɱ����
	}

	va_end(var_arg);//��ɴ���

	return sum / n;
}


int main510000() {
	float result = average(3, 2, 1, 22, 2);
	printf("average value = %g\n", result);
	return 0;
}