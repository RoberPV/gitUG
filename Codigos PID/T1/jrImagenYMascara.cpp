#include <iostream>
#include <unistd.h>
#include "opencv2\core.hpp"
#include "opencv2\imgcodecs.hpp"
#include "opencv2\highgui.hpp"


using namespace std;
using namespace cv;

void resultadoConMascara(Mat r, Mat m, Mat inp);
void generacionDeMascara(Mat m, int x, int y, int t);
void movimientoMascara(int &x, int &y, Mat m);
int t = 50;
bool ys = true, xs = true;

int main()
{
	cout << "Inicia programa donde se aplica una mascara a una imagen.\n";

	Mat input, mask, res;
	input = imread("C:/Users/rprie/OneDrive - Universidad de Guanajuato/MIE/Segundo Cuatrimestre/Procesamiento de imagenes/Imagenes/Tarea 1/Paisaje.jpg",IMREAD_COLOR);
	int xpos = 0, ypos = 0;
	mask = Mat::zeros(input.rows, input.cols, CV_8UC1);
	res = Mat::zeros(input.rows, input.cols, CV_8UC3);

	do
	{
		generacionDeMascara(mask, xpos, ypos, t);
		resultadoConMascara(res,mask,input);
		
		movimientoMascara(xpos, ypos, mask);

		imshow("Resultado", res);
		usleep(2000);
		waitKey(10);
		int key = waitKey(10);
        if (key == 'q' || key == 27)
            break;
	}
	while(true);
	waitKey(0);
	return 0;
}

void resultadoConMascara(Mat r, Mat m, Mat inp)
{
	r = Mat::zeros(r.size(),CV_8UC3);
	for(int i = 0; i < inp.rows; i++)
	{
		for(int j = 0; j < inp.cols; j++)
		{
			if(m.at<unsigned char>(i,j) == 255)
			{
				r.at<Vec3b>(i,j) = inp.at<Vec3b>(i,j);
			}
		}
	}
}

void generacionDeMascara(Mat m, int x, int y, int t)
{
	m = Mat::zeros(m.size(), CV_8UC1);
	for(int i = x; i < t + x; i++)
	{
		for(int j = y; j < t + y; j++)
		{
			m.at<unsigned char>(i,j) = 255;
		}
	}
}

void movimientoMascara(int &x, int &y, Mat m)
{
	if(x == 0)
	{
		xs = true;
	}

	if(y == 0)
	{
		ys = true;
	}

	if(x == m.rows - t)
	{
		xs = false;
	}

	if(xs)
	{
		x += 2;
	}
	else
	{
		x-=2;
	}

	if(ys) y ++;

}