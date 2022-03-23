#ifndef TYPE_DEDUCTION_H_
#define TYPE_DEDUCTION_H_

template <typename T>
void f(T param);

template <typename T>
void f_ref(T& param);

template <typename T>
void f_ptr(T* param);

template <typename T>
void f_const_ref(const T& param);

template <typename T>
void f_uni_ref(T&& param);

namespace type_deduction {
void test() {
  int x = 7;
  const int cx = x;
  const int& rx = x;

  // T와 param의 형식을 잘 생각해보면 된다.
  // int일 경우, T는 당연히 int, param도 당연히 int&.
  f_ref(x);
  // const int인 경우, cx는 const속성을 가져야 한다는 것을 알려줘야 한다.
  // 따라서 T는 const int이고 그대로 param에 매칭되어 param은 const int&형식.
  f_ref(cx);
  // const int&인경우, rx는 const속성을 가져야하지만 참조형식이다.
  // 그럼 T와 T&의 모양을 봤을때, T가 const int가 되어야지만 const int 와 const
  // int&형식이 된다.
  f_ref(rx);

  // param자체가 const속성을 가질때는?
  // const가 없을때는 역시나 그대로, T는 int, param은 const int&형식
  f_const_ref(x);
  // const만 있다. param타입과 cx의 모양을 매칭시키기 위해선 T가 int여야만한다.
  f_const_ref(cx);
  // 위 경우와 동일. T가 const와 &를 때고 int여아지만 모양이 맞다.
  f_const_ref(rx);

  // T가 보편참조 일때는 두가지 경우로 나뉜다. 함수에 전달하는 표현식이 lvalue냐
  // rvalue냐에 따라. rvalue일때는 일반적인 규칙을 따르므로 패스. lvalue일때는
  // 참조(reference)로 연역된다. x는 lvalue다, 그럼 T와 param의 타입은 int&로
  // 연역.
  f_uni_ref(x);
  // cx도 lvalue. 따라서 const int + &가 붙어서 T와 param타입.
  f_uni_ref(cx);
  // 위와 동일.
  f_uni_ref(rx);

  // 99는 rvalue, T는 int그대로. param도 int&&
  f_uni_ref(99);

  // param타입이 reference나 pointer가 아니고 그냥 T라면, param은 복사된
  // 객체.(당연) 따라서 참조이던 const이던 모두 무시된다.
  f(x);
  f(cx);
  f(rx);
  f(88);
}
}  // namespace type_deduction

/**
 * @brief auto 사용의 장점.
 * 1. 변수 초기화를 컴파일시점에 강제할 수 있다.
 * 2. 타이핑이 줄어든다.
 * 3. 암묵적인 형식변환을 방지할 수 있다.
 *
 */
#endif