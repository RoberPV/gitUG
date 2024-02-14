/*
Programa 2. Uso de la estructura MAT para crear matrices multidimensionales
*/

#include <iostream>
#include "opencv2\core.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat matriz(3,3,CV_32FC2);
	Mat m1 = Mat::ones(3,3,CV_32FC2);
	//Unas propiedades de la clase Mat

	cout << "Numero de filas: " << matriz.rows << endl;
	cout << "Numero de columnas: " << matriz.cols << endl;
	cout << "Tamanio de la matriz: " << matriz.size << endl;
	cout << "Numero de canales: " << matriz.channels() << endl;
	return 0;
}