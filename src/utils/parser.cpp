#include "parser.h"
#include <fstream>
ParserWords Parse(int argc, char** argv) {

    ParserWords parser_words;
    parser_words.input = argv[1];
    parser_words.output = argv[2];
    std::ifstream file(parser_words.input);
    if (!file.good()) {
    throw std::runtime_error("Input file does not exist: " + parser_words.input);
    }
    for (int i = 3; i < argc; ++i) {
        if (argv[i][0] == '-') {
            FilterParsed filter;
            filter.name = std::string(argv[i]).substr(1);
            parser_words.filters.emplace_back(filter);
            continue;
        }
        parser_words.filters.back().args.emplace_back(argv[i]);
    }
    for (const auto& filter : parser_words.filters) {

        if (filter.name != "crop" &&
    filter.name != "gs" &&
    filter.name != "neg" &&
    filter.name != "sharp" &&
    filter.name != "edge" &&
    filter.name != "blur" &&
    filter.name != "rotate" &&
    filter.name != "mine") {

    throw std::runtime_error("Unknown filter: " + filter.name);
}
    if (filter.name == "crop") {
    if (filter.args.size() != 2) {
        throw std::runtime_error(
            "Filter 'crop' requires 2 parameters (width height)"
        );
    }

    int width = std::stoi(filter.args[0]);
    int height = std::stoi(filter.args[1]);

    if (width <= 0 || height <= 0) {
        throw std::runtime_error(
            "Crop width and height must be positive numbers"
        );
    }
}

    if (filter.name == "edge") {
    if (filter.args.size() != 1) {
        throw std::runtime_error(
            "Filter 'edge' requires 1 parameter (threshold)"
        );
    }

    double threshold = std::stod(filter.args[0]);

    if (threshold < 0.0 || threshold > 1.0) {
        throw std::runtime_error(
            "Edge threshold must be between 0 and 1"
        );
    }
}

    if (filter.name == "gs" || filter.name == "neg" || filter.name == "sharp") {
        if (!filter.args.empty()) {
            throw std::runtime_error(
                "Filter '" + filter.name + "' does not take parameters"
            );
        }
    }
}
    return parser_words;
}