

#ifndef POBIPROJECT_REPOSITORY_H
#define POBIPROJECT_REPOSITORY_H

#include <memory>
#include <list>
#include <sstream>

template< class myClass>

class Repository{
public:
    virtual bool create(std::shared_ptr<myClass>&)=0;
    virtual bool remove(std::shared_ptr<myClass>&)=0;
    virtual bool update(std::shared_ptr<myClass>&,std::shared_ptr<myClass>&)=0;
    virtual std::string getAll()=0;
    virtual std::shared_ptr<myClass>& find(const unsigned int&)=0;
    virtual const std::list<std::shared_ptr<myClass>>& getRepository() const= 0;
};


#endif //POBIPROJECT_REPOSITORY_H
