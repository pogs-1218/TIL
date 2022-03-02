## Architectural Patterns
어플리케이션의 기본적인 구조를 정의함.

### From Mud to Structure

#### Layers
서브태스크 그룹으로 분리하도록 도와줌. 각각의 그룹은 특정 추상화 레벨을 의미.  
ex) 네트워크 OSI 7계층.

top-down: request(N...1 or N...M)  
botttom-up: notification(1...N or 1...M)

1. 각 task 그룹을 레이어로 나눌 기준을 정의  
작고, 하드웨어에 가까운 최하층 레이어로부터 작은 task를 결합하고 유저와 어플리케이션 특성에 맞춘 최상위 레이어로.
2. 몇개의 레이어로 나눌것인지  
3. 레이어의 이름을 정하고 각 레이어에 task를 할당  
4. 서비스를 정의  
보통은 높은 레이어에 더 많은 서비스를 배치하는게 나음. 개발자가 시스템마다 다른 API를 모두 알지 않아도 되므로.
아래쪽 레이어는 슬림해야함. "inverted pyramid of reuse"
5. 1~4를 돌면서 레이어를 정제  
6. 각 레이어의 인터페이스를 정의  
black-box형식이 가능하다면 제일 좋음.  
7. 개별 레이어를 구조화  
8. 인접한 레이어들 사이의 communication을 정의  
9. 인접한 레이어를 디커플  
보통은 보면 상위레이어는 하위레이어를 알고있는데, 하위레이어는 자신을 사용하는 상위레이어에 대해 알기 어려움.(one-way coupling)
top-down구조일 경우 하위레이어의 인터페이스를 stable하게 설계하고 bottom-up구조일 경우 callback을 활용.  
10. 에러핸들링 전략 설계  

예) 네트워크 레이어  

#### Pipes and Filters
데이터의 스트림을 처리하는 구조. 각각의 처리과정은 필터 컴포넌트로 추상화됨. 데이터는 인접한 필터들로 이루어진
파이프를 지나면서 처리.

data source -> filters -> data sink = a pipe
passive filter and active filter
filter들 사이의 연결을 pipe로 칭함
각각의 구현은 pipe를 부모클래스로 가지는 composite패턴의 일종으로 보임.
push pipeline
pull pipeline
push-pull pipeline
으로 구분. data source, filters, data sink가 모두 passive로 동작하는 경우임.read 혹은 write를 하냐의 문제.
그리고 모두 active로 동작할 수 있다.
active로 동작한다는 것은 각 컴포넌트가 루프를 돌며(쓰레드에서) 데이터를 pull하고 처리한다. 각 필터들사이는 버퍼링으로 처리.

1. task를 처리하는 단계를 나눈다.
2. 각 파이프에 전달될 데이터 포맷을 정의한다.
3. 각 파이프 연결을 어떻게 구현할지 정한다. 즉 filter들을 active로 할건지, passive로 할건지, push를 할건지 pull을 할건지.
4. filter를 설계하고 구현한다.
5. 에러 핸들링

예) unix pipe

#### Blackboard
확실하지 않은 솔루션을 가진 문제를 해결하기 위함(?)

### Broker

### Model-View-Controller

### Presentation-Abstraction-Control

### Microkernel

### Reflection


## Design Patterns
### Structural Decomposition
#### Whole-Part pattern
부분(Part)로 전체(Whole)를 구성함.  
하나의 논리적 기능을 하는 시스템을 여러 서브시스템으로 나누는 것.  
클라이언트는 Whole 객체를 통해서만 접근하고 세부동작을 하는 Part부분에 관해서는 알 수 없다.  
예) 점으로 이루어진 선을 이동할때.  
선 = Whole, 점 = Part.  
Line has 2 points.
line.move(1->4)  
  point1.move(1->4)  
  point2.move(1->4)  

구현과정
1. Whole객체의 인터페이스 설계
2. Whole객체를 Part로 분리. bottom-up방식이냐 top-down방식이냐로 나뉘는데, 핵심은 단일책임의 원칙. 그리고 커플링을 줄이고 재사용성을 높이는것.
3. Part의 서비스들을 기반으로 Whole객체의 서비스를 정의. client가 어떤 기능을 사용할때(어떤 Whole함수를 호출할 때) 어떤 Part들이 사용되는지.
4. Part 구현
5. Whole 구현


* Part의 life cycle은 whole이 관리해야함.
* 연관 gof 패턴: composite, facade  


### Organization of Work
#### Master-Slave pattern

### Access Control
#### Proxy pattern
### Management
#### Command Processor pattern

### Communication
#### Forwarder-Receiver pattern
#### Client-Dispatcher-Server pattern

### Publish-Subscriber pattern

