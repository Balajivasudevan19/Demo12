
//Protobuf Definition:

//Create a file named helloworld.proto with the following content:

Protocol Buffers
syntax = "proto3";

package helloworld;

message HelloRequest {
  string name = 1;
}

message HelloReply {
  string message = 1;
}

service Greeter {
  rpc SayHello(HelloRequest) returns (HelloReply);
}


#####################################################################################################################
//Compile the protocol buffer file using protoc:

Bash
protoc helloworld.proto --cpp_out=. --grpc_cpp_out=.


########################################################################################################################
//Create a file named server.cc 

#include "helloworld.grpc.pb.h"
#include "helloworld.pb.h"
#include <grpc++/server.h>
#include <grpc++/server_builder.h>
#include <grpc++/server_context.h>

class GreeterServiceImpl final : public helloworld::Greeter::Service {
 public:
  grpc::Status SayHello(grpc::ServerContext* context,
                         const helloworld::HelloRequest* request,
                         helloworld::HelloReply* reply) override {
    reply->set_message("Hello, " + request->name() + "!");
    return grpc::Status::OK;
  }
};

int main() {
  std::string server_address("0.0.0.0:50051");
  GreeterServiceImpl service;

  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);
  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();

  return 0;
}

###############################################################################################################################
//Create a file named client.cc :

C++
#include "helloworld.grpc.pb.h"
#include "helloworld.pb.h"
#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>
#include <grpc++/credentials.h>

int main() {
  std::string server_address("localhost:50051");
  std::unique_ptr<helloworld::Greeter::Stub> stub =
      helloworld::Greeter::NewStub(grpc::CreateChannel(
          server_address, grpc::InsecureChannelCredentials()));

  helloworld::HelloRequest request;
  request.set_name("John Doe");
  helloworld::HelloReply reply;

  grpc::ClientContext context;
  grpc::Status status = stub->SayHello(&context, request, &reply);

  if (status.ok()) {
    std::cout << "Greeting from server: " << reply.message() << std::endl;
  } else {
    std::cerr << "RPC failed: " << status.error_message() << std::endl;
  }

  return 0;
}
