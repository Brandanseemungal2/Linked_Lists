// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t* mylist =  (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
  return myList;
}

void list_free(list_t *l) {
  node_t *current = l->head;
  while (current != NULL) {
    node_t *temp = current;
    current = current->next;
    free(temp);
  }
  free(l);
}

void list_print(list_t *l) {
  node_t *current = l->head;
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 10024);
  buf[0] = '\0';
  char tbuf[20];

	node_t *current = l->head;
  while (current != NULL) {
    sprintf(tbuf, "%d->", current->value);
    strcat(buf, tbuf);
    current = current->next;
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) {
  int count = 0;
  node_t *current = l->head;
  while (current != NULL) {
    count ++;
    current = currrent->next;
  }
  return count;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *new_node = getNode(value);
  if (l->head == NULL) {
    l->head = new_node;
    return;
  }
  node_t *current = l->head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
     node_t *new_node = getNode(value);
     new_node->next = l->head;
     l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
  if (index < 0) return;
  if (index == 0) {
    list_add_to_front(l, value);
    return;
  }

  node_t *new_node = getNode(value);
  node_t *current = l->head;
  for (int i = 0; i < index - 1 && current != NULL; i++) {
    current = current->next;
  }
  if (current == NULL) return;

  new_node->next = current->next;
  current->next = new_node;
}

elem list_remove_from_back(list_t *l) {
  if (l->head == NULL) return -1;

  node_t *current = l->head;
  if (current->next == NULL) {
    int value = current->value;
    free(current);
    l->head = NULL;
    return value;
  }

  while (current->next->next != NULL) {
    current = current->next;
  }

  int value = current->next->value;
  free(current->next);
  current->next = NULL;
  return value;
}

elem list_remove_from_front(list_t *l) {
  if (l->head == NULL) return -1;

  node_t *temp = l->head;
  int value = temp->value;
  l->head = temp->next;
  free(temp);
  return value;
}

elem list_remove_at_index(list_t *l, int index) {
  if (index < 0 || l->head == NULL) return -1;
  
  if (index == 0) {
    return list_remove_from_front(l);
  }

  node_t *current = l->head;
  for (int i = 0; i < index - 1 && current->next != NULL; i++) {
    current = current->next;
  }
  if (current->next == NULL) return -1;
  
  node_t *temp = current->next;
  int value = temp->value;
  current->next = temp->next;
  free(temp);
  return value;
}

bool list_is_in(list_t *l, elem value) {
  node_t *current = l->head;
  while(current != NULL) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  if (index < 0) return -1;

  node_t *current = l->head;
  for (int i = 0; i < index && current != NULL; i++) {
    current = current->next;
  }
  if (current == NULL) return -1;

  return current->value;
}

int list_get_index_of(list_t *l, elem value) {
  int index = 0;
  node_t *current = l->head;
  while (current != NULL) {
    if (current->value == value) {
      return index;
    }
    current = current->next;
    index++;
  }
  return -1;
}

node_t *getNode(elem value) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;
  return new_node;
}