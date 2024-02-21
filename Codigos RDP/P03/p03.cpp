/*
Programa 3. Uso de la estructura MAT para crear matrices multidimensionales
*/

#include <iostream>
#include "opencv2\core.hpp"
#include "opencv2\imgcodecs.hpp"
#include "opencv2\highgui.hpp"

using namespace std;
using namespace cv;

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
	
	Mat mx;

	//mx = Mat::zeros(256,256,CV_8UC1);
	////mx = Mat::ones(256,256,CV_8UC1);

	mx = Mat::eye(256,256,CV_8UC1);
	mx = 255*mx;

	for(int j = 0; j < mx.cols; j++)
		mx.at<char>(128,j) = 255;

	imshow("Imagen",mx);
	imwrite("Resultado.jpg", mx);

	cout << "Numero de filas: " << mx.rows << endl;
	cout << "Numero de columnas: " << mx.cols << endl;
	cout << "Tamanio de la matriz: " << mx.size << endl;
	cout << "Numero total de elementos: " << mx.total() << endl;
	cout << "Numero de canales: " << mx.channels() << endl;

	waitKey(0);

	return 0;
}