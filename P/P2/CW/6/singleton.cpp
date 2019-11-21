 #include <iostream>
 
class singleton{
private:
    singleton() {}
    singleton(const singleton &);
    singleton& operator=(const singleton&);
    ~singleton() {}
public:
    std::string method(){ 
		return "To jest singleton"; 
	}
    
	static singleton& getInstance(){
	    static singleton instance;
	    return instance;
    }
};
 
 
int main(){
	std::cout << &(singleton::getInstance()) << std::endl;
	std::cout << &(singleton::getInstance()) << std::endl;
	std::cout << singleton::getInstance().method() << std::endl;	

	return 0;
}
