//ע�⣬���C�ļ���visual studio ����ͨ��
//ʹ����������Ҫ�� scanf_s ��Ϊ scanf
//scanf_sΪvisual studio ���У������ź���Ҳ�����bug�����������������̣�
//��ô�����


//������
//������ų���
//�û�����
//�ļ�д���ȡ

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_STUDENTS 2//������ų���


int main11(int argc, char* argv[]) {
	/* �ҵĵ�һ�� C ���� */
	printf("hello, world");
	printf("��ִ�г��� %s ,��������Ϊ[%d], ���������[%s]\n"
		, argv[0], argc, argv[1]);
	return 0;
}


//�û�����
int main12() {
	int int1, int2, int3;
	double flo1 = 0.0;
	scanf_s("%d", &int1);
	scanf_s("%d%d", &int2,&int3);

	printf("you give three nums:%d,%d,%d\n",int1,int2,int3);


	flo1 = (int1 + int2) / 2;
	printf("%.2f", flo1);
	return 0;
}


int main13(void) {
	float a_grade[5] = { 66.4,33.5,22.123,33.1,23.0 };
	float max = 0, min = 100;
	int i = 0;
	do {
		printf("%.2f ", a_grade[i]);
		if (a_grade[i] > max) {
			max = a_grade[i];
		}
		if (a_grade[i] < min) {
			min = a_grade[i];
		}
		++i;
	} while (i != 5);
	printf("\n");

	printf("max:%.2f\n", max);
	printf("min:%.2f\n", min);

	return 0;
}


struct Student {
	char name[20];
	int age;
	float score;
};


int main14(void) {
	struct Student AQ,QMS;
	scanf("%s%d%f", &AQ.name, &AQ.age, &AQ.score);//����ֵ�������
	printf("%s\n%d\n%.2f\n", AQ.name, AQ.age, AQ.score);
	QMS = AQ;
	printf("%s\n%d\n%.2f\n", QMS.name, QMS.age, QMS.score);

	return 0;
}


int main15(void) {
	int course_num;
	printf("input number of course:");
	scanf("%d", &course_num);
	float* Scores = (float*)malloc(sizeof(float) * course_num);

	printf("input score of %d courses:",course_num);
	for (int i = 0;i != course_num;++i) {
		 scanf("%f", &Scores[i]);
	}

	float sum = 0;
	for (int i = 0;i != course_num;++i) {
		sum += Scores[i];//�������
	}
	printf("total score is %.2f", sum);
	free(Scores);

	return 0;
}


//�ļ�д���ȡ������
//�и����⣬c�ܿ����ļ����˲��ܣ������
int main16(void) {
	struct Student class_5_students[NUM_OF_STUDENTS];

	for (int i = 0;i != NUM_OF_STUDENTS;++i) {
		printf("input information of "
			"no.%d student(total %d)(name, age, score) :\n", (i + 1),NUM_OF_STUDENTS);
		scanf("%s%d%f", &class_5_students[i].name, 
			&class_5_students[i].age, &class_5_students[i].score);
	}

	FILE* fp;
	if ((fp = fopen("file1.txt", "wb")) == NULL) {
		printf("error! can't open target file!\n");
		printf("\n\npress any key to continue...");
		getch();
		exit(1);
	}

	fwrite(class_5_students, sizeof(struct Student), NUM_OF_STUDENTS, fp);
	fclose(fp);
	printf("saved successfully!");


	printf("\n\npress any key to continue...");
	getch();
	return 0;
}


int  main17() {
	struct Student students[NUM_OF_STUDENTS];
	FILE* fp;
	if ((fp = fopen("file1.txt", "rb")) == NULL) {
		printf("error! can't open target file!\n");
		printf("\n\npress any key to continue...");
		getch();
		exit(1);
	}

	fread(students, sizeof(struct Student), NUM_OF_STUDENTS, fp);
	for (int i = 0;i != NUM_OF_STUDENTS;++i) {
		printf("%s\n%d\n%.2f\n", students[i].name, students[i].age, students[i].score);
	}
	fclose(fp);


	printf("\n\npress any key to continue...");
	getch();
	return 0;
}

