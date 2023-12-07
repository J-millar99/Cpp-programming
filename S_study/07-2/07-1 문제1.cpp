#include <iostream>
using namespace std;

class Car
{
    private:
        int gasolineGauge;
    
    public:
        Car(int gas) : gasolineGauge(gas) {}
        int GetGasGauge()
        {
            return gasolineGauge;
        }
};

class HybirdCar : public Car
{
    private:
        int electricGauge;

    public:
        HybirdCar(int gas, int elec) : Car(gas), electricGauge(elec) {}
        int GetElecGauge()
        {
            return electricGauge;
        }
};

class HybirdWaterCar : public HybirdCar
{
    private:
        int waterGauge;
    
    public:
        HybirdWaterCar(int gas, int elec, int water) : HybirdCar(gas, elec), waterGauge(water) {}
        void ShowCurrentGauge()
        {
            cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
            cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
            cout<<"잔여 워터량: "<<waterGauge<<endl;
        }
};

int main(void)
{
    HybirdWaterCar car(1, 2, 3);
    car.ShowCurrentGauge();
    return 0;
}