# sample-grpc-cpp

A sample cpp project with gRPC

# Build

Build a docker image with the Dockerfile in the `tools` directory.

```sh
$ docker build -t sample-grpc-cpp tools/Dockerfile
```

Run the script `run_docker.sh` and get in the container.

```sh
$ ./tools/run_docker.sh
```

In the docker container, run the script `gen_grpc.sh`.

```sh
$ ./tools/gen_grpc.sh
```

See if pb.cc and pb.h files were generated in the `protos/rpc` directory.

```sh
$ ls protos/rpc
sample.grpc.pb.cc sample.grpc.pb.h  sample.pb.cc      sample.pb.h
```

