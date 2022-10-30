#include <iostream>
#include "imageio.h"

void invert_whole(std::string photo){
    int img[MAX_H][MAX_W];
    int h, w;

    readImage(photo, img, h, w);
    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            out[row][col] = (255 - img[row][col]);
        }
    }

    writeImage("temp.pgm", out, h, w);
}

void invert_half(std::string photo){
    int img[MAX_H][MAX_W];
    int h, w;

    readImage(photo, img, h, w);
    int out[MAX_H][MAX_W];

    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if (col >= w/2){
                out[row][col] = (255 - img[row][col]);
            }
            else{
                out[row][col] = (img[row][col]);
            }
        }
    }

    writeImage("temphalf.pgm", out, h, w);
}
