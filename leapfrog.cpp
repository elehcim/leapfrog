#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;


const double mu = 0.01;
const double h  = 0.001;
const double t_max = 100;

double energy(Vec r, Vec v)
{
    return 0.5 * v.norm2() - mu / r.norm();
}

Vec acceleration(Vec r)
{
    return - mu * r / r.norm3();
}

double energy_error(double E, double E0)
{
    return (E - E0) / E0;
}


int main()
{
    string filename = "orbit.txt";
    cout << "Writing to file '"<< filename << "'..." << endl;

    ofstream outfile(filename);
    outfile << setprecision(8);

    const Vec r0 {1, 0};
    const Vec v0 {0, 0.06};
    Vec a0 = acceleration(r0);
    double E0 = energy(r0, v0);

    cout << "a0 = " << setprecision(8) << a0 << endl;
    cout << "E0 = " << setprecision(8) << E0 << endl;

    outfile << "# t x y E err\n" << endl;

    outfile << 0 << ' ' << r0.x() << ' ' << r0.y() << ' ' << E0 << ' ' << 0 << '\n';

    Vec r_half = r0 + 0.5 * h * v0 + 1.0/8.0 * h*h * a0;

    Vec v_n(v0);
    Vec r(r_half);

    cout << "r = " << r << endl;
    cout << "Going to perform " << t_max/h << " steps" << endl;

    for (double t=h; t < t_max; t += h)
    {
        // Drift
        r = r + h * v_n;

        // Kick
        Vec v_np1 = v_n + h * acceleration(r);

        // Compute energy error
        Vec v_nphalf = (v_np1 + v_n) / 2;
        double E_nphalf = energy(r, v_nphalf);
        double relative_error = energy_error(E_nphalf, E0);

        v_n = v_np1;
        outfile << t << ' ' << r.x() << ' ' << r.y() << ' ' << E_nphalf << ' '<< relative_error <<'\n';
    }

    outfile.close();

    cout << "Done writing." << endl;
}
