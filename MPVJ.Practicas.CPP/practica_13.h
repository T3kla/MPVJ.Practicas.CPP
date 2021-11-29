#pragma once
#include "lib\image\image.h"

namespace p13
{

void remove_AlphaChannel(img::image **images, size_t length)
{
    for (auto i = 0; i < length; i++)
        if (images[i]->m_format == img::format::png)
            (static_cast<img::png *>(images[i]))->remove_alphaChannel();
}

} // namespace p13

void run_practica_13()
{
    const size_t length = 3;

    img::image *images[length];
    images[0] = new img::image();
    images[1] = new img::png();
    images[2] = new img::jpg();

    std::cout << "Draw each" << std::endl;

    images[0]->draw(nullptr);
    images[1]->draw(nullptr);
    images[2]->draw(nullptr);

    std::cout << "Remove alpha channel" << std::endl;

    p13::remove_AlphaChannel(images, length);
}
