#pragma once
#include "Link.h"
template<class T>
struct BidNode:public Node<T>{
	Node<T> *pre;
};

template<class T>
class BidLink:public Link<T>{
public:
	BidLink() {
		setSize();
		setHead(NULL);
	}

	virtual int add(T *data) {
		if(data==NULL){
			return 0;
		}else {
			BidNode<T> *n=new BidNode<T>;
			static BidNode <T> *t= NULL;
			if (t == NULL)
				t = n;
			if (getHead() == NULL) 
				setHead(n);
			n->data = data;
			t->next = n;
			n->pre = t;
			((BidNode<T> *)getHead())->pre=n;
			n->next = getHead();
			t = n;
			setSize(1);
		}
		return 1;
	};
	virtual int del(T *data) {
		if(data==NULL){
			return 0;
		}
		else {
			Node<T> *t=(BidNode<T> *)getHead();
			for (int i = getSize(); i > 0; i--) {
				if (t->data == data) {
					if (t == getHead()) {
						setHead(t->next);
					}
					((BidNode<T> *)t)->pre->next = t->next;
				    ((BidNode<T> *)t->next)->pre = ((BidNode<T> *)t)->pre;
					delete t; free(data);
					setSize(-1);
					return 1;
				}
				else {
					t = t->next;
				}
			}
		}
		return 0;
	};
	virtual int connect(Link *arg1, Link *arg2) {

		if (arg1 == NULL&&arg2 == NULL) {
			return 0;
		}
		else {
			BidNode<T> *t;
			BidNode<T> *head1 = (BidNode<T> *)arg1->getHead();
			BidNode<T> *head2 = (BidNode<T> *)arg2->getHead();
			head1->pre->next = head2;
			head2->pre->next = head1;	
			head2->pre = head1->pre;
		}

		return 1;
	
	};
	virtual int insert(T *data,Node *Number) {
		return 1;
	};
};
