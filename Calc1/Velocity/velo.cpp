#include <iostream>
using namespace std;

int main() {

   
    // Time values
    double t1 = 3;
    double t2 = 2.0;

    double m = 215;
    double x = 16;

    double y1 = (m*t1) - (x*(t1*t1));
    double y2 = (m*t2) - (x*(t2*t2));

    // Calculate average speed
    double answer = (y2-y1)/(t2-t1);

    // Output the result
    cout << "Average Speed over the interval (" << t1 << ", " << t2 << "): " << answer << " m/s" << endl;

    return 0;
}
