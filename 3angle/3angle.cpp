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
				if ((a != 0) && (xr != 0) && (yr != 0))
				{
					zr = deg_z(a, b, c, xr, yr, zr);
					b = side_b(a, b, c, xr, yr, zr);
					c = side_c(a, b, c, xr, yr, zr);
				}
				else
					if ((b != 0) && (yr != 0) && (zr != 0))
					{
						xr = deg_x(a, b, c, xr, yr, zr);
						a = side_a(a, b, c, xr, yr, zr);
						c = side_c(a, b, c, xr, yr, zr);
					}
					else
						if ((c != 0) && (xr != 0) && (zr != 0))
						{
							yr = deg_y(a, b, c, xr, yr, zr);
							a = side_a(a, b, c, xr, yr, zr);
							b = side_b(a, b, c, xr, yr, zr);
						}
						else
							if ((a != 0) && (yr != 0) && (zr != 0))
							{
								xr = deg_x(a, b, c, xr, yr, zr);
								b = side_b(a, b, c, xr, yr, zr);
								c = side_c(a, b, c, xr, yr, zr);
							}
							else
								if ((a != 0) && (xr != 0) && (zr != 0))
								{
									yr = deg_y(a, b, c, xr, yr, zr);
									b = side_b(a, b, c, xr, yr, zr);
									c = side_c(a, b, c, xr, yr, zr);
								}
								else
									if ((b != 0) && (yr != 0) && (xr != 0))
									{
										zr = deg_z(a, b, c, xr, yr, zr);
										a = side_a(a, b, c, xr, yr, zr);
										c = side_c(a, b, c, xr, yr, zr);
									}
									else
										if ((b != 0) && (zr != 0) && (xr != 0))
										{
											yr = deg_y(a, b, c, xr, yr, zr);
											a = side_a(a, b, c, xr, yr, zr);
											c = side_c(a, b, c, xr, yr, zr);
										}
										else
											if ((c != 0) && (xr != 0) && (yr != 0))
											{
												zr = deg_z(a, b, c, xr, yr, zr);
												a = side_a(a, b, c, xr, yr, zr);
												b = side_b(a, b, c, xr, yr, zr);
											}
											else
												if ((c != 0) && (zr != 0) && (yr != 0))
												{
													xr = deg_x(a, b, c, xr, yr, zr);
													a = side_a(a, b, c, xr, yr, zr);
													b = side_b(a, b, c, xr, yr, zr);
												}
												else
													if ((a != 0) && (b != 0) && (xr != 0))
													{
														zr = deg_z(a, b, c, xr, yr, zr);
														yr = deg_y(a, b, c, xr, yr, zr);
														c = side_c(a, b, c, xr, yr, zr);
													}
													else
														if ((a != 0) && (b != 0) && (zr != 0))
														{
															xr = deg_x(a, b, c, xr, yr, zr);
															yr = deg_y(a, b, c, xr, yr, zr);
															c = side_c(a, b, c, xr, yr, zr);
														}
														else
															if ((a != 0) && (c != 0) && (yr != 0))
															{
																zr = deg_z(a, b, c, xr, yr, zr);
																xr = deg_x(a, b, c, xr, yr, zr);
																b = side_b(a, b, c, xr, yr, zr);
															}
															else
																if ((a != 0) && (c != 0) && (zr != 0))
																{
																	yr = deg_y(a, b, c, xr, yr, zr);
																	xr = deg_x(a, b, c, xr, yr, zr);
																	b = side_b(a, b, c, xr, yr, zr);
																}
																else
																	if ((b != 0) && (c != 0) && (xr != 0))
																	{
																		yr = deg_y(a, b, c, xr, yr, zr);
																		zr = deg_z(a, b, c, xr, yr, zr);
																		a = side_a(a, b, c, xr, yr, zr);
																	}
																	else
																		if ((b != 0) && (c != 0) && (yr != 0))
																		{
																			xr = deg_x(a, b, c, xr, yr, zr);
																			zr = deg_z(a, b, c, xr, yr, zr);
																			a = side_a(a, b, c, xr, yr, zr);
																		}
}



double deg_x(double a, double b, double c, double xr, double yr, double zr)
{
	if ((yr != 0) && (zr != 0)) xr = M_PI - yr - zr; else
		if ((a != 0) && (b != 0) && (c != 0)) xr = acos((a * a + c * c - b * b) / (2 * a * c)); else
			if ((b != 0) && (a != 0) && (zr != 0)) xr = asin(b * sin(zr) / a); else
				if ((b != 0) && (a != 0) && (yr != 0)) xr = asin(b * sin(yr) / a);

	return xr;
}

double deg_y(double a, double b, double c, double xr, double yr, double zr)
{
	if ((xr != 0) && (zr != 0)) yr = M_PI - xr - zr; else
		if ((a != 0) && (b != 0) && (c != 0)) yr = acos((a * a + b * b - c * c) / (2 * a * b)); else
			if ((b != 0) && (c != 0) && (xr != 0)) yr = asin(c * sin(xr) / b); else
				if ((a != 0) && (c != 0) && (zr != 0)) yr = c * sin(zr) / a; if (yr > 1) yr = 1; yr = asin(yr);

	return yr;

}

double deg_z(double a, double b, double c, double xr, double yr, double zr)
{
	if ((a != 0) && (b != 0) && (xr != 0)) zr = asin(a * sin(xr) / b); else
		if ((xr != 0) && (yr != 0)) zr = M_PI - xr - yr; else
			if ((a != 0) && (c != 0) && (yr != 0)) zr = asin(a * sin(yr) / c);

	return zr;

}

double side_a(double a, double b, double c, double xr, double yr, double zr)
{
	if ((b != 0) && (c != 0)) a = sqrt(b * b + c * c - 2 * b * c * cos(zr)); else
		if ((b != 0) && (yr != 0) && (zr != 0)) a = b * sin(zr) / sin(xr); else
			if ((c != 0) && (xr != 0) && (zr != 0)) a = c * sin(zr) / sin(yr);

	return a;
}

double side_b(double a, double b, double c, double xr, double yr, double zr)
{
	if ((a != 0) && (c != 0) && (xr != 0)) b = sqrt(a * a + c * c - 2 * a * c * cos(xr)); else
		if ((a != 0) && (xr != 0) && (yr != 0)) b = a * sin(xr) / sin(zr);

	return b;
}

double side_c(double a, double b, double c, double xr, double yr, double zr)
{
	if ((a != 0) && (b != 0) && (yr != 0)) c = sqrt(a * a + b * b - 2 * a * b * cos(yr));

	return c;
}

void if_degrees(double& ar, double xr, double yr, double zr, double& xg, double& xm, double& xs, double& yg, double& ym, double& ys, double& zg, double& zs, double& zm)
{
	double  ag, am, as;
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			ar = xr;
			xg = conversion_deg(ar);
			xm = conversion_min(ar);
			xs = conversion_sec(ar);
		}
		else
			if (i == 1) {
				ar = yr;
				yg = conversion_deg(ar);
				ym = conversion_min(ar);
				ys = conversion_sec(ar);
			}
			else
				if (i == 2) {
					ar = zr;
					zg = conversion_deg(ar);
					zm = conversion_min(ar);
					zs = conversion_sec(ar);
				}
	}
}

double conversion_deg(double ar)
{
	double ag;

	ar *= DMS;
	ag = floor(ar);

	return ag;
}

double conversion_min(double ar)
{
	double am, ag;

	ar *= DMS;
	ag = floor(ar);
	am = (ar - ag) * 60;
	am = floor(am);

	return am;
}

double conversion_sec(double ar)
{
	double as, am, ag, a1;

	ar *= DMS;
	ag = floor(ar);
	a1 = (ar - ag) * 60;
	am = floor(a1);
	as = (a1 - am) * 60;

	return as;
}

void conclusion(double a, double b, double c, double xg, double xm, double xs, double yg, double ym, double ys, double zg, double zs, double zm) //Вывод данных
{
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
	cout << "x=" << xg << char(248) << xm << "\'" << xs << "\"" << endl;
	cout << "y=" << yg << char(248) << ym << "\'" << ys << "\"" << endl;
	cout << "z=" << zg << char(248) << zs << "\'" << zm << "\"" << endl;
}