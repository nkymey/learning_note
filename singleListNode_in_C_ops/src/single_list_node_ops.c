#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lk_debug.h"

typedef int elemType;

/************************************************************************/
/*             以下是关于线性表链接存储（单链表）操作的18种算法        */
/* 1.初始化线性表，即置单链表的表头指针为空 */
/* 2.创建线性表 */
/* 3.打印链表，链表的遍历 */
/* 4.清除线性表L中的所有元素，即释放单链表L中所有的结点，使之成为一个空表 */
/* 5.返回单链表的长度 */
/* 6.检查单链表是否为空，若为空则返回１，否则返回０ */
/* 7.返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 */
/* 8.从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL */
/* 9.把单链表中第pos个结点的值修改为x的值，若修改成功返回１，否则返回０ */
/* 10.向单链表的表头插入一个元素 */
/* 11.向单链表的末尾添加一个元素 */
/* 12.向单链表中第pos个结点位置插入元素为x的结点，若插入成功返回１，否则返回０ */
/* 13.向有序单链表中插入元素x结点，使得插入后仍然有序 */
/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */
/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */
/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
/* 17.从单链表中删除值为x的第一个结点，若删除成功则返回1,否则返回0 */
/* 18.交换2个元素的位置 */
/* 19.将线性表进行快速排序 */
/************************************************************************/

/* 定义单链表结点类型 */
typedef struct Node {
	elemType element;
	struct Node *next;
} Node_t;

/* 1.初始化线性表，即置单链表的表头指针为空 */
void initList(Node_t **pNode)
{
	*pNode = NULL;
	lk_print("done\n");
}

/* 2.创建线性表 */
Node_t *createList(Node_t *pHead, elemType *data, long lengh)
{
	Node_t *p, *p1;
	long i = 0;

	while(i < lengh)
	{
		p1 = (Node_t *)malloc(sizeof(Node_t));	//申请一个节点
		if(p1 == NULL)
		{
			lk_print("Memory allocate failed, exit(0).\n");
			exit(0);
		}
		memset(p1, 0, sizeof(Node_t));
		p1->element = *(data + i);
		p1->next = NULL;
		if(pHead != NULL)
			p->next = p1;	//非空表，接入表尾
		else
			pHead = p1;		//空表，接入表头
		p = p1;
		i++;
	}
	lk_print("done\n");
	return pHead;
}

/* 3.打印链表，链表的遍历*/
void printList(Node_t *pHead)
{
	if(NULL == pHead)
	{
		lk_print("pHead is null, return.\n");
		return;
	}
	else
	{
		do
		{
			printf("%d ", pHead->element);
			pHead = pHead->next;
		} while(NULL != pHead);
		printf("\n");
	}
	lk_print("done\n");
}

/* 4.清除线性表L中的所有元素，即释放单链表L中所有的结点，使之成为一个空表 */
void clearList(Node_t *pHead)
{
	Node_t * pNext;
	if(pHead == NULL)
	{
		lk_print("pHead is null, return.\n");
		return;
	}
	else
	{
		do
		{
			pNext = pHead->next;
			free(pHead);
			pHead = pNext;
		} while(pHead != NULL);
	}
	lk_print("done\n");
}

/* 5.返回单链表的长度 */
long sizeList(Node_t *pHead)
{
	long size = 0;
	while(pHead != NULL)
	{
		size++;
		pHead = pHead->next;
	}
	return size;
}

/* 6.检查单链表是否为空，若为空则返回１，否则返回０ */
/* 7.返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行 */
elemType getElement(Node_t *pHead, long pos)
{
	long i = 1, lenOfList;
	Node_t *p;
	lenOfList = sizeList(pHead);
	if(pos < 1 || pos > lenOfList || pHead == NULL)
	{
		lk_print("pos < 1 or pHead = null, return.\n");
		return 0;
	}
	p = pHead;
	while(i < pos)
	{
		p = p->next;
		i++;
	}
	return p->element;
}

/* 8.从单链表中查找具有给定值x的第一个元素，若查找成功则返回该结点data域的存储地址，否则返回NULL */
elemType *getDataFromList(Node_t *pHead, elemType x)
{
	Node_t *p;
	p = pHead;
	while(p != NULL)
	{
		if(p->element == x)
			break;
		p = p->next;
	}
	if(p == NULL)
		return NULL;
	return &p->element;
}

/* 9.把单链表中第pos个结点的值修改为x的值，若修改成功返回１，否则返回０ */
int setDataByPosition(Node_t *pHead, long pos, elemType x)
{
	Node_t *p;
	long i = 1;

	p = pHead;
	if(p == NULL || pos < 1 || pos > sizeList(p))
		return 0;
	while(i < pos && p != NULL)
	{
		p = p->next;
		i++;
	}
	p->element = x;
	return 1;
}

/* 10.向单链表的表头插入一个元素 */
int insertHeadNode(Node_t **pHead, elemType insertElem)
{
	Node_t *insertNode;

	if(pHead == NULL)
		return 0;
	insertNode = (Node_t *)malloc(sizeof(Node_t));
	if(insertNode == NULL)
		return 0;
	insertNode->element = insertElem;
	insertNode->next = *pHead;
	*pHead = insertNode;

	return 1;
}

/* 11.向单链表的末尾添加一个元素 */
int insertLastNode(Node_t **pHead, elemType insertElem)
{
	Node_t *insertNode, *p;

	p = *pHead;
	if(p == NULL)
		return 0;
	insertNode = (Node_t *)malloc(sizeof(Node_t));
	if(insertNode == NULL)
		return 0;
	insertNode->element = insertElem;
	while(p->next != NULL)
		p = p->next;
	p->next = insertNode;
	insertNode->next = NULL;

	return 1;
}

/* 12.向单链表中第pos个结点位置插入元素为x的结点，若插入成功返回１，否则返回０ */
int insertNodeByPosition(Node_t **pHead, long pos, elemType x)
{
	Node_t *insertNode, *p;
	long i = 1;

	p = *pHead;
	if(p == NULL || pos < 0 || (pos > sizeList(*pHead) + 1))
		return 0;
	insertNode = (Node_t *)malloc(sizeof(Node_t));
	if(insertNode == NULL)
		return 0;
	insertNode->element = x;
	if(pos == 0)
	{
		insertNode->next = *pHead;
		*pHead = insertNode;
		return 1;
	}
	while(i < pos - 1)
	{
		p = p->next;
		i++;
	}
	insertNode->next = p->next;
	p->next = insertNode;

	return 1;
}

/* 13.向有序单链表中插入元素x结点，使得插入后仍然有序 */

/* 14.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行 */

/* 15.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行 */

/* 16.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行 */
int deleteNodeByPosition(Node_t **pHead, long pos)
{
	Node_t *delNode, *p;
	long i = 1;

	p = *pHead;
	if(p == NULL || pos < 0 || pos > sizeList(p))
		return 0;
	if(pos == 0)
	{
		*pHead = (*pHead)->next;
		free(p);
		return 1;
	}
	while(i < pos - 1)
	{
		p = p->next;
		i++;
	}
	delNode = p->next;
	p->next = delNode->next;
	free(delNode);

	return 1;
}

/* 17.从单链表中删除值为x的第一个结点，若删除成功则返回1,否则返回0 */

/* 18.交换2个元素的位置 */
int swapTwoNodeElemInList(Node_t **pHead, long pos_m, long pos_n)
{
	Node_t *p1, *p2;
	elemType temp;
	long i = 1;

	p1 = *pHead;
	if(pos_m > pos_n)
	{
		i = pos_m;
		pos_m = pos_n;
		pos_n = i;
	}
	if((p1 == NULL) || (pos_m == pos_n) || pos_m < 1 || pos_n > sizeList(p1))
		 return 0;
	//printf("pos_m:%ld, pos_n:%ld.\n", pos_m, pos_n);
	i = 1;
	while(i++ < pos_m) p1 = p1->next;
	p2 = p1->next;
	while(i++ < pos_n) p2 = p2->next;

	temp = p1->element;
	p1->element = p2->element;
	p2->element = temp;

	return 1;
}

/* 19.将线性表进行快速排序 */

/* List Node Test function */
void list_node_test(void)
{
	Node_t *pList = NULL;
	elemType data[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	elemType *ret_data;

	initList(&pList);
	pList = createList(pList, data, 10L);
	printList(pList);
	lk_print("The size of pList: %ld.\n", sizeList(pList));
	lk_print("getElement(pList, 4) = %d.\n", getElement(pList, 4));
	ret_data = getDataFromList(pList, 4);
	lk_print("ret_data[4] = %d.\n", *ret_data);
	setDataByPosition(pList, 4, 0);
	printList(pList);
	insertHeadNode(&pList, 9);
	lk_print("The size of pList: %ld.\n", sizeList(pList));
	printList(pList);
	insertLastNode(&pList, 0);
	printList(pList);
	lk_print("The size of pList: %ld.\n", sizeList(pList));
	insertNodeByPosition(&pList, 14, 8);
	printList(pList);
	deleteNodeByPosition(&pList, 12);
	printList(pList);
	swapTwoNodeElemInList(&pList, 10, 10);
	printList(pList);
	clearList(pList);
	lk_print("done\n");
}
