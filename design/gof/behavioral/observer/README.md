subject 와 observer로 구성

observer는 말그대로 관찰자.
subject가 변화가 있나, 없나, 뭐가 바뀌었나, 관찰하고 subject로 부터 noti를 받음

subject
: observer들을 추가/제거하기 위한 인터페이스가 필요함.
다수의 observer를 추가 할 수 있음.

concrete subject
: concrete observer구현체의 상태를 저장.
: 자신의 상태가 변경되었을 때, observer에 상태변경을 알려줌.

observer
: subject의 변화를 noti받기위한 업데이트 인터페이스 필요.e

concrete observer
: concrete subject와 연관.

concrete observer가 생성될때 concrete subject를 생성자 파라미터로 받아서  
attach를 호출하도록 해, subject관점에서의 raii를 수행한다.(생성자에서 attach호출, 소멸자에서 detach호출)  


구현시 쟁점은 subject인터페이스와 observer인터페이스의 연결.  
subject.notify()를 호출해야하고, notify()안에서 observer.update()를 호출해야한다.  
이 때, subject에서 변경이 된 데이터를 다루는 방법에 따라 push/pull 모델로 나눌수있다.  
push model의 경우, observer의 update의 파라미터로 데이터를 push해주는 형태이고,  
pull model의 경우, observer의 update 파라미터로 subject를 넘겨, subject로 부터 데이터를 pull한다.
push model로 구현할 경우 observer는 subject가 넘겨주는 데이터의 포맷을 알고 있어야 하고  
subject에 따라 구현이 달라지므로 observer의 복잡도가 올라간다.  
반면에 pull model로 구현할 경우는 observer는 subject가 넘겨주는 데이터를 알 필요없이,  
subject의 함수를 콜백해 필요한 동작을 수행한다. 

클라이언트 코드에서는 observer에 관여하지 않고 subject의 함수를 호출하도록 인터페이스를 만들어야 한다.  