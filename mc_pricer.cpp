#include<cmath>
#include<random>
#include<algorithm>
#include<fstream>
using namespace std;


double MCS_call(double s,double r,double sigma,double t,double k){
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double>dist(0.0,1.0);
    int N=100000;
    ofstream file("convergence.csv");
    double payoff=0;
    for(int i=0;i<N;i++){
        double z=dist(gen);
        double mc_val=s*exp((r-(sigma*sigma)/2)*t+(sigma*sqrt(t))*z);
        payoff += max(mc_val-k,0.0);  
        if(i % 100 == 0 && i > 0){       
            double running_avg =(payoff/i)*exp(-r*t);
            file<<i<<","<<running_avg<<"\n";
        }
    }
    file.close();
    return (payoff/N)*(exp(-r*t));
}

double MCS_put(double s,double r,double sigma,double t,double k){
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double>dist(0.0,1.0);
    int N=100000;
    double payoff=0;
    for(int i=0;i<N;i++){
        double z=dist(gen);
        double mc_val=s*exp((r-(sigma*sigma)/2)*t+(sigma*sqrt(t))*z);
        payoff+=max(k-mc_val,0.0); 
    }
    return (payoff/N)*(exp(-r*t));
}