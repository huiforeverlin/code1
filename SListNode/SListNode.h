#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

typedef int DataType;

typedef struct SListNode
{
    DataType data;
    struct SListNode *pNext;
} SListNode;


//申请新空间
SListNode *__CreatNewNode(DataType data)
{
    SListNode *pNewNode = (SListNode *)malloc(sizeof(SListNode));
    assert(pNewNode);

    pNewNode->data = data;
    pNewNode->pNext = NULL;

    return pNewNode;
}


//打印函数
void SListNodePrint(SListNode **ppfirst)
{
    SListNode *pNode;
    for (pNode = *ppfirst; pNode != NULL; pNode = pNode->pNext)
    {
	printf("%d -> ", pNode->data);
    }
    printf("NULL\n");
}

void SListPushBack(SListNode **ppfirst, DataType data);
void SListPushFront(SListNode **ppfirst, DataType data);
void SListPopBack(SListNode **ppfirst);
void SListPopFront(SListNode **ppfirst);
void SListInsert(SListNode **ppfirst,SListNode *pos, DataType data);
void SListErase(SListNode **ppfirst,SListNode *pos);
void SListRemove(SListNode **ppfirst, DataType data);
void SListRemoveAll(SListNode **ppfirst, DataType data);


//初始化
void SListNodeInit(SListNode **ppfirst)
{
    *ppfirst = NULL;
}


//尾插
void SListPushBack(SListNode **ppfirst, DataType data)
{
    SListNode *pNewNode = __CreatNewNode(data);
    SListNode *pNode;
    if (*ppfirst == NULL)
    {
	*ppfirst = pNewNode;
	return;
    }
    for (pNode = *ppfirst; pNode->pNext != NULL; pNode = pNode->pNext)
    {}
    pNode->pNext = pNewNode;
}


//头插
void SListPushFront(SListNode **ppfirst, DataType data)
{
    SListNode *pNewNode = __CreatNewNode(data);
    if (*ppfirst == NULL)
    {
	*ppfirst = pNewNode;
	return;
    }
    pNewNode->pNext = *ppfirst;
    *ppfirst = pNewNode;
}


//尾删
void SListPopBack(SListNode **ppfirst)
{
    SListNode *pNode;
    SListNode *pDel;
    if (*ppfirst == NULL)
    {
	return;
    }

    if ((*ppfirst)->pNext == NULL)
    {
	free(*ppfirst);
	return;
    }
    for (pNode = *ppfirst; pNode->pNext->pNext != NULL; pNode = pNode->pNext)
    {

    }
    pDel = pNode->pNext;
    pNode->pNext = NULL;
    free(pDel);
}


//头删
void SListPopFront(SListNode **ppfirst)
{
    SListNode *pNode;
    if (*ppfirst == NULL)
    {
	return;
    }
    if ((*ppfirst)->pNext == NULL)
    {
	free(*ppfirst);
	return;
    }
    pNode = *ppfirst;
    *ppfirst = pNode->pNext;
    free(pNode);
}


//查找函数
SListNode *Find(SListNode **ppfirst, DataType data)
{
    SListNode *pNode;
    for (pNode = *ppfirst; pNode != NULL; pNode = pNode->pNext)
    {
	if (pNode->data == data)
	    return pNode;
    }
    return NULL;
}


//中间插
void SListInsert(SListNode **ppfirst, SListNode *pos, DataType data)
{
    assert(*ppfirst);
    SListNode *pNewNode = __CreatNewNode(data);
    SListNode *pNode;
    if (*ppfirst == NULL)
    {
	*ppfirst = pNewNode;
	return;
    }
    if (*ppfirst == pos)
    {
	SListPushFront(ppfirst,data);
	return;
    }
    for (pNode = *ppfirst; pNode->pNext != pos; pNode = pNode->pNext)
    {

    }
    pNode->pNext = pNewNode;
    pNewNode->pNext = pos;
}

//中间删
void SListErase(SListNode **ppfirst,SListNode *pos)
{
    assert(*ppfirst);
    SListNode *pNode;
    for (pNode = *ppfirst; pNode->pNext != pos; pNode = pNode->pNext)
    {

    }
    pNode->pNext = pos->pNext;
    free(pos);
}



//按值删
void SListRemove(SListNode **ppfirst, DataType data)
{
    assert(*ppfirst);
    SListNode *pNode=Find(ppfirst,data);
    assert(pNode);
    SListErase(ppfirst, pNode);


}


//按值删所有
void SListRemoveAll(SListNode **ppfirst, DataType data)
{
    assert(*ppfirst);
    SListNode *pNode=*ppfirst;
    SListNode *pCmp;
    while (pNode->pNext != NULL)
    {
	pCmp = pNode->pNext;
	if (pCmp->data == data)
	{
	    pNode->pNext = pCmp->pNext;
	    free(pCmp);
	}
	else
	{
	    pNode = pNode->pNext;
	}
    }
    if ((*ppfirst)->data == data)
    {
	pNode = *ppfirst;
	*ppfirst = (*ppfirst)->pNext;
	free(pNode);
    }
}


//销毁
void SListDestroy(SListNode **ppfirst)
{
    assert(*ppfirst);
    SListNode *pNode;
    SListNode  *pN;
    for (pNode = *ppfirst; pNode != NULL;)
    {
	pN = pNode;
	pNode = pNode->pNext;
	free(pN);
    }
}



void TestSListNode()
{
    SListNode *s1;
    SListNodeInit(&s1);

    //SListPushBack(&s1, 5);
    //SListPushBack(&s1, 6);
    //SListPushBack(&s1, 7);
    //SListNodePrint(&s1);
    SListPushFront(&s1, 3);
    SListPushFront(&s1, 2);
    SListPushFront(&s1, 2);
    SListPushFront(&s1, 1);
    SListNodePrint(&s1);

    //SListPopBack(&s1);
    //SListNodePrint(&s1);
    //SListPopFront(&s1);

    SListNode *p1=Find(&s1,3);
    SListInsert(&s1, p1, 8);
    SListNodePrint(&s1);

    SListNode *p2 = Find(&s1, 2);
    //SListErase(&s1,p2);
    SListRemoveAll(&s1,2);

    SListNodePrint(&s1);
    SListDestroy(&s1);
}
