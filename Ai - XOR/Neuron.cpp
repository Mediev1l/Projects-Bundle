#include "Neuron.hpp"


Neuron::Neuron(int nInputs)
	:
	vecWeights(nInputs + 1)
	, dActivated(0.)
	, dValue(0.)
	, dDerived(0.)
	, dFault(0.)
{
	std::generate_n(vecWeights.begin(), vecWeights.size(), std::ref(fill));
}

void Neuron::use(std::vector<double>& vec)
{
	dValue = 0.;
	for (int i = 0, e = vec.size(); i < e; ++i) dValue += vec[i] * vecWeights[i];
	activate();
	derive();
}

void Neuron::updateWeights(double eta, std::vector<double> vec, double t)
{
	for (int i = 1, e = vecWeights.size(); i < e; ++i)
	{
		//printf("Old %4.6f ", vecWeights[i]);
		vecWeights[i] = vecWeights[i] + eta * (t - dActivated) * (1. - dActivated) * vec[i - 1] * dActivated;
		//printf("New %4.6f\n", vecWeights[i]);
	}
}

void Neuron::updateWeights(double eta, std::vector<double> vec)
{
	for (int i = 0, e = vecWeights.size(); i < e; ++i)
	{
		//printf("Old %4.6f ", vecWeights[i]);
		vecWeights[i] = vecWeights[i] + eta * dFault * vec[i];
		//printf("New %4.6f\n", vecWeights[i]);
	}
}

void Neuron::activate()
{
	dActivated = 1. / (1 + exp(-dBeta * dValue));
}

void Neuron::derive()
{
	dDerived = (dBeta * exp(-dBeta * dValue)) / pow(1 + exp(-dBeta * dValue), 2);
}

void Neuron::print()
{
	printf("Value in  : %4.4f\n", dValue);
	printf("Activation: %4.4f\n", dActivated);
	printf("Derived   : %4.4f\n", dDerived);
}

double Neuron::getVal() const
{
	return dValue;
}

double Neuron::getActiv() const
{
	return dActivated;
}

double Neuron::getDerived() const
{
	return dDerived;
}

double Neuron::getFault() const
{
	return dFault;
}

double& Neuron::getFault()
{
	return dFault;
}

std::vector<double>& Neuron::getWeights()
{
	return vecWeights;
}

void Neuron::setFault(double x)
{
	dFault = x;
}

std::ostream& operator<<(std::ostream& out, const Neuron& n)
{
	out << "Val       : " << n.getVal() << '\n'
		<< "Avtivation: " << n.getActiv() << '\n'
		<< "Derived   : " << n.getDerived() << '\n';;
	return out;
}
