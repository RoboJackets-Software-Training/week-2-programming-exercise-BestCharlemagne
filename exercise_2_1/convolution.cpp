#include "convolution.h"

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros){
  // TODO write your code here
  // =========== START =========
  std::vector<double> y;

  int vector_offset = (w.size() - 1) / 2;

  for (int i = 0; i < x.size(); i ++) {
    int intermediate_convolution = 0;
    for (int j = 0; j < w.size(); j++) {
      int vector_multiplier = x[i - vector_offset + j];
      if (!pack_with_zeros) {
        if (i - vector_offset + j < 0) {
          vector_multiplier = x[0];
        } else if (i - vector_offset + j > x.size() - 1) {
          vector_multiplier = x[x.size() - 1];
        }
      }

      intermediate_convolution += w[j] * vector_multiplier;
    }
      y.push_back(intermediate_convolution);
  }
  
  return y;
}

void printVector(std::vector<double> vec) {
  std::cout << "{" << vec[0];
  for(int i = 1; i < vec.size(); i++) {
    std::cout << ", " << vec[i];
  }
  std::cout << "}" << std::endl;
}