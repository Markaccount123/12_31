#include"List.h"

//哨兵位的头结点初始化
//void ListInit(ListNode** pphead)
//{
//	//这里要考虑优先级的问题你的*和->都是解引用要先进行哪一步，为了避免出错，用（）
//	*pphead = BuyListNode(0);
//	(*pphead)->next = *pphead;
//	(*pphead)->prev = *pphead;
//}
ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
//打印
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
}

//创建结点（最终我要返回创建的这个新结点的地址）
ListNode* BuyListNode(LTDateType x)
{
	//只要是malloc出来的一定要对其初始化
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->date = x;
	return node;
}

//尾插(这里的操作是不可能改变phead这个头结点的，所以这里不需要传二级指针)
void ListPushBack(ListNode* phead, LTDateType x)
{
	//assert(phead);
	////先找尾
	//ListNode* tail = phead->prev;
	////创建结点
	//ListNode* newNode = BuyListNode(x);

	//tail->next = newNode;
	//newNode->prev = tail;

	//newNode->next = phead;
	//phead->prev = newNode;

	ListInsert(phead, x);
}

//尾删
void ListPopBack(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead); //链表已经为空了，你还
	//ListNode* tail = phead->prev;
	//ListNode* tailPrev = tail->prev; //这一句增加了代码的可读性,避免了-> ->两次解引用

	//phead->prev = tailPrev;
	//tailPrev->next = phead;
	//free(tail);
	//tail = NULL;

	ListErase(phead->prev);
}

//头插
void ListPushFront(ListNode* phead, LTDateType x)
{
	//assert(phead);
	//ListNode* newNode = BuyListNode(x);
	//ListNode* first = phead->next;
	//phead->next = newNode;
	//newNode->prev = phead;
	////你后面还需要考虑到你插入的新结点和下一个之间的关系
	//newNode->next = first;
	//first->prev = newNode;

	
	 ListInsert(phead->next, x);
}

//头删
void ListPopFront(ListNode* phead)
{
	//assert(phead);
	////不管咋样链表都不能把这个哨兵位的头结点删除掉
	//assert(phead->next != phead);
	////phead first second
	//ListNode* first = phead->next;
	//ListNode* second = first->next;
	//phead->next = second;
	//second->prev = phead;
	//free(first);
	//first = NULL;

	ListErase(phead->next);
}

//查找（你后面的Insert和Erase都是要找到那个结点，然后在操作）
ListNode* ListFind(ListNode* phead, LTDateType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->date == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

//中间插入
void ListInsert(ListNode* pos, LTDateType x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newNode = BuyListNode(x);

	//posPrev newNode pos
	posPrev->next = newNode;
	newNode->prev = posPrev;
	newNode->next = pos;
	pos->prev = newNode;
}

//中间删除
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	pos = NULL;
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

//删除链表（保留了哨兵位头结点，相当于清理掉里面的数据）
void ListClear(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	//保持双向链表的结构特点
	phead->next = phead;
	phead->prev = phead;
}

//删除链表（彻底删除，包括哨兵位的头结点，相当于整个干掉很彻底）
void ListDestory(ListNode** pphead)
{
	//销毁
	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
}