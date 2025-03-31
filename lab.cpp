#include <iostream>

class A{
public: //interfata
    A() { std::cout<<"A"; }
    ~A() { std::cout<<"~A"; }
    void setStatus(std::string newS) { m_status=newS; }
    std::string getStatus() { return m_status; }
private:
    std::string m_status;
};
class B: public A
{
    public:
    B() {std::cout<<"B";};
    ~B() {std::cout<<"~B";};
};
/*
class W{
    o clasa goala ocupa 1 byte
};
*/
class printable
{
    virtual void drawMe() = 0;
};
class shape : public printable
{

};
class square : public shape
{

};
int main()
{
    
    A* A_ptr=new A();
    A* B_ptr=new B();
    //std::cout<<sizeof(A)<<" "<<sizeof(B);

    delete A_ptr;
    delete B_ptr;
    

    return 0;
}