#include "rotate.h"
#include <vector>

Rotate::Rotate(int angle) : angle_(angle) {}

Image Rotate::Change(Image& image) {

    int height = image.colors_.size();
    int width = image.colors_[0].size();

    std::vector<std::vector<Color>> result;

    if (angle_ == 90) {

        result.resize(width, std::vector<Color>(height));

        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                result[j][height - i - 1] = image.colors_[i][j];

    }

    else if (angle_ == 180) {

        result.resize(height, std::vector<Color>(width));

        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                result[height - i - 1][width - j - 1] = image.colors_[i][j];

    }

    else if (angle_ == 270) {

        result.resize(width, std::vector<Color>(height));

        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                result[width - j - 1][i] = image.colors_[i][j];

    }

    image.colors_ = result;

    return image;
}