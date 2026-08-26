#include <stdio.h>
#include <stdlib.h>

// 定义二叉排序树节点结构体
typedef struct node
{
    int data;
    struct node *left_child;  // 左子节点
    struct node *right_child; // 右子节点
} bstnode_t;                  // binary search tree
// 初始化二叉排序树
bstnode_t *init_bst()
{
    return NULL;
}
// 插入节点
void insert_node(bstnode_t **root, int data)
{
    // 如果根节点为空，则创建新节点并作为根节点
    if (*root == NULL)
    {
        bstnode_t *new_node = (bstnode_t *)malloc(sizeof(bstnode_t));
        new_node->data = data;
        new_node->left_child = new_node->right_child = NULL;
        *root = new_node;
        printf("插入节点 %d 成功！\n", data);
        return;
    }
    // 如果根节点不为空
    else
    {
        // 如果待插入节点的值小于根节点的值，则递归插入左子树
        if (data < (*root)->data)
        {
            insert_node(&((*root)->left_child), data);
        }
        // 如果待插入节点的值大于根节点的值，则递归插入右子树
        else if (data > (*root)->data)
        {
            insert_node(&((*root)->right_child), data);
        }
        // 如果待插入节点的值等于根节点的值，则插入失败
        else
        {
            printf("插入节点 %d 失败，该节点已存在！\n", data);
        }
    }
}
// 查询节点
bstnode_t *search_node(bstnode_t *root, int data)
{
    // 如果根节点为空，则查找失败
    if (root == NULL)
    {
        return NULL;
    }
    // 如果根节点不为空
    else
    {
        // 如果待查找节点的值小于根节点的值，则递归查找左子树
        if (data < root->data)
        {
            return search_node(root->left_child, data);
        }
        // 如果待查找节点的值大于根节点的值，则递归查找右子树
        else if (data > root->data)
        {
            return search_node(root->right_child, data);
        }
        // 如果待查找节点的值等于根节点的值，则查找成功
        else
        {
            printf("查找节点 %d 成功！\n", data);
            return root;
        }
    }
}
// 删除节点
void delete_node(bstnode_t **root, int data)
{
    // 如果根节点为空，则删除失败
    if (*root == NULL)
    {
        printf("删除节点 %d 失败，该节点不存在！\n", data);
        return;
    }
    // 如果根节点不为空
    else
    {
        // 如果待删除节点的值小于根节点的值，则递归删除左子树
        if (data < (*root)->data)
        {
            delete_node(&((*root)->left_child), data);
        }
        // 如果待删除节点的值大于根节点的值，则递归删除右子树
        else if (data > (*root)->data)
        {
            delete_node(&((*root)->right_child), data);
        }
        // 如果待删除节点的值等于根节点的值，则删除节点
        else
        {
            // 如果待删除节点是叶子节点，则直接删除
            if ((*root)->left_child == NULL && (*root)->right_child == NULL)
            {
                bstnode_t *temp_node = *root;
                *root = NULL;
                free(temp_node);
                printf("删除节点 %d 成功！\n", data);
                return;
            }
            // 如果待删除节点只有左子树，则让左子树代替该节点
            else if ((*root)->left_child != NULL && (*root)->right_child == NULL)
            {
                bstnode_t *temp_node = *root;
                *root = (*root)->left_child;
                free(temp_node);
                printf("删除节点 %d 成功！\n", data);
                return;
            }
            // 如果待删除节点只有右子树，则让右子树代替该节点
            else if ((*root)->left_child == NULL && (*root)->right_child != NULL)
            {
                bstnode_t *temp_node = *root;
                *root = (*root)->right_child;
                free(temp_node);
                printf("删除节点 %d 成功！\n", data);
                return;
            }
            // 如果待删除节点有左右子树，则找到该节点的中序遍历的后继节点代替该节点
            // 该节点的中序遍历的后继节点即为该节点的右子树中值最小的节点
            else
            {
                bstnode_t *current_node = (*root)->right_child;
                while (current_node->left_child != NULL)
                {
                    current_node = current_node->left_child;
                }
                (*root)->data = current_node->data;
                delete_node(&((*root)->right_child), current_node->data);
                printf("删除节点 %d 成功！\n", data);
                return;
            }
        }
    }
}
int main()
{
    bstnode_t *root = init_bst();
    insert_node(&root, 8);
    insert_node(&root, 3);
    insert_node(&root, 10);
    insert_node(&root, 1);
    insert_node(&root, 6);
    insert_node(&root, 14);
    insert_node(&root, 4);
    insert_node(&root, 7);
    insert_node(&root, 13);
    search_node(root, 6);
    search_node(root, 2);
    delete_node(&root, 6);
    delete_node(&root, 2);
    return 0;
}