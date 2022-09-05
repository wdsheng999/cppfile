struct X;
//上面的声明只是为了Y的编译可以通过
struct Y{
    void f(X*);//此处也不能使用 X sample ,因为上面的X没给定义
};

struct X
{
    /* data */
    private:
    int i;
    public:
    void initialize();
    friend void g(X*,int);//global friend
    friend void Y::f(X*);//struct member friend
    friend struct Z;
    friend void h();
};

void X::initialize(){
    i=0;
}

void g(X* x, int i){
    x->i=i;
}

void Y::f(X* x){
    x->i=47;
}

struct Z
{
    /* data */
    private: int j;
    public: void f();
};

