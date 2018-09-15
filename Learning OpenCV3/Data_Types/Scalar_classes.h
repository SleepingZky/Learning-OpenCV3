#ifndef __SCALAR_CLASS__
#define __SCALAR_CLASS__

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

namespace test_scalar {

	void test_scalar() {
		// four-dimensional point class
		// members are all double 

		cv::Scalar s1(2);//fist element is 2
		cv::Scalar s2(1, 2, 3, 4);
		cv::Scalar s3(1.4, 2.7);
		
		cout << "s1 : " << s1 << endl;
		cout << "s2 : " << s2 << endl;
		cout << "s3 : " << s3 << endl;
		cout << "s2[0] : " << s2[0] << "	s2[1] : " << s2[1] << "		s2[2] : " << s2[2] << "		s2[3] : " << s2[3] << endl;


		//operation

		cv::Scalar s4(s1.mul(s2));
		cv::Scalar s5(s3.mul(s2));

		cout << "s1 mul s2 : " << s4 << endl;
		cout << "s3 mul s2 : " << s5 << endl;

		//conjugation
		cout << "s2 conjugation : " << s2.conj() << endl;

		//real test
		cout << "s1 real test : " << s1.isReal() << endl;
		cout << "s2 real test : " << s2.isReal() << endl;

	}
}

#endif
