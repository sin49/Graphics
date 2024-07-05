#include <iostream>


//������Ϸ� ������ �� ���Ǹ� �и����Ѽ� ������ ���ϰ� ����� ����(state.h)
using namespace std;
 class State {
public:
	virtual void GoNext(Context* c)=0;
	virtual ~State() {
		cout << "State Release" << endl;
	}
};
 //Ŭ���� ���� ���� ��� ��ü���� �Լ� ȣ�⿡ ����
 class StateOne :public State {
 public:
	 StateOne() {
		 cout << "StateOne" << endl;
	 }
	 ~StateOne() {
		 cout << "StateOne Release" << endl;
	 }
	
	 void GoNext(Context* c) override {
		 c->SetState(new StateTwo()); 
	 };

 };

 class StateTwo :public State {
 public:
	 StateTwo() {
		 cout << "StateTwo" << endl;
	 }
	 ~StateTwo() {
		 cout << "StateTwo Release" << endl;
	 }
	 void GoNext(Context* context) override {
		
		 context->SetState(new StateThree());

	 }
 };
 class StateThree :public State {
 public:
	 StateThree() {
		 cout << "StateThree" << endl;
	 }
	 ~StateThree() {
		 cout << "StateThree Release" << endl;
	 }
	void  GoNext(Context* context)override {
		context->SetState(new StateOne());
	 }
 };

class Context {
	State* pstate;
public:
	
	~Context() {
		if (pstate)
			delete(pstate);
		cout << "Context Release" << endl;
	}
	void SetState(State*  s) {
		if (pstate)
			delete(pstate);
		pstate = s;
	}
	void GoNext() {
		if (pstate)
		pstate->GoNext(this);
	}
};
//Ŭ��������Լ�:������ Ŭ������ ����Լ��� �����ؼ� ���
void StateOne::GoNext(Context* c) {

}

void main() {
	Context* con = new Context;
	con->SetState(new StateOne());

	con->GoNext();
	con->GoNext();
	con->GoNext();

	delete con;
	return;
}