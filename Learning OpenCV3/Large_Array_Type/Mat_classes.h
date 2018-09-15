#ifndef __MAT_CLASS__
#define __MAT_CLASS__

#include<iostream>
#include<opencv2/opencv.hpp>
#include<ctime>

using namespace std;

namespace test_mat_class {

	void test_mat_class() {

		//how to create a mat

		cv::Mat m1;
		m1.create(3, 10, CV_32FC3);
		m1.setTo(cv::Scalar(1.0f, 0.0f, 1.0f));

		cv::Mat m2(3, 10, CV_32FC3, cv::Scalar(1.0, 0.0, 1.0));
		
		srand(time(NULL));
		short data[240];
		for (int i = 0; i < 240; i++)
		{
			data[i] = rand()%10;
		}
		cv::Mat m3(6, 10, CV_16SC4, data);

		cv::Mat m4(cv::Size(10, 14), CV_16UC1,cv::Scalar(1));

		int sizes[] = {2,2,2 };
		cv::Mat m5(3, sizes, CV_32FC2, cv::Scalar(1.0, 0.5));

		cout << "m1 : \n" << m1 << endl;
		cout << "m2 : \n" << m2 << endl;
		cout << "m3 : \n" << m3 << endl;
		cout << "m4 : \n" << m4 << endl;
		cout << m3.size << " " << m3.channels() << " " << m3.depth() << " " << endl;
		//cout << "m5 : \n" << m5 << endl; //when dimensions>=3, it can't use << in dos


		// copy constructor

		cv::Mat m6 (m3,  cv::Range(2, 4), cv::Range(6, 8));//only for one channels?
		cv::Mat m7 (m3,  cv::Rect(cv::Point2i(4,3), cv::Size2i(3,2)));
		// CV_Assert( 0 <= roi.x && 0 <= roi.width && roi.x + roi.width <= m.cols &&
		//			  0 <= roi.y && 0 <= roi.height && roi.y + roi.height <= m.rows );
		//x to cols and y to rows

		cout << "m6 : \n" << m6 << endl;
		cout << "m7 : \n" << m7 << endl;

		// template constructors 
		// mat from template

		cv::Mat m8(cv::Vec6i(10, 12, 16, 18, 20, 22), 1);//6 rows and one col
		cv::Mat m9(cv::Matx23f(11.1,11.2,11.3,11.4,11.5,11.6), 1);

		cout << "m8 : \n" << m8 << endl;
		cout << "m9 : \n" << m9 << endl;

		// static funcions 
		
		cout << "Mat::zeros() : \n" << cv::Mat::zeros(3, 3, CV_16UC3) << endl;
		cout << "Mat::ones() : \n" << cv::Mat::ones(3, 3, CV_16UC3) << endl;//just set first channel
		cout << "Mat::eye() : \n" << cv::Mat::eye(3,3,CV_16UC3) << endl;//also just set first channel

		// access elements individually at<> & iterator

		cout << "m7.at<cv::Vec<short,4>>(1,1) : " << m7.at<cv::Vec<short, 4>>(1, 2) << endl;
		
		cv::MatIterator_<cv::Vec<short, 4>> it = m7.begin<cv::Vec<short, 4>>();//so troublesome
		while (it != m7.end<cv::Vec<short, 4>>()) {
			
			cout << (*it)[0] << "	"<< endl;
			it++;
		}

		//N-ary Array Iterator
		{
			const cv::Mat* arrays[] = { &m3, 0 };
			cv::Mat my_planes[1];
			cv::NAryMatIterator it(arrays, my_planes);

			for (int p = 0; p < it.nplanes; p++, ++it) {
				cout << (it.planes[0]) << endl;
			
				//if there are more then one mat in arrays, you can use planes[0,1,2...] to access them
				//it.planes refer to a continous face ,if the mat includes discontinuous data, the it will iterator to access all the face
				//the planes is not only 2D, if you pass into a 3D mat, it planes will also refer to it 
			}
		}

		//access array elements by block
		//the data is not copied 

		cout << "m7.row(1) : \n" << m7.row(1) << endl;
		cout << "m7.col(2) : \n" << m7.col(2) << endl;
		cout << "m7.diag(1) : \n" << m7.diag(1) << endl;//diag(n) n-offset diagonal

		// Matrix Algebra

		//Saturation Casing
		uchar Vxy = (uchar)10;
		uchar Vxy1 = (Vxy - 128) * 2 + 128;
		uchar Vxy2 = cv::saturate_cast<uchar>((Vxy - 128) * 2 + 128);
		cout << Vxy1 << endl;
		cout << Vxy2 << endl;


		
 	}
}

#endif
