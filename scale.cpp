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


/*
#include <iostream>

int main()
{
    int img[2][2] = {1,2 , 3,4};
    int out[4][4];
    int h = 2; int w = 2;
    int newrow = 0; int newcol = 0;
    
    //std::cout << img[1][1] <<std::endl;
    for ( int row = 0; row < h; row++){
        for ( int col = 0; col < w; col++){
            if (row % 2 == 0){
                 if (col % 2 == 0){
                     std::cout << row << ' ' << col << ' ' << img[row][col] << '\n';
                 }
        //             out[newrow][newcol] = img[row][col];
        //         }
        //         else{
        //             out[newrow][newcol] = img[row][col-1];
        //         }
        //     }
        //     else{
        //         if (col % 2 == 0){
        //             out[newrow][newcol] = img[row-1][col];
        //         }
        //         else{
        //             out[newrow][newcol] = img[row-1][col-1];
        //         }
        //     }
        //     newcol+=1;
        // }
        // newrow+=1;
            }
            }
    }
     
     for (int x = 0; x < 2; x++){
          for (int g = 0; g < 2; g++){
              std::cout << img[x][g] << "         ";
         }
         std::cout << std::endl;
      }
     
      std::cout << "\n__________________________________________\n\n";
    //  for (int i = 0; i < 4; i++){
    //      for (int o = 0; o < 4; o++){
    //          //std::cout << out[i][o] << "         ";
    //      }
    //      //std::cout << std::endl;
    //  }
    return 0;
}



    for ( int row = 0; row < h; row++){
        for ( int col = 0; col < w; col++){
            if (row % 2 == 0){
                if (col % 2 == 0){
                    out[newrow][newcol] = img[row][col];
                }
                else{
                    out[newrow][newcol] = img[row][col-1];
                }
            }
            else{
                if (col % 2 == 0){
                    out[newrow][newcol] = img[row-1][col];
                }
                else{
                    out[newrow][newcol] = img[row-1][col-1];
                }
            }
            newcol+=1;
        }
        newrow+=1;
    }
*/