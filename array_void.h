#ifndef __ARRAY_VOID_H
#define __ARRAY_VOID_H

#include "array.h"

typedef void *Object;
typedef Object (*MapperVoid)(Object);
typedef Bool (*PredicateVoid)(Object);
typedef Object (*ReducerVoid)(Object, Object);

typedef struct
{
  Object *array;
  int length;
} ArrayVoid;

typedef ArrayVoid *ArrayVoid_ptr;
typedef void (*DisplayData)(Object);

Object Sqr(Object data);
Bool is_Even(Object);
Bool is_Odd(Object);
Object Sum(Object a, Object b);

ArrayVoid_ptr create_void_array(Object *, int);

ArrayVoid_ptr map_void(ArrayVoid_ptr src, MapperVoid mapper);
ArrayVoid_ptr filter_void(ArrayVoid_ptr src, PredicateVoid predicate);
Object reduce_void(ArrayVoid_ptr src, Object init, ReducerVoid reducer);

void display_number(Object);
void display_character(Object);
void display_void(ArrayVoid_ptr, DisplayData);
#endif