#include "linked_list.h"

#include <stdlib.h>

//function to make a NEW node
struct list_node *new_node(size_t value)
{
  struct list_node *n = calloc(1, sizeof(struct list_node));
  n->value = value;
  n->next = NULL;
  return n;
}

//function to insert values to the head of the linked list
void insert_at_head(struct linked_list *list, size_t value)
{
  struct list_node *n = new_node(value);
  n->next = list->head;
  n->value = value;
}

//function to insert values to the tail of the linked list
void insert_at_tail(struct linked_list *list, size_t value)
{
  if(list->head == NULL)
  {
    list->head = new_node(value);
  }
  struct list_node * p = list->head;
  while((p->next)!=NULL)
  {
    p = p->next;
  }
  p->next = new_node(value);
}

//function to remove values from the head of the linked list
size_t remove_from_head(struct linked_list *list)
{
  struct list_node *q = list->head;
  if (q == NULL)
  {
    return 0;
  }
  int value_need = 0;
  value_need = list->head->value;
  list->head = list->head->next;
  free(q);
  return (value_need);
}

//function to remove values from the tail of the linked list
size_t remove_from_tail(struct linked_list *list)
{
  struct list_node * q= list->head;
  while((q->next)!=NULL)
  {
    q = q->next;
  }
  int value_need = q->value;
  //free(q);
  q = NULL;
  return (value_need);
}

//function to free linked lists, must implement myself
void free_list(struct linked_list list) 
{
  struct list_node *p;
  struct list_node * q= list.head;
  while(q != NULL)
  {
    p = q->next;
    free(q);
    q = p;
  }
}

// Utility function to help you debugging, do not modify!!
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
