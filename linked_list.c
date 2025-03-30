#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) { return NULL; }

//function to insert values to the head of the linked list
void insert_at_head(struct linked_list *list, size_t value) {}

//function to insert values to the tail of the linked list
void insert_at_tail(struct linked_list *list, size_t value) {}

//function to remove values from the head of the linked list
size_t remove_from_head(struct linked_list *list) { return 0; }

//function to remove values from the tail of the linked list
size_t remove_from_tail(struct linked_list *list) { return 0; }

//function to free linked lists, must implement myself
void free_list(struct linked_list list) {}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
