#include<exception>
#include<string>
using namespace std;

class invalidparams:public exception{
    public:
        string message;
        invalidparams(const string &param){
            message="invalid input :"+param+" should be positive";
        }
        const char* what() const noexcept override{
            return message.c_str();
        }

};