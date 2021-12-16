#pragma once
#include <iostream>

namespace p14 {

class ext {
public:
  ext() { std::cout << "    ext constructor" << std::endl; }
  ~ext() {
    std::cout << "    ext deconstructor" << std::endl;
    std::cout << std::endl;
  }
  void Size() { std::cout << "ext  size: " << sizeof(*this) << std::endl; };
};

class base {
public:
  base() {
    std::cout << "    base constructor" << std::endl;
    print_asd();
  }
  ~base() {
    std::cout << "    base deconstructor" << std::endl;
    std::cout << std::endl;
  }

  virtual void print_asd() { std::cout << "    base asd" << std::endl; };

  virtual void method1(){};
  virtual void method2(){};
  virtual void method3(){};
  virtual void method4(){};
  virtual void method5(){};
  virtual void method6(){};
  virtual void method7(){};
  virtual void method8(){};
  virtual void method9(){};

  void Size() { std::cout << "base size: " << sizeof(*this) << std::endl; };
};

class dev1 : public base {
public:
  dev1() { std::cout << "    dev1 constructor" << std::endl; }
  ~dev1() { std::cout << "    dev1 deconstructor" << std::endl; }
  virtual void print_asd() { std::cout << "    dev1 asd" << std::endl; };
  void Size() { std::cout << "dev1 size: " << sizeof(*this) << std::endl; };
};

class dev2 : public base {
public:
  dev2() { std::cout << "    dev2 constructor" << std::endl; }
  ~dev2() { std::cout << "    dev2 deconstructor" << std::endl; }
  void Size() { std::cout << "dev2 size: " << sizeof(*this) << std::endl; };
};

class dev3 : public dev1, public dev2 {
public:
  dev3() { std::cout << "    dev3 constructor" << std::endl; }
  ~dev3() { std::cout << "    dev3 deconstructor" << std::endl; }
  void Size() { std::cout << "dev3 size: " << sizeof(*this) << std::endl; };
};

} // namespace p14

void run_practica_14() {
  auto ext = p14::ext();
  std::cout << std::endl;
  auto base = p14::base();
  std::cout << std::endl;
  auto dev1 = p14::dev1();
  std::cout << std::endl;
  auto dev2 = p14::dev2();
  std::cout << std::endl;
  auto dev3 = p14::dev3();

  // ¿Cuanto espacio ocupa la tabla de funciones virtuales?
  //
  //      El tamaño de un puntero en la arquitectura del pc multiplicado por
  //      el numero de funciones virtuales a las que pueda acceder la clase.
  //
  //      He intentado buscar maneras de hacer el sizeof de la vtable
  //      pero me ha resultado imposible.
  //
  // ¿Donde esta situada la vtable?
  //
  //      Las vtables se crean en compile time asi que estaran estaticamente
  //      asignadas en algun lugar del binario.
  //
  //      Por otra parte, el puntero a la vtable estara situado al
  //      principio del bloque de memoria alocado al crear un objeto
  //      con funciones virtuales.
  //
  // ¿Cuanto espacio adicional ocupa un objeto que implemente un vtable?
  //
  //      El numero de herencias que implementen metodos virtuales multiplicado
  //      por el tamaño de un puntero en la arquitectura del pc.

  std::cout << std::endl;

  ext.Size();  // returns: 1
  base.Size(); // returns: 8
  dev1.Size(); // returns: 8
  dev2.Size(); // returns: 8
  dev3.Size(); // returns: 16

  //      ext tiene tamaño 1 porque es el tamaño mínimo al que poder apuntar
  //
  // ¿Que pasa si llamo a un metodo virtual desde el constructor?
  //
  //      Se llama a la altura de la implementacion. Si llamo a print_asd()
  //      en el constructor de base, se llamara la funcion a nivel de base.
  //
  //      Esto es porque la construcion ocurre de base hacia arriba. Al
  //      construir una derivada se construira primero base. En el momento de
  //      llamar a la funcion virtual en el constructor de base, todavia no
  //      existen los datos de la derivada, por lo que se llama a la función
  //      virtual al nivel de base.
  //
  // Comparar la llamada a una funcion virtual con la llamada a una funcion
  // no virtual ¿Cuantos pasos adicionales tienen que realizarse cuando la
  // funcion es virtual?
  //
  //      La virtual tiene que visitar el vtable de dev1 y ver donde apunta la
  //      funcion que quiero llamar, que en este caso esta implementada en dev1.
  //      Esto se traduce en los siguientes saltos en lectura de memoria:
  //
  //          llamada > clase > vtable > funcion > retorno
  //
  //      Por otra parte, una llamada no virtual haria:
  //
  //          llamada > clase > funcion > retorno
  //

  std::cout << std::endl;

  dev1.Size();      // no virtual
  dev1.print_asd(); // virtual

  //
  //      Segun los dioses de stackoverflow, mirar la vtable solo añade
  //      alrededor de 7ns en ordenadores modernos. El peligro viene de que
  //      puede romper la branch prediction y/o causar cache misses. Pero esto
  //      depende del procesador asi que a menos que estemos desarrollando para
  //      una plataforma especifica, es inutil medir su eficiencia.
  //

  std::cout << std::endl;
}
