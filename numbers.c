#include "array.h"
#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>

void perform_array_methods(Array_ptr list)
{
  printf("sqr of numbers in list:");
  Array_ptr sqr_of_numbers = map(list, &sqr);
  display(sqr_of_numbers);

  printf("even numbers in list: ");
  Array_ptr even_numbers = filter(list, &is_even);
  display(even_numbers);

  printf("odd numbers in list: ");
  Array_ptr odd_numbers = filter(list, &is_odd);
  display(odd_numbers);

  int sum_of_numbers = reduce(list, 0, &sum);
  printf("sum of numbers in list is: %d \n\n", sum_of_numbers);
}

void perform_int_array_methods(ArrayVoid_ptr list)
{
  printf("sqr of numbers in list: ");
  ArrayVoid_ptr sqr_of_numbers = map_void(list, &Sqr);
  display_void(sqr_of_numbers, &display_number);

  printf("even numbers in list: ");
  ArrayVoid_ptr even_numbers = filter_void(list, &is_Even);
  display_void(even_numbers, &display_number);

  printf("odd numbers in list: ");
  ArrayVoid_ptr odd_numbers = filter_void(list, &is_Odd);
  display_void(odd_numbers, &display_number);

  Object *init = malloc(sizeof(int));
  *init = 0;
  Object sum_of_numbers = reduce_void(list, init, &Sum);
  printf("sum of numbers in list is: %d \n\n", *(int *)sum_of_numbers);
}

int main()
{
  int array_1[] = {1, 2, 3, 4, 5};
  Array_ptr list_1 = create_array(array_1, 5);
  perform_array_methods(list_1);

  Object array_2[5];
  int a = 6;
  array_2[0] = &a;
  int b = 7;
  array_2[1] = &b;
  int c = 8;
  array_2[2] = &c;
  int d = 9;
  array_2[3] = &d;
  int e = 10;
  array_2[4] = &e;
  ArrayVoid_ptr list_2 = create_void_array(array_2, 5);
  perform_int_array_methods(list_2);

  Object name[5];
  char ch1 = 'k';
  name[0] = &ch1;
  char ch2 = 'u';
  name[1] = &ch2;
  char ch3 = 'm';
  name[2] = &ch3;
  char ch4 = 'a';
  name[3] = &ch4;
  char ch5 = 'r';
  name[4] = &ch5;
  ArrayVoid_ptr list_3 = create_void_array(name, 5);
  display_void(list_3, &display_character);

  return 0;
}