#include <iostream>
#include <cmath>

using namespace std;

void kula()
{
	double r;
	cout<<"R = "; cin>>r;
	cout<<"V = "<<4.0/3*M_PI*r*r*r<<endl;
	cout<<"P = "<<4*M_PI*r*r<<endl;
}

void cubiod()
{
	double a, b, c;
	cout<<"A = "; cin>>a;
	cout<<"B = "; cin>>b;
	cout<<"C = "; cin>>c;
	cout<<"V = "<<a*b*c<<endl;
	cout<<"P = "<<a*b*2+a*c*2+b*c*2<<endl;
}

void stozek()
{
	double r, h;
	cout<<"R = "; cin>>r;
	cout<<"H = "; cin>>h;
	cout<<"V = "<<M_PI*r*r*h/3<<endl;
	cout<<"P = "<<M_PI*r*r+M_PI*r*sqrt(r*r+h*h)<<endl;
}

int main()
{
	cout<<"a) kula\nb) prostopadłościan\nc) stożek\n";
	
	char odp;
	cin>>odp;
	
	if(odp == 'a') kula();
	else if(odp == 'b') cubiod();
	else if(odp == 'c') stozek();
}
