#include <iostream>

template <typename T>
void swap(T* a, T* b) {
  T mem = *a;
  *a = *b;
  *b = mem; 
}

template <typename T>
T* MergeSort(T* array, size_t size) {
  T* answer = new int64_t[size];

  if(size == 1) {
    *answer = *array;
    std::cout << *answer << " ";
    return answer;
  }
  if (size == 2) {
    *answer = *array;
    *(answer + 1) = *(array + 1);
    if(*answer >= *(answer + 1)) {
      swap(answer, (answer + 1));
    }
    std::cout << *answer << " " << *(answer + 1) << " ";
    return answer;
  }
  
  size_t middle = size/2;
  T* left_array = MergeSort(array, middle); // answer instead array
  T* right_array = MergeSort(array + middle, size - middle);

  std::cout << std::endl;
/*
L = *In1;
R = *In2;

if( L <= R ) {
 *Out++ = L;
 In1++;
} else {
 *Out++ = R;
 In2++;
}
*/

  size_t left_ptr = 0;
  size_t right_ptr = 0;
  size_t answer_ptr = 0;

  for (;left_ptr < middle && right_ptr < size - middle;) {
    if (*(left_array + left_ptr) > *(right_array + right_ptr)) {
      *(answer + answer_ptr) = *(right_array + right_ptr);
      ++answer_ptr;
      ++right_ptr;
    } else {
      *(answer + answer_ptr) = *(left_array + left_ptr);
      ++answer_ptr;
      ++left_ptr;
    }
    std::cout << *(answer + answer_ptr - 1) << " ";
  }
  while (left_ptr < middle) {
    *(answer + answer_ptr) = *(left_array + left_ptr);
    ++answer_ptr;
    ++left_ptr;
    std::cout << *(answer + answer_ptr - 1) << " ";
  }
  while (right_ptr < size - middle) {
    *(answer + answer_ptr) = *(left_array + right_ptr);
    ++answer_ptr;
    ++right_ptr;
    std::cout << *(answer + answer_ptr - 1) << " ";
  }

  return answer;
}

int main() {


  size_t n;

  std::cin >> n;

  int64_t* arr = new int64_t[n];

  std::cout << arr << " " << (arr + 1) << std::endl;

  for (size_t curr = 0; curr < n; ++curr) {
    std::cin >> *(arr + curr);
  }

  std::cout << "-----------\n";

  int64_t* new_arr = MergeSort(arr, n);

  std::cout << "\n-----------\n";

  std::cout << "\nMS:\n";
  for (size_t curr = 0; curr < n; ++curr) {
    std::cout << *(new_arr + curr) << " ";
  }
}