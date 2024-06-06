
#include "image.h"
#include <iostream>

int main()
{
    Image image;

    image.load("/mnt/data/obrazek.ppm");
    image.add_watermark();
    image.save_as("/mnt/data/watermark.ppm");

    image.load("/mnt/data/obrazek.ppm");
    image.blurr();
    image.save_as("/mnt/data/blurr.ppm");

    image.load("/mnt/data/obrazek.ppm");
    image.extract_layer(ColorLayer::Red);
    image.save_as("/mnt/data/red-layer.ppm");

    image.load("/mnt/data/tree.ppm");
    image.filter();
    image.save_as("/mnt/data/filter.ppm");

    image.load("/mnt/data/obrazek.ppm");
    image.flip_horizontally();
    image.save_as("/mnt/data/flip-horizontally.ppm");

    image.load("/mnt/data/obrazek.ppm");
    image.flip_vertically();
    image.save_as("/mnt/data/flip-vertically.ppm");

    image.load("/mnt/data/obrazek.ppm");
    image.inflate();
    image.save_as("/mnt/data/inflate.ppm");

    image.load("/mnt/data/obrazek.ppm");
    image.negative();
    image.save_as("/mnt/data/negatyw.ppm");

    image.load("/mnt/data/obrazek.ppm");
    image.rotate_clockwise_90();
    image.save_as("/mnt/data/rotate-clockwise-90.ppm");

    image.load("/mnt/data/obrazek.ppm");
    image.sepia();
    image.save_as("/mnt/data/sepia.ppm");

    image.load("/mnt/data/obrazek.ppm");
    image.shrink();
    image.save_as("/mnt/data/shrink.ppm");

    image.load("/mnt/data/obrazek.ppm");
    image.to_grayscale();
    image.save_as("/mnt/data/grayscale.ppm");

    return 0;
}
