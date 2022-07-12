// RayTracing_ch01.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

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
			int ir = (int)(255.59f * r);
			int ig = (int)(255.59f * g);
			int ib = (int)(255.59f * b);
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