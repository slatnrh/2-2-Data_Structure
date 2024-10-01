#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
} student;

int main(void){
	student *p;

	p = (student*)malloc(sizeof(student));
	if (p == NULL) {
		fprintf(stderr, "exceed the scope\n");
		exit(1);
	}

	strcpy(p->name, "Park");
	p->age = 20;

    printf("%s, %d\n", p->name, p->age);

	free(p);
	return 0;
}