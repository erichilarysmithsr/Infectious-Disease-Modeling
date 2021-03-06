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
using state_type = array<double, 3>;

void diff(double
          const, double
          const, state_type
          const &, state_type &, double
          const);

void write_diff(state_type
                const &, double
                const);

//Solving the differential equations
void diff(double
          const beta, double
          const alpha,
          state_type
          const &x, state_type &dxdt,
          double
          const t) {
    dxdt[0] = -beta * x[0] * x[1];
    dxdt[1] = beta * x[0] * x[1] - alpha * x[1];
    dxdt[2] = alpha * x[1];
}

int main() {
    double S0, I0, R0, beta, alpha, t0, t1, dt;
    cout << "Enter values for S,I,R,alpha,beta,t0,t1,dt" << endl;
    cin >> S0 >> I0 >> R0 >> beta >> alpha >> t0 >> t1 >> dt;

    double N = S0 + I0 + R0;

    cout << '\n' << "Output of SIR DETERMINISTIC Model" << '\n' << endl;
    cout << "The total population is " << N << '\n' << endl;
    //Displays the suceptible,infected and recovered number at each point of time.
    cout << "TIME" << '\t' << '\t' << "S(t)" << '\t' << "  I(t)" << '\t' << '\t' << "R(t)" << '\n' << endl;

    state_type x;
    x[0] = S0 / N;
    x[1] = I0 / N;
    x[2] = R0 / N;
    integrate(bind(diff, beta, alpha, _1, _2, _3),
              x, t0, t1, dt, write_diff);
}

void write_diff(const state_type &x,
                const double t) {
    if (t == 0) {
        cout << setw(7) << "Time" << ' ' << setw(12) << "s(t)" << ' ' << setw(12) << "i(t)" << ' ' << setw(12) << "r(t)"
             << ' ' << endl;
        cout << setfill('-') << setw(8) << ' ' << setw(13) << ' ' << setw(13) << ' ' << setw(13) << ' ' << endl;
    }
    cout.precision(5);
    cout.fill(' ');
    cout << setw(7) << t << ' ' << setw(12) << x[0] << ' ' << setw(12) << x[1] << ' ' << setw(12) << x[2] << endl;
}