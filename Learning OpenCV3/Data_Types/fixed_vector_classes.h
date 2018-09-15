#ifndef __FIXED_VECTOR_CLASS__
#define __FIXED_VECTOR_CLASS__

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

namespace test_fixed_vector {

	void test_fixed_vector() {

		//cv::Vec{2,3,4,6}{b,s,w,i,f,d}
		//cv::Vec<type, m>
		cv::Vec2i v2i(15, 60);
		cv::Vec<double, 10> v10d = cv::Vec<double, 10>::all(10.2);

		cout << "v2i[0] : " << v2i[0] << "	v2i(1) : " << v2i(1) << endl;
		cout << "v10d : " << v10d << endl;

	}
}


#endif
