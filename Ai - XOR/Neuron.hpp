#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <functional>
class Neuron
{
public:
	Neuron(int nInputs);

	void use(std::vector<double>& vec);
	void updateWeights(double eta, std::vector<double> vec, double t);
	void updateWeights(double eta, std::vector<double> vec);


	//sigmoid function
	// f(x) = 1/(1+e^-x);
	void activate();

	// Derivitive of sigmoid function
	// e^-x / (1+e^-x)^2
	void derive();


	void print();

	//Gettery
	double getVal() const;
	double getActiv() const;
	double getDerived() const;
	double getFault()const;
	double& getFault();
	std::vector<double>& getWeights();

	//Setters
	void setFault(double x);

	friend std::ostream& operator << (std::ostream& out, const Neuron& n);

private:
	//Co przyszlo
	double dValue;

	//Zmiana na wartosc [0-1]
	double dActivated;

	//Wartosc pochodnej dla funkcji aktywacji
	double dDerived;

	//Fault in
	double dFault;

	//Beta in sigmoid unipolar function
	const double dBeta = 1;

	//Vector of weights
	std::vector<double> vecWeights;

	static double fill()
	{
		static std::random_device dev;
		static std::mt19937 eng(dev());
		static std::uniform_real_distribution<double> x(0., 1.);
		return x(eng);
	}
};

