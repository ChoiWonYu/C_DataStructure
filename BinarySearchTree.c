#include"BinarySearchTree.h"
#include"BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{

	return GetData(bst);
}

void BSTInsert(BTreeNode** pRoot, BSTData data)
{

	BTreeNode* cNode = *pRoot;
	BTreeNode* pNode = NULL;
	BTreeNode* nNode = NULL;

	while (cNode != NULL)
	{
		if (cNode->data == data)return;
		pNode = cNode;
		if (cNode->data > data)
		{
			cNode = GetLeftSubTree(cNode);
		}
		else {
			cNode = GetRightSubTree(cNode);
		}
	}
	nNode = MakeBTreeNode();
	SetData(nNode, data);
	if (pNode != NULL)
	{

		if (pNode->data < data)MakeRightSubTree(pNode, nNode);
		else MakeLeftSubTree(pNode, nNode);

	}
	else
	{
		*pRoot = nNode;
	}
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{

	BTreeNode* cNode = bst;
	BSTData cd = cNode->data;
	while (cNode != NULL)
	{
		cd = cNode->data;
		if (cd == target)return cNode;
		else if (cd > target)cNode = GetLeftSubTree(cNode);
		else cNode = GetRightSubTree(cNode);
	}
	return NULL;

}

int SubTreeCount(BTreeNode* dnode)
{
	if (dnode->left == NULL && dnode->right == NULL)return 0;
	else if (dnode->left != NULL && dnode->right == NULL)return 1;
	else if (dnode->left != NULL && dnode->right != NULL)return 2;
	else return -1;
}

BTreeNode* RemoveRightSubTree(BTreeNode* pnode)
{
	BTreeNode* Dnode = GetRightSubTree(pnode);
	pnode->right = NULL;
	return Dnode;
}
BTreeNode* RemoveLeftSubTree(BTreeNode* pnode)
{
	BTreeNode* Dnode = GetLeftSubTree(pnode);
	pnode->left = NULL;
	return Dnode;
}
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->left = sub;
}
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	main->right = sub;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* cnode;
	BTreeNode* pnode;
	BTreeNode* dnode;
	BTreeNode* pvroot=MakeBTreeNode();
    BTreeNode* dcnode;
    ChangeRightSubTree(pvroot,*pRoot);
	cnode = *pRoot;
	while (cnode->data != target)
	{
		
		pnode = cnode;
		if (cnode->data < target)cnode = GetRightSubTree(cnode);
		
		else cnode = GetLeftSubTree(cnode);

		if (cnode == NULL)return NULL;

	}
	dnode = cnode;
	if (SubTreeCount(dnode) == 0)
	{
		if (GetLeftSubTree(pnode) == dnode)RemoveLeftSubTree(pnode);
		else RemoveRightSubTree(pnode);
	}
	else if(SubTreeCount(dnode)==1)
	{
		if (GetLeftSubTree(dnode) != NULL)dcnode = GetLeftSubTree(dnode);
		else dcnode = GetRightSubTree(dnode);

		if (GetRightSubTree(pnode) == dnode)ChangeRightSubTree(pnode, dcnode);
		else ChangeLeftSubTree(pnode, dcnode);

	}
	
    else if(SubTreeCount(dnode) == 2)
	{
		BTreeNode * mpnode=dnode;
        BTreeNode *mnode=GetRightSubTree(mpnode);
        while(GetLeftSubTree(mnode)!=NULL)
        {
            mpnode=mnode;
            mnode=GetLeftSubTree(mnode);
        }
        BTData deldata=GetData(dnode);
        SetData(dnode,GetData(mnode));
        if(GetLeftSubTree(mpnode)==mnode)
        {
            ChangeLeftSubTree(mpnode,GetRightSubTree(mnode));
        }
        else
            ChangeRightSubTree(mpnode,GetRightSubTree(mnode));
        dnode=mnode;
        GetData(mnode,deldata);
        /*dcnode = GetRightSubTree(dnode);
		if(SubTreeCount(dcnode)==1&&GetRightSubTree(dcnode)!=NULL)
		{
			BTData bdata = dnode->data;
			dnode->data = dcnode->data;
			dcnode->data = bdata;
			ChangeRightSubTree(dnode, GetRightSubTree(dcnode));
			dnode = dcnode;
		}
		else
		{
			BTreeNode* cnode = dcnode;
			BTreeNode* minpnode = dcnode;
			while (GetLeftSubTree(cnode) != NULL)
			{
				minpnode = cnode;
				cnode = GetLeftSubTree(cnode);
			}
			BTreeNode* minnode = cnode;
			BTData bdata = dnode->data;
			dnode->data = minnode->data;
			minnode->data = bdata;
			dnode=RemoveLeftSubTree(minpnode);*/


		}
        if(GetRightSubTree(pvroot)==*pRoot)
            *pRoot=GetRightSubTree(pvroot);

            free(pvroot);
            return dnode;
	



}
void InorderTraverse(BTreeNode*bt,VisitFuncPtr action)
{
    if(bt==NULL)return;
    action(bt->data);
    InorderTraverse(bt,action);
    InorderTraverse(bt,action);
}