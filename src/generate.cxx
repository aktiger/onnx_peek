#include "onnx_loader.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[]) {


  GOOGLE_PROTOBUF_VERIFY_VERSION;

  onnx_loader loader(argv[1]);
  const onnx::ModelProto model = loader.get_model();
  std::cout << "1" << endl;

  return 0;
}
