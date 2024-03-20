#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat img, imgrayI, imgrayG, imgrayL, imgrayLuma, r, g, b;
	Mat imagenCLAHEI, imagenCLAHEG, imagenCLAHEL, imagenCLAHELuma, imagenCLAHEV;
	Mat imagenBinariaI, imagenBinariaG, imagenBinariaL, imagenBinariaLuma, imagenBinariaV;
	vector<Mat> canales;
	img = imread("C:/Users/rprie/OneDrive - Universidad de Guanajuato/MIE/Segundo Cuatrimestre/Procesamiento de imagenes/Imagenes/Tarea 2/Petrifilm 1.jpg", IMREAD_UNCHANGED);
	imshow("Imagen A Color", img);
	Ptr<CLAHE> clahe = createCLAHE();
    clahe->setClipLimit(2.0);
  
  
    

	split(img, canales);

	imgrayI = (canales[0]+canales[1]+canales[2])/3;

	clahe->apply(imgrayI, imagenCLAHEI);
    /*threshold(imgrayI, imagenBinariaI, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	imshow("Escala de gris (Intensity)", imgrayI);
	imshow("Escala de gris (Intensity) con CLAHE", imagenCLAHEI);
	imshow("Escala de gris (Intensity) con CLAHE y Otsu", imagenBinariaI);

	transpose(canales[0],b);
	transpose(canales[1],g);
	transpose(canales[2],r);

	imgrayG = (b+g+r)/3;
	clahe->apply(imgrayG, imagenCLAHEG);
    threshold(imgrayG, imagenBinariaG, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	imshow("Escala de gris (Gleam)", imgrayG);
	imshow("Escala de gris (Gleam) con CLAHE", imagenCLAHEG);
	imshow("Escala de gris (Gleam) con Otsu", imagenBinariaG);

	imgrayL = (0.3*canales[2]+0.59*canales[1]+0.11*canales[0]);
	clahe->apply(imgrayL, imagenCLAHEL);
    threshold(imgrayL, imagenBinariaL, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	imshow("Escala de gris (Luminance)", imgrayL);
	imshow("Escala de gris (Luminance) con CLAHE", imagenCLAHEL);
	imshow("Escala de gris (Luminance) con Otsu", imagenBinariaL);

	imgrayLuma = (0.2126*r+0.7152*g+0.0722*b);
	clahe->apply(imgrayLuma, imagenCLAHELuma);
    threshold(imgrayLuma, imagenBinariaLuma, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	imshow("Escala de gris (Luma)", imgrayLuma);
	imshow("Escala de gris (Luma) con CLAHE", imagenCLAHELuma);
	imshow("Escala de gris (Luma) con Otsu", imagenBinariaLuma);*/

 	Mat imgrayV(img.rows, img.cols, CV_8UC1);
    
    for(int i = 0; i < img.rows; ++i) 
    {
        for(int j = 0; j < img.cols; ++j) 
        {
            Vec3b color = img.at<Vec3b>(i, j);
            
            uchar valorMax = max(color[0], max(color[1], color[2]));
            
            imgrayV.at<uchar>(i, j) = valorMax;
        }
    }
    cout << imgrayV.channels();
    Mat normalized_img;
    normalize(imgrayV, imgrayV, 0, 255, NORM_MINMAX, CV_8UC1);
    //medianBlur(imgrayV, imgrayV, 3);
    blur(imgrayV, imgrayV, Size(5,5));

    clahe->apply(imgrayV, imagenCLAHEV);
    //threshold(imgrayV, imagenBinariaV, 216, 255, THRESH_OTSU);
    adaptiveThreshold(imgrayV, imagenBinariaV, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 7, 12);
	imshow("Escala de gris (Valor) normalizada y con blur", imgrayV);
	imshow("Escala de gris (Luminance) con CLAHE", imagenCLAHEV);
	imshow("Escala de gris (Luminance) umbralizacion", imagenBinariaV);
	waitKey(0);

	return 0;
}