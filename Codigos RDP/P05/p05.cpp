/*
Fecha: 11/03/2024
Extracción de caracteristicas geometricas para la clasificación de objetos en una imagen.

Programa 5. Calculo de perimetro
*/
#include <iostream>
#include "opencv2\core.hpp"
#include "opencv2\imgcodecs.hpp"
#include "opencv2\highgui.hpp"

using namespace std;
using namespace cv;

void FindNextPixelContour(int dir, int i, int j, Mat &img, int &Inew, int &Jnew, int &dirA);
int DirAnterior(int ia, int ja, int in, int jn);

int main()
{
	Mat mx;
	mx = imread("C:/Users/rprie/OneDrive - Universidad de Guanajuato/MIE/Segundo Cuatrimestre/Reconocimiento de patrones/Imagenes/Nube.bmp",IMREAD_UNCHANGED);
	int dirA, perimetro = 0, area = 0, alto, ancho, rini_i, rini_j, rfin_i, rfin_j;

	if(mx.empty())
	{
		cout << "No existe el archivo" << endl;
	}
	else
	{
		imshow("Imagen Entrada", mx);
		float r,g,b;
		int Is, Js, Iact, Jact, Inew, Jnew;
		for(int i = 0; i < mx.rows ; i++)
			for(int j = 0; j < mx.cols; j++)
			{
				r = (float)mx.at<Vec3b>(i,j)[0];
				//g = (float)mx.at<Vec3b>(i,j)[1];
				//b = (float)mx.at<Vec3b>(i,j)[2];
				if(r == 0)
				{
					mx.at<Vec3b>(i,j)[0] = 0;
					mx.at<Vec3b>(i,j)[1] = 0;
					mx.at<Vec3b>(i,j)[2] = 255;
					Iact = i;
					Jact = j;
					i = mx.rows;
					break;
				}
			}
		Is = Iact;
		Js = Jact;
		int dir = 4;
		do
		{
			FindNextPixelContour(dir, Iact, Jact, mx, Inew, Jnew, dirA);
			Iact = Inew;
			Jact = Jnew;
			dir = dirA;
			perimetro++;
		}
		while(!((Is == Inew)&&(Js == Jnew)));
		
		for(int i = 0; i < mx.rows ; i++)
			for(int j = 0; j < mx.cols; j++)
			{
				r = (float)mx.at<Vec3b>(i,j)[0];
				//g = (float)mx.at<Vec3b>(i,j)[1];
				//b = (float)mx.at<Vec3b>(i,j)[2];
				if(r == 0) area++;
			}
		//Dibujar bounding box
		int ymin, ymax, xmin, xmax;
		xmax = 0;
		xmin = mx.cols;
		ymax = 0;
		ymin = mx.rows;

		for(int i = 0; i < mx.rows ; i++)
			for(int j = 0; j < mx.cols; j++)
			{
				r = (float)mx.at<Vec3b>(i,j)[0];
				//g = (float)mx.at<Vec3b>(i,j)[1];
				//b = (float)mx.at<Vec3b>(i,j)[2];
				if(r == 0)
				{
					if(i < ymin) ymin = i;
					if(i > ymax) ymax = i;
					if(j < xmin) xmin = j;
					if(j > xmax) xmax = j;
				}
			}
		alto = ymax - ymin;
		ancho = xmax - xmin;

		rini_i = ymin;
		rini_j = xmin;
		rfin_i = ymax;
		rfin_j = xmax;
		
		for(int j = rini_j; j < rfin_j; j++)
		{
			mx.at<Vec3b>(rini_i,j)[0] = 0;
			mx.at<Vec3b>(rini_i,j)[1] = 0;
			mx.at<Vec3b>(rini_i,j)[2] = 255;
			mx.at<Vec3b>(rfin_i,j)[0] = 0;
			mx.at<Vec3b>(rfin_i,j)[1] = 0;
			mx.at<Vec3b>(rfin_i,j)[2] = 255;
		}
		for(int i = rini_i; i < rfin_i; i++)
		{
			mx.at<Vec3b>(i,rini_j)[0] = 0;
			mx.at<Vec3b>(i,rini_j)[1] = 0;
			mx.at<Vec3b>(i,rini_j)[2] = 255;
			mx.at<Vec3b>(i,rfin_j)[0] = 0;
			mx.at<Vec3b>(i,rfin_j)[1] = 0;
			mx.at<Vec3b>(i,rfin_j)[2] = 255;
		}
			
		imshow("Resultado", mx);
		cout << "Perimetro: " << perimetro << endl;
		cout << "Area: " << area << endl; 
		cout << "Alto: " << alto << endl;
		cout << "Ancho: " << ancho << endl;
		cout << "Numero de filas: " << mx.rows << endl;
		cout << "Numero de columnas: " << mx.cols << endl;
		cout << "Tamanio de la matriz: " << mx.size << endl;
		cout << "Numero total de elementos: " << mx.total() << endl;
		cout << "Numero de canales: " << mx.channels() << endl;

		waitKey(0);
	}
	return 0;
}

int DirAnterior(int ia, int ja, int in, int jn)
{
	int difi, difj;
	difi = in - ia;
	difj = jn - ja;
	if((difi == 0) && (difj == -1))
		return 0;
	if((difi == 1) && (difj == -1))
		return 1;
	if((difi == 1) && (difj == 0))
		return 2;
	if((difi == 1) && (difj == 1))
		return 3;
	if((difi == 0) && (difj == 1))
		return 4;
	if((difi == -1) && (difj == 1))
		return 5;
	if((difi == -1) && (difj == 0))
		return 6;
	if((difi == -1) && (difj == -1))
		return 7;

	return 0;
}

void FindNextPixelContour(int dir, int i, int j, Mat &img, int &Inew, int &Jnew, int &dirA)
{
	float r;
	int ia = i;
	int ja = j;
	for(int k = 0; k < 7; k++)
	{
		i = ia;
		j = ja;
		dir -= 1;
		if(dir < 0)
		{
			dir = 7;
		}
		switch(dir)
		{
			case 0:
				j+=1;
				break;
			case 1:
				i-=1;
				j+=1;
				break;
			case 2:
				i-=1;
				break;
			case 3:
				i-=1;
				j-=1;
				break;
			case 4:
				j-=1;
				break;
			case 5:
				i+=1;
				j-=1;
				break;
			case 6:
				i+=1;
				break;
			case 7:
				i+=1;
				j+=1;
				break;
			default:
				break;	
		}
		r = (float)img.at<Vec3b>(i,j)[0];
		if(r == 0)
		{
			img.at<Vec3b>(i,j)[0] = 0;
			img.at<Vec3b>(i,j)[1] = 255;
			img.at<Vec3b>(i,j)[2] = 0;
			Inew = i;
			Jnew = j;
			dirA = DirAnterior(ia, ja, Inew, Jnew);
			break;
		}
	}
}