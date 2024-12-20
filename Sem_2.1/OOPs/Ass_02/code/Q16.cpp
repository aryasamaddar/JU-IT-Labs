#include<bits/stdc++.h>
using namespace std;

class point{
    int x,y,z;
    public:
    point(int a=0,int b=0,int c=0) : x(a),y(b),z(c) {} // constructor
    double distance (point p1,point p2){
        return sqrt((double)pow(p2.x-p1.x,2)+pow(p2.y-p1.y
        ,2)+pow(p2.z-p1.z,2));
    }
};
int main(){
    point p1(1,2,3),p2(4,5,6);
    cout<<p1.distance(p1,p2)<<endl;
}