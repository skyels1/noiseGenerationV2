# simple noise generation

this project is entirely made because I made the old noise generation without any knowledge of how to make noise
this project is used to benchmark if I can make a noise map that is better than the first one I made since I attemtped Perlin noise

those links are here ->
- [noiseGenerator](https://github.com/skyels1/noiseGenerator) – A simple C project to generate basic noise.
- [PerlinNoise](https://github.com/skyels1/PerlinNoise) – A Perlin noise generator to explore how it works.

## what does this project do differently

in this project I combined a few things I learned from making Perlin noise and my own noise generation
basically I wanted to remake the noise map I had before but with some ideas that can make it a lot better

## updated image of what the code looks like currently running

current commit\
![(image) example of what the code looks like currently](/previews/newNoiseMap2.png)

## info and installation

the code currently only auto opens the image on linux

to run the code just use the commands

```bash

# Compile the C code
gcc src/main.c -o newNoiseMap -lrt

# Run the program
./newNoiseMap

```