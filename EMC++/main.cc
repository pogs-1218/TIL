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

/*
 decltype

*/
void AuthenticationUser() {}

// Version 1.(c++11)
template <typename Container, typename Index>
auto AuthAndAccess1(Container& c, Index i) -> decltype(c[i]) {
  AuthenticationUser();
  return c[i];
}

// Version 1.(c++14)
template <typename Container, typename Index>
auto AuthAndAccess2(Container& c, Index i) {
  AuthenticationUser();
  return c[i];
}

// Version 2.(c++14)
template <typename Container, typename Index>
decltype(auto) AuthAndAccess3(Container& c, Index i) {
  AuthenticationUser()();
  return c[i];
}

// Version 3.(c++14)
template <typename Container, typename Index>
decltype(auto) AuthAndAccess4(Container&& c, Index i) {
  AuthenticationUser()();
  return c[i];
}

// Version 4.(c++14)
template <typename Container, typename Index>
decltype(auto) AuthAndAccess4(Container&& c, Index i) {
  AuthenticationUser()();
  return std::forward<Container>(c)[i];
}

// Version 4.(C++11)
template <typename Container, typename Index>
auto AuthAndAccess5(Container&& c, Index i)
    -> decltype(std::forward<Container>(c)[i]) {
  AuthenticationUser();
  return std::forward<Container>(c)[i];
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

  // Case 1.
  auto x = 27;         // type specifier(ParamType) = auto
  const auto cx = x;   // ParamType = const auto
  const auto& rx = x;  // ParamType = const auto&

  // Case 2.
  auto&& uref1 = x;
  auto&& uref2 = cx;
  auto&& uref3 = rx;
  auto&& uref4 = 27;

  // Exception case between 'auto' and 'template type deduction'.
  // : (initialize_list)
  auto x1 = 27;
  auto x2(27);
  auto x3 = {27};
  auto x4{27};
  // How about template?

  return 0;
}