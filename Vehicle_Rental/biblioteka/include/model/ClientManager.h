#ifndef POBIPROJECT_CLIENTMANAGER_H
#define POBIPROJECT_CLIENTMANAGER_H
#include <memory>
#include <string>
#include <vector>
#include "Client.h"
#include "ClientRepository.h"


typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientRepository> ClientRepPtr;
class ClientManager {
private:
    ClientRepPtr currentClients;
    ClientRepPtr archiveClients;
public:
    void addClient(const ClientPtr&);
    void removeClient(ClientPtr &);
    ClientManager();
    std::string getArchiveClients() const;
    std::string getCurrentClients() const ;
    int getArchiveClientsNumber() const;
    int getCurrentClientsNumber() const;
    list<ClientPtr> getAllCurrentClients();
};

#endif //POBIPROJECT_CLIENTMANAGER_H
