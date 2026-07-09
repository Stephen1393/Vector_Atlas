#include <crow.h>
#include "server.hpp"

void routeComponents(crow::SimpleApp&app) {

    CROW_ROUTE(app,"/") ([](){
        return  "Project VectorAtlas";
    });

};