#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int sqr(int a)
{
  return a * a;
}

Array *map(Array *src, Mapper mapper)
{
  Array *mapped_array = malloc(sizeof(Array));
  mapped_array->length = src->length;
  mapped_array->array = malloc(sizeof(int) * mapped_array->length);

  for (Index i = 0; i < src->length; i++)
  {
    mapped_array->array[i] = (*mapper)(src->array[i]);
  }

  return mapped_array;
}

void display(Array *list)
{
  for (Index i = 0; i < list->length; i++)
  {
    printf("%d ", list->array[i]);
  }
  printf("\n");
}