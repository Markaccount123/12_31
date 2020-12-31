#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
typedef int LTDateType;
//����˫��������˵�ص㣺�ṹ���ӣ����ǲ�����

//˫�����������������Ķ���
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDateType date;
}ListNode;
//�������������ɾ���������ڱ�λ��ͷ��㣩
//��ʼ��
//void ListInit(ListNode* phead);
ListNode* ListInit();
//�������������������Ϊ���ﳵ
//�������������ɾ���������ڱ�λ��ͷ��㣩
void ListDestory(ListNode** pphead);
//ɾ�������������ڱ�λ��ͷ��㣬Ϊ�˺����ļ���ʹ�ã�
void ListClear(ListNode* phead);
//β��
void ListPushBack(ListNode* phead, LTDateType x);
//�������
ListNode* BuyListNode(LTDateType x);
//��ӡ
void ListPrint(ListNode* phead);
//βɾ
void ListPopBack(ListNode* phead);
//ͷ��
void ListPushFront(ListNode* phead, LTDateType x);
//ͷɾ
void ListPopFront(ListNode* phead);
//����(���ص��ǲ��ҵ��Ǹ����ĵ�ַ)
ListNode* ListFind(ListNode* phead, LTDateType x);
//�м����
void ListInsert(ListNode* pos, LTDateType x);
//�м�ɾ��
void ListErase(ListNode* pos);
