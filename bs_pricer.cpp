#include<cmath>
#include "utils.h"
#include "exception.h"


static void validate(double s,double k,double t,double sigma){
    if(s<=0) throw invalidparams("S");
    if(k<=0) throw invalidparams("K");
    if(t<=0) throw invalidparams("T");
    if(sigma<=0) throw invalidparams("Sigma");
}

static double d1(double s,double k,double t,double r,double sigma){
    double denom=sigma*sqrt(t);
    double numer=(log(s/k)+((r+((sigma*sigma)/2))*t));
    double d1_val=numer/denom;
    return d1_val;
}

static double d2(double d1_val,double sigma,double t){
    double d2_val=d1_val-(sigma*sqrt(t));
    return d2_val;
}

double bsm_call(double s,double k,double t,double r,double sigma){
    validate(s,k,t,sigma);
    double d1_val=d1(s,k,t,r,sigma);
    double d2_val=d2(d1_val,sigma,t);
    double n_d1=normal_cdf(d1_val);
    double n_d2=normal_cdf(d2_val);
    double bsm_call_val=(s*n_d1)-(k*exp(-r*t)*n_d2);
    return bsm_call_val;
}

double bsm_put(double s,double k,double t,double r,double sigma){
    validate(s,k,t,sigma);
    double d1_val=d1(s,k,t,r,sigma);
    double d2_val=d2(d1_val,sigma,t);
    double n_d1=normal_cdf(d1_val);
    double n_d2=normal_cdf(d2_val);
    double discount=exp(-r*t);
    double bsm_call_val=(s*n_d1)-(k*discount*n_d2);
    double bsm_put_val=bsm_call_val-s+(k*discount);
    return bsm_put_val;
}