#include "Gaussian_Distribution.h"

Gaussian_Distribution::Gaussian_Distribution(double sigma, double mu) : m_sigma(sigma), m_mu(mu) {

}

Gaussian_Distribution::~Gaussian_Distribution() {

}

Gaussian_Distribution Gaussian_Distribution::operator+ (const Gaussian_Distribution& obj) {
    Gaussian_Distribution temp(this->m_mu = obj.m_mu + m_mu, this->m_sigma = obj.m_sigma + m_sigma);
    return temp;
}

Gaussian_Distribution Gaussian_Distribution::operator* (const Gaussian_Distribution& obj) {
    Gaussian_Distribution temp(this->m_mu = obj.m_mu * m_mu, this->m_sigma = obj.m_sigma * m_sigma);
    return temp;
}

double Gaussian_Distribution::getSigma() {
    return m_sigma;
}

double Gaussian_Distribution::getMu() {
    return m_mu;
}