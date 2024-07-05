#include <iostream>

using namespace std;

//�̱���
class singleton {
	
	int data = 2;
	static singleton* msingleton;//�����Ҵ簴ü 
	 singleton() {
		cout << "singleton["<<this<<"]" <<data <<endl;
	}
	 ~singleton() {
		 cout << "~singleton[" << this << "]" << data << endl;
	 }
public:
	//���� ���� ������ �̿��� �̱��� ����,�ٸ� ��ü���⿡�� X
	static singleton* Getinstance() {
		//���� ��� �Լ��� this ȣ�� �Ұ�
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
singleton* singleton::msingleton = NULL;//���� �������:�������� �����ϴ� ���� ����
int main() {

	singleton* ps=NULL;

	///*singleton& Singobj=ps->Getinstance();
	//Singobj.Display();
	ps =singleton:: Getinstance();


	singleton::Release();
	return 0;
}