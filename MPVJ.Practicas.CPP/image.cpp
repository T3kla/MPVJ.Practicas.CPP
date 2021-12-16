#include "image.h"
#include <iostream>

namespace tkl::img {

unsigned int Image::draw(unsigned char *_buffer) {
  std::cout << "    IMAGE Draw" << std::endl;
  return 0;
}

unsigned int ImagePNG::draw(unsigned char *_buffer) {
  std::cout << "    PNG Draw" << std::endl;
  return 0;
}

unsigned int ImageJPG::draw(unsigned char *_buffer) {
  std::cout << "    JPG Draw" << std::endl;
  return 0;
}

ImagePNG::ImagePNG() {
  codec = new CodecPNG();
  format = ImgFormat::ImagePNG;
}

ImagePNG::~ImagePNG() { delete (codec); }

ImageJPG::ImageJPG() {
  codec = new CodecJPG();
  format = ImgFormat::ImageJPG;
}

ImageJPG::~ImageJPG() { delete (codec); }

void ImagePNG::remove_alphaChannel() {
  std::cout << "    PNG Delete alpha channel" << std::endl;
}

} // namespace tkl::img
