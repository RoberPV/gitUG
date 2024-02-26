/*
Programa 3. Uso de la estructura MAT para crear matrices multidimensionales
*/

#include <iostream>
#include "opencv2\core.hpp"
#include "opencv2\imgcodecs.hpp"
#include "opencv2\highgui.hpp"

using namespace std;
using namespace cv;

void ajusteDeRango(Mat input);

int main()
{

	//Esta es la manera mas basica de acceder a los datos, pero
	//tambien se puede mediante apuntadores
	//Vec2b es un vector de 2 bytes
	/*
	Mat MX(2,2,CV_8SC3);

	MX.at<Vec3b>(0,0)[0] = 1;
	MX.at<Vec3b>(0,1)[0] = 2;
	MX.at<Vec3b>(1,0)[0] = 3;
	MX.at<Vec3b>(1,1)[0] = 4;

	MX.at<Vec3b>(0,0)[1] = 5;
	MX.at<Vec3b>(0,1)[1] = 6;
	MX.at<Vec3b>(1,0)[1] = 7;
	MX.at<Vec3b>(1,1)[1] = 8;

	MX.at<Vec3b>(0,0)[2] = 2;
	MX.at<Vec3b>(0,1)[2] = 2;
	MX.at<Vec3b>(1,0)[2] = 2;
	MX.at<Vec3b>(1,1)[2] = 2;

	cout << MX << endl;

	//MX = 2*MX;
	//MX = MX/2;
	//MX = MX + 1; //La suma y resta realizada de esta forma solo afecta a un canal
	//MX = MX - 1;

	//MX = Scalar(1,1) + MX; // Esta suma o resta toma un 1 para un canal y el otro 1 para el segundo canal
	//MX = MX - Scalar(1,1);
	MX = MX + Scalar(1,1,1);
	//MX = MX - Scalar(1,1,1);
	*/


	//mx = Mat::zeros(256,256,CV_8UC1);
	////mx = Mat::ones(256,256,CV_8UC1);
	/*
	mx = Mat::eye(256,256,CV_8UC1);
	mx = 255*mx;

	for(int j = 0; j < mx.cols; j++)
		mx.at<char>(128,j) = 255;

	imshow("Imagen",mx);
	imwrite("Resultado.jpg", mx);
	*/
	Mat mx, mx2;
	mx = imread("C:/Users/rprie/OneDrive - Universidad de Guanajuato/MIE/Segundo Cuatrimestre/Reconocimiento de patrones/Imagenes/uno.bmp",IMREAD_UNCHANGED);
	mx2 = imread("C:/Users/rprie/OneDrive - Universidad de Guanajuato/MIE/Segundo Cuatrimestre/Reconocimiento de patrones/Imagenes/dos.bmp",IMREAD_UNCHANGED);

	if(mx.empty())
	{
		cout << "No existe el archivo" << endl;
	}
	else
	{
		/*Mat b = Mat::ones(mx.rows,mx.cols,CV_8UC1);
		b= 255*b;
		mx = mx + b; // La matriz trunca el limite superior ha 255 en el formato 8U
		imshow("Imagen generada", b);

		for(int j = 0; j < mx.cols; j++)
		mx.at<char>(128,j) = 0;*/

		/*imshow("Imagen UNO", mx);
		for(int i = 0; i < mx.rows; i++)
			for(int j = 0; j < mx.cols; j++)
				if(mx.at<unsigned char>(i,j) > 128)
					mx.at<unsigned char>(i,j) = 255;
				else
					mx.at<unsigned char>(i,j) = 0;
		imshow("Imagen UNO Binarizada", mx);*/

		/*mx = 255 - mx; //Genera el negativo de una imagen
		imshow("Imagen UNO negativo", mx);*/
		unsigned char aux, aux2;
		Mat b = Mat::ones(mx.rows,mx.cols,CV_32FC1);
		Mat r = Mat::zeros(mx.rows,mx.cols,CV_32FC1);
		b = 255 * b;
		unsigned char min , max;
		max = mx.at<unsigned char>(0,0);
		min = max;
		for(int i = 0; i < mx.rows; i++)
			for(int j = 0; j < mx.cols; j++)
			{
				if(mx.at<unsigned char>(i,j) < min)
					min = mx.at<unsigned char>(i,j);
				if(mx.at<unsigned char>(i,j) > max)
					max = mx.at<unsigned char>(i,j);
			}
		
		cout << "Maximo de la imagen original: " << (int) max << endl;
		cout << "Minimo de la imagen original: " << (int) min << endl;

		for(int i = 0; i < mx.rows; i++)
			for(int j = 0; j < mx.cols; j++)
			{
				aux = mx.at<unsigned char>(i,j);
				b.at<float>(i,j) += (float)aux;
			}
		imshow("Imagen Sumada", b);
		float minS, maxS;
		maxS = b.at<float>(0,0);
		minS = maxS;
		for(int i = 0; i < mx.rows; i++)
			for(int j = 0; j < mx.cols; j++)
			{
				if(b.at<float>(i,j) < minS)
					minS = b.at<float>(i,j);
				if(b.at<float>(i,j) > maxS)
					maxS = b.at<float>(i,j);
			}
		
		cout << "Maximo de la imagen sumada: " <<  maxS << endl;
		cout << "Minimo de la imagen sumada: " <<  minS << endl;

		float rango = maxS - minS;
		for(int i = 0; i < mx.rows; i++)
			for(int j = 0; j < mx.cols; j++)
			{
				b.at<float>(i,j) = (b.at<float>(i,j) - minS)/rango;
			}
		imshow("Imagen ajustada B", b);

		for(int i = 0; i < mx.rows; i++)
			for(int j = 0; j < mx.cols; j++)
			{
				aux = mx.at<unsigned char>(i,j);
				aux2 = mx2.at<unsigned char>(i,j);
				r.at<float>(i,j) = (float)aux + (float)aux2;
			}
		ajusteDeRango(r);
	}

	cout << "Numero de filas: " << mx.rows << endl;
	cout << "Numero de columnas: " << mx.cols << endl;
	cout << "Tamanio de la matriz: " << mx.size << endl;
	cout << "Numero total de elementos: " << mx.total() << endl;
	cout << "Numero de canales: " << mx.channels() << endl;

	waitKey(0);

	return 0;
}

void ajusteDeRango(Mat r)
{
	float min, max;
	max = r.at<float>(0,0);
	min = max;
	for(int i = 0; i < r.rows; i++)
		for(int j = 0; j < r.cols; j++)
		{
			if(r.at<float>(i,j) < min)
				min = r.at<float>(i,j);
			if(r.at<float>(i,j) > max)
				max = r.at<float>(i,j);
		}
	imshow("Suma de Imagenes", r);

	float rango = max - min;
	for(int i = 0; i < r.rows; i++)
		for(int j = 0; j < r.cols; j++)
		{
			r.at<float>(i,j) = ((r.at<float>(i,j) - min)/rango);
		}
	imshow("Imagen ajustada", r);
	cout << "Maximo de la imagenes sumadas: " <<  max << endl;
	cout << "Minimo de la imagenes sumadas: " <<  min << endl;
}

