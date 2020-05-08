#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Bool isEven(int a)
{
  return a % 2 == 0;
}

Bool isOdd(int a)
{
  return !isEven(a);
}

Array *filter(Array *src, Predicate predicate)
{
  Array *filtered_array = malloc(sizeof(Array));
  filtered_array->length = src->length;
  filtered_array->array = malloc(sizeof(int) * filtered_array->length);
  int count = 0;

  for (Index i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      filtered_array->array[count] = src->array[i];
      count++;
    }
  }

  Array *copy_of_filtered_array = malloc(sizeof(Array));
  copy_of_filtered_array->length = count;
  copy_of_filtered_array->array = malloc(sizeof(int) * count);
  memcpy(copy_of_filtered_array->array, filtered_array->array, sizeof(int) * count);

  return copy_of_filtered_array;
}

void display(Array *list)
{
  for (Index i = 0; i < list->length; i++)
  {
    printf("%d ", list->array[i]);
  }
  printf("\n");
}