#include <iostream>
#include "imageio.h"

void box(std::string photo){
    int img[MAX_H][MAX_W];
    int h, w;

    readImage(photo, img, h, w);
    int out[MAX_H][MAX_W];

    int whalf = ((w/2)/2);
    int rhalf = ((h/2)/2);
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if((row >= rhalf && row <= h - rhalf) && (col >= whalf && col <= w - whalf)){
                out[row][col] = 255;
            }
            else{
                out[row][col] = img[row][col];
            }
        }
    }
    writeImage("tempbox.pgm", out, h, w);
}

void frame(std::string photo){
    int img[MAX_H][MAX_W];
    int h, w;

    readImage(photo, img, h, w);
    int out[MAX_H][MAX_W];

    int whalf = ((w/2)/2);
    int rhalf = ((h/2)/2);
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if ((col == whalf || col == w - whalf) && (row >= rhalf && row <= h - rhalf)){
                out[row][col] = 255;
            }
            else if ((row == rhalf || row == h - rhalf) && (col >= whalf && col <= w - whalf)){
                out[row][col] = 255;
            }
            else{
                out[row][col] = img[row][col];
            }
        }
    }
    writeImage("tempframe.pgm", out, h, w);
}
