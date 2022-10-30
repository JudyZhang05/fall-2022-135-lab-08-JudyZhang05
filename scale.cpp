#include <iostream>
#include "imageio.h"

void scale(std::string input){
    int img[MAX_H][MAX_W];
    int h, w;
    int newrow = 0;
    int newcol = 0; 
    readImage(input, img, h, w); 

    int out[MAX_H][MAX_W];
    //std::cout << h << ' ' << w << std::endl;
    //std::cout << h << ' ' << w << std::endl;
    
    for (int row = 0; row < h; row++){
            for (int col = 0; col < w; col++){

                out[newrow][newcol]=img[row][col];
                out[newrow][newcol+1]=img[row][col];
                out[newrow+1][newcol]=img[row][col];
                out[newrow+1][newcol+1]=img[row][col];
            
                //std::cout<<std::endl;
                //std::cout<<newrow <<' ' <<newcol << "        " << row << ' ' << col;
                //std::cout<<std::endl;
                newcol+=2;
        }

        newrow+=2;
        newcol = 0;

    }
    h*=2; w*=2;
    
    writeImage("tempscale.pgm", out, h, w);

}

void pixel(std::string input){
    int img[MAX_H][MAX_W];
    int h, w;
    readImage(input, img, h, w); 

    int out[MAX_H][MAX_W];
    int avg;

    for(int row = 0; row < h; row+=2) {
        for(int col = 0; col < w; col+=2) {
            avg = ((img[row][col] + img[row][col+1] + img[row+1][col] + img[row+1][col+1])/4);
            for (int twoh = 0; twoh < 2; twoh++){
                for (int twow = 0; twow < 2; twow++){
                    out[row+twoh][col+twow] = avg;
                }
            }
        }
    }
    writeImage("temppixel.pgm", out, h, w);  
}
