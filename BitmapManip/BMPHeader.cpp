#include "BMPHeader.h"

bool BMPHeader::read(ifstream &file_in)
{
	file_in.read((char*)type, 2);

	//return if this is not a bmp-format image
	if (type[0] != 'B' || type[1] != 'M')
		return 0;

	file_in.read((char*)&file_size, sizeof(int));
	file_in.read((char*)&reserved, sizeof(int));
	file_in.read((char*)&offset, sizeof(int));
	file_in.read((char*)&info_header_size, sizeof(int));
	file_in.read((char*)&width, sizeof(int));
	file_in.read((char*)&height, sizeof(int));
	file_in.read((char*)&planes, sizeof(short));
	file_in.read((char*)&bits_per_pixel, sizeof(short));
	file_in.read((char*)&compression, sizeof(int));
	file_in.read((char*)&data_size, sizeof(int));
	file_in.read((char*)&h_resolution, sizeof(int));
	file_in.read((char*)&v_resolution, sizeof(int));
	file_in.read((char*)&colours, sizeof(int));
	file_in.read((char*)&important_colours, sizeof(int));

	return 1;
}


void BMPHeader::write(ofstream &file_out)
{
	file_out.write((char*)&type, 2 * sizeof(char));
	file_out.write((char*)&file_size, sizeof(int));
	file_out.write((char*)&reserved, sizeof(int));
	file_out.write((char*)&offset, sizeof(int));
	file_out.write((char*)&info_header_size, sizeof(int));
	file_out.write((char*)&width, sizeof(int));
	file_out.write((char*)&height, sizeof(int));
	file_out.write((char*)&planes, sizeof(short));
	file_out.write((char*)&bits_per_pixel, sizeof(short));
	file_out.write((char*)&compression, sizeof(int));
	file_out.write((char*)&data_size, sizeof(int));
	file_out.write((char*)&h_resolution, sizeof(int));
	file_out.write((char*)&v_resolution, sizeof(int));
	file_out.write((char*)&colours, sizeof(int));
	file_out.write((char*)&important_colours, sizeof(int));
}