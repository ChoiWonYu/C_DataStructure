#include"BinarySearchTree.h"
#include"BinaryTree.h"
void ShowIntData(int data)
{
    printf("%d ",data);
}
void BSTShowAll(BTreeNode *bst)
{
    InorderTraverse(bst,ShowIntData);
}

int mian(void)
{
    BTreeNode*bstRoot;
    BTreeNode*sNode;

    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot,5);
    BSTInsert(&bstRoot,1);
    BSTInsert(&bstRoot,4);
    BSTInsert(&bstRoot,3);
    BSTInsert(&bstRoot,7);
    BSTInsert(&bstRoot,8);
    BSTInsert(&bstRoot,6);
    BSTInsert(&bstRoot,9);
    BSTInsert(&bstRoot,2);

    BSTShowAll(bstRoot);
    printf("\n");
    sNode=BSTRemove(&bstRoot,3);
    free(sNode);

    BSTShowAll(bstRoot);
    printf("\n");
    sNode=BSTRemove(&bstRoot,8);
    free(sNode);

    BSTShowAll(bstRoot);
    printf("\n");
    sNode=BSTRemove(&bstRoot,1);
    free(sNode);

    BSTShowAll(bstRoot);
    printf("\n");
    sNode=BSTRemove(&bstRoot,6);
    free(sNode);

    BSTShowAll(bstRoot);
    printf("\n");
    
    return 0;
}