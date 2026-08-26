#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *lchild; // left child 左孩子指针
    struct node *rchild; // right child 右孩子指针
} bitree_t;

// i :根的起始编号, n :要创建节点的个
// 根节点从1 开始
// n 表示的一共的节点个数
// binary tree
bitree_t *create_bitree(int i, int n)
{
    bitree_t *r = malloc(sizeof(bitree_t));
    r->data = i; // 创建根节点
    printf("i=%d\n", i);
    if (2 * i <= n) // 有左孩子
    {
        r->lchild = create_bitree(2 * i, n);
    }
    else
    {
        r->lchild = NULL; // 左孩子为空
    }

    if (2 * i + 1 <= n) // 有右孩子
    {
        r->rchild = create_bitree(2 * i + 1, n);
    }
    else
    {
        r->rchild = NULL;
    }

    return r;
}

// 前序遍历
int preorder(bitree_t *b)
{
    if (b == NULL) // 递归结束条件
    {
        return 0;
    }

    // 先访问 根节点
    printf("%d ", b->data);
    // 再访问 左子树
    preorder(b->lchild);
    // 最后访问 右子树
    preorder(b->rchild);
    return 0;
}

// 中序遍历
int inorder(bitree_t *b)
{
    if (b == NULL) // 递归结束条件
    {
        return 0;
    }

    // 先访问 左子树
    inorder(b->lchild);
    // 再访问 根节点
    printf("%d ", b->data);
    // 最后访问 右子树
    inorder(b->rchild);
    return 0;
}

// 后序遍历
int postorder(bitree_t *b)
{
    if (b == NULL) // 递归结束条件
    {
        return 0;
    }

    // 先访问 左子树
    postorder(b->lchild);
    // 再访问 右子树
    postorder(b->rchild);
    // 最后访问 根节点
    printf("%d ", b->data);
    return 0;
}

int main(int argc, char const *argv[])
{
    bitree_t *B = create_bitree(1, 15);
    printf("先序遍历(根左右):");
    preorder(B);
    printf("\n");
    printf("中序遍历(左根右):");
    inorder(B);
    printf("\n");
    printf("后序遍历(左右根):");
    postorder(B);
    printf("\n");

    return 0;
}
