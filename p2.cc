// Program 2 - HW2
// Author: Katherin Cuautli

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

  //Testing for input image
  Image inputIm; //reading image first
  if(!ReadImage(input_file, &inputIm)){
    std::cout << "File not read" << std::endl;
    return 1;
  };

  //Set new image to be of same dimensions of input
  int rows = inputIm.num_rows();
  int cols = inputIm.num_columns();

  //Generating new output image with labels
  Image outputIm;
  outputIm.AllocateSpaceAndSetSize(rows, cols);
  outputIm.SetNumberGrayLevels(255); //****

  //Initializing output to 0
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      outputIm.SetPixel(i, j, 0); 
    }
  }

  int nextLabel = 1;
  DisjSets equal(rows * cols + 100); //set the max num of labels

  //First Pass: assigning temporary labels
  std::cout << "Starting first pass..." << std::endl;
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      if(inputIm.GetPixel(i,j) == 0) continue; //skip the black bg pixels
        //Checking the left and top neighbors (4-connectedness)
        int left = 0;
        if(j > 0 && inputIm.GetPixel(i, j-1) != 0){
          left = outputIm.GetPixel(i, j-1);}
        int top = 0;
        if (i > 0 && inputIm.GetPixel(i-1, j) != 0){
          top = outputIm.GetPixel(i-1, j);}

      //If no labeled neighbor, assign new label
      if (left == 0 && top == 0){
        outputIm.SetPixel(i, j, nextLabel);
        ++nextLabel;
      
      //If only left is labeled, assign that same label
      } else if(left != 0 && top == 0){
          outputIm.SetPixel(i, j, left);

      //If only top is labeled, assign that same label
      } else if (left == 0 && top != 0){
          outputIm.SetPixel(i, j, top);

      //Both neighbors labeled, could be same or diff.
      } else{ 
          int minLabel = (left < top) ? left : top;
          int maxLabel = (left > top) ? left : top;
          outputIm.SetPixel(i, j, minLabel); //assign min label
          int root1 = equal.find(minLabel);
          int root2 = equal.find(maxLabel);
          if(root1 != root2){
            equal.unionSets(root1, root2);
          } //eventually will reach equivalence
      }
      /* Checking if merging between different objects' pixels is occuring 
      if(left != 0 && top != 0 && left != top) {
        std::cout << "Merging " << left << " and " << top 
        << " at (" << i << "," << j << ")" << std::endl;
      }
      */
    }
  }

  std::cout << "Max label used: " << nextLabel << std::endl;
  std::cout << "Finished first pass. Starting second pass..." << std::endl;
  //Second pass: resolving equivalence
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      int label = outputIm.GetPixel(i,j);
      if(label != 0){
        outputIm.SetPixel(i, j, equal.find(label));
      }
    }
  } 

  std::cout << "Finished second pass. Writing image..." << std::endl;
  //Writing to new output image
  if (!WriteImage(output_file, outputIm)) {
      std::cout << "Failed to write to image" << std::endl;
      return 1;
  }

  return 0;
}
