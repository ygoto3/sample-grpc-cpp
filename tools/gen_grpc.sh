mkdir protos
protoc \
    --proto_path=./source_protos \
    --grpc_out=./protos --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` \
    ./source_protos/rpc/*.proto
protoc \
    --proto_path=./source_protos \
    --cpp_out=./protos \
    ./source_protos/rpc/*.proto

