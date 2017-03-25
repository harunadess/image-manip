#ifndef IMAGE_H
#define IMAGE_H

#include "BMPHeader.h"

class Image
{
public:
	//constructor
	Image(const char *file_name);
	//destructor
	~Image();

	//read and save image with given file name
	void read(const char *file_name);
	void save(const char *file_name);

	//get information of the image
	int get_height() { return header.get_height(); }
	int get_width() { return header.get_width(); }

	//get/set pixel values (r, g, b) at location (x, y)
	void get_pixel(int x, int y, int &r, int &g, int &b);
	void set_pixel(int x, int y, int r, int g, int b);

private:
	//image header
	BMPHeader header;
	//data
	unsigned int **b_data, **g_data, **r_data;
};

#endif // !IMAGE_H
