#include <iostream>
#include <chrono>
#include <ratio>
#include <iomanip>
#include <sstream>

int main()
{
  // compile-time constants!!
  using r1 = std::ratio<1, 60>;

  std::intmax_t num = r1::num;
  std::intmax_t den = r1::den;

  std::cout << num << ", " << den << std::endl;

  using r2 = std::ratio<1, 30>;
  using result = std::ratio_add<r1, r2>::type;
  std::cout << result::num << "/" << result::den << std::endl;

  using res = std::ratio_less<r2, r1>;
  std::cout << "r2 < r1: " << res::value << std::endl;

  std::chrono::duration<long> d1;       // same as std::duration<long, std::ratio<1>> d1;
  std::chrono::duration<long, std::ratio<60>> d2(123);
  std::chrono::duration<double, std::ratio<1, 60>> d3;
  std::chrono::duration<double, std::milli> d4;

  std::cout << d2.count() << std::endl;

  auto d5 = std::chrono::duration<double>::max();
  std::cout << d5.count() << std::endl;

  std::chrono::duration<long, std::ratio<60>> d6(10); // Q: What's the meaning?
  std::chrono::duration<long, std::ratio<1>> d7(14); // Q: What's the meaning?

  if(d6 > d7) std::cout << "d6 > d7" << std::endl;
  else std::cout << "d6 <= d7" << std::endl;

  ++d7;                         // Q: d7 ?
  d7 *= 2;                      // Q: d7 ?

  std::chrono::duration<double, std::ratio<60>> d8(d6 + d7);
  std::chrono::duration<long, std::ratio<1>> d9(d6 + d7);

  std::cout << d6.count() << "min + " << d7.count() << "sec = "
            << d8.count() << "min or " << d9.count() << "sec" << std::endl;

  std::chrono::duration<long> dd1{30};
  //std::chrono::duration<long, std::ratio<60>> dd2{dd1};  // Q: What's the problem? why?
  auto dd2 { std::chrono::duration_cast<std::chrono::duration<long, std::ratio<60>>>(dd1) };

  std::chrono::minutes dd3 { 10 };

#if __cplusplus >= 201402L
  using namespace std::chrono_literals;
  auto my_duration { 42min };
#endif

  std::chrono::system_clock::time_point tpoint { std::chrono::system_clock::now() };
  std::time_t tt { std::chrono::system_clock::to_time_t(tpoint) };
  std::tm* t { std::localtime(&tt) }; // Q: Is localtime safe?? What is an alternative function?

  std::cout << std::put_time(t, "%H:%M:%S") << std::endl;

  std::stringstream ss;
  ss << std::put_time(t, "%H:%M:%S");
  std::string string_time { ss.str() };
  std::cout << string_time << std::endl;

  char buffer[80] { 0 };
  std::strftime(buffer, sizeof(buffer), "%H:%M:%S", t);
  std::cout << buffer << std::endl;
  
  return 0;
}
