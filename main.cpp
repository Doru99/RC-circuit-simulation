#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>

using namespace std;

int main()
{
    vector<float> Vo;
    vector<float>::iterator it;
    int delay=1, cycles=3, T=4;
    float tau;
    float val=0, E=5, V0=0, R, C;
    ofstream f;
    
    cout<<"Introduceti R(ohmi): ";
    cin>>R;
    cout<<"Introduceti C(F): ";
    cin>>C;
    tau=R*C*1000;

    for (float i=0; i<delay; i+=0.01) {
            Vo.push_back(0);
    }
    for (int j=0; j<cycles*2; j++) {
        for (float i=0; i<T; i+=0.01) {
            if (j%2==0) {
                E=5;
                val=V0*exp(-i/tau)+E*(1-exp(-i/tau));
                Vo.push_back(val);
            }
            else {
                V0=0;
                val=V0*(1-exp(-i/tau))+E*exp(-i/tau);
                Vo.push_back(val);
            }
        }
        if (j%2==0) E=*(Vo.end()-1);
        else V0=*(Vo.end()-1);
    }

    for (float i=0; i<delay; i+=0.01) {
            Vo.push_back(*(Vo.end()-1));
    }

    f.open("Output1.dat");
    float i=0;
    for (it=Vo.begin();it!=Vo.end();it++) {
        f<<i<<"\t"<<*it<<endl;
        i+=0.01;
    }
    f.close();
    return 0;
}
