Initializer list are used to initialize objects while constructor is being called.
Initializer list initializes only once the data-members of the object
While if we do not initialize, the object data-members with initializer list, then firstly they are initialized with default cunstructor and then parameterized cunstructor


//without initializer list
#include<bits/stdc++.h>
using namespace std;

class c1{
public:
    c1()
    {
        cout<<"Default constructor\n";//firstly this is called
    }
    c1(int x)
    {
        cout<<"Parameterized constructor";//secondly this is called
    }
};

class c2{
    c1 ob1;//this line calls default cunstructor of class c1
public:
    c2()
    {
	ob1=c1(10);//this line calls parameterized cunstructor of class c1
    }
};

int main()
{
    c2 ob2;
    return 0;
}


____________________________________________________________________________________________________________________________


//with initializer list

#include<bits/stdc++.h>
using namespace std;

class c1{
public:
    c1()
    {
        cout<<"Default constructor\n";
    }
    c1(int x)
    {
        cout<<"Parameterized constructor";//only this cunstructor is called;
    }
};

class c2{
    c1 ob1;
public:
    c2():ob1(10)//initializer list
    {
    }
};

int main()
{
    c2 ob2;
    return 0;
}
