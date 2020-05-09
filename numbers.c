#include "array.h"
#include "array_void.h"
#include <stdio.h>
#include <stdlib.h>

void perform_array_methods(Array_ptr list)
{
  Array_ptr sqr_of_numbers = map(list, &sqr);
  display(sqr_of_numbers);

  Array_ptr even_numbers = filter(list, &is_even);
  display(even_numbers);

  Array_ptr odd_numbers = filter(list, &is_odd);
  display(odd_numbers);

  int sum_of_numbers = reduce(list, 0, &sum);
  printf("%d \n", sum_of_numbers);
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  Array_ptr list_1 = create_array(arr, 5);
  perform_array_methods(list_1);

  return 0;
}