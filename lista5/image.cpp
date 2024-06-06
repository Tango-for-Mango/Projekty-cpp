#include "image.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <cmath>

void Image::load(const std::string& filename)
{
    constexpr auto MAGIC = "P6";

    this->filename = filename;

    std::ifstream in(filename, std::ios::binary);
    if (!in) throw std::invalid_argument("failed to open \"" + filename + "\"");

    in >> magic;
    if (magic != MAGIC) throw std::logic_error("unknown magic naumber " + magic);

    in >> my_width >> my_height >> color_depth;

    if (!in || my_width < 0 || my_width > 10000 || my_height < 0 || my_height > 10000 || color_depth <= 0 ||
        color_depth > 255)
        throw std::logic_error("invalid image parameter(s): " + std::to_string(my_width) + " " +
                               std::to_string(my_height) + " " + std::to_string(color_depth));
    in.ignore(1);
    pixels.resize(my_height);
    for (auto& line : pixels)
    {
        line.resize(my_width);
        in.read(reinterpret_cast<char*>(&line[0]), my_width * sizeof(RGB));
        if (!in) throw std::logic_error("failed to read binary pixel data from file " + filename);
    }
}

void Image::save_as(const std::string& filename)
{
    constexpr auto MAGIC = "P6";

    std::ofstream out(filename, std::ios::binary);
    if (!out) throw std::invalid_argument("failed to open " + filename + "for writting");

    out << MAGIC << "\n";
    out << my_width << " " << my_height << "\n";
    out << color_depth << "\n";

    for (const auto& line : pixels)
    {
        out.write(reinterpret_cast<const char*>(line.data()), line.size() * sizeof(RGB));
        if (!out) throw std::logic_error("failed to write binary pixel data to file " + filename);
    }
}

void Image::add_watermark()
{
    int line_number = (my_height / 5); //Dodaje znak wodny w 1/5 wysokości obrazu
    for (int i = 0; i < my_width; i++)
    {
        pixels[line_number - 1][i] = {128, 128, 128};
        pixels[line_number][i] = {128, 128, 128};
        pixels[line_number + 1][i] = {128, 128, 128};
    }
}

void Image::blurr()
{
    std::vector<std::vector<RGB>> tempPixels = pixels;
    for (int i = 1; i < my_height - 1; i++)
    {
        for (int j = 1; j < my_width - 1; j++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    totalRed += tempPixels[i + di][j + dj].red;
                    totalGreen += tempPixels[i + di][j + dj].green;
                    totalBlue += tempPixels[i + di][j + dj].blue;
                }
            }
            unsigned char newRed = static_cast<unsigned char>(totalRed / 9);
            unsigned char newGreen = static_cast<unsigned char>(totalGreen / 9);
            unsigned char newBlue = static_cast<unsigned char>(totalBlue / 9);
            pixels[i][j] = {newRed, newGreen, newBlue};
        }
    }
}

void Image::extract_layer(ColorLayer color_layer)
{
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            RGB& pixel = pixels[i][j];
            switch (color_layer)
            {
                case ColorLayer::Red:
                    pixel.green = 0;
                    pixel.blue = 0;
                    break;
                case ColorLayer::Green:
                    pixel.red = 0;
                    pixel.blue = 0;
                    break;
                case ColorLayer::Blue:
                    pixel.red = 0;
                    pixel.green = 0;
                    break;
            }
        }
    }
}

void Image::filter()
{
    std::vector<std::vector<RGB>> tempPixels = pixels;

    for (int i = 0; i < my_height - 1; i++)
    {
        for (int j = 0; j < my_width - 1; j++)
        {
            // Obliczamy różnice składowych kolorów między pikselami (x, y) i (x+1, y+1)
            int diffRed = std::abs(tempPixels[i][j].red - tempPixels[i + 1][j + 1].red);
            int diffGreen = std::abs(tempPixels[i][j].green - tempPixels[i + 1][j + 1].green);
            int diffBlue = std::abs(tempPixels[i][j].blue - tempPixels[i + 1][j + 1].blue);

            // Aktualizujemy wartości składowych kolorów piksela (x, y) na wartości bezwzględne różnic
            pixels[i][j] = {static_cast<unsigned char>(diffRed), static_cast<unsigned char>(diffGreen), static_cast<unsigned char>(diffBlue)};
        }
    }
}

void Image::flip_horizontally()
{
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width / 2; j++)
        {
            RGB temp_pixel = pixels[i][j];
            pixels[i][j] = pixels[i][my_width - j - 1];
            pixels[i][my_width - j - 1] = temp_pixel;
        }
    }
}

void Image::flip_vertically()
{
    for (int i = 0; i < my_height / 2; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            RGB temp_pixel = pixels[i][j];
            pixels[i][j] = pixels[my_height - i - 1][j];
            pixels[my_height - i - 1][j] = temp_pixel;
        }
    }
}

void Image::inflate()
{
    int new_width = my_width * 2;
    int new_height = my_height * 2;
    std::vector<std::vector<RGB>> inflatedPixels(new_height, std::vector<RGB>(new_width));
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            RGB pixel = pixels[i][j];
            inflatedPixels[i * 2][j * 2] = pixel;
            inflatedPixels[i * 2][j * 2 + 1] = pixel;
            inflatedPixels[i * 2 + 1][j * 2] = pixel;
            inflatedPixels[i * 2 + 1][j * 2 + 1] = pixel;
        }
    }
    my_width = new_width;
    my_height = new_height;
    pixels = inflatedPixels;
}

void Image::negative()
{
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            RGB &pixel = pixels[i][j];
            pixel = {static_cast<unsigned char>(255 - pixel.red), static_cast<unsigned char>(255 - pixel.green), static_cast<unsigned char>(255 - pixel.blue)};
        }
    }
}

void Image::rotate_clockwise_90()
{
    std::vector<std::vector<RGB>> rotatedPixels(my_width, std::vector<RGB>(my_height));
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            int new_i = j;
            int new_j = my_height - 1 - i;
            rotatedPixels[new_i][new_j] = pixels[i][j];
        }
    }
    std::swap(my_width, my_height);
    pixels = rotatedPixels;
}

void Image::sepia() //sepia
{
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            RGB &pixel = pixels[i][j];
            unsigned char grey = static_cast<unsigned char>(std::round((pixel.red + pixel.green + pixel.blue))/3);
            pixel = {static_cast<unsigned char>(std::round((grey + 162)/2)), static_cast<unsigned char>(std::round(((grey + 128)/2)), static_cast<unsigned char>(std::round((grey + 101)/2))) };
        }
    }
}

void Image::shrink()
{
    int new_width = my_width / 2;
    int new_height = my_height / 2;
    std::vector<std::vector<RGB>> shrunkenPixels(new_height, std::vector<RGB>(new_width));
    for (int i = 0; i < new_height; i++)
    {
        for (int j = 0; j < new_width; j++)
        {
            int sum_red = 0, sum_green = 0, sum_blue = 0;
            for (int di = 0; di < 2; di++)
            {
                for (int dj = 0; dj < 2; dj++)
                {
                    sum_red += pixels[i * 2 + di][j * 2 + dj].red;
                    sum_green += pixels[i * 2 + di][j * 2 + dj].green;
                    sum_blue += pixels[i * 2 + di][j * 2 + dj].blue;
                }
            }
            unsigned char avg_red = static_cast<unsigned char>(sum_red / 4);
            unsigned char avg_green = static_cast<unsigned char>(sum_green / 4);
            unsigned char avg_blue = static_cast<unsigned char>(sum_blue / 4);
            shrunkenPixels[i][j] = {avg_red, avg_green, avg_blue};
        }
    }
    my_width = new_width;
    my_height = new_height;
    pixels = shrunkenPixels;
}

void Image::to_grayscale()
{
    for (int i = 0; i < my_height; i++)
    {
        for (int j = 0; j < my_width; j++)
        {
            RGB &pixel = pixels[i][j];
            unsigned char color = static_cast<unsigned char>(std::round((pixel.red + pixel.green + pixel.blue))/3);
            pixel = {color, color, color};
        }
    }
}

int Image::width() const
{
    return my_width;
}

int Image::height() const
{
    return my_height;
}