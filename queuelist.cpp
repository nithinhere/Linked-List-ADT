#include "queuelist.h"

// singly linked list implementation of queue
// linked list has a sentenal node

queue::queue(){
	_rear = _front = 0;
	_size = 0;
}

queue::~queue(){
	destructCode();
}

// copy constructor
queue::queue(const queue &v){
    copyCode(v);
}

// assignment operator
queue& queue::operator=(const queue &rhs){
    if (this != &rhs) {
        destructCode();
        copyCode(rhs);
    }
    return *this;
}

// common copy code 
void queue::copyCode(const queue &v)
{
    // set up the empty list
    _front = _rear = 0;

    // copy elements from tail to head 
    node * cur = v._front;
    while ( cur != 0) {
        enqueue(cur -> data); 
        cur = cur->next;
    }
    _size = v._size;
	
}

void queue::destructCode(){
    node * tmp = _front; 
	while (_front != 0){
		_front = _front->next;
		delete tmp;
		tmp = _front; 
	}
}

void queue::enqueue(const TYPE data){
	node * tmp = new node(data);
	if (_front == 0){   // empty queue
		_front = _rear = tmp;
	}
	else{
		_rear->next = tmp;
		_rear = tmp;
	}
	_size++;
}

TYPE queue::dequeue(){
    if ( _front == 0 )
		throw EmptyQueueException();

	node * tmp = _front;
	TYPE val = tmp->data;
	_front = tmp->next;
	delete tmp;
	_size--;
	return val;
}

void queue::dump(ostream &os){
	node * cur = _front;
    while( cur != _rear){
		os << cur -> data << " ";
		cur = cur->next;
	}
	os << cur -> data << " ";
	os << endl;
}

int queue::size(){
    return _size;
}

bool queue::empty(){
    return _front==0;
}

