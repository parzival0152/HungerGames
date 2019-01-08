#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct
{
	char * name;
	int id;
	struct Person *next;
}Person;


/************************
Ilay Tzuberi
211873286
83-120-05
*************************/

int main()
{
	char str[] = "fuck";
	Person man;
	man.id = 5;
	man.name = str;
	printf("%d\n",man.id);
	printf("%s\n",man.name);
	system("pause");
	return 0;
}