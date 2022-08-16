#ifndef currentRentsRepositoryClass
#define currentRentsRepositoryClass
#include <list>
#include <memory>
#include "model/Rent.h"
#include "model/Repository.h"
#include "model/ExceptionRentRepository.h"

typedef shared_ptr<Rent> RentPtr;

class RentsRepository: public Repository<Rent>{
private:
    list<RentPtr> rentRepositoryList{};
public:
    bool create(RentPtr &rent) override;
    bool remove(RentPtr &rent) override;
    bool update(RentPtr &actualRent, RentPtr &newRent) override;
    string getAll() override;
    RentPtr& find(const unsigned int&) override;
    const list<RentPtr>& getRepository() const override ;
};
#endif