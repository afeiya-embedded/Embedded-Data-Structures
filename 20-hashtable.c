#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100 // 哈希表的最大长度
// 定义一个结构体，表示哈希表中的每个节点
typedef struct node
{
    char key[20];          // 关键字 , 
    int value;             // 值
    struct node *next; // 链表指针
} hashnode_t;
// 哈希表结构体
typedef struct
{
    int size;         // 哈希表的长度
    hashnode_t **table; // 哈希表
} hashtable_t;
// 初始化哈希表
void hashtable_init(hashtable_t *ht)
{
    ht->size = MAX_SIZE;
    // 这是一个二维数组， 可以把table当成一个数组，二维数组的数组名
    ht->table = (hashnode_t **)malloc(sizeof(hashnode_t *) * ht->size);
    memset(ht->table, 0, sizeof(hashnode_t *) * ht->size);
}
// 哈希函数，将关键字转换为哈希值
int hash_code(char *key)
{
    int code = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        code = code * 31 + key[i]; // key[i] 字符串的内容
    }
    return code % MAX_SIZE;
}
// 插入元素到哈希表中
void hashtable_insert(hashtable_t *ht, char *key, int value)
{
    int index = hash_code(key);
    hashnode_t *node = (hashnode_t *)malloc(sizeof(hashnode_t));
    strcpy(node->key, key);
    node->value = value;
    node->next = ht->table[index];
    ht->table[index] = node;
    printf("插入元素[%s, %d]成功\n", key, value);
}
// 在哈希表中查找元素
int hashtable_search(hashtable_t *ht, char *key)
{
    int index = hash_code(key);
    hashnode_t *node = ht->table[index];
    while (node)
    {
        if (strcmp(node->key, key) == 0)
        {
            printf("查找元素[%s]成功，值为%d\n", key, node->value);
            return node->value;
        }
        node = node->next;
    }
    printf("查找元素[%s]失败，不存在该元素\n", key);
    return -1;
}
// 从哈希表中删除元素
void hashtable_delete(hashtable_t *ht, char *key)
{
    int index = hash_code(key);
    hashnode_t *node = ht->table[index];
    hashnode_t *pre = NULL;
    while (node)
    {
        if (strcmp(node->key, key) == 0)
        {
            if (pre == NULL)
            {
                ht->table[index] = node->next;
            }
            else
            {
                pre->next = node->next;
            }
            free(node);
            printf("删除元素[%s]成功\n", key);
            return;
        }
        pre = node;
        node = node->next;
    }
    printf("删除元素[%s]失败，不存在该元素\n", key);
}
// 测试哈希查找
int main()
{
    hashtable_t ht;
    hashtable_init(&ht);
    hashtable_insert(&ht, "Tom", 20);
    hashtable_insert(&ht, "Jerry", 18);
    hashtable_insert(&ht, "Mike", 25);
    hashtable_search(&ht, "Tom");
    hashtable_search(&ht, "Mary");
    hashtable_delete(&ht, "Jerry");
    hashtable_search(&ht, "Jerry");
    return 0;
}