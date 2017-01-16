#include <iostream>
#include <cstdlib>

#define TYPE int

using namespace std;

class EmptyQueueException{};

struct node{
	node(TYPE x, node * n=0):data(x), next(n){}

	TYPE data;
	node * next;
	
};

class queue{
public:
	// default constructor 
    queue(); 
	
	// copy constructor
	queue(const queue &v);
		
	// assignment operator 	
	queue& operator=(const queue &rhs);
	
	// destructor
	~queue();       
	
	// add an element to the end of queue
    void enqueue(const TYPE); 
	
	// remove an element from the front of queue 
	// throws EmptyQueueException if queue if empty 
    TYPE dequeue();
	
	// output queue elements to ostream
	// output from queue front to queue end; output nothing if queue is empty
    void dump(ostream &os); 
	
	// return the number of elements currently in the queue
    int size();         
	
	// return true if the queue is empty, false otherwise
    bool empty();  
	
	
	void copyCode(const queue &v);
	void destructCode();
	
private:
    node * _front;  
    node * _rear;       //  rear of queue
    int _size; 
};
