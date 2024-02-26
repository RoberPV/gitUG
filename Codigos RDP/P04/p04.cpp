/*
Programa 4. Imagenes de Color
*/

#include <iostream>
#include "opencv2\core.hpp"
#include "opencv2\imgcodecs.hpp"
#include "opencv2\highgui.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat mx;
	mx = imread("C:/Users/rprie/OneDrive - Universidad de Guanajuato/MIE/Segundo Cuatrimestre/Procesamiento de imagenes/Imagenes/Tarea 1/Paisaje.jpg",IMREAD_UNCHANGED);
	
	if(mx.empty())
	{
		cout << "No existe el archivo" << endl;
	}
	else
	{
		imshow("Imagen Entrada", mx);
		float r,g,b;
		unsigned char gris;
		/* Se calcula la imagen a gris con los 3 canales
		for(int i = 0; i < mx.rows ; i++)
			for(int j = 0; j < mx.cols; j++)
			{
				r = (float)mx.at<Vec3b>(i,j)[0];
				g = (float)mx.at<Vec3b>(i,j)[1];
				b = (float)mx.at<Vec3b>(i,j)[2];

				gris = (r+g+b)/3.0;

				mx.at<Vec3b>(i,j)[0] = gris;
				mx.at<Vec3b>(i,j)[1] = gris;
				mx.at<Vec3b>(i,j)[2] = gris;
			}*/
		//mx.convertTo(mx,CV_32FC3); imshow no sirve con datos flotantes
		//imshow("Imagen Gris", mx);
		//mx.convertTo(mx,CV_8UC3); se regresa a char

		// Calculo de la imagen en negativo
		mx = Scalar(255,255,255) - mx;

		imshow("Imagen Negativo", mx);

		cout << "Numero de filas: " << mx.rows << endl;
		cout << "Numero de columnas: " << mx.cols << endl;
		cout << "Tamanio de la matriz: " << mx.size << endl;
		cout << "Numero total de elementos: " << mx.total() << endl;
		cout << "Numero de canales: " << mx.channels() << endl;

		waitKey(0);
	}
	return 0;
}