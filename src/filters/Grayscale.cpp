#include "Grayscale.h"
#include "constants.h"

Image Grayscale::Change(Image &image) {

    for (auto& row : image.colors_) {
        for (auto& pixel : row) {

            double gray =
                pixel.Red * RED_WEIGHT +
                pixel.Green * GREEN_WEIGHT +
                pixel.Blue * BLUE_WEIGHT;

            pixel.Red = gray;
            pixel.Green = gray;
            pixel.Blue = gray;
        }
    }

    return image;
}