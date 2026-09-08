#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main(int argc, char const *argv[])
{
    struct Node *head = NULL;
    struct Node *node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 10;
    struct Node *node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 20;
    struct Node *node3 = (struct Node*)malloc(sizeof(struct Node));
    node3->data = 30;
    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    struct Node *current = head;
    printf("链表节点数据：");
    while(current != NULL)
    {
        printf("%d->",current->data);
        current = current->next;
    }
    printf("\n");
    //头插法
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = 1;
    new_node->next = head;
    head = new_node;
    struct Node *new_node_1 = (struct Node*)malloc(sizeof(struct Node));
    new_node_1->data = 2;
    new_node_1->next = head;
    head = new_node_1;
    struct Node *current_1 = head;
    printf("头插法节点数据：");
    while(current_1 != NULL)
    {
        printf("%d->",current_1->data);
        current_1 = current_1->next;
    }
    printf("\n");
    //尾插法
    struct Node *new_node_2 = (struct Node*)malloc(sizeof(struct Node));
    new_node_2->data = 100;
    new_node_2->next = NULL;
    node3->next = new_node_2;
    struct Node *new_node_3 = (struct Node*)malloc(sizeof(struct Node));
    new_node_3->data = 200;
    new_node_3->next = NULL;
    new_node_2->next = new_node_3;
    struct Node *current_2 = head;
    printf("尾插法节点数据：");
    while(current_2 != NULL)
    {
        printf("%d->",current_2->data);
        current_2 = current_2->next;
    }
    printf("\n");
    //插入法
    struct Node *new_node_4 = (struct Node*)malloc(sizeof(struct Node));
    new_node_4->data = 50;
    new_node_4->next = node2;
    node1->next = new_node_4;
    struct Node *new_node_5 = (struct Node*)malloc(sizeof(struct Node));
    new_node_5->data = 150;
    new_node_5->next = node2;
    new_node_4->next = new_node_5;
    struct Node *current_3 = head;
    printf("插入法节点数据：");
    while(current_3 != NULL)
    {
        printf("%d->",current_3->data);
        current_3 = current_3->next;
    }
    printf("\n");
    //删除法
    struct Node *temp = node2;
    new_node_4->next = new_node_5->next;
    free(temp);
    struct Node *current_4 = head;
    printf("删除法节点数据：");
    while(current_4 != NULL)
    {
        printf("%d->",current_4->data);
        current_4 = current_4->next;
    }
    printf("\n");
    //释放内存
    struct Node *current_5 = head;
    while(current_5 != NULL)
    {
        struct Node *temp = current_5;
        current_5 = current_5->next;
        free(temp);
    }
    printf("\n");

    return 0;
}
