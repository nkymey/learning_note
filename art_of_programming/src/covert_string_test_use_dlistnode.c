#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lk_debug.h"
#include "test_api.h"

#define DATA_TYPE char

typedef struct DoubleLinkedList
{
	DATA_TYPE data;	// data type.
	struct DoubleLinkedList *pre;
	struct DoubleLinkedList *next;
} DlinkedList_Node;
//typedef DlinkedList_Node *DLinkList_t;

//建立链表
DlinkedList_Node* createDLink(DATA_TYPE *c_data)
{
	DlinkedList_Node *head,*p,*s;
	head = (DlinkedList_Node*)malloc(sizeof(DlinkedList_Node));
	p = head;

	while(*c_data != '\0')
	{
		s = (DlinkedList_Node*)malloc(sizeof(DlinkedList_Node));
		s ->data = *c_data;
		s-> pre = p;
		p->next = s;
		p = s;
		c_data++;
	}
	p->next = NULL;
	head = head ->next;
	head->pre = NULL;

	return head;
}

//顺序、反序打印链表
void printDLink(DlinkedList_Node *head)
{
	DlinkedList_Node *p,*s;
	p = head;
	printf("正序输出双向链表：\n");
	while(p)
	{
		printf("%c",p->data);
		s = p;
		p = p->next;
	}

	printf("\n逆序输出双向链表：\n");
	while(s)
	{
		printf("%c",s->data);
		s = s->pre;
	}
	printf("\n\n");
}
/*
//删除一个结点
DlinkedList_Node* deleteDlinkedList_Node(DlinkedList_Node *head, DATA_TYPE ch)
{
	DlinkedList_Node *p;
	p = head;
	if(p->data == ch)
	{
		head = p->next;
		head->pre = NULL;
		free(p);
		return head;
	}
	while(p)
	{
		if(p->data == ch)
		{
			p->pre->next = p->next;
			p->next->pre = p->pre;
			free(p);
			return head;
		}
		p = p->next;
	}
	printf("没有找到想要删除的数据\n");
	return head;
}

//插入一个结点
DlinkedList_Node* insertDlinkedList_Node(DlinkedList_Node *head,DATA_TYPE i)
{
	DlinkedList_Node *p,*temp;
	p = head;
	temp = (DlinkedList_Node*)malloc(sizeof(DlinkedList_Node));
	temp ->data = i;
	if(i < p->data)//比头结点数据小，插入到链表头部
	{
		head = temp;
		head->next = p;//此处p为原来的head
		head->pre = NULL;
		p->pre = head;//此处p为原来的head
		return head;
	}
	while(p != NULL && i > p->data)//寻找合适的插入位置
	{
		p = p->next;
	}
	if(i < p->data)//在链表中间某处找到合适插入位置
	{
		temp ->next = p;
		temp ->pre = p->pre;
		p ->pre->next = temp;
		p ->pre = temp;
		return head;
	}
	else//没有找到合适的位置，只有将数据插入到链表尾部
	{
		p->next = temp;  //遍历到链表尾部，p==NULL
		temp ->pre = p;
		temp ->next = NULL;
		return head;
	}
}
*/
void convert_string_use_listnode_test(char *str, long num)
{
	DlinkedList_Node *head, *p, *q, *temp;
	_ASSERT((str == NULL));

	head = createDLink(str);
	//printDLink(head);

	if(num < 0)
	{
		num = (-num) % strlen(str);
		num = strlen(str) - num;
	}
	else if(num > 0)
	{
		num = num % strlen(str);
	}
	if(num == 0)
	{
		printDLink(head);
		return;
	}

	_ASSERT((num < 0));
	p = head;
	while((head != NULL) && (num > 0))
	{
		head = head->next;
		num--;
	}
	temp = head->pre;
	head->pre = NULL;
	temp->next = NULL;
	printDLink(head);

	q = head;
	while(q->next != NULL)
		q = q->next;
	q->next = p;
	p->pre = q;
	printDLink(head);
}

