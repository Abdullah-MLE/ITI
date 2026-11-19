#include <iostream>
using namespace std;

// Duplication  DRY
class Animal {
 protected:
  int noOfleg;
  char* name;
  int color;

 public:
  Animal(char* name) {
    cout << "parameter Animal Constructor" << endl;
    this->name = name;
  }
  virtual void sound() { cout << "Sound Animal" << endl; }
};
class CAT : public Animal {
  char* nickName;

 public:
  CAT(char* nickName, char* name) : Animal(name), nickName(nickName) {
    cout << "CAT Parameter Constructor" << endl;
    // Animal::Animal(name); //ERROR
    // this->nickName=nickName;
  }
  // Overwriting
  /* void sound(){
      cout<<"Naow"<<endl;
  }*/
  void sound() override { cout << "Naow int" << endl; }

  /*
  - Same Signuature (Name , Parameter , No of Parameter , OrderParamter)
  - Different Class (Inherinatance)
  - Overriding (Polymoriphsm)
      - Static Binding (Compile) [Overwriting]
      - Dynamic Binding (RunTime)



  */
};

/*class Complex{
    int real;
    int img;
    Complex(int r, int i):real(r),img(i);/*{
        this->real=real;
        this->img=img;
    }
};*/

class Dog : public Animal {
  char* nickName;

 public:
  Dog(char* nickName, char* name) : Animal(name), nickName(nickName) {
    cout << "Dog Parameter Constructor" << endl;
    // Animal::Animal(name); //ERROR
    // this->nickName=nickName;
  }
  // Overwriting
  /* void sound(){
      cout<<"Naow"<<endl;
  }*/
  void sound() override { cout << "Haow" << endl; }

  /*
  - Same Signuature (Name , Parameter , No of Parameter , OrderParamter)
  - Different Class (Inherinatance)
  - Overriding (Polymoriphsm)
      - Static Binding (Compile) [Overwriting]
      - Dynamic Binding (RunTime)



  */
};

/*class Complex{
    int real;
    int img;
    Complex(int r, int i):real(r),img(i);/*{
        this->real=real;
        this->img=img;
    }
};*/
void DisplaySound(Animal* ptr) { ptr->sound(); }

int main() {
  CAT c("Nono", "cat");
  Dog d("Lucky", "Dog");
  // c.sound(10);
  c.sound();  // naow
  d.sound();  // Haow

  /*Animal *ptr;
  ptr=new Dog("Lucy","Dog");//Sound Animal
  ptr->sound();*/
  cout << "==================================" << endl;
  DisplaySound(new Dog("Lucy", "Dog"));
  DisplaySound(new CAT("Lucy", "Dog"));
  cout << "==================================" << endl;
  Animal* ptr[4] = {new Dog("Geman", "test"), new CAT("Balady", "test2"),
                    new Animal("test"), NULL};
  cout << "==================================" << endl;

  for (int i = 0; i < 4; i++) {
    if (ptr[i] != NULL) {
      ptr[i]->sound();
    }
  }
  cout << "==================================" << endl;

  cout << "Hello world!" << endl;
  return 0;
}