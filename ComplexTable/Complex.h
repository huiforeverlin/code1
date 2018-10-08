#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct CSListNode
{
    DataType data;
    struct CSListNode *pNext;
    struct CSListNode *pRandom;
}CSListNode;

//申请新空间
CSListNode *BuyNewNode(DataType data)
{
    CSListNode *pNewNode = (CSListNode *)malloc(sizeof(CSListNode));
    assert(pNewNode);
    pNewNode->data = data;
    pNewNode->pNext = NULL;
    pNewNode->pRandom = NULL;
    return pNewNode;
}

//复杂链表的复制
CSListNode *CopyComplexSList(CSListNode *pFirst)
{
    CSListNode *pNewNode = NULL;
    CSListNode *pNewHead = NULL;
    CSListNode *pNode = pFirst;
    while (pNode)
    {
	pNewNode = BuyNewNode(pNode->data);
	pNewNode->pNext = pNode->pNext;
	pNode->pNext = pNewNode;
	pNode = pNewNode->pNext;
    }

    pNode = pFirst;
    while (pNode)
    {
	pNewNode = pNode->pNext;
	if (pNode->pRandom)
	{
	    pNewNode->pRandom = pNode->pRandom->pNext;
	}
	pNode = pNewNode->pNext;

    }

    pNode = pFirst;
    pNewHead = pFirst->pNext;
    while (pNode->pNext)
    {
	pNewNode = pNode->pNext;
	pNode->pNext = pNewNode->pNext;
	pNode = pNewNode;
    }
    return pNewHead;
}

void test()
{
    CSListNode *s1 = BuyNewNode(1);
    CSListNode *s2 = BuyNewNode(2);
    CSListNode *s3 = BuyNewNode(3);
    CSListNode *s4 = BuyNewNode(4);

    s1->pNext = s2;
    s2->pNext = s3;
    s3->pNext = s4;

    s1->pRandom = s2;
    s2->pRandom = s1;
    s3->pRandom = s3;
    s4->pRandom = NULL;

    CopyComplexSList(s1);
}
