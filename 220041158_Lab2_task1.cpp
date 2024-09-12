#include <iostream>

//using namespace std;
inline int call( int& para1, char& para2){
para1++;
std::cout<<para1;

}

int main()
{
//    int a,b,c,d;
//    char character;
//
//    std::cout<< "Enter the first fraction: ";
//    std::cin>>a>>character>>b;
//    std::cout<< "Enter the second fraction: ";
//    std::cin>>c>>character>>d;
//    std::cout <<"Sum = " << (a*d + b*c)<<"/"<<b*d;

int a= 2;
char b = 'm';
call(a  ,b);
std::cout <<a;
    return 0;
}
