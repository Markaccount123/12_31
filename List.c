#include"List.h"

//�ڱ�λ��ͷ����ʼ��
//void ListInit(ListNode** pphead)
//{
//	//����Ҫ�������ȼ����������*��->���ǽ�����Ҫ�Ƚ�����һ����Ϊ�˱�������ã���
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
//��ӡ
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

//������㣨������Ҫ���ش���������½��ĵ�ַ��
ListNode* BuyListNode(LTDateType x)
{
	//ֻҪ��malloc������һ��Ҫ�����ʼ��
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->next = NULL;
	node->prev = NULL;
	node->date = x;
	return node;
}

//β��(����Ĳ����ǲ����ܸı�phead���ͷ���ģ��������ﲻ��Ҫ������ָ��)
void ListPushBack(ListNode* phead, LTDateType x)
{
	//assert(phead);
	////����β
	//ListNode* tail = phead->prev;
	////�������
	//ListNode* newNode = BuyListNode(x);

	//tail->next = newNode;
	//newNode->prev = tail;

	//newNode->next = phead;
	//phead->prev = newNode;

	ListInsert(phead, x);
}

//βɾ
void ListPopBack(ListNode* phead)
{
	//assert(phead);
	//assert(phead->next != phead); //�����Ѿ�Ϊ���ˣ��㻹
	//ListNode* tail = phead->prev;
	//ListNode* tailPrev = tail->prev; //��һ�������˴���Ŀɶ���,������-> ->���ν�����

	//phead->prev = tailPrev;
	//tailPrev->next = phead;
	//free(tail);
	//tail = NULL;

	ListErase(phead->prev);
}

//ͷ��
void ListPushFront(ListNode* phead, LTDateType x)
{
	//assert(phead);
	//ListNode* newNode = BuyListNode(x);
	//ListNode* first = phead->next;
	//phead->next = newNode;
	//newNode->prev = phead;
	////����滹��Ҫ���ǵ��������½�����һ��֮��Ĺ�ϵ
	//newNode->next = first;
	//first->prev = newNode;

	
	 ListInsert(phead->next, x);
}

//ͷɾ
void ListPopFront(ListNode* phead)
{
	//assert(phead);
	////����զ���������ܰ�����ڱ�λ��ͷ���ɾ����
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

//���ң�������Insert��Erase����Ҫ�ҵ��Ǹ���㣬Ȼ���ڲ�����
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

//�м����
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

//�м�ɾ��
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

//ɾ�������������ڱ�λͷ��㣬�൱���������������ݣ�
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
	//����˫������Ľṹ�ص�
	phead->next = phead;
	phead->prev = phead;
}

//ɾ����������ɾ���������ڱ�λ��ͷ��㣬�൱�������ɵ��ܳ��ף�
void ListDestory(ListNode** pphead)
{
	//����
	ListClear(*pphead);
	free(*pphead);
	*pphead = NULL;
}