#include <iostream>
#include "opencv2\core.hpp"
#include "opencv2\imgcodecs.hpp"
#include "opencv2\highgui.hpp"


using namespace std;
using namespace cv;

int main()
{
	cout << "Inicia programa donde se aplica una mascara a una imagen.\n";

	Mat input, mask, res;
	input = imread("C:/Users/rprie/OneDrive - Universidad de Guanajuato/MIE/Segundo Cuatrimestre/Procesamiento de imagenes/Imagenes/Tarea 1/Paisaje.jpg",IMREAD_COLOR);
	imshow("Input",input);

	mask = Mat::zeros(input.rows, input.cols, CV_8UC3);

	for(int i = 0; i < 30; i++)
	{
		for(int j = 0; j < 30; j++)
		{
			mask.at<unsigned char>(i,j) = 255;
		}
	}
	imshow("Mascara", mask);
	
	res.create(input.rows,input.cols,CV_8UC3);
	/*for(int i = 0; i < input.rows; i++)
	{
		for(int j = 0; j < input.cols; j++)
		{
			if(mask.at<unsigned char>(i,j) == 255)
				res.at<unsigned char>(i,j) = input.at<unsigned char>(i,j);
		}
	}*/
	transform(input,res,mask);

	//imshow("Resultado", res);

	cout << input.rows << "\n";
	cout << input.cols << "\n";
	cout << input.channels() << "\n";
	cout << mask.rows << "\n";
	cout << mask.cols << "\n";
	cout << mask.channels() << "\n";
	cout << res.rows << "\n";
	cout << res.cols << "\n";
	cout << res.channels() << "\n";

	waitKey(0);
	return 0;
}