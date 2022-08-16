#ifndef address
#define address
#include <string>
#include <iostream>

class Address{
private:
    std::string street;
    int houseNumber;
public:
    Address(std::string ulica, int numerDomu);
    ~Address();
    std::string getAddress() const;
    void setAddress(std::string,int);
};
#endif