

#include <iostream>
#include <string>
using namespace std;

class Engine {
    private:
        int m_EngineCapacity;
        int m_Horsepower;
        bool m_EngineRunning;
    public:
        Engine(int EngineCapacity=2000, int Horsepower=200) {
            m_EngineCapacity = EngineCapacity;
            m_Horsepower = Horsepower;
            m_EngineRunning = false;
        }
        bool EngineStart() {
            if(!m_EngineRunning) {
                m_EngineRunning = true;
            }
            return true;
        };
        bool EngineStop() {
            if(m_EngineRunning) {
                m_EngineRunning = false;
            }
            return false;
        };
        bool get_EngineStatus() {
            return m_EngineRunning;
        };
};
class Car {
    protected:
        string m_DriveMode;
    
    private:
        Engine m_Engine;
        int m_price;
        int m_MaxSeating;
        void m_UpdatePrice(int base = 500000) {
            m_price = m_MaxSeating * base;
        }
    public:
        string m_brand;
        string m_model;
        int m_year;
        
        Car(string x, string y, int z, int s) {
            m_brand = x;
            m_model = y;
            m_year = z;
            m_MaxSeating = s;
            m_UpdatePrice();
            m_DriveMode = "No-wheel";
        }
        int get_m_MaxSeating() {
            return m_MaxSeating;
        }
        int get_m_price() {
            return m_MaxSeating * 500000;
        }
        string get_DriveMode() {
            return m_DriveMode;
        }
        bool get_EngineStatus() {
            return m_Engine.get_EngineStatus();
        };
        bool startEngine() {
            return m_Engine.EngineStart();
        };
        bool stopEngine() {
            return m_Engine.EngineStop();
        };
};

class BMW_Car : public Car {   
    public:
    BMW_Car(string y, int z, int s) : Car("BMW", y, z, s) {
        cout << "Constructing BMW_Car\n";
        m_DriveMode = "Rear-wheel" ;
    }
    string get_DriveMode() {
        return m_DriveMode;
    }
};
class AUDI_Car : public Car {   
    public:
    AUDI_Car(string y, int z, int s) : Car("AUDI", y, z, s) {
        cout << "Constructing AUDI_Car\n";
        m_DriveMode = "Front-wheel" ;
    }
    string get_DriveMode() {
        return m_DriveMode;
    }
};
class BENZ_Car: public Car {
    public:
    BENZ_Car(string y, int z, int s) : Car("BENZ", y, z, s) {
        cout << "Constructing BENZ_Car" << endl;
        m_DriveMode = "Rear-wheel";
    }
    string get_DriveMode() {
        return m_DriveMode;
    }
};



int main()
{

    BMW_Car car_1("X5", 2023, 6);
    cout << car_1.m_brand;
    cout << " : EngineStatus = " << car_1.get_EngineStatus() << endl;
    
    AUDI_Car car_2("A1", 2023, 5);
    car_2.startEngine();
    cout << car_2.m_brand;
    cout << " : EngineStatus = " << car_2.get_EngineStatus() << endl;
    car_2.stopEngine();
    cout << " : EngineStatus = " << car_2.get_EngineStatus() << endl;

    return 0;
}
