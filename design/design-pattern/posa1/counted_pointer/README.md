1. shared_ptr를 쓰지않고 counted reference를 구현하기.
2. shared_ptr와의 비교.


ref count의 원리는 handle 과 body를 분리하는것.

첫번째 버전.
body가 ref count멤버변수를 가지고, handle객체가 복사될때 body의 ref count를 업데이트한다.
-> body가 ref count멤버변수를 가지는것을 강제하게 된다.
