#include <iostream>
#include "opencv2\core.hpp"
#include "opencv2\imgcodecs.hpp"
#include "opencv2\highgui.hpp"


using namespace std;
using namespace cv;

int main()
{
	cout << "Inicia programa donde se aplica una mascara a una imagen.\n";

	Mat input;
	input = imread("C:/Users/rprie/OneDrive - Universidad de Guanajuato/MIE/Segundo Cuatrimestre/Procesamiento de imagenes/Imagenes/Tarea 1/Paisaje.jpg",IMREAD_COLOR);
	imshow("Input",input);

	waitKey(0);
	return 0;
}