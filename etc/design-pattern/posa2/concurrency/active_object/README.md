method의 실행을 method호출로부터 decouple시키기 위함. 

예제.
통신게이트웨이. 
supplier들이 있고, supplier들이 제공하는 메세지를 consumer로 라우트함.
tcp의 flow control?
supplier들의 데이터 전송속도가 consumer에 비해 빠르지 않도록 데이터 전송을 조절하는 것.
그리고 gateway는 block되지 않아야함. flow control중이더라도.

proxy는 active object의 인터페이스를 나타내고, servant는 active object의 구현을 제공함.
proxy는 client 쓰레드에서 동작하는 반면 servant는 다른 쓰레드에서 동작.
곧, proxy는 method호출을 담당하고 이 method 호출은 method request로 표현.
그럼 client가 proxy를 통해서 method를 호출하면 method request가 만들어지고, 이 method request는
scheduler에 의해 activation list에 저장됨. scheduler의 이벤트루프는 servant와 같은 쓰레드.
activation list에 있는 method requst를 dequeueing해오고, servant로 dispatch함.
필요할 경우 client는 proxy로부터 future를 반환받아 method의 결과를 알수잇음.

six components

1. proxy
   : client 쓰레드에 있음. client가 active object에 있는 method를 실행할 수 있도록 인터페이스 제공
   : method를 호출하면 method request object를 생성함.
2. method request
   : active object의 method를 호출하기 위한 인터페이스를 정의.
   : method가 실행될 수 있는지 확인하기 위한 guard method도 포함될 수 있음.
3. concrete method request
4. activation list
  : proxy가 conrete method request를 activation list에 넣음. method request의 대기열임.
5. scheduler
  : active object의 쓰레드에서 동작. 어떤 method가 실행될 것인지 결정.
6. servant
  : active object의 구현? 

client가 proxy에 있는 method를 호출하면, future를 받음.
client가 servant가 method의 실행을 완료하면 결과를 받기 위함.

1. method request 생성과 스케쥴링
2. method request의 실행
3. 완료(completion)

* 구현.
1. servant의 구현.
2. invocation관련 구현. proxy를 구현하고, method request를 구현.


2022.03.24
TODO
1. have to know ref-counted idiom in c++
2. bounded-buffer producer/consumer
3. mutlthread and atomic in c++