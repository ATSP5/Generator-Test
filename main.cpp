#include <iostream>
#include "Generators.h"
#include <vector>
#include "NumericIntegrator.h"
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

int FindValue(double value, vector<NumericIntegrator*> numeric_integrator_v_)
{
	if (numeric_integrator_v_.size() != 0)
	{
		for (int i = 0; i < numeric_integrator_v_.size(); i++)
		{
			if (numeric_integrator_v_[i]->GetValue() == value)
			{
				return i;
			}
		}
		return -1;
	}
	else
	{
		return -1;
	}
}

bool PushSorted(vector<NumericIntegrator*> &numeric_integrator_v_, NumericIntegrator *NumericInt)
{
	if (numeric_integrator_v_.size() == 0)
	{
		numeric_integrator_v_.push_back(NumericInt);
	}
	else
	{
		for (int i = 0; i < numeric_integrator_v_.size(); i++)
		{
			if (numeric_integrator_v_[i]->GetValue() > NumericInt->GetValue())
			{
				numeric_integrator_v_.insert(numeric_integrator_v_.begin()+(i),NumericInt);
				return true;
			}
		}
		numeric_integrator_v_.insert(numeric_integrator_v_.end(), NumericInt);
	}
	return true;
}
int main()
{
	Generators* generator_ = new Generators();
	cout << "Give me: KERNEL!!!" << endl;
	double kern = 0.0, rand_value_=0.0;
	cin >> kern;
	generator_->KRand(kern);
	vector<NumericIntegrator*> numeric_integrator_vect_;
	int index = 0;
	for (int i = 0; i <30000; i++)
	{
		rand_value_ = generator_->RndExp(0.05,2)*1000;
		index = FindValue(rand_value_, numeric_integrator_vect_);
		if (index != -1)
		{
			numeric_integrator_vect_[index]->IncreaseNumberOfOcurance(1.0);
		}
		else
		{
			PushSorted(numeric_integrator_vect_, new NumericIntegrator(rand_value_));
		}
	}

	string log_ = "Kernel initial value: " + to_string(kern) + "\n";
	for (int i = 0; i < numeric_integrator_vect_.size(); i++)
	{
		log_ += to_string(numeric_integrator_vect_[i]->GetValue()) + " \t " + to_string(numeric_integrator_vect_[i]->GetNumberOfOcurance()) + "\n";
	}

	string histname_;
	cout << "Specify histogram file name" << endl;
	cin >> histname_;
	ofstream myfile;
	myfile.open(histname_);
	myfile << log_;
	myfile.close();

	return 0;
}