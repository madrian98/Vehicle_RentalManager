#include <iostream>
#include "model/Functions.h"

using namespace std;

void Functions::displayFunction(const ClientManager& clientManager, const VehicleManager& vehicleManager, const RentsManager& rentsManager) {
    int display=0;
    while(display!=7){
        cout << "What do u want to display ? " << endl << "1.Current clients" << endl
             << "2.Archived clients" << endl << "3.Current vehicles" << endl
             << "4.Archived vehicles" << endl << "5.Current loans" << endl
             << "6.Terminated loans" << endl<<"7.Exit display section"<<endl;
        cout << "Select your choice(number): ";
        cin >> display;
        if(display==7) break;
        cout<<endl;
        switch (display) {
            default:
                cout<<"Wrong choice!"<<endl;
                break;
            case 1:
                if(clientManager.getCurrentClients().empty()){
                    cout<<"None!"<<endl;
                }
                else cout << clientManager.getCurrentClients();
                break;
            case 2:
                if(clientManager.getArchiveClients().empty()){
                    cout<<"None!"<<endl;
                }
                else cout << clientManager.getArchiveClients();
                break;
            case 3:
                if(vehicleManager.getCurrentVehicles().empty()){
                    cout<<"None!"<<endl;
                }
                else cout << vehicleManager.getCurrentVehicles();
                break;
            case 4:
                if(vehicleManager.getArchVehicles().empty()){
                    cout<<"None!"<<endl;
                }
                else cout << vehicleManager.getArchVehicles();
                break;
            case 5:
                if(rentsManager.getCurrentRents().empty()){
                    cout<<"None!"<<endl;
                }
                else cout << rentsManager.getCurrentRents();
                break;
            case 6:
                if(rentsManager.getArchRents().empty()){
                    cout<<"None!"<<endl;
                }
                else cout << rentsManager.getArchRents();
                break;
        }
    }
}

void Functions::manageFunction(ClientManager& clientManager, VehicleManager& vehicleManager, RentsManager& rentsManager) {
    int manage = 0;
    while (manage != 7) {
        cout << "What do you want to perform ?" << endl << "1.Add new client" << endl
             << "2.Remove any client" << endl << "3.Add new vehicle" << endl
             << "4.Remove any vehicle" << endl << "5.Add new loan" << endl
             << "6.Terminate any loan" << endl << "7.Exit manage section" << endl;
        cout << "Select your choice(number): ";
        cin >> manage;
        if (manage == 7) break;
        cout << endl;
        switch (manage) {
            default:
                cout << "Wrong choice!" << endl;
                break;
            case 1:
                dodajKlienta(clientManager);
                break;
            case 2:
                usunKlienta(clientManager);
                break;
            case 3:
                dodajPojazd(vehicleManager);
                break;
            case 4:
                usunPojazd(vehicleManager);
                break;
            case 5:
                dodajWypozyczenie(clientManager,vehicleManager,rentsManager);
                break;
            case 6:
                zakonczWypozyczenie(vehicleManager,rentsManager);
        }
    }
}

void Functions::dodajKlienta(ClientManager& clientManager) {
    string imie;
    string nazwisko;
    string id;
    string ulica;
    int nrDomu;
    string ulica2;
    int nrDomu2;
    cout << "Insert new client data" << endl;
    cout << "First name: ";
    cin >> imie;
    cout << "Last name: ";
    cin >> nazwisko;
    cout << "ID: ";
    cin >> id;
    cout << "Address" << endl;
    cout << "Street: ";
    cin >> ulica;
    cout << "House number: ";
    cin >> nrDomu;
    cout << "Registered address" << endl;
    cout << "Street: ";
    cin >> ulica2;
    cout << "House number: ";
    cin >> nrDomu2;
    ClientPtr klient = make_shared<Client>(imie, nazwisko, id, ulica, nrDomu, ulica2, nrDomu2);
    try {
        clientManager.addClient(klient);
    }
    catch (ExceptionClientRepository::exception &e) {
        cout<<endl<<e.what()<<endl<<endl;
    }
}

void Functions::usunKlienta(ClientManager &clientManager) {
    string id;
    bool found = false;
    cout << "Insert ID of chosen client to remove" << endl;
    cin >> id;
    for (auto &client: clientManager.getAllCurrentClients()) {
        if (client->getPersonalID() == id) {
            found = true;
            clientManager.removeClient(client);
            break;
        }
    }
    if (!found) cout << "Client with inserted ID not found!" << endl;
}

void Functions::dodajPojazd(VehicleManager &vehicleManager) {
    string rodzaj;
    float cena;
    string rejestracja;
    float pojemnosc;
    char seg;
    cout << "Insert data of new vehicle:" << endl;
    cout << "Type of vehicle (car,moped,bike): ";
    cin >> rodzaj;
    if (rodzaj != "car" && rodzaj != "moped" && rodzaj != "bike") {
        cout << "Wrong type of vehicle !" << endl;
    } else {
        cout << "Price: ";
        cin >> cena;
        cout << "Registration number: ";
        cin >> rejestracja;
        if (rodzaj == "car" || rodzaj == "moped") {
            cout << "Engine Capacity (cm3): ";
            cin >> pojemnosc;
            if (rodzaj == "car") {
                cout << "Vehicle Segment (A-E): ";
                cin >> seg;
            }
        }
        VehiclePtr pojazd=nullptr;
        if (rodzaj == "car") pojazd = make_shared<Car>(cena, rejestracja, pojemnosc, seg);
        if (rodzaj == "moped") pojazd = make_shared<Moped>(cena, rejestracja, pojemnosc);
        if (rodzaj == "bike") pojazd = make_shared<Bicycle>(cena, rejestracja);
        try {
            vehicleManager.addVehicle(pojazd);
        }
        catch (ExceptionVehicleRepository::exception &e) {
            cout << endl << e.what() << endl << endl;
        }
    }
}

void Functions::usunPojazd(VehicleManager &vehicleManager) {
    string rejestracja;
    bool found = false;
    cout << "Insert registration number of vehicle to remove" << endl;
    cin >> rejestracja;
    for (auto &vehicle: vehicleManager.getAllCurrentVehicles()) {
        if (vehicle->getRegistrationNumber()== rejestracja) {
            found = true;
            vehicleManager.removeVehicle(vehicle);
            break;
        }
    }
    if (!found) cout << "Vehicle with inserted registration number not found!" << endl;
}

void Functions::dodajWypozyczenie(ClientManager &clientManager, VehicleManager &vehicleManager, RentsManager& rentsManager) {
    string pesel;
    string rejestracja;
    ClientPtr klient=nullptr;
    VehiclePtr pojazd=nullptr;
    bool found=false;
    cout<<"Insert client ID to add new loan: ";
    cin>>pesel;
    for (auto &client: clientManager.getAllCurrentClients()) {
        if (client->getPersonalID() == pesel) {
            found = true;
            klient=client;
            break;
        }
    }
    if (!found) cout << "Client with inserted ID not found!" << endl;
    else {
        cout << "Insert vehicle registration number to add new loan: ";
        cin >> rejestracja;
        found = false;
        for (auto &vehicle: vehicleManager.getAllCurrentVehicles()) {
            if (vehicle->getRegistrationNumber() == rejestracja) {
                found = true;
                pojazd = vehicle;
                break;
            }
        }
        if (!found) cout << "Vehicle with inserted registration number not found!" << endl;
        else {
            RentPtr wypozyczenie = make_shared<Rent>(klient, pojazd);
            try{
                rentsManager.rentVehicle(wypozyczenie);
            }
            catch (ExceptionRentRepository::exception & e){
                cout << endl << e.what() << endl << endl;
            }
        }
    }
}

void Functions::zakonczWypozyczenie(VehicleManager& vehicleManager, RentsManager& rentsManager) {
    bool found = false;
    string rejestracja;
    VehiclePtr pojazd=nullptr;
    RentPtr wypozyczenie=nullptr;
    cout << "Insert registration number of vehicle to terminate its loan: ";
    cin >> rejestracja;
    for (auto &vehicle: vehicleManager.getAllCurrentVehicles()) {
        if (vehicle->getRegistrationNumber() == rejestracja) {
            found = true;
            pojazd = vehicle;
            break;
        }
    }
    if (!found) cout << "Loan of vehicle not found!" << endl;
    else {
        found=false;
        for (auto &rent: rentsManager.getAllCurrentRents()) {
            if (rent->getVehicleRented()==pojazd->vehicleInfo()) {
                wypozyczenie = rent;
                break;
            }
        }
        try {
            rentsManager.returnVehicle(wypozyczenie);
            found=true;
            cout<<wypozyczenie->rentInfo();
        }
        catch (ExceptionRentRepository::exception &e) {
            cout << endl << e.what() << endl << endl;
        }
        if (!found) cout << "Vehicle is not currently loaned" << endl;
    }
}
