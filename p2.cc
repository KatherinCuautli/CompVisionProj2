// Program 2 - HW2
// Author: <YOUR NAME>

#include <iostream>
#include <string>

#include "image.h"
#include "DisjSets.h"
using namespace ComputerVisionProjects;

int main(int argc, char **argv){
  
  if (argc!=3) {
    std::cout << "Usage: " <<
      argv[0] << " {input_image_name} {output_image_name}" << std::endl;
    return 0;
  }
  const std::string input_file(argv[1]);
  const std::string output_file(argv[2]);

  std::cout << "Running p2 " << input_file << " " << output_file << std::endl;

  return 0;
}
