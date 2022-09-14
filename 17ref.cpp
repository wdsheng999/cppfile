int*f (int*x){
    (*x)++;
    return x;//safe, x is outside the scope
}

int& g(int& x){
    x++;//same effect as f()
    return x;//safe, x is outside 
}

int x;

int& h(){
    int q;
    //return q;// ERROR
    return x;
}

int main(){
    int a=0;
    f(&a);//ugly but explict
    g(a);//clean but hidden \
    但是此时的形式和直接操作a的函数一样,\
    如果按常规写一个g()操作a, 不会实现多态,\
     虽然用的参数一个时本身,一个时ref
    h()=16;//直接通过ref修改x, 通过x的ref修改x
}