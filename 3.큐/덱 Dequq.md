## 덱(deque) : double-ended queue

큐의 전단과 후단에서 모두 삽입과 삭제가 가능한 큐 (중간에서는 안 됨)

덱은 스택과 큐의 연산들을 모두 가지고 있다.

add_front, delete_front : 스택의 push 와 pop

add_rear, delete_front : 큐의 enqueue 와 dequeue

=> 덱의 전단과 관련된 연산들만 사용하면 스택, 

​	삽입은 후단, 삭제는 전단만을 사용하면 큐

