#pragma once

namespace tkl::img {

struct Codec {};
struct CodecPNG : public Codec {};
struct CodecJPG : public Codec {};

enum class ImgFormat {
  none,
  ImagePNG,
  ImageJPG,
};

class Image {
protected:
  unsigned int length = 0;
  unsigned int width = 0;
  unsigned int colorDepth = 0;
  Codec *codec = nullptr;

public:
  ImgFormat format = ImgFormat::none;
  unsigned int virtual Draw(unsigned char *_buffer);
};

class ImageJPG : public Image {
public:
  ImageJPG();
  ~ImageJPG();
  unsigned int virtual Draw(unsigned char *_buffer) override;
};

class ImagePNG : public Image {
public:
  ImagePNG();
  ~ImagePNG();
  void remove_alphaChannel();
  unsigned int virtual Draw(unsigned char *_buffer) override;
};

} // namespace tkl::img
