
PROJECT(rpc)

CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

ADD_SUBDIRECTORY(src)

#INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
#INCLUDE_DIRECTORIES(/usr/local/include/)


#INCLUDE_DIRECTORIES("/home/cdsl/cvs/protobuf/build/include")
message(${PROJECT_SOURCE_DIR})
message(WARNING "bin dir is ${CMAKE_CURRENT_BINARY_DIR}")

ADD_EXECUTABLE(generate ${PROJECT_SOURCE_DIR}/src/generate.cxx ${PROJECT_SOURCE_DIR}/src/onnx.pb.cc)
#ADD_EXECUTABLE(generate ${PROJECT_SOURCE_DIR}/src/generate.cxx )

message("-------------------")

TARGET_LINK_LIBRARIES(generate ${PROTOBUF_LIBRARY})


#TARGET_LINK_LIBRARIES(generate  "/usr/local/lib/libprotobuf.so")

message(WARNING "pb lib path is ${PROTOBUF_LIBRARY}")
