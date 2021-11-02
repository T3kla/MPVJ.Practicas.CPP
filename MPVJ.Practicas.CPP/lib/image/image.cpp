#include "image.h"
#include <iostream>

namespace img
{

unsigned int image::draw(unsigned char *_buffer)
{
    std::cout << "IMAGE Draw" << std::endl;
    return 0;
}

unsigned int png::draw(unsigned char *_buffer)
{
    std::cout << "PNG Draw" << std::endl;
    return 0;
}

unsigned int jpg::draw(unsigned char *_buffer)
{
    std::cout << "JPG Draw" << std::endl;
    return 0;
}

png::png()
{
    m_format = format::png;
}

jpg::jpg()
{
    m_format = format::jpg;
}

void png::remove_alphaChannel()
{
    std::cout << "PNG Delete alpha channel" << std::endl;
}

} // namespace img
