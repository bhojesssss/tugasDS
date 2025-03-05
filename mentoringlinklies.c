#include<stdio.h>
#include<stdlib.h>

struct tnode{
    int x;
    struct tnode *next;
    struct tnode *prev;

};

struct tnode *head = NULL;
struct tndoe *tail = NULL;

struct tnode *createnode(int x){
    struct tnode *newnode = (struct tnode*)malloc(sizeof(struct tnode));
    newnode->x = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

void pushhead(struct tnode *tnode){
    if(!head){
        head = tail = tnode;
    }else{
        head->prev = tnode;
        tnode->next = head;
        head = tnode;
    }
}

void pushtail(struct tnode *tnode){
    if(!head){
        head = tail = tnode;

    }else{
        tail->next = tnode;
        tnode->prev = tail;
        tail = tnode; 
    }
}

void pophead(){
    if(!head){
        printf("yahahah hayukkk");
    }else if(head==tail){
        head = tail = NULL;
        free(head);
    }else{
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
}

int main(){

    return 0;
}