#include <pistache/endpoint.h>
#include "MessageHandler.h"
#include "DataInit.h"
#include "FoodCategory.h"

using namespace Pistache;

std::vector<FoodCategory> categories;

int main() {
    initializeData(categories);

    Address addr(Ipv4::any(), Port(4700));
    // Create the HTTP endpoint
    Http::Endpoint server(addr);

    auto opts = Http::Endpoint::options().threads(4);
    server.init(opts);

    // Create and configure the handler
    MessageHandler messageHandler;

    // Set the handler for the server
    server.setHandler(Http::make_handler<MessageHandler>());

    // Start the server
    server.serve();
    server.shutdown();

    return 0;
}
