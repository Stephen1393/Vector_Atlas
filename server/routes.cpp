#include <crow.h>

void routes() {
    
    CROW_ROUTE(app, "/")([]()) {
    return "hello World!";

};
} 