#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkstack.h"

int main() 
{
	int i = 0;
	int a[10];
	LinkStack *stack = NULL;
	stack = LinkStack_Create();
	if (stack == NULL)
	{
		return;
	}

	for (; i < 10; i++)
	{
		a[i] = i + 1;
		LinkStack_Push(stack,&a[i]);
	}

	printf("length:%d \n",LinkStack_Size(stack));
	printf("Õ»¶¥ÔªËØ :%d \n",*( (int*)LinkStack_Top(stack) ) );

	while (LinkStack_Size(stack) > 0)
	{
		int tmp = *((int*)LinkStack_Pop(stack));
		printf("%d \n",tmp);
	}

	LinkStack_Destroy(stack);

	return 0;
}