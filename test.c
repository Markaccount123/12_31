#include"List.h"
void TestList1()
{
	//���ﻹ���Բ�����ַ�������������µĵ�ַ�Ϳ�����
	//ListNode* phead = NULL;
	//ListInit(&phead);
	ListNode*  phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);

	ListPrint(phead);
	printf("\n");

	//��������ɾ��1,2,3,4���ǿ��Եģ����ǵ���ɾ��5����ʱ�����ͻ���ֱ�������Ϊ��ʱ�����Ѿ�Ϊ���ˣ��㻹Ҫɾ����������Ҫ����ж��Ƿ�Ϊ�յĴ���
	ListPopBack(phead);
	ListPopBack(phead);
	ListPrint(phead);
	printf("\n");

	ListPushFront(phead, 6);
	ListPushFront(phead, 7);
	ListPrint(phead);
	printf("\n");

	ListPopFront(phead);
	ListPrint(phead);
	printf("\n");

	ListDestory(&phead);
}

void TestList2()
{
	ListNode*  phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);
	ListPrint(phead);
	printf("\n");

	ListNode* pos = ListFind(phead, 3);
	ListInsert(pos, 7);
	ListPrint(phead);
	printf("\n");

	ListErase(pos);
	ListPrint(phead);
	printf("\n");

	ListDestory(&phead);

}

int main()
{
	TestList1();
	//TestList2();

	return 0;
}

//�����˳������飩���������ϵ��Ҳ���Ƿֱ�˵һ�����Ǹ��Ե���ȱ�㣩
//a.���ܴ���һ���Ŀռ��˷�
//b.������һЩЧ�ʵ���ʧ
//c.�м����ͷ������ɾ����ʱ�临�Ӷ�ΪO(N),��ΪҪŲ�����ݡ�

//�����Ψһȱ�ݾ��ǣ����ܹ�����������ʣ�����˳������