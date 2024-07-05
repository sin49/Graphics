#include <iostream>
#include <list>
using namespace std;


class  Commander
{
	list<Unit> unitCollection=list<Unit>();
public:
	void SelectUnit(Unit* u) {
		unitCollection.push_front(*u);
	}
	void DeselectUnit(Unit u) {
		unitCollection.remove(u);
	}
	void Move(int x, int y) {
		list<Unit>::iterator iter;
		for (iter = unitCollection.begin(); iter != unitCollection.end();iter++) {
			Unit u = *iter;
			u.Move(x, y);
		}
	}
};


class Unit {
public:
	virtual void Move(int x, int y) {};
		
};
class Marine:public Unit {
public:
	virtual void Move(int x, int y)override {
		cout << "Marine"<<typeid(*this).name() <<"move(" << x << ", " << y << ")" << endl;
	}
};
class Medic:public Unit {
public:
	virtual void Move(int x, int y)override {
		cout << "Medic" << typeid(*this).name() << " move (" << x << "," << y << ")" << endl;
	}
};
void main() {

	Commander c;
	Medic* m;
	Marine* marine;
	c.SelectUnit(m);
	c.SelectUnit(marine);
	c.Move(1, 2);

	return;
}