#include "array.h"
#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>

void perform_array_methods(Array_ptr list)
{
  printf("sqr_of_numbers in list:");
  Array_ptr sqr_of_numbers = map(list, &sqr);
  display(sqr_of_numbers);

  printf("even_numbers in list:");
  Array_ptr even_numbers = filter(list, &is_even);
  display(even_numbers);

  printf("odd_numbers in list:");
  Array_ptr odd_numbers = filter(list, &is_odd);
  display(odd_numbers);

  int sum_of_numbers = reduce(list, 0, &sum);
  printf("sum of numbers in list is: %d \n\n", sum_of_numbers);
}

void perform_void_array_methods(ArrayVoid_ptr list)
{
  printf("sqr_of_numbers in list:");
  ArrayVoid_ptr sqr_of_numbers = map_void(list, &int_sqr);
  display_void(sqr_of_numbers, &display_number);

  Object *init = malloc(sizeof(int));
  *init = 0;
  Object sum_of_numbers = reduce_void(list, init, &int_sum);
  printf("sum of numbers in list is: %d \n", *(int *)sum_of_numbers);
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  Array_ptr list_1 = create_array(arr, 5);
  perform_array_methods(list_1);

  Object array[5];
  int a = 6;
  array[0] = &a;
  int b = 7;
  array[1] = &b;
  int c = 8;
  array[2] = &c;
  int d = 9;
  array[3] = &d;
  int e = 10;
  array[4] = &e;

  ArrayVoid_ptr list_2 = create_void_array(array, 5);
  perform_void_array_methods(list_2);

  return 0;
}