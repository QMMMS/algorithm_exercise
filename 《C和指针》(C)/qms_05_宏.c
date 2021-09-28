#include<stdio.h>
#include<stdarg.h>

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

int main5() {
	float result = average(3, 2, 1, 22, 2);
	printf("average value = %g\n", result);
}