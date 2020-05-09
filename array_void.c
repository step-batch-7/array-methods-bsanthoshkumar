#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer)
{
  Object reduced_value = init;
  for (Index i = 0; i < src->length; i++)
  {
    reduced_value = (*reducer)(reduced_value, src->array[i]);
  }

  return reduced_value;
}