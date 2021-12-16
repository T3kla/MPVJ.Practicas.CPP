#pragma once
#include "lib\image\image.h"

namespace p13 {

void remove_AlphaChannel(img::Image **images, size_t length) {
  for (auto i = 0; i < length; i++)
    if (images[i]->format == img::ImgFormat::ImagePNG)
      (static_cast<img::ImagePNG *>(images[i]))->remove_alphaChannel();
}

} // namespace p13

void run_practica_13() {
  const size_t length = 3;

  img::Image *images[length];
  images[0] = new img::Image();
  images[1] = new img::ImagePNG();
  images[2] = new img::ImageJPG();

  std::cout << "Draw each" << std::endl;

  images[0]->draw(nullptr);
  images[1]->draw(nullptr);
  images[2]->draw(nullptr);

  std::cout << "Remove alpha channel" << std::endl;

  p13::remove_AlphaChannel(images, length);
}
