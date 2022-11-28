#include <memory.h>

#include "server/grpc_server.hpp"

void serve() {
    std::unique_ptr<GrpcServer> grpc_server(new GrpcServer());
    grpc_server->run();
}

int main(int argc, char** argv) {
    serve();
    return 0;
}
