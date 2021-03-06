/*
 *  @filename       Disease.h
 *  @tile           Disease
 *  @author         Team Infection
 *
 */
#ifndef GUARD_DISEASE_H
#define GUARD_DISEASE_H

#include <iostream>

class Disease {
public:
    Disease(std::string n, double a, double b, double m_r, int r, int time);

    Disease(std::string n, double a, double b, double m_r, int r);

    Disease(std::string n, double a, double b, double m_r);

    std::string getName();

    double getAlpha();

    double getBeta();

    double get_mortality_rate();

    int get_range();

    int get_incubation_time();

    void set_alpha(double a);

    void set_beta(double b);

    void set_mortality_rate(double m_r);

    void set_range(int r);

    void set_incubation_time(int t);

private:
    std::string name;
    double alpha;
    double beta;
    double mortality_rate;
    int incubation_time;
    int range;
};

#endif // GUARD_DISEASE_H