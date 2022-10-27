class XYPos{};
class Shape{
public:
    Shape();
    virtual ~Shape();
    virtual void render();//如果将来的子类重新写了render, 声明后面会有联系
    void move(const XYPos&);//子类的和这个无关
    virtual void resize();
protected:
    XYPos center;
};

class Ellipse: public Shape{
public:
    Ellipse(float maj, float minr);
    virtual void render();
    //此处不定义virtual也可以, 只要继承关系有一个定义了后面都是
protected:
    float major_axis,minor_axis;
};

class Circle:public Ellipse{
public:
    Circle(float radius):Ellipse(radius,radius){}
    virtual void render();
    virtual void resize();
    virtual float radius();
protected:
    float area;
};
//接受一个shape指针,让所指对象render. 这个就是会自动调整
void render(Shape*p){
    p->render();
}//p时多态对象 p的静态类型时shape的指针,
// 动态类型时当时指的对象的类型, 如果render时virtual的,则是动态绑定
void func(){
    Ellipse ell(10,20);
    ell.render();//他自己的render
    Circle circle(40);
    circle.render();//zijide
    render(&ell);//upcast,也能实现自己的render
    render(&circle);
}