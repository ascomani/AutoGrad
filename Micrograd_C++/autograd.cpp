#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>
using namespace std;

class Value{
    public:

        Value(float data, string label ="", const vector<shared_ptr<Value>>& prev = {}, const string& op = "") 
        : data(data), prev(prev), op(op), grad(0.0), label(label) {}

        float get_data() const{
            return data;
        }

        Value operator+(const Value& other) const{
            return Value(data + other.data, "", prev, "+");
        }

        Value operator*(const Value& other) const{
            return Value(data * other.data, "",  prev, "*");
        }

        friend ostream& operator<<(ostream& os, const Value& value){
            os<<value.data <<" {Parents: ";
            for(const auto & parent: value.prev){
                os<<parent->label<<" "<<parent->op<<" ";
            }
            os<<"}";
            return os;
        }

     private:
        float data;
        vector<shared_ptr<Value>> prev;
        string op;
        float grad;
        string label;
};      

int main(){
    Value a(2.0, "a");
    Value b(-3.0, "b");
    Value c = a + b;

    cout<<c<<endl;
    return 0;
}