#include<cmath>

double normal_cdf(double x){
    double p=0.5*erfc(-x/sqrt(2));
    return p;
}