#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArrayVoid_ptr create_void_array(Object *arr, int length)
{
  ArrayVoid_ptr list = malloc(sizeof(ArrayVoid));
  list->length = length;
  list->array = malloc(sizeof(Object) * list->length);
  memcpy(list->array, arr, sizeof(Object) * length);

  return list;
}

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper)
{
  ArrayVoid_ptr mapped_array = malloc(sizeof(ArrayVoid));
  mapped_array->length = src->length;
  mapped_array->array = malloc(sizeof(Object) * mapped_array->length);

  for (Index i = 0; i < src->length; i++)
  {
    mapped_array->array[i] = (*mapper)(src->array[i]);
  }

  return mapped_array;
}

ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate)
{
  Object filtered_array[src->length];
  int count = 0;

  for (Index i = 0; i < src->length; i++)
  {
    if ((*predicate)(src->array[i]))
    {
      filtered_array[count] = src->array[i];
      count++;
    }
  }

  return create_void_array(filtered_array, count);
}

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  Object reduced_value = init;
  for (Index i = 0; i < src->length; i++)
  {
    reduced_value = (*reducer)(reduced_value, src->array[i]);
  }

  return reduced_value;
}

void display_number(void *data)
{
  printf("%d ", *(int *)data);
}

void display_void(ArrayVoid_ptr list, DisplayData display)
{
  for (Index i = 0; i < list->length; i++)
  {
    display(list->array[i]);
  }
  printf("\n");
}