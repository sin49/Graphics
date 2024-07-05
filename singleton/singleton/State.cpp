#include <iostream>


//헤더파일로 선언한 후 정의를 분리시켜서 구현을 편하게 만들기 가능(state.h)
using namespace std;
 class State {
public:
	virtual void GoNext(Context* c)=0;
	virtual ~State() {
		cout << "State Release" << endl;
	}
};
 //클레스 선언만 있을 경우 구체적인 함수 호출에 에러
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
//클레스멤버함수:선언한 클레스의 멤버함수를 정의해서 사용
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