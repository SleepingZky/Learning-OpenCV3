#ifndef __POINT_CLASS__
#define __POINT_CLASS__

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

namespace test_point {

	void test_point() {

		
		cv::Point2i p1(0, 5);
		cv::Point2f p2(0.4, 1.5);
		cv::Point3d p3(0.7, 1.5, 6.0);
		cv::Point2l p4(30000, 60000);
		cv::Point3i p5(4, 6, 8);
		// No Point3b Point3s Point3l

		cv::Vec3d vec;
		vec = p3;//point could cast to the Vec

		cout << "P3.x : " << p3.x << "		P3.y : " << p3.y << "		P3.z : " << p3.z << endl;
		cout << "p1 : " << p1 << endl;
		cout << "p2 : " << p2 << endl;
		cout << "p3 : " << p3 << endl;
		cout << "p4 : " << p4 << endl;
		cout << "p5 : " << p5 << endl;

		//calucation
		{
			float x = p1.dot(p4);
			float y = p2.dot(p4);//long cast to float

			double z = p1.ddot(p2);//double-precision dot product;p2 cast to int [0,2]
			double w = p2.ddot(p1);

			cout << "p1 dot p4 : " << x << "	p2 dot p4 : " << y << "		p1 ddot p2 : " << z << "		p2 ddot p1 : " << w << endl;
		}

		{
			float x = p1.cross(p2);//p2 cast to int [0,2]->0*1.5-5*0=0;
			//double Point_<_Tp>::cross(const Point_& pt) const
			//{
			//	return (double)x*pt.y - (double)y*pt.x;
			//}
			// so cross is not only for 3d point, and the result is a value not vector
			float y = p2.cross(p1);

			cout << "cross for 2D : " << "p1 cross p2 : " << x << "		p2 cross p1 : " << y << endl;

			//double z = p3.cross(p5);//3d point::cross return a 3dPoint not just value
			//Point3_<_Tp> Point3_<_Tp>::cross(const Point3_<_Tp>& pt) const
			//{
			//	return Point3_<_Tp>(y*pt.z - z * pt.y, z*pt.x - x * pt.z, x*pt.y - y * pt.x);
			//}
			auto p6 = p3.cross(p5);//p5 cast to double so p6 is double vaule

			cout << "cross for 3D : " << "p3 cross p5 : " << p6 << endl;

			
		}
		

	}
}

#endif