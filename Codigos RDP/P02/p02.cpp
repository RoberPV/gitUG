/*
Programa 2. Uso de la estructura MAT para crear matrices multidimensionales
*/

#include <iostream>
#include "opencv2\core.hpp"

using namespace std;
using namespace cv;
/*Se utiliza la referencia
Mat productoMat(Mat &A, Mat &B); 
Y para usar la función Mr = productoMat(mx, my);
*/

Mat* productoMat(Mat* A, Mat* B); //es la manera que se manda por apuntador
//Y para usar la función Mr = productoMat(&mx, &my);

int main()
{
	Mat mx(3,3,CV_8SC1);
	Mat my(3,3,CV_8SC1);
	Mat* Mr;

	cout << "MX:\n";
	mx.at<char>(0,0) = 1;
	mx.at<char>(0,1) = 2;
	mx.at<char>(0,2) = 3;
	mx.at<char>(1,0) = 4;
	mx.at<char>(1,1) = 5;
	mx.at<char>(1,2) = 6;
	mx.at<char>(2,0) = 7;
	mx.at<char>(2,1) = 8;
	mx.at<char>(2,2) = 9;

	cout << mx << endl;

	cout << "MY:\n";
	my.at<char>(0,0) = 9;
	my.at<char>(0,1) = 8;
	my.at<char>(0,2) = 7;
	my.at<char>(1,0) = 6;
	my.at<char>(1,1) = 5;
	my.at<char>(1,2) = 4;
	my.at<char>(2,0) = 3;
	my.at<char>(2,1) = 2;
	my.at<char>(2,2) = 1;

	cout << my << endl;

	Mr = productoMat(&mx, &my);

	cout << "MR:\n";
	cout << *Mr << endl;
	/*
	//Unas propiedades de la clase Mat
	cout << "Numero de filas: " << matriz.rows << endl;
	cout << "Numero de columnas: " << matriz.cols << endl;
	cout << "Tamanio de la matriz: " << matriz.size << endl;
	cout << "Numero total de elementos: " << matriz.total() << endl;
	cout << "Numero de canales: " << matriz.channels() << endl;
	*/
	delete Mr;
	return 0;
}

Mat* productoMat(Mat* A, Mat* B)
{
	Mat *R;
	R = new Mat;

	*R = *A + *B;

	return R;
}