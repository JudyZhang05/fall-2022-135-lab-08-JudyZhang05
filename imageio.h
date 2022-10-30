#pragma once

const int MAX_H = 512; //512
const int MAX_W = 512;

void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width);
void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width); 

void invert_whole(std::string photo);
void invert_half(std::string photo);
void box(std::string photo);
void frame(std::string photo);
void scale(std::string input);
void pixel(std::string input);