#pragma once

#include "image.h"

using namespace tkl::img;

namespace P13 {

void RemoveAlphaChannel(img::Image **images, size_t length) {
  for (auto i = 0; i < length; i++)
    if (images[i]->format == img::ImgFormat::ImagePNG)
      (static_cast<img::ImagePNG *>(images[i]))->remove_alphaChannel();
}

} // namespace P13

void RunP13() {
  const size_t length = 3;

  img::Image *images[length]{nullptr};
  images[0] = new img::Image();
  images[1] = new img::ImagePNG();
  images[2] = new img::ImageJPG();

  std::cout << "Draw each" << std::endl;

  images[0]->Draw(nullptr);
  images[1]->Draw(nullptr);
  images[2]->Draw(nullptr);

  std::cout << "Remove alpha channel" << std::endl;

  P13::RemoveAlphaChannel(images, length);
}
