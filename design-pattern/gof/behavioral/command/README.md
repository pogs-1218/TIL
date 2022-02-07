command 패턴은 어떤 동작을 수행해야 할때, 동작자체를 객체로 생성하고
그 인터페이스를 사용하여 컴파일타임/런타임 유연성을 확보할 수 있다.

구성은 invoker, command(interface), concrete command, receiver 로 이루어 진다.

예를 들어 a객체가 b객체의 어떤 메소드를 호출한다고 했을 때,
```
class A{
  void Func1() {
    B b;
    b.Action();
  }
}
```
과 같은 형태가 되겠지. 보통의 경우는 이렇게 사용하고 당연하겠지만 b.Action의 동작에 대한 제어가 필요할때가 있다.
callback, queueing, undo, transaction과 같이, 동작을 나중에 수행하거나, 동작의 순서를 바꾸거나, 동작의 상태를
추적하거나 등과 같은 경우에 해당한다.

각각의 경우에 대한 예제들을 만들어 보면 좋을듯?
+ 위 기능이 포함된 오픈소스를 찾아보고 실제로 command패턴이 어떻게 적용되어 있는지 분석하기.