
#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

#include"BinaryTree.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode** pRoot);

BSTData BSTGetNodeData(BTreeNode* bst);

void BSTInsert(BTreeNode** pRoot, BSTData data);

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

BTreeNode* RemoveRightSubTree(BTreeNode* pnode);
BTreeNode* RemoveLeftSubTree(BTreeNode* pnode);
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

void InorderTraverse(BTreeNode*bt,VisitFuncPtr action);

#endif