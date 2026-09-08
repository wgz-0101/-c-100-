#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//数组和链表的区别

//链表的定义方式
struct Node
{
    int data;   //数据域
    struct Node *next;   //指针域
};

void print_list(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void free_list(struct Node *head)
{
    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }
}

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    struct Node *head = NULL;   //头指针
    struct Node *p1 = (struct Node *)malloc(sizeof(struct Node));   //创建第一个节点
    if (p1 == NULL)
    {
        return 1;
    }
    p1->data = 10;   //给第一个节点赋值
    p1->next = NULL;   //第一个节点的指针域指向NULL
    head = p1;   //头指针指向第一个节点
    struct Node *p2 = (struct Node *)malloc(sizeof(struct Node));   //创建第二个节点
    if (p2 == NULL)
    {
        free_list(head);
        return 1;
    }
    p2->data = 20;   //给第二个节点赋值
    p2->next = NULL;   //第二个节点的指针域指向NULL
    p1->next = p2;   //第一个节点的指针域指向第二个节点
    struct Node *p3 = (struct Node *)malloc(sizeof(struct Node));   //创建第三个节点
    if (p3 == NULL)
    {
        free_list(head);
        return 1;
    }
    p3->data = 30;   //给第三个节点赋值
    p3->next = NULL;   //第三个节点的指针域指向NULL
    p2->next = p3;   //第二个节点的指针域指
    printf("原始链表: ");
    print_list(head);

    //头插法
    for (int i = 0; i < 5; i++)
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));   //创建新节点
        if (p == NULL)
        {
            free_list(head);
            return 1;
        }
        p->data = i;   //给新节点赋值
        p->next = head;   //新节点的指针域指向头指针
        head = p;   //头指针指向新节点
    }
    printf("头插法创建的链表: ");
    print_list(head);

    free_list(head);

    //尾插法
    head = NULL;   //头指针置空
    struct Node *tail = NULL;   //尾指针置空
    for (int i = 0; i < 5; i++)
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));   //创建新节点
        if (p == NULL)
        {
            free_list(head);
            return 1;
        }
        p->data = i;   //给新节点赋值
        p->next = NULL;   //新节点的指针域指向NULL
        if (head == NULL)   //如果头指针为空
        {
            head = p;   //头指针指向新节点
            tail = p;   //尾指针指向新节点
        }
        else
        {
            tail->next = p;   //尾指针的指针域指向新节点
            tail = p;   //尾指针指向新节点
        }
    }
    printf("尾插法创建的链表: ");
    print_list(head);

    //在中间插入节点
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        free_list(head);
        return 1;
    }
    newNode->data = 25;
    newNode->next = NULL;
    struct Node *current = head;
    while (current != NULL && current->data != 20)
    {
        current = current->next;
    }
    if (current != NULL)
    {
        newNode->next = current->next;
        current->next = newNode;
    }
    else
    {
        free(newNode);
    }
    printf("在中间插入节点后的链表: ");
    print_list(head);

    free_list(head);
    return 0;
}
