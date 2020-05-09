#include "array.h"
#include <stdlib.h>
#include <stdio.h>

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

  Array *even_numbers = filter(list, &is_even);
  display(even_numbers);

  Array *odd_numbers = filter(list, &is_odd);
  display(odd_numbers);

  int sum_of_numbers = reduce(list, 0, &sum);
  printf("%d \n", sum_of_numbers);

  return 0;
}