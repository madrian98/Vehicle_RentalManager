
#ifndef POBIPROJECT_CLIENTREPOSITORY_H
#define POBIPROJECT_CLIENTREPOSITORY_H

#include <memory>
#include <list>
#include "model/Client.h"
#include "model/ClientType.h"
#include "model/Rent.h"
#include "model/Repository.h"

using namespace std;

typedef shared_ptr<Client> ClientPtr ;
typedef shared_ptr<ClientType> ClientTypePtr;

class ClientRepository: public Repository<Client>{
private:
    list<ClientPtr> allClients{};
public:
   bool create(ClientPtr &client) override;
   bool remove(ClientPtr &client) override;
   bool update(ClientPtr &actualClient, ClientPtr &newClient) override;
  std::string getAll() override;
   ClientPtr& find(const unsigned int&) override;
   void removeClient(unsigned int &);
   void changeType(ClientPtr &, ClientTypePtr &);
    const list<ClientPtr>& getRepository() const override ;
};


#endif //POBIPROJECT_CLIENTREPOSITORY_H
