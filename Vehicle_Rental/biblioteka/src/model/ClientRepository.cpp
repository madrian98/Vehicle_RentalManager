
#include "model/Client.h"
#include "model/ClientRepository.h"
#include "model/ExceptionClientRepository.h"

bool ClientRepository::create(ClientPtr &client) {
    for (const auto &c : allClients) {
        if(client->getPersonalID() == c -> getPersonalID())
        {
          throw ExceptionClientRepository(ExceptionClientRepository::exceptionClientExist);
        }
    }
        allClients.push_back(client);
    return true;
}
bool ClientRepository::remove(ClientPtr &client) {
    if (client == nullptr) throw ExceptionClientRepository(ExceptionClientRepository::exceptionClientNullPtr);
    bool found = (std::find(allClients.begin(), allClients.end(), client) != allClients.end());
    if (!found) throw ExceptionClientRepository(ExceptionClientRepository::exceptionClientNotExist);
    allClients.remove(client);
    return true;
}
bool ClientRepository::update(ClientPtr &actualClient, ClientPtr &newClient) {
    if(actualClient== nullptr || newClient== nullptr) throw ExceptionClientRepository(ExceptionClientRepository::exceptionClientNullPtr);
    actualClient=newClient;
    allClients.erase(std::remove(allClients.begin(),allClients.end(),newClient),allClients.end());
    return actualClient!= nullptr && newClient== nullptr;
}
string ClientRepository::getAll() {
    ostringstream chain;
    int it=1;
    for(const auto& clientPtr: allClients){
        chain<<"Nr. "<<to_string(it++)<<endl;
        chain<< clientPtr->clientInfo();
        chain<<endl;
    }
    return chain.str();
}
ClientPtr &ClientRepository::find(const unsigned int &in) {
    if(in>allClients.size()) throw ExceptionClientRepository(ExceptionClientRepository::exceptionClientNotExist);
    unsigned int i=1;
    for (auto& c:allClients){
        if(i==in){
            return c;
        }
        i++;
    }
    throw ExceptionClientRepository(ExceptionClientRepository::exceptionClientNotExist);
}
void ClientRepository::removeClient(unsigned int &in) {
    unsigned int i = 1;
    if (in > allClients.size()) throw ExceptionClientRepository(ExceptionClientRepository::exceptionClientNotExist);
    for (auto& client : allClients){
        if(i==in){
            allClients.remove(client);
        }
    }
    throw ExceptionClientRepository(ExceptionClientRepository::exceptionClientNotExist);
}
void ClientRepository::changeType(ClientPtr &client, ClientTypePtr &clientType) {
    if (client == nullptr) throw ExceptionClientRepository(ExceptionClientRepository::exceptionClientNullPtr);
    client->setClientType(clientType);
}

const list<ClientPtr>& ClientRepository::getRepository() const{
    return allClients;
}
