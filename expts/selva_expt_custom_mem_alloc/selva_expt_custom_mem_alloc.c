#include<malloc.c>
#include<stdio.h>


ACM_list G_ACM_POOL;
int id=0;

struct _node{
  struct _node *prev, *next;
};


struct _ACM_alloc{
  struct _ACM_alloc *prev, *next;
  int id;
  long *region;
  
};

struct ACM_list{
  struct _ACM_alloc *head, *tail;
};

int ACM_init(const int size)
{
  G_ACM_POOL->head = (ACM_alloc*)malloc(sizeof(ACM_alloc));
  G_ACM_POOL->head->id = id++;
  G_ACM_POOL->head->region = (long*)(malloc(sizeof(char)*size);
}

int ACM_add_new(ACM_alloc** elem)
{
  G_ACM_POOL.tail->next = *elem;
  (*elem)->prev = G_ACM_POOL->tail;
  (*elem)->next = NULL;

  G_ACM_POOL.tail = *elem;

}

int ACM_extend()
{
  

}
