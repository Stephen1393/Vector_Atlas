#include <crow.h>
#include <iostream>
#include "server.hpp"
#include "routes.cpp"

 void startServer() {

    crow::SimpleApp app;

    routeComponents(app);

    std::cout << "server listening..."; 

    app.port(18080).run();

}

