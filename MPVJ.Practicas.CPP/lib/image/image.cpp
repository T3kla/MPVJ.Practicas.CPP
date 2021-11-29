#include "image.h"
#include <iostream>

namespace img
{

unsigned int image::draw(unsigned char *_buffer)
{
    std::cout << "    IMAGE Draw" << std::endl;
    return 0;
}

unsigned int png::draw(unsigned char *_buffer)
{
    std::cout << "    PNG Draw" << std::endl;
    return 0;
}

unsigned int jpg::draw(unsigned char *_buffer)
{
    std::cout << "    JPG Draw" << std::endl;
    return 0;
}

png::png()
{
    // si 'codec_png' no hereda de manera pública, no se puede
    // hacer new porque rompe el casteo implicito por no ser accesible
    m_codec = new codec_png();
    m_format = format::png;
}

png::~png()
{
    delete (m_codec);
}

jpg::jpg()
{
    m_codec = new codec_jpg();
    m_format = format::jpg;
}

jpg::~jpg()
{
    delete (m_codec);
}

void png::remove_alphaChannel()
{
    std::cout << "    PNG Delete alpha channel" << std::endl;
}

} // namespace img
