#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void writePPM(int width, int height, string outFile) {
	fstream stream(outFile, ios::out);
	stream << "P3\n";
	stream << width << " " << height << "\n";
	stream << "255\n";

	for (int j = height - 1; j >= 0; j--) {
		for (int i = 0; i < width; i++) {
			float r = (float)i / width;
			float g = (float)j / height;
			float b = 0.2f;
			int ir = (int)(256.f * r);
			int ig = (int)(256.f * g);
			int ib = (int)(256.f * b);
			stream << ir << " " << ig << " " << ib << "\n";
		}
	}

	stream.close();
}


int main()
{
	writePPM(960, 540, "output.ppm");
	return 0;
}