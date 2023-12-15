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
    dynamic casting: 유도클래스에서 기초클래스로 바꿀 수 있게
*/
int main(void)
{
    Car *pcar1 = new Truck(80, 200);
    Truck *ptruck1 = dynamic_cast<Truck *>(pcar1);
    Car *pcar2 = new Car(120);
    Truck *ptruck2 = dynamic_cast<Truck *>(pcar2);
    Truck *pcar3 = new Truck(80, 200);
    Car *ptruck1 = dynamic_cast<Car *>(pcar3);
    return 0;
}