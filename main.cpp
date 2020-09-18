//Абдыкеримов Урмат Эмирбекович М8О-206Б-19

#include <iostream>
#include <cmath>

using namespace std;

const double PI = acos(-1), eps = 1e-8;

class Angle {
  public:
  double degrees;
  Angle();
  Angle(double _degrees, double _minutes) {
    degrees = _degrees + _minutes / 60.0;    
  }
  Angle(Angle rhs) {
    degrees = rhs.degrees;
  }
  void add(Angle rhs) {
    //увеличиваю degrees на угол rhs
    degrees += rhs.degrees;
  }
  void subtract(Angle rhs) {
    //уменьшаю degrees на rhs
    degrees -= rhs.degrees;
  }

  double inRadians() {
    //значение degrees в радианах
    double res = degrees / 180.0 * PI;
    return res;
  }

  double getSin() {
    return sin(degrees / 180.0 * PI);
  }

  double getCos() {
    return cos(degrees / 180.0 * PI);
  }

  void to2pi() {
    //привожу degrees к отрезку [0:360] градусов
    if(degrees >= 0) {
      degrees -= (int)degrees / 360 * 360;
    } else {
      degrees += ((int)(abs((int)degrees) / 360 + 1)) * 360;
    }
  }

  bool isBigger(Angle rhs) {
    //если rhs больше degrees возвращает true
    return rhs.degrees > degrees; 
  }

  bool isSmaller(Angle rhs) {
    //если rhs меньше degrees возвращает true
    return rhs.degrees < degrees;
  }

  bool isEqual(Angle rhs) {
    return abs(rhs.degrees - degrees) < eps;
  }

  double div(Angle rhs) {
    //во сколько раз degrees больше чем rhs
    return degrees / rhs.degrees;
  }
};

int main() {
  double alDegrees, alMinutes, beDegrees, beMinutes;
  cin >> alDegrees >> alMinutes >> beDegrees >> beMinutes;
  Angle alpha(alDegrees, alMinutes), betta(beDegrees, beMinutes);
  cout << "Sin of alpha " << alpha.getSin() << endl;
  cout << "alpha / betta = " << alpha.div(betta) << endl;
  cout << "Is betta smaller then alpha " << alpha.isSmaller(betta) << endl;
  cout << "Alpha in radians = " << alpha.inRadians() << endl;
  cout << "Adding betta to alpha " << endl;
  alpha.add(betta);
  cout << "New alpha "<< alpha.degrees << endl;
  cout << "Subtracting betta from alpha" << endl;
  alpha.subtract(betta);
  cout << "New alpha " << alpha.degrees << endl;
  alpha.to2pi();
  cout << "Alpha in [0;360] degrees " << alpha.degrees << endl;
}