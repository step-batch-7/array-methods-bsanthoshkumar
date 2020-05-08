#include "array.h"
#include <stdlib.h>
#include <stdio.h>

void display(Array *list)
{
  for (Index i = 0; i < list->length; i++)
  {
    printf("%d ", list->array[i]);
  }
  printf("\n");
}

int main()
{
  Array *list = malloc(sizeof(Array));
  list->length = 5;
  list->array = malloc(sizeof(int) * list->length);
  list->array[0] = 1;
  list->array[1] = 2;
  list->array[2] = 3;
  list->array[3] = 4;
  list->array[4] = 5;

  Array *sqr_of_numbers = map(list, &sqr);
  display(sqr_of_numbers);
}