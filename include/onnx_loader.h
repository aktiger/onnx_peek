#ifndef ONNX_LOADER_H
#define ONNX_LOADER_H

#include <fstream>
#include <iostream>
#include <string>

#include <unistd.h>  // for O_RDONLY
#include <fcntl.h>  //for open ,close(), create

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/text_format.h>

#include "onnx.pb.h"

using google::protobuf::io::FileInputStream;
using google::protobuf::io::FileOutputStream;
using google::protobuf::io::ZeroCopyInputStream;
using google::protobuf::io::CodedInputStream;
using google::protobuf::io::ZeroCopyOutputStream;
using google::protobuf::io::CodedOutputStream;
using google::protobuf::Message;

class onnx_loader {
  public:
    onnx_loader(const char* file) {

      //std::fstream input(file, std::ios::in | std::ios::binary);
      int fd = open(file, O_RDONLY);

      ZeroCopyInputStream * raw_input = new FileInputStream(fd);
      CodedInputStream * coded_input = new CodedInputStream(raw_input);
      coded_input->SetTotalBytesLimit(INT_MAX, 536870912);

      bool success = m_model.ParseFromCodedStream(coded_input);

      if (!success) {
        std::cerr << "Failed to parse onnx file." << std::endl;
        exit(1);
      }

      close(fd);

    }

    ~onnx_loader() {}

    const onnx::ModelProto& get_model() {
        return m_model;
    }

  private:
    onnx::ModelProto m_model;


};

#endif
