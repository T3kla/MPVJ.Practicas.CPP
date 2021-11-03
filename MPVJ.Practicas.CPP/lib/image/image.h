#pragma once

namespace img
{

struct codec
{
};

struct codec_png : public codec
{
};

struct codec_jpg : public codec
{
};

enum class format
{
    none,
    png,
    jpg,
};

class image
{
  private:
  protected:
    unsigned int m_length = 0;
    unsigned int m_width = 0;
    unsigned int m_colorDepth = 0;
    codec *m_codec = nullptr;

  public:
    // Uso esto porque no quiero hacer un metodo virtual 'remove_alphaChannel' en
    // image, dado que la mayoria de formatos de imagen no tienen alphachannel.
    // Sin embargo, todas las imagenes tienen formato y voy a querer saberlo.
    format m_format = format::none;
    unsigned int virtual draw(unsigned char *_buffer);
};

class jpg : public image
{
  public:
    jpg();
    ~jpg();
    unsigned int virtual draw(unsigned char *_buffer) override;
};

class png : public image
{
  public:
    png();
    ~png();
    void remove_alphaChannel();
    unsigned int virtual draw(unsigned char *_buffer) override;
};

} // namespace img
