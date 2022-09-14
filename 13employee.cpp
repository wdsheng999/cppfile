#include<iostream>
using namespace std;
#include<string>


class Employee{
    public:
    Employee(const std::string& name, const std::string& ssn);
    const std::string& get_name() const;
    void print(std::ostream& out) const;
    void print(std::ostream& out, const std::string& msg) const;
    protected:
    std::string m_name;
    std::string m_ssn;
    };

Employee::Employee(const std::string& name, const std::string& ssn):m_name(name),m_ssn(ssn)
{
    //initializer list sets up the valuess
}

inline const std::string& Employee::get_name() const{
    return m_name;
}
inline void Employee::print(std::ostream& out) const{
    cout<<m_name<<std::endl;
    out<<m_ssn<<std::endl;
}
inline void Employee::print(std::ostream& out, const std::string& msg) const{
    cout<<msg<<std::endl;
    print(out);
}

//add a manager
class Manager:public Employee{
    public:
    Manager(const std::string& name,const std::string& ssn,const std::string& title);
    const std::string title_name() const;
    const std::string& get_title() const;
    void print(std::ostream& out) const;//和上面的一样
    private:
    std::string m_title;//和自己的一个private的参数
};

inline void Manager::print(std::ostream& out ) const{
    Employee::print(out);//call the base class print
    cout<<m_title<<endl;
}

inline const std::string& Manager::get_title() const{
    return m_title;
}

inline const std::string Manager::title_name() const{
    return std::string(m_title+":"+m_name);//access base name
}

int main(){
    Employee bob("Bob Jones","555-44-000");
    Manager bill("Bill Smith","666-55-1234","important Person");
    std::cout<<"mananger and employee"<<endl;

}