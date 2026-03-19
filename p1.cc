// Program 1 - HW2
// Author: Katherin Cuautli

#include <iostream>
#include <string>

#include "image.h"
using namespace ComputerVisionProjects;

int main(int argc, char **argv){ //command line arguments
  if (argc != 4) { //program exits if wrong number of arguments on command line are given
    std::cout << "Usage: " <<
      argv[0] << " {input_image_name} {threshold} {output_image_name}" << std::endl;
    return 0;
  }
  const std::string input_file(argv[1]);
  const int threshold = std::stoi(argv[2]);
  const std::string output_file(argv[3]);

  std::cout << "Running p1 " << input_file << " " 
  << threshold << " " << output_file << std::endl;

  //Testing my first image:
  Image testIm;
  if(!ReadImage(input_file, &testIm)){
    std::cout << "Failed to Read!" << std::endl;
    return 1;
  }

  //Looping through each pixel & setting either white or black based on provided threshold
  for(size_t i=0; i<testIm.num_rows(); ++i){
    for(size_t j=0; j<testIm.num_columns(); ++j){
      int pixel = testIm.GetPixel(i, j);
      if(pixel >= threshold){
        testIm.SetPixel(i, j, 255); //setting to white pixels
      } else {
        testIm.SetPixel(i, j, 0);   //setting to black pixels
      }
    }
}
  //Creates a new image with specified name applying these changes to the pixels
  if(!WriteImage(output_file, testIm)){
    std::cout << "Failed to Write!" << std::endl;
    return 1;
  } 
}
