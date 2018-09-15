#ifndef __FIXED_MATRIX_CLASS__
#define __FIXED_MATRIX_CLASS__

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

namespace test_fixed_matrix {

	void test_fixed_matrix() {

		//cv::Matx{1,2,3,4,6}{1,2,3,4,6}{f,d}
		//cv::Matx<type, m, n>

		cv::Matx33f m33f(0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9);
		cv::Matx22d m22d;
		cv::Matx43f m43f;
		cv::Matx16d m16d;
		cv::Matx23f m23f;

		m22d = cv::Matx22d::all(10);
		m43f = cv::Matx43f::zeros();
		m16d = cv::Matx16d::ones();
		m23f = cv::Matx23f::eye();//a unit matrix

		cout << "m33f : \n" << m33f << endl;
		cout << "m22d : \n" << m22d << endl;
		cout << "m43f : \n" << m43f << endl;
		cout << "m16d : \n" << m16d << endl;
		cout << "m23f : \n" << m23f << endl;

		cv::Matx31f m31f = m33f.diag();//create a matrix can hold the diagonal of another
		cv::Matx33d m33d = cv::Matx33d::randu(1, 9);//uniformly distributed entries
		cv::Matx33f m33f2 = cv::Matx33f::randn(1, 9);//normally distributed entries

		cout << "m31f : \n" << m31f << endl;
		cout << "m33f2 : \n" << m33f2 << endl;
		cout << "m33d : \n" << m33d << endl;

		//member access
		cout << "m33d(2,1) : " << m33d(2, 1) << endl;

		//Matrix algebra
		cv::Matx33d m33d2 = m33d + cv::Matx33d::randu(9, 20);
		cv::Matx33d m33d3 = m33d - cv::Matx33d::randu(9, 20);
		cv::Matx33d m33d4 = m33d * cv::Matx33d::randu(9, 20);

		cout << "m33d2 : \n" << m33d2 << endl;
		cout << "m33d3 : \n" << m33d3 << endl;
		cout << "m33d4 : \n" << m33d4 << endl;

		//Singleton algebra
		cv::Matx33d m33d5 = m33d * 3;
		cv::Matx33d m33d6 = 3 * m33d;
		//cv::Matx33d m33d7 = m33d / 3 ;

		cout << "m33d5 : \n" << m33d5 << endl;
		cout << "m33d6 : \n" << m33d6 << endl;
		//cout << "m33d7 : \n" << m33d7 << endl;

		cv::Matx<double,9,1> m91d = m33d.reshape<9, 1>();
		cout << "m91d : \n" << m91d << endl;

		//solve linear system
		//cv::Matx31d m31d = m33d.solve(rhs31f, DECOMP_LU);
		//不知道怎么使用solve


	


	}
}

#endif
