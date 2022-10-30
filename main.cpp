#include <iostream>
#include "imageio.h"

int main(){
     std::cout << "\nTASK A\n";
     invert_whole("image1.pgm");

     std::cout << "\nTASK B\n";
     invert_half("image1.pgm");

     std::cout << "\nTASK C\n";
     box("image1.pgm");

     std::cout << "\nTASK D\n";
     frame("image1.pgm");
    
    std::cout << "\nTASK E\n";
    scale("image3.pgm");

     std::cout << "\nTASK F\n";
     pixel("image1.pgm");

    return 0;
}