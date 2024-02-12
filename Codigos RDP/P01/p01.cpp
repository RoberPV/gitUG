/*
Programa 1. Creación y uso del dato base de OpenCV.
*/

#include <iostream>
#include "opencv2\core.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat M1;
	cout << "Creacion y uso del tipo de dato de OpenCV\n";
	M1.create(2,4,CV_8U);
	cout << M1 << "\n"<< endl;

	cout << "Creacion de una matriz usando la funcion zeros(3x3)\n";
	M1 = Mat::zeros(3,3,CV_8U);
	cout << M1 << "\n"<<endl;

	cout << "Creacion de una matriz usando la funcion ones(3x3)\n";
	M1 = Mat::ones(3,3,CV_8U);
	cout << M1 << "\n"<<endl;

	cout << "Creacion de una matriz usando la funcion eye(3x3)\n";
	M1 = Mat::eye(3,3,CV_8U);
	cout << M1 << "\n"<<endl;

	//Para tener un tamaño preestablecido es con el tipo de dato Size
	Size tipo1(3,7);
	cout << "Creacion de una matriz usando la funcion eye(3x3) y usando el tipo de dato Size\n";
	M1 = Mat::eye(tipo1,CV_8U);
	cout << M1 << "\n"<<endl;

	//Aritmetica con Mat
	cout << "Sumando 2 a la matriz\n";
	M1 += 2;
	cout << M1 << "\n"<<endl;
	cout << "Multiplicando por 2 a la matriz\n";
	M1 *= 2;
	cout << M1 << "\n"<<endl;

	cout << "Dividiendo entre 3 a la matriz\n";
	M1 /= 3;
	cout << M1 << "\n"<<endl;

	return 0;
}