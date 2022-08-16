#include <iostream>
#include <memory>
#include <sstream>
#include "model/Client.h"
#include "model/ClientType.h"
#include "model/SilverClient.h"
#include "model/ClientManager.h"
#include "model/RentsManager.h"
#include "model/VehicleRepository.h"
#include "model/VehicleManager.h"
#include "model/Moped.h"
#include "model/Car.h"
#include "model/Bicycle.h"
#include "model/Functions.h"
#include "model/ExceptionClientRepository.h"

using namespace std;

int main()
{
    //Default clients

    ClientPtr klient1=make_shared<Client>("Jan", "Kowalski", "1", "Polna", 215, "Testowa", 2);
    ClientPtr klient2=make_shared<Client>("Anna", "Nowak", "2", "Lesna", 15, "Testowa", 2);
    ClientPtr klient3=make_shared<Client>("Marcin", "Wozniak", "3", "Wschodnia", 31, "Testowa", 2);
    ClientPtr klient4=make_shared<Client>("Michal", "Mickiewicz", "4", "Ludowa", 1, "Testowa", 2);
    ClientPtr klient5=make_shared<Client>("Radosław", "Kowalski", "5", "Miejska", 98, "Testowa", 2);
    ClientManager clientManager;
    clientManager.addClient(klient1);
    clientManager.addClient(klient2);
    clientManager.addClient(klient3);
    clientManager.addClient(klient4);
    clientManager.addClient(klient5);

    //Default vehicles
    VehiclePtr rower1 = make_shared<Bicycle>(10,"BMX1");
    VehiclePtr samochod1=make_shared<Car>(1500,"BMW2",1000,'A');
    VehiclePtr samochod2=make_shared<Car>(4300,"MERC3",4000,'C');
    VehiclePtr samochod3=make_shared<Car>(2500,"AUDI4",3000,'E');
    VehiclePtr skuter1=make_shared<Moped>(50,"MOPED1",50);
    VehicleManager vehicleManager;
    vehicleManager.addVehicle(rower1);
    vehicleManager.addVehicle(samochod1);
    vehicleManager.addVehicle(samochod2);
    vehicleManager.addVehicle(samochod3);
    vehicleManager.addVehicle(skuter1);

    //Default loans

    RentPtr wypozyczenie1=make_shared<Rent>(klient1,samochod1);
    RentPtr wypozyczenie2=make_shared<Rent>(klient2,rower1);
    RentsManager rentsManager;
    rentsManager.rentVehicle(wypozyczenie1);
    rentsManager.rentVehicle(wypozyczenie2);

    //Logic
    int function_insert=0;
    while(function_insert != 3){
        cout<<"Welcome in car workshop"<<endl<<"Choose your action(1-3)!"<<endl<<"1.Display workshop information"<<endl<<"2.Manage the workshop"<<endl<<"3- Terminate program"<<endl;
        cin >> function_insert;
        if(function_insert == 3) break;
        switch(function_insert){
            default:
                cout<<"Incorrect choice!"<<endl;
                break;
            case 1:
                Functions::displayFunction(clientManager, vehicleManager, rentsManager);
                break;
            case 2:
                Functions::manageFunction(clientManager, vehicleManager, rentsManager);
                break;
        }
    }
    return 0;
}

