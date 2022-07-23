behavioral 클래스 패턴
: 객체의 상속을 통해서 행위를 분산
template method
interpreter

behavioral 객체 패턴
: 상속보다는 객체의 구성을 통해서 행위를 분산, 단일 객체가 행위를 수행하는게 아니라 여러객체가 서로간에 통신하여 수행
mediator

chain of reponsibility
어떤 행위에 참가하는 객체들의 chain을 생성하여 행위를 수행하기 위한 요청을 위임함.

observer
객체간의 의존성을 정의하고 유지함. MVC패턴에서 활용

strategy
객체내부의 알고리즘을 캡슐화함. 런타임에 객체가 수행하는 알고리즘을 변경할 수 있음

command
객체의 요청을 캡슐화함. 요청자체가 단일 메소드가 아닌 객체로 캡슐화 되기 때문에 자료구조의 element로 활용할 수 있음

state
객체의 상태를 캡슐화함. 상태가 변할때 객체의 행동을 변경할 수 있음

visitor
객체들에 분산되어 있는 행위를 캡슐화 함.

iterator
군집된 객체집합이 있을 때 객체에 접근하거나 순회하는 방법을 추상화 함.