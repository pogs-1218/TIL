브릿지 패턴의 핵심은 런타임에서 인터페이스와 구현의 분리.
흔히 사용하는 인터페이스와 구현을 분리하는 방식은 상속을 통한 분리.
인터페이스의 상속은 어쩔수없이 구현체가 인터페이스에 커플링됨.
새로운 기능이 필요할때 마다, 인터페이스를 상속한 새로운 구현체를 만들어야함.
코드를 사용하는 클라이언트 측에서도 의존성에 생김.

플랫폼이 변경될때를 가정하면?

언제 쓰나?
1. 인터페이스 구현이 런타임에 선택되어야 할때.
2. 추상화와 구현의 확장이 필요할때. 브릿지 패턴에서는 추상화된 인터페이스와 구현을 이어주는 구현체 인터페이스가 있으므로 필요에 따라 개별 인터페이스를 사용해 확장이 가능하다.
3. 구현의 변경이 클라이언트 코드에 영향이 가지 않아야 할때. 클라이언트 코드는 추상화된 인터페이스 코드만 사용함.
4. 여러 객체들 사이에서 구현체를 공유하고자 할때. 구현체의 상세한 동작을 클라이언트 코드로부터 숨길 수 있다. 이말은 클라이언트 코드가 구현체의 상세한 동작을 몰라도 된다고 볼 수 있다.(레퍼런스 카운팅?)

구성
- abstraction
abstraction interface를 정의. 클라이언트 코드는 해당 interface를 사용함.
implementor에 대한 레퍼런스(포인터)를 가짐
- refined abstraction
abstraction클래스를 확장하는 경우 필요
- implementor
abstraction에 의해 참조되며 구현체의 인터페이스 역할. 인터페이스 상속과 달리 abstraction의 인터페이스들을 동일하게 가지지 않아도 된다.
- concrete implementor
implementor인터페이스를 구현한 구현체


구현
- 하나의 implementor만 사용
abstraction과 implementor가 1:1의 관계일때는 굳이 implementor인터페이스 클래스가 불필요. 하나의 abstraction과 하나의 (concrete?)implementor만 있으면 됨.
c++의 cheshire cat idiom참고 링크:https://www.youtube.com/watch?v=l9GEZtBqhmw
pimpl idiom이라고도 함. 
- 적절한 ipmlementor 객체 생성
- implementor공유
c++의 handle/body idiom이 있음. 여러 객체사이에 implementor를 공유할때 reference counting사용가능.(예제 필요)

샘플
플랫폼에 따라 다른 라이브러리를 사용하는 Renderer의 구현. 
Renderer는 text와 image를 그린다.
최초 구현이 renderer.h, text_renderer.h 그리고 image_renderer.h에 있다.
Renderer의 인터페이스를 상속해 text 혹은 image를 그리기 위한 구현클래스다.
이때, 윈도우OS에서는 DirectX를 사용하려하고, linux에서는 opengl을 사용한다고 가정하자.
