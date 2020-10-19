#include "Generators.h"

void Generators::KRand(double kern_)
{
	kernel_ = kern_;
}

double Generators::Random()
{
	double h = Floor(kernel_ / Q);
	kernel_ = A * (kernel_ - Q * h) - R * h;
	if (kernel_ < 0.0)
	{
		kernel_ += M;
	}
	return kernel_ / M;
}

double Generators::Random(int precision_)
{
	double h = Floor(kernel_ / Q);
	kernel_ = A * (kernel_ - Q*h) - R*h;
	if (kernel_ < 0.0)
	{
		kernel_ += M;
	}
	return SetPrecision( kernel_ / M, precision_);
}

double Generators::Random(double min, double max, int precision_)
{
	return SetPrecision(Random() * (max - min) +min, precision_);
}

double Generators::Random(double min, double max)
{
	return Random() * (max - min) + min;
}

double Generators::RndExp(double lambda, int precision_)
{
	double k = Random();
	return SetPrecision(-(1.0/ lambda) * (double)log(k), precision_);
}

int Generators::RndZeroOne(double p)
{
	double k = Random();
	if (k < p)
		return 1;
	else
		return 0;
}

double Generators::Floor(double number_)
{
	double fraction_ = number_;
	double integer_ = 0;
	fraction_ = modf(number_, &integer_);
	if (number_ >= 0.0)
	{
		return integer_;
	}
	else
	{
		return integer_ - 1.0;
	}

}

int Generators::FloorToInt(double number_)
{
	if (number_ >= 0.0)
	{
		return static_cast<int> (number_);
	}
	else
	{
		return static_cast<int> (number_ - 1.0);
	}
}

size_t Generators::FloorToSizeT(double number_)
{
	if (number_ >= 0.0)
	{
		return static_cast<size_t> (number_);
	}
	else
	{
		return static_cast<size_t> (number_ - 1.0);
	}
}

double Generators::SetPrecision(double value_, int numbers_after_coma_)
{
	int multiplier = 1;
	for (int i = 0; i < numbers_after_coma_; i++)
	{
		multiplier = multiplier * 10;
	}
	value_ = value_ * (double)multiplier;
	value_ = Floor(value_);
	value_ = value_ / (double)multiplier;
	return value_;
}
