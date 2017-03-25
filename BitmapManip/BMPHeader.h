#ifndef BMP_HEADER_H
#define BMP_HEADER_H

#include <fstream>
using std::ifstream;
using std::ofstream;

//BMP format image header
class BMPHeader
{
public:
	//read and write the ehader with given file stream
	bool read(ifstream &file_in);
	void write(ofstream &file_out);

	//get information from image
	int get_height() const { return height; }
	int get_width() const { return width; }
	short get_bits_per_pixel() const { return bits_per_pixel; }

private:
	//BMP image header parameters
	char type[2];	//must contain "BM"
	int file_size;
	int reserved;
	int offset;
	int info_header_size;
	int width;	//image width
	int height;	//image height
	short planes;
	short bits_per_pixel;	//number of bits per pixel
	int compression;
	int data_size;
	int h_resolution;
	int v_resolution;
	int colours;
	int important_colours;
};

#endif // !BMP_HEADER_H
