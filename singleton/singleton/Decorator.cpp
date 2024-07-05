#include <iostream>

using namespace std;

class  Context
{
public:
	Context() {
		cout << "Context" << endl;
	 }
};

class ConcreateContext:Context{
public:
	ConcreateContext() {
		cout << "ConcreateContext" << endl;
	}
};
class Decorator :Context {
	Context context;
public:
	Decorator() {
	
		cout << "Decorator" << endl;
		context = Context();
	}
};
class  ConcreateDecoratorA :Decorator
{
	int addedStatus;

public:
	ConcreateDecoratorA() {

		addedStatus = 0;
		cout << "ConcreateDecoratorA addedStatus:"<<addedStatus << endl;
	}
};
class  ConcreateDecoratorB :Decorator
{

public:
	ConcreateDecoratorB() {
		cout << "ConcreateDecoratorB" << endl;
		AddBehavior();
	}
	void AddBehavior() {
		cout << "AddBehavior" << endl;
	}
};

void main() {
	Context* c=new Context();
	ConcreateContext* cc=new ConcreateContext();
	Decorator* d=new Decorator();
	ConcreateDecoratorA* da=new ConcreateDecoratorA();
	ConcreateDecoratorB* db=new ConcreateDecoratorB();
}