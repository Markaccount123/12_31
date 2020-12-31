#include"List.h"
void TestList1()
{
	//这里还可以不传地址，我让他返回新的地址就可以了
	//ListNode* phead = NULL;
	//ListInit(&phead);
	ListNode*  phead = ListInit();
	ListPushBack(phead, 1);
	ListPushBack(phead, 2);
	ListPushBack(phead, 3);
	ListPushBack(phead, 4);

	ListPrint(phead);
	printf("\n");

	//当你这里删除1,2,3,4都是可以的，但是当你删除5个的时候程序就会出现崩溃，因为此时链表已经为空了，你还要删除，所以需要添加判断是否为空的代码
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

//链表和顺序表（数组）的区别和联系（也就是分别说一下他们各自的优缺点）
//a.可能存在一定的空间浪费
//b.增容有一些效率的损失
//c.中间或者头部插入删除，时间复杂度为O(N),因为要挪动数据。

//链表的唯一缺陷就是：不能够做到随机访问，但是顺序表可以