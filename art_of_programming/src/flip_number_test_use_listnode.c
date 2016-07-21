#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lk_debug.h"
#include "test_api.h"

#define DATA_TYPE int

typedef struct SingleList
{
	DATA_TYPE data;	// data type.
	struct SingleList *next;
} SingleNode;
//typedef SingleNode *DLinkList_t;

//建立链表
SingleNode* createSingleLink(DATA_TYPE *data, int len)
{
	SingleNode *head = NULL,*p,*s;
	int i = 0;

	while(i < len)
	{
		s = (SingleNode*)malloc(sizeof(SingleNode));
		if(head == NULL) {
			head = s;
			p = head;
		}
		s->data = *(data + i);
		p->next = s;
		p = s;
		i++;
	}
	p->next = NULL;

	return head;
}

long sizeList(SingleNode *head)
{
	int i = 0;
	while(head->next != NULL)
	{
		i++;
		head = head->next;
	}
	return i;
}

//打印链表
void printSingleLink(SingleNode *head)
{
	SingleNode *p;
	p = head;
	printf("输出链表：\n");
	while(p != NULL)
	{
		printf("%2d",p->data);
		p = p->next;
	}

	printf("\n");
}

void deleteSingleLink(SingleNode **head)
{
	SingleNode *tmp = NULL;
	while(*head != NULL)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void reverseListNodeByPosition(SingleNode **pHead, long pos)
{
	SingleNode *p, *q, *tmp;
	long i = 1;

	if(pos < 1 || pos > sizeList(*pHead))
		return;

	p = *pHead;
	while(p->next != NULL)
	{
		i++;
		if(i <= pos)
		{
			q = p->next;
			p->next = q->next;
			q->next = *pHead;
			*pHead = q;
		}
		else if(i == pos + 1)
		{
			tmp = p;
			p = p->next;
		}
		else
		{
			q = p->next;
			p->next = q->next;
			q->next = tmp->next;
			tmp->next = q;
		}
	}
}

void flip_number_use_listnode_test(int *array_num, long len, long num)
{
	SingleNode *head;
	_ASSERT((array_num == NULL));

	head = createSingleLink(array_num, len);
	printSingleLink(head);
	lk_print("Initial convert array.\n");

	_ASSERT((num < 0));
	if(num < 0)
	{
		return;
	}
	else if(num > 0)
	{
		num = num % len;
	}
	if(num == 0)
	{
		printSingleLink(head);
		return;
	}

	reverseListNodeByPosition(&head, 4);
	printSingleLink(head);
	deleteSingleLink(&head);
}

