#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

template <typename T>
T f(T x){
   T ans = 3*pow(x,2) - 4*x + 5;
   return ans;
}


template <typename T>
vector<T> f(vector<T> x){
    vector<T> ans;
    for (T value: x){
        int i = 3 * pow(value, 2) - 4 * value + 5;
        ans.push_back(i);
    }

    return ans;
}


int main(){
    // double h = 0.00001;
    // double x = 0.666666666666;

    // cout<<(f(x + h) - f(x))/h<<endl;

    float a; float b; float c; float d1; float d2; float h;
    
    h = 0.00001;
    
    a = 2.0;
    b = -3.0;
    c =  10.0; 
    
    d1 = a * b + c;
    c += h;
    d2 = a * b + c;

    cout<<"D1: "<<d1<<endl;
    cout<<"D2: "<<d2<<endl;
    cout<<"Slope: "<<(d2-d1)/h<<endl;
   
//    ofstream dataFile("data.dat");
    
//     vector<int> val = {-9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

//     for (int x: val){
//         int y = f(x);
//         dataFile<<x<<" "<<y<<endl;
//         }
//     dataFile.close();
//     system("gnuplot -persist -e \"plot 'data.dat' with lines\"");
    return 0;
}