#include "bidLink.h"
#include<stdio.h>
struct user {
	int age;
	int b;
	int c;
	char a;
};

int main() {
	BidLink<user> *a=new BidLink<user>;
	user *u;
	for (int i = 0; i <= 10;i++) {
		u = new user;
		u->a = i; u->age = i * 10; u->b = i * 100; u->c = i * 1000;
		a->add(u);
	}

	BidLink<user> *b = new BidLink<user>;
	for (int i = 0; i <= 10; i++) {
		u = new user;
		u->a = i; u->age = i * 20; u->b = i * 200; u->c = i * 2000;
		b->add(u);
	}
	b->connect(a,b);
	
	return 1;
}