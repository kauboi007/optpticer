#include<iostream>
#include<iomanip>
#include "bs_pricer.h"
#include "mc_pricer.h"
#include "greeks.h"
#include "exception.h"
using namespace std;

int main(){
    double s,k,t,r,sigma;
    cout<<"enter s:";
    cin>>s;
    cout<<"enter k:";
    cin>>k;
    cout<<"enter t:";
    cin>>t;
    cout<<"enter r:";
    cin>>r;
    cout<<"enter sigma:";
    cin>>sigma;
    try{
        double bsm_call_val=bsm_call(s,k,t,r,sigma);
        double mcs_call_val=MCS_call(s,r,sigma,t,k);
        double bsm_put_val=bsm_put(s,k,t,r,sigma);
        double mcs_put_val=MCS_put(s,r,sigma,t,k);
        double delta_call_val=call_delta(s,k,t,r,sigma);
        double delta_put_val=put_delta(s,k,t,r,sigma);
        cout<<fixed<<setprecision(4);
        cout << left << setw(20) << "BS Call"  <<bsm_call_val<<endl;
        cout << left << setw(20) << "BS Put"   <<bsm_put_val<<endl;
        cout << left << setw(20) << "MC Call"  <<mcs_call_val<<endl;
        cout << left << setw(20) << "MC Put"   <<mcs_put_val<<endl;
        cout << left << setw(20) << "Call Delta" <<delta_call_val<<endl;
        cout << left << setw(20) << "Put Delta"  <<delta_put_val<<endl;
    }
    catch(invalidparams&e){
        cout<<e.what()<<endl;
    }
    return 0;
}