#include<stdio.h>
#include<stdlib.h>
typedef struct _node{
    int value;
    struct _node* next;
}node;
 node* NODE();  //创建一个存储 {1,2,3,4} 且无头节点的链表，并返回头值针
 void display(node* head); //遍历输出链表
 node* add(node*head,int a,int number);  //向链表中插入新节点
 node* del(node*head,int number);  //删除链表中的节点 
 int main(){
    node*p=NULL;
    p=NODE();
    p=add(p,5,2);
    p=del(p,0);  
    display(p);
    system("pause");
    return 0;
 }
 node* NODE()
{
    node* head=NULL;  //创建头指针
    node* p=(node*)malloc(sizeof(node));  //创建首元节点
    p->value=1;
    p->next=NULL;
    head=p;  //令头指针指向首元节点
    for(int i=2;i<5;i++){
        node* a=(node*)malloc(sizeof(node));
        a->value=i;
        a->next=NULL;
        p->next=a;
        p=p->next;
    }
    return head;
 }
 void display(node* head){
    node* temp=head;
    while(temp){
        node *q=temp;
        printf("%d\n",temp->value);
        temp=temp->next;
        free(q);
    }
 }
 node* add(node*head,int a,int number){   //head表示头指针，a表示要插入的值，number为插入的位置(从零开始计数)
    node*p=(node*)malloc(sizeof(node));
    p->value=a;
    if(number==0){
        p->next=head;
        p=head;
        return p;
    }else{
        node*temp=head;
        for(int i=1;i<number;i++){
            temp=temp->next;
        }
        if(temp){
            p->next=temp->next;
            temp->next=p;
        }else{
            printf("插入位置不存在\n");
        }
        return head;
    }
 }
 node* del(node*head,int number){  //head为头指针，number为要删除的节点位置
    if(number==0){
        head=head->next;
        return head;
    }else{
        node*temp=(node*)malloc(sizeof(node));
        temp=head;
        for(int i=1;i<number;i++){
            temp=temp->next;
        }
        if(temp->next){
            temp->next=temp->next->next;
        }else{
            printf("无法删除\n");
        }
        return head;
    }
 }
