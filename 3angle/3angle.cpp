// 3angle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "stdafx.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include "math.h"
using namespace std;

const double RHO = M_PI / 180;
const double DMS = 180 / M_PI;

void enter_triangle(double&, double&, double&, double&, double&, double&);
double dms_to_rad(double);
void comparision(double&, double&, double&, double&, double&, double&);
double deg_x(double, double, double, double, double, double);
double deg_y(double, double, double, double, double, double);
double deg_z(double, double, double, double, double, double);
double side_a(double, double, double, double, double, double);
double side_c(double, double, double, double, double, double);
double side_b(double, double, double, double, double, double);
void if_degrees(double&, double, double, double, double&, double&, double&, double&, double&, double&, double&, double&, double&);
double conversion_deg(double);
double conversion_min(double);
double conversion_sec(double);
void conversion(double, double&, double&, double&);
void conclusion(double, double, double, double, double, double, double, double, double, double, double, double);

int _tmain(int argc, _TCHAR* argv[])
{
	double a, b, c, xg, xm, xs, yg, ym, ys, zg, zm, zs, xr, yr, zr, ar, ag, am, as;
	enter_triangle(a, b, c, xr, yr, zr);
	comparision(a, b, c, xr, yr, zr);
	if_degrees(ar, xr, yr, zr, xg, xm, xs, yg, ym, ys, zg, zs, zm);
	conclusion(a, b, c, xg, xm, xs, yg, ym, ys, zg, zm, zs);
	system("pause");
	return 0;
}

void enter_triangle(double& a, double& b, double& c, double& xr, double& yr, double& zr) //Ввод данных
{
	cout << "Enter a,b,c (sides of a triangle) (If one of the sides is unknown, type 0) \n";
	cin >> a >> b >> c;
	cout << "Enter x as degrees, minutes and seconds" << endl;
	xr = dms_to_rad(xr);
	cout << "Enter y as degrees, minutes and seconds" << endl;
	yr = dms_to_rad(yr);
	cout << "Enter z as degrees, minutes and seconds" << endl;
	zr = dms_to_rad(zr);
}

double dms_to_rad(double r) //Перевод в градусы
{
	double d, m, s;
	cin >> d >> m >> s;
	r = (d + m / 60 + s / 3600) * RHO;

	return r;
}

void comparision(double& a, double& b, double& c, double& xr, double& yr, double& zr)
{
	if ((a != 0) && (b != 0) && (c != 0))
	{
		xr = deg_x(a, b, c, xr, yr, zr);
		yr = deg_y(a, b, c, xr, yr, zr);
		zr = deg_z(a, b, c, xr, yr, zr);
	}
	else
		if ((a != 0) && (c != 0) && (xr != 0))
		{
			b = side_b(a, b, c, xr, yr, zr);
			yr = deg_y(a, b, c, xr, yr, zr);
			zr = deg_z(a, b, c, xr, yr, zr);
		}
		else
			if ((a != 0) && (yr != 0) && (b != 0))
			{
				c = side_c(a, b, c, xr, yr, zr);
				xr = deg_x(a, b, c, xr, yr, zr);
				zr = deg_z(a, b, c, xr, yr, zr);
			}
			else
				//ороро