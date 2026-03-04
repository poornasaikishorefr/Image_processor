#pragma once
#include "filter.h"

class Blur : public Filter {
public:
    Image Change(Image& image) override;
};