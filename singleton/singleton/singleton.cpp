#include <iostream>

using namespace std;

//싱글톤
class singleton {
	
	int data = 2;
	static singleton* msingleton;//동적할당객체 
	 singleton() {
		cout << "singleton["<<this<<"]" <<data <<endl;
	}
	 ~singleton() {
		 cout << "~singleton[" << this << "]" << data << endl;
	 }
public:
	//정적 지역 변수를 이용해 싱글톤 가능,다른 객체지향에서 X
	static singleton* Getinstance() {
		//정적 멤버 함수는 this 호출 불가
		if (!msingleton)
			msingleton = new singleton();
		return msingleton;

	}
	
	
	static void Release() {
		cout << "~singletonRelease" << endl;
		if (msingleton) {
			delete(msingleton);
			msingleton = NULL;
		}
	 }
	 void Display() {

		 cout <<typeid(this).name() << "Display"+data << endl;
	 }
};
singleton* singleton::msingleton = NULL;//정적 멤버변수:실행전에 생성하는 전역 변수
int main() {

	singleton* ps=NULL;

	///*singleton& Singobj=ps->Getinstance();
	//Singobj.Display();
	ps =singleton:: Getinstance();


	singleton::Release();
	return 0;
}