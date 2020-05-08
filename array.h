#ifndef __ARRAY_H
#define __ARRAY_H
typedef enum
{
  False,
  True
} Bool;
typedef unsigned int Index;

typedef int (*Mapper)(int);
typedef Bool (*Predicate)(int);
typedef int (*Reducer)(int, int);

typedef struct
{
  int *array;
  int length;
} Array;

int sqr(int);
Bool isEven(int a);
Bool isOdd(int a);

Array *map(Array *src, Mapper mapper);
Array *filter(Array *src, Predicate predicate);
int reduce(Array *src, int init, Reducer reducer);

void display(Array *);
#endif
