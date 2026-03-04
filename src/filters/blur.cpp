#include "blur.h"
#include <algorithm>

Image Blur::Change(Image& image) {

    int height = image.colors_.size();
    int width = image.colors_[0].size();

    std::vector<std::vector<Color>> result = image.colors_;

    int radius = 8;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {

            double r = 0;
            double g = 0;
            double b = 0;
            int count = 0;

for (int di = -radius; di <= radius; ++di) {
    for (int dj = -radius; dj <= radius; ++dj) {

        int ni = i + di;
        int nj = j + dj;

        if (ni < 0) ni = 0;
        if (ni >= height) ni = height - 1;

        if (nj < 0) nj = 0;
        if (nj >= width) nj = width - 1;

        r += image.colors_[ni][nj].Red;
        g += image.colors_[ni][nj].Green;
        b += image.colors_[ni][nj].Blue;

        count++;
    }
}

            result[i][j].Red = r / count;
            result[i][j].Green = g / count;
            result[i][j].Blue = b / count;
        }
    }

    image.colors_ = result;
    return image;
}