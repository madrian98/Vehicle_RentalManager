#include "model/ClientManager.h"
#include"model/ExceptionClientRepository.h"

void ClientManager::addClient(const ClientPtr &client) {
    for(const auto& klient : currentClients->getRepository())
    {
        if(client == klient)
        {
            throw ExceptionClientRepository(ExceptionClientRepository::exceptionClientExist);
        }
    }
    for(const auto& klient : archiveClients->getRepository())
    {
        if(client == klient)
        {
            archiveClients->remove(const_cast<ClientPtr &>(client));
            break;
        }
    }
    currentClients->create(const_cast<ClientPtr &>(client));
}

void ClientManager::removeClient(ClientPtr &client) {
    archiveClients->create(client);
    currentClients->remove(client);
}

ClientManager::ClientManager():
    currentClients(new ClientRepository),
    archiveClients(new ClientRepository)
    {}

int ClientManager::getArchiveClientsNumber() const {
    return archiveClients->getRepository().size();
}

int ClientManager::getCurrentClientsNumber() const {
    return currentClients->getRepository().size();
}

string ClientManager::getArchiveClients() const {
    return archiveClients->getAll();
}

string ClientManager::getCurrentClients() const {
    return currentClients->getAll();
}

list<ClientPtr> ClientManager::getAllCurrentClients(){
    return currentClients->getRepository();
}