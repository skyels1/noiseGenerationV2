#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define gridCellsX 10
#define gridCellsY 10
#define pixelsPerCell 100
#define WIDTH (gridCellsX * pixelsPerCell)
#define HEIGHT (gridCellsY * pixelsPerCell)

int main() {
    srand(time(NULL));

    bool selectedPoint = false;
    int noiseMap[WIDTH][HEIGHT] = {0};

    // loop through whole map, all grids
    for(int gridPosY = 0; gridPosY < gridCellsY; gridPosY++) {
        for(int gridPosX = 0; gridPosX < gridCellsX; gridPosX++) {

            // loop through only the grids box for each cell
            for(int i = 0; i < pixelsPerCell; i++) {
                for(int j = 0; j < pixelsPerCell; j++) {

                    // if the point isnt made make one and if it is dont make another
                    if(!selectedPoint) {
                    int randX = rand() % pixelsPerCell;
                    int randY = rand() % pixelsPerCell;
                    int pixelX = gridPosX * pixelsPerCell + randX;
                    int pixelY = gridPosY * pixelsPerCell + randY;

                    noiseMap[pixelX][pixelY] = 255;
                    selectedPoint = true;
                    }

                }
            }
            selectedPoint = false;
        }
    }

    // directions of nearby pixels 
    int directions[25][2] = {
        {-2,-1}, {-2,0}, {-2,1},
        {-1,-2}, {-1,-1}, {-1,0}, {-1,1}, {-1,2},
        {0,-2}, {0,-1},          {0,1}, {0,2},
        {1,-2}, {1,-1}, {1,0}, {1,1}, {1,2},
        {2,-1}, {2,0}, {2,1}
    };


    // loop both directions to spread the gradient
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            for(int d = 0; d < 25; d++) {
                int Oi = i + directions[d][0];
                int Oj = j + directions[d][1];
                if(Oi >= 0 && Oi < WIDTH && Oj >= 0 && Oj <HEIGHT) {
                    if(noiseMap[Oi][Oj] < noiseMap[i][j]) {
                        noiseMap[Oi][Oj] = noiseMap[i][j] * 0.9625;
                    }
                }
            }
            
        }
    }
    for(int i = WIDTH - 1; i >= 0; i--) {
        for(int j = HEIGHT - 1; j >= 0; j--) {
            for(int d = 0; d < 25; d++) {
                int Oi = i + directions[d][0];
                int Oj = j + directions[d][1];
                if(Oi >= 0 && Oi < WIDTH && Oj >= 0 && Oj <HEIGHT) {
                    if(noiseMap[Oi][Oj] < noiseMap[i][j]) {
                        noiseMap[Oi][Oj] = noiseMap[i][j] * 0.9625;
                    }
                }
            }
            
        }
    }
    // loop and all values over a set amount just go to highest
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            if(noiseMap[i][j] >= 80) {
                noiseMap[i][j] = 0;
            }
        }
            
    }

    // loop both directions to spread the gradient
    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            for(int d = 0; d < 25; d++) {
                int Oi = i + directions[d][0];
                int Oj = j + directions[d][1];
                if(Oi >= 0 && Oi < WIDTH && Oj >= 0 && Oj <HEIGHT) {
                    if(noiseMap[Oi][Oj] < noiseMap[i][j]) {
                        noiseMap[Oi][Oj] = noiseMap[i][j] * 0.9625;
                    }
                }
            }
            
        }
    }
    for(int i = WIDTH - 1; i >= 0; i--) {
        for(int j = HEIGHT - 1; j >= 0; j--) {
            for(int d = 0; d < 25; d++) {
                int Oi = i + directions[d][0];
                int Oj = j + directions[d][1];
                if(Oi >= 0 && Oi < WIDTH && Oj >= 0 && Oj <HEIGHT) {
                    if(noiseMap[Oi][Oj] < noiseMap[i][j]) {
                        noiseMap[Oi][Oj] = noiseMap[i][j] * 0.9625;
                    }
                }
            }
            
        }
    }

    // write to file
    FILE *f = fopen("newNoiseMap.ppm", "w");
    if (!f) {
        perror("failed to write file");
        return 1;
    }

    fprintf(f, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    for(int i = 0; i<HEIGHT; i++) {
        for(int j = 0; j<WIDTH; j++) {
            
            fprintf(f, "%d %d %d ", noiseMap[i][j] * 3, 0, 255 / noiseMap[i][j]);
            
        }
        fprintf(f, "\n");
    }

    fclose(f);

    printf("file wrote to newNoiseMap.ppm\n");

    // auto open the file on linux
    system("xdg-open newNoiseMap.ppm");
    

    return 0;
}