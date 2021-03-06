/*
 *  @filename       _
 *  @fileheader     _
 *  @tile           _
 *  @author         Team Infection
 *
 */
#include <iostream>
#include <array>
#include <boost/numeric/odeint.hpp>
#include <functional>
#include <iomanip>

using namespace std;
using namespace boost::numeric::odeint;
using namespace std::placeholders;
using state_type = array<double, 2>;

//defining method diff to calculate the number of susceptibles and infected at each time interval
void diff(double const, double const, state_type const &, state_type &, double const);

void write_diff(state_type const &, double const);

//Solving the differential equations for SIS Model
void diff(double const beta, double const alpha,
          state_type const &x, state_type &dxdt,
          double const t) {
    dxdt[0] = -beta * x[0] * x[1] + alpha * x[1];
    dxdt[1] = beta * x[0] * x[1] - alpha * x[1];
}

int main() {
    double S0, I0, beta, alpha, t0, t1, dt;

    //User defined values are taken for S,I,alpha,beta,t0,t1 and dt
    cout << "Enter values for S,I,alpha,beta,t0,t1,dt" << endl;
    cin >> S0 >> I0 >> beta >> alpha >> t0 >> t1 >> dt;

    //Calculating the total population
    double N = S0 + I0;

    //Displays output for SIS Model
    cout << '\n' << "Output of SIS DETERMINISTIC Model" << '\n' << endl;

    //Displays total population
    cout << "The Total population is " << N << '\n' << endl;
    cout << "TIME" << '\t' << '\t' << "S(t)" << '\t' << "  I(t)" << '\t' << '\t' << '\n' << endl;

    //Defining the state of susceptibles and infected at time 0 and time 1
    state_type x;
    x[0] = S0 / N;
    x[1] = I0 / N;

    integrate(bind(diff, beta, alpha, _1, _2, _3),
              x, t0, t1, dt, write_diff);
}

//Describing the write_diff method to display the suceptible and infected at each point of time.
void write_diff(const state_type &x, const double t) {
    cout.precision(5);
    cout.fill(' ');
    cout << setw(7) << t << ' '
         << setw(12) << x[0] << ' '
         << setw(12) << x[1] << ' '
         << endl;
}

