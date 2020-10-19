#ifndef GENERATORS_H
#define GENERATORS_H
#include <math.h>
class Generators
{
public:
	void KRand(double kern_);
	double Random();
	double Random(int precision_);
	double Random(double min, double max);
	double Random(double min, double max, int precision_);
	double RndExp(double lambda, int precision_);
	int RndZeroOne(double p);
private:
	double kernel_;
	double Floor(double number_);
	int FloorToInt(double number_);
	size_t FloorToSizeT(double number_);
	double SetPrecision(double value_, int numbers_after_coma_);
	double M = 2147483647.0;
	double A = 16807.0;
	double Q = 127773.0;
	double R = 2836;
};

#endif // !GENERATORS_H


