#pragma once
#include "filter.h"

class Rotate : public Filter {
private:
    int angle_;

public:
    explicit Rotate(int angle);
    Image Change(Image& image) override;
};