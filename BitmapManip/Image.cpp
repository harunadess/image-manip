#include<fstream>
#include "Image.h"

Image::Image(const char *file_name)
{
	b_data = 0;
	g_data = 0;
	r_data = 0;
	read(file_name);
}


Image::~Image()
{
	if (b_data)
	{
		for (int i = 0; i < header.get_height(); i++)
		{
			delete[] b_data[i];
			delete[] g_data[i];
			delete[] r_data[i];
		}
		delete[] b_data;
		delete[] g_data;
		delete[] r_data;
	}
}


void Image::read(const char *file_name)
{
	ifstream file_in(file_name, std::ios::binary);
	if (!file_in)
		return;

	//load header
	if (!header.read(file_in))
		return;

	//allocate space for image data
	int height = get_height();
	b_data = new unsigned int*[height];
	g_data = new unsigned int*[height];
	r_data = new unsigned int*[height];

	int width = get_width();
	for (int i = 0; i < height; i++)
	{
		b_data[i] = new unsigned int[width];
		g_data[i] = new unsigned int[width];
		r_data[i] = new unsigned int[width];
	}

	
	//pad zeros at the end of each row so it is multiples of 4 bytes long
	int num_zeros = 4 - width * (header.get_bits_per_pixel() / 8) % 4;
	if (num_zeros == 4)
		num_zeros = 0;

	//load the image data row by row
	for (int y = height - 1; y >= 0; y--)
	{
		unsigned char b, g, r;
		for (int x = 0; x < width; x++)
		{
			//read pixel values at (x, y)
			file_in.read((char*)&b, 1);
			file_in.read((char*)&g, 1);
			file_in.read((char*)&r, 1);

			b_data[y][x] = b;
			g_data[y][x] = g;
			r_data[y][x] = r;
		}
		//read padded zeros at end of the row if any
		for (int z = 0; z < num_zeros; z++)
			file_in.read((char*)&b, 1);
	}
	file_in.close();
}


void Image::save(const char *file_name)
{
	ofstream file_out(file_name, std::ios::binary);
	//write header
	header.write(file_out);

	//pad zeros at end of each row so it is multiples of 4 bytes long
	int width = header.get_width();
	int num_zeros = 4 - (width * (header.get_bits_per_pixel() / 8) % 4);
	if (num_zeros == 4)
		num_zeros = 0;

	//write image data row by row
	int height = header.get_height();
	for (int y = height - 1; y >= 0; y--)
	{
		unsigned char b, g, r;
		for (int x = 0; x < width; x++)
		{
			b = b_data[y][x];
			g = g_data[y][x];
			r = r_data[y][x];

			file_out.write((char*)&b, 1);
			file_out.write((char*)&g, 1);
			file_out.write((char*)&r, 1);
		}
		//write any padded zeros at the end of the row if any
		b = 0;
		for (int z = 0; z < num_zeros; z++)
			file_out.write((char*)&b, 1);
	}
	file_out.close();
}


void Image::get_pixel(int x, int y, int &r, int &g, int &b)
{
	r = r_data[y][x];
	g = g_data[y][x];
	b = b_data[y][x];
}


void Image::set_pixel(int x, int y, int r, int g, int b)
{
	if (x >= 0 && x < header.get_width() && y >= 0 && y < header.get_height())
	{
		//pixel is within values of 0-255
		if (r < 0) r = 0; if (r > 255) r = 255;
		if (g < 0) g = 0; if (g > 255) g = 255;
		if (b < 0) b = 0; if (b > 255) b = 255;

		r_data[y][x] = r;
		g_data[y][x] = g;
		b_data[y][x] = b;
	}
}