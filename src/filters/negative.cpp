#include "negative.h"

Image Negative::Change(Image& image) {

    for (auto& row : image.colors_) {
        for (auto& pixel : row) {

            pixel.Red = 1 - pixel.Red;
            pixel.Green = 1 - pixel.Green;
            pixel.Blue = 1 - pixel.Blue;

        }
    }

    return image;
}