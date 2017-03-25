#include <iostream>
#include "Image.h"

#define FILENAME_LEN 100
#define PATH_LEN 300

int main()
{
	std::cout << "give the file name of bmp picture to load: " << std::flush;

	char file_name[FILENAME_LEN];
	std::cin >> file_name;

	char *path = new char[PATH_LEN];
	strcpy_s(path, 300, "C:\\Users\\Jordan\\Documents\\Uni\\2nd Year\\CSC2040 - Data Structures, Algorithms and Programming Languages\\Demo Programs\\ImageManipulation\\BitmapManip\\BitmapManip\\");
	std::string full_path = path;
	full_path += file_name;
	const char *c_path = full_path.c_str();
	std::cout << c_path << std::endl;

	//load the image
	Image image(c_path);
	std::cout << "size of image: " << image.get_width() << " x " << image.get_height() << std::endl;

	////modify the image - red*3
	//for (int y = 0; y < image.get_height(); y++)
	//{
	//	for (int x = 0; x < image.get_width(); x++)
	//	{
	//		//get pixel value at [x, y]
	//		int r, g, b;
	//		image.get_pixel(x, y, r, g, b);

	//		//modify the values
	//		r *= 3;
	//		image.set_pixel(x, y, r, g, b);
	//	}
	//}

	////save modified image with new name
	//std::string new_full_path = path;
	//new_full_path += std::string("red_") + file_name;
	//const char *new_c_path = new_full_path.c_str();
	//image.save(new_c_path);
	//std::cout << "red image saved to:\n" << new_c_path << std::endl;


	////modify the image - darken
	//for (int y = 0; y < image.get_height(); y++)
	//{
	//	for (int x = 0; x < image.get_width(); x++)
	//	{
	//		//get pixel value at [x, y]
	//		int r, g, b;
	//		image.get_pixel(x, y, r, g, b);

	//		//modify the values
	//		r /= 1.1; g /= 1.1; b /=1.1;
	//		image.set_pixel(x, y, r, g, b);
	//	}
	//}

	////save modified image with new name
	//std::string new_full_path = path;
	//new_full_path += std::string("darken_") + file_name;
	//const char *new_c_path = new_full_path.c_str();
	//image.save(new_c_path);
	//std::cout << "darkened image saved to:\n" << new_c_path << std::endl;


	//modify the image - #filter
	for (int y = 0; y < image.get_height(); y++)
	{
		for (int x = 0; x < image.get_width(); x++)
		{
			//get pixel value at [x, y]
			int r, g, b;
			image.get_pixel(x, y, r, g, b);

			//modify the values
			r *= 0.95; g *= 0.95; b *=1.05;
			image.set_pixel(x, y, r, g, b);
		}
	}

	//save modified image with new name
	std::string new_full_path = path;
	new_full_path += std::string("filter_") + file_name;
	const char *new_c_path = new_full_path.c_str();
	image.save(new_c_path);
	std::cout << "filter image saved to:\n" << new_c_path << std::endl;

	delete[] path, c_path;

	return 0;
}