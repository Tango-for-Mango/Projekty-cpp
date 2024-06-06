#include "image.h"
#include <iostream>
#include "sstream"

int main()
{
    Image image;

    //Zrobione
    image.load("obrazek.ppm");
    image.add_watermark();
    image.save_as("watermark.ppm");

    //Zrobione
    image.load("obrazek.ppm");
    image.blurr();
    image.save_as("blurr.ppm");
    image.load("blurr.ppm");
    for (int i = 0; i < 100; i++)
    {
        image.blurr();
    }
    image.save_as("blurr.ppm");

    //Zrobione
    image.load("obrazek.ppm");
    image.extract_layer(ColorLayer::Red);
    image.save_as("red-layer.ppm");

    //Zrobione
    image.load("tree.ppm");
    image.filter();
    image.save_as("filter.ppm");

    //Zrobione
    image.load("obrazek.ppm");
    image.flip_horizontally();
    image.save_as("flip-horizontally.ppm");

    //Zrobione
    image.load("obrazek.ppm");
    image.flip_vertically();
    image.save_as("flip-vertically.ppm");

    //Zrobione
    image.load("obrazek.ppm");
    image.inflate();
    image.save_as("inflate.ppm");

    //Zrobione
    image.load("obrazek.ppm");
    image.negative();
    image.save_as("negatyw.ppm");

    //Zrobione
    image.load("obrazek.ppm");
    image.rotate_clockwise_90();
    image.save_as("rotate-clockwise-90.ppm");

    //Zrobione
    image.load("obrazek.ppm");
    image.sepia();
    image.save_as("sepia.ppm");

    //Zrobione
    image.load("obrazek.ppm");
    image.shrink();
    image.save_as("shrink.ppm");

    //Zrobione
    image.load("obrazek.ppm");
    image.to_grayscale();
    image.save_as("grayscale.ppm");

    //Zrobione
    std::cout << image.width() << "\n";
    std::cout << image.height() << "\n";

    return 0;
}