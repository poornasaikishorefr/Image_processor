#include "controller.h"
#include "image.h"
#include <iostream>
#include "parser.h"
#include "read_image.h"
#include "write_image.h"
#include <cstdlib>

int main(int argc, char** argv) {
    if (argc == 2 && std::string(argv[1]) == "-h") {
    std::cout << "Usage:\n";
    std::cout << "image_processor <input.bmp> <output.bmp> [filters]\n\n";
    std::cout << "Filters:\n";
    std::cout << "-crop width height   Crop image\n";
    std::cout << "-gs                  Convert to grayscale\n";
    std::cout << "-neg                 Negative image\n";
    std::cout << "-sharp               Sharpen image\n";
    std::cout << "-edge threshold      Edge detection\n";
    std::cout << "-blur                Blur image\n";
    std::cout << "-mine                Custom filter\n";

    return 0;
}
    if (argc < 3) {
        std::cerr << "Usage: image_processor <input.bmp> <output.bmp> [filters...]\n";
        return 1;
    }
    try {
        std::cout << "Image Processor v1.0\n";
        std::cout << "--------------------\n";
        auto parser_results = Parse(argc, argv);
        auto filters = CreateFilters(parser_results.filters);
        std::cout << "Reading image...\n";
Image image = ReadImage(parser_results.input);

std::cout << "Applying filters...\n";
image = UseFilters(image, filters);

std::cout << "Writing output...\n";
WriteImage(image, parser_results.output);

std::cout << "Processing completed successfully\n";
std::string command = "start " + parser_results.output;
system(command.c_str());
    }catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
