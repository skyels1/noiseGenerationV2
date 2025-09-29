#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define gridCellsX 10
#define gridCellsY 10
#define pixelsPerCell 10
#define WIDTH (gridCellsX * pixelsPerCell)
#define HEIGHT (gridCellsY * pixelsPerCell)

int main() {
    srand(time(NULL));

    bool selectedPoint = false;
    int noiseMap[WIDTH][HEIGHT] = {0};

    for(int gridPosY = 0; gridPosY < gridCellsY; gridPosY++) {
        for(int gridPosX = 0; gridPosX < gridCellsX; gridPosX++) {

            for(int i = 0; i < pixelsPerCell; i++) {
                for(int j = 0; j < pixelsPerCell; j++) {

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

    // write to file
    FILE *f = fopen("newNoiseMap.ppm", "w");
    if (!f) {
        perror("failed to write file");
        return 1;
    }

    fprintf(f, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    for(int i = 0; i<HEIGHT; i++) {
        for(int j = 0; j<WIDTH; j++) {
            
            fprintf(f, "%d %d %d ", noiseMap[i][j], noiseMap[i][j], noiseMap[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);

    printf("file wrote to newNoiseMap.ppm\n");

    // auto open the file on linux
    system("xdg-open newNoiseMap.ppm");
    

    return 0;
}