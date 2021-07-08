#include <iostream>

/*
Type Deduction Samples
-----------------------
template<typename T>
void f(ParamType param);

f(expr);    // calling function 'f'
-----------------------
*/
template <typename T>
void f(const T& param);

// Case 1.
template <typename T>
void f1(T& param);

template <typename T>
void cf1(const T& param);

// Case 2.
template <typename T>
void f2(T&& param);

// Case 3.
template <typename T>
void f3(T param);

template <typename T, std::size_t N>
constexpr std::size_t ArraySize(T (&)[N]) noexcept {
  return N;
}

int main() {
  int x = 27;
  const int cx = x;
  const int& rx = x;

  // Case 1.
  f1(x);
  f1(cx);
  f1(rx);

  cf1(x);
  cf1(cx);
  cf1(rx);

  // Case 2.
  f2(x);
  f2(cx);
  f2(rx);
  f2(27);

  // Case 3.
  f3(x);
  f3(cx);
  f3(rx);
  const char* const ptr = "Fun with pointers";
  f3(ptr);

  const char name[] = "sujeong";
  const char* name_ptr = name;

  f1(name);
  f3(name);

  int values[] = {1, 3, 5, 7, 9, 11};
  int new_values[ArraySize(values)];

  return 0;
}