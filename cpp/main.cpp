#include <iostream>
#include "image.h"
#include "group.h"
#include <memory>
#include <string>
#include <iostream>
#include <sstream>
#include "tcpserver.h"
#include "data.h"

const int PORT = 3331;

int main()
{
    std::shared_ptr<Data> data(new Data());
    data->createImage("image char", "char.jpg",1,1);
    data->createImage("image voiture", "voiture.png",1,1);
    data->createGroup("images");
    data->addMediaToGroup("image char","images");
    // cree le TCPServer
    std::shared_ptr<cppu::TCPServer> server(new cppu::TCPServer());

    // le serveur appelera cette méthode chaque fois qu'il y a une requête
    server->setCallback(*data, &Data::processRequest);
    
    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;
    int status = server->run(PORT);
    
    // en cas d'erreur
    if (status < 0)
    {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }

	return 0;
}
