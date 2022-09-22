#include<iostream>
using namespace std;
int main(){
    int root=4,left=2,right=3;
     int wholepath = max(max(root, root + left + right),
                        max(root + left, root + right));
                        cout<<wholepath;

}