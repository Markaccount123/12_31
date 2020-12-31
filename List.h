#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int LTDateType;
//对于双向链表来说特点：结构复杂，但是操作简单

//双向链表里面所包含的东西
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDateType date;
}ListNode;
//整体清除（彻底删除，包括哨兵位的头结点）
//初始化
//void ListInit(ListNode* phead);
ListNode* ListInit();
//这里的两种情况可以理解为购物车
//整体清除（彻底删除，包括哨兵位的头结点）
void ListDestory(ListNode** pphead);
//删除链表（保留下哨兵位的头结点，为了后续的继续使用）
void ListClear(ListNode* phead);
//尾插
void ListPushBack(ListNode* phead, LTDateType x);
//创建结点
ListNode* BuyListNode(LTDateType x);
//打印
void ListPrint(ListNode* phead);
//尾删
void ListPopBack(ListNode* phead);
//头插
void ListPushFront(ListNode* phead, LTDateType x);
//头删
void ListPopFront(ListNode* phead);
//查找(返回的是查找到那个结点的地址)
ListNode* ListFind(ListNode* phead, LTDateType x);
//中间插入
void ListInsert(ListNode* pos, LTDateType x);
//中间删除
void ListErase(ListNode* pos);
