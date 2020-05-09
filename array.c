#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Array_ptr create_array(int *arr, int length)
{
  Array_ptr list = malloc(sizeof(Array));
  list->length = length;
  list->array = malloc(sizeof(int) * list->length);
  memcpy(list->array, arr, sizeof(int) * length);

  return list;
}

int sqr(int a)
{
  return a * a;
}

Array_ptr map(Array_ptr src, Mapper mapper)
{
  Array_ptr mapped_array = malloc(sizeof(Array));
  mapped_array->length = src->length;
  mapped_array->array = malloc(sizeof(int) * mapped_array->length);

  for (Index i = 0; i < src->length; i++)
  {
    mapped_array->array[i] = (*mapper)(src->array[i]);
  }

  return mapped_array;
}

Bool is_even(int a)
{
  return a % 2 == 0;
}

Bool is_odd(int a)
{
  return !is_even(a);
}

Array_ptr filter(Array_ptr src, Predicate predicate)
{
  int filtered_array[src->length];
  int count = 0;

  for (Index i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      filtered_array[count] = src->array[i];
      count++;
    }
  }

  return create_array(filtered_array, count);
}

int sum(int a, int b)
{
  a = a + b;
  return a;
}

int reduce(Array_ptr src, int init, Reducer reducer)
{
  int reduced_value = init;
  for (Index i = 0; i < src->length; i++)
  {
    reduced_value = (*reducer)(reduced_value, src->array[i]);
  }

  return reduced_value;
}

void display(Array_ptr list)
{
  for (Index i = 0; i < list->length; i++)
  {
    printf("%d ", list->array[i]);
  }
  printf("\n");
}