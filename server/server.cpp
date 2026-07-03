#include <crow.h>
#include <iostream>
#include "server.hpp"

 void startServer() {

    crow::SimpleApp app;

    std::cout << "server listening...";

    app.port(18080).run();

}

