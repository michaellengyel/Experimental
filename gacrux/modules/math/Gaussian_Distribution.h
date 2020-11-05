//
// Created by michael on 2020. 11. 05..
//

#ifndef EXPERIMENTAL_GAUSSIAN_DISTRIBUTION_H
#define EXPERIMENTAL_GAUSSIAN_DISTRIBUTION_H

class Gaussian_Distribution{
public:

    Gaussian_Distribution(double sigma, double mu);

    ~Gaussian_Distribution();

    Gaussian_Distribution operator+ (const Gaussian_Distribution& obj);

    Gaussian_Distribution operator* (const Gaussian_Distribution& obj);

    double getSigma();

    double getMu();

private:

    double m_sigma;
    double m_mu;

};

#endif //EXPERIMENTAL_GAUSSIAN_DISTRIBUTION_H
