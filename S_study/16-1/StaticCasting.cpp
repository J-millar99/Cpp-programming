#include <iostream>
using namespace std;

class Car
{
	private:
		int fuelGauge;		
	public:
		Car (int fuel) : fuelGauge(fuel)
		{  }
		void ShowCarState()
		{
			cout << "잔여 연료량: " << fuelGauge << endl;
		}
};

class Truck : public Car
{
private:
	int freightWeight;

public:
	Truck (int fuel, int weight)
		: Car(fuel), freightWeight(weight)
	{  }
	void ShowTruckState()
	{
		ShowCarState();
		cout << "화물의 무게: " << freightWeight << endl;
	}
};

/*
    static casting: 유도클래스에서 기초클래스로 갈 수 있게 + dynamic casting의 방식까지
    static casting은 dynamic casting보다 더 많은 형 변환을 허용한다.
*/

int main(void)
{
    Car *pcar1 = new Truck(80, 200);
    Truck *ptruck1 = static_cast<Truck *>(pcar1);
    ptruck1->ShowTruckState();
    cout << endl;

    Car *pcar2 = new Car(120);
    Truck *ptruck2 = static_cast<Truck *>(pcar2);
    ptruck2->ShowTruckState();
    cout << endl;
    return 0;
}