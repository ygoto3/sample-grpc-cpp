IMAGE_NAME=sample-grpc-cpp
CONTAINER_NAME=sample-grpc-cpp-c

docker run -it --rm --mount type=bind,source="$(pwd)",target=/workspace --name ${CONTAINER_NAME} ${IMAGE_NAME} /bin/bash

