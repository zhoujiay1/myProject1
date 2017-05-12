#pragma once
#include<stdlib.h>
template<class T>
struct Node {
	Node<T> *next;
	T *data;
};

template<class T>
class Link{
public:
	virtual int add(T *data)=0{};
	virtual int del(T *data)=0{};
	virtual int insert(T *data)=0{};
	virtual int connect(Link *arg1T, Link *arg2)=0{};
	int getSize() { return size; };
	Node<T> *getHead()const { return head; };
protected:
	void setSize(char i) {size+=i;};
	void setSize() { size =0; };
	void setHead(Node<T> *head) { this->head = head; };
private:
	Node<T> *head;
	int size;
};