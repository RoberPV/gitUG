#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <opencv2\opencv.hpp>
#include "opencv2\core.hpp"
#include "opencv2\imgcodecs.hpp"
#include "opencv2\highgui.hpp"


using namespace std;
using namespace cv;

void resultadoConMascara(Mat &r, Mat &m, Mat &inp);
void generacionDeMascara(Mat &m, int x, int y, int t, char fig);
void movimientoMascara(int &x, int &y, Mat &m, char fig);

int t = 150, xr = 1, yr = 1;
bool ys = true, xs = true;
char f;

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
		cout << "\nElije la figura de la mascara (r - rectangulo) o (c - circulo)\n";
		cin >> f;
		if(f == 'r' || f == 'c')
		{
			cout << "\nIngresa el size de la mascara del cuadrado: \n";
			cin >> t;
			if(t < input.rows)
			{
				cout << "\nIngresa la x inicial de la mascara: \n";
				cin >> xpos;
				if(xpos >= 0 && xpos <= input.cols)
				{
					cout << "\nIngresa la y inicial de la mascara: \n";
					cin >> ypos;
					if(ypos >= 0 && ypos <= input.rows)
						break;
					else
						cout << "\nY no valida";
				}
				else
					cout << "\nX no valida";
			}
			else
				cout << "\nMascara muy grande";
		}
		else
			cout << "\nFigura no reconocida\n";
	}
	while(true);

	do
	{
		generacionDeMascara(mask, xpos, ypos, t, f);
		resultadoConMascara(res,mask,input);
		movimientoMascara(xpos, ypos, mask, f);
		imshow("Mascara", mask);
		imshow("Imagen", input);
		imshow("Resultado", res);
		usleep(2000);
		int key = waitKey(10);
        if (key == 'q' || key == 27)
            break;
	}
	while(true);

	return 0;
}

void resultadoConMascara(Mat &r, Mat &m, Mat &inp)
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

void generacionDeMascara(Mat &m, int x, int y, int t, char fig)
{
	m = Mat::zeros(m.size(), CV_8UC1);
	switch(fig)
	{
	case 'r':
		for(int i = x; i < t + x; i++)
		{
			for(int j = y; j < t + y; j++)
			{
				m.at<unsigned char>(j,i) = 255;
			}
		}
		break;
	case 'c':
		Point centro(x , y);
		circle(m,centro,t,Scalar(255),-1);
		break;
	}

	
}

void movimientoMascara(int &x, int &y, Mat &m, char fig)
{
	srand(time(NULL));
	if(fig == 'r')
	{
		if(x <= 0)
		{
			xs = true;
			xr = 1 + rand()%(3-1);
		}
		if(y <= 0)
		{
			ys = true;
			yr = 1 + rand()%(3-1);
		}
	}
	else
	{
		if(x <= t)
		{
			xs = true;
			xr = 1 + rand()%(3-1);
		}

		if(y <= t)
		{
			ys = true;
			yr = 1 + rand()%(3-1);
		}
	}
	if(x >= m.rows - t)
	{
		xs = false;
		xr = 1 + rand()%(3-1);
	}
	if(y >= m.cols - t)
	{
		ys = false;
		yr = 1 + rand()%(3-1);
	}
	if(xs)
		x += xr;
	else
		x-=xr;
	if(ys)
		y += yr;
	else
		y -=yr;
}