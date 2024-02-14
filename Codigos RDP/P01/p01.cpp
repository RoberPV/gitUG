/*
Programa 1. Creación y uso del dato base de OpenCV.
*/

#include <iostream>
#include "opencv2\core.hpp"

using namespace std;
using namespace cv;

int main()
{
	Mat M1, M2;
	cout << "Creacion y uso del tipo de dato de OpenCV\n";
	M1.create(3,3,CV_8U);
	M2 = Mat::ones(3,3,CV_8U);
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
	Size tipo1(3,3);
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

	cout << "Resta de dos matrices M1 y M2\n";
	M1-=M2;
	cout << M1 << "\n"<<endl;

	cout << "Suma de dos matrices M1 y M2\n";
	M1+=M2;
	cout << M1 << "\n"<<endl;

	cout << "Multiplicacion de dos matrices M1 y M2\n";
	//M1*=M2; Solo puede ser con el tipo de dato flotante 32F
	cout << M1 << "\n"<<endl;

	cout << "Multiplicacion de dos matrices M1 y M2 punto a punto\n";
	M1=M1.mul(M2); //No es equivalente al producto de matrices
	cout << M1 << "\n"<<endl;

	//Unas propiedades de la clase Mat
	cout << "Numero de filas: " << M1.rows << endl;
	cout << "Numero de columnas: " << M1.cols << endl;
	cout << "Tamanio de la matriz: " << M1.size << endl;
	cout << "Numero de canales: " << M1.channels() << endl;

	//Para acceder a una posición de la matriz es con la siguiente función
	cout << "Accediendo a un dato en particular de la matriz\n";
	M1.at<unsigned char>(6,2) = 128;
	cout << M1 << "\n"<<endl;

	return 0;
}