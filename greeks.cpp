#include<cmath>
#include "utils.h"

static double d1(double s,double k,double t,double r,double sigma){
    double denom=sigma*sqrt(t);
    double numer=(log(s/k)+((r+((sigma*sigma)/2))*t));
    double d1_val=numer/denom;
    return d1_val;
}

double call_delta(double s,double k,double t,double r,double sigma){
    double d1_val=d1(s,k,t,r,sigma);
    double n_d1=normal_cdf(d1_val);
    return n_d1;
}

double put_delta(double s,double k,double t,double r,double sigma){
    double d1_val=d1(s,k,t,r,sigma);
    double n_d1=normal_cdf(d1_val);
    return n_d1-1;
}
