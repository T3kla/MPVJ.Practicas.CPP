#pragma once
#include <iostream>

namespace p14
{

class ext
{
  public:
    void size()
    {
        std::cout << "ext size:" << std::endl;
        std::cout << "    " << sizeof(*this) << std::endl;
    };
};

class base
{
  private:
    const char *name = "base";

  public:
    virtual void me() const
    {
        std::cout << name << std::endl;
    }

    base()
    {
        this->me();
        std::cout << "    constructor" << std::endl;
    }

    virtual void size_virt()
    {
        me();
        std::cout << "    size: " << sizeof(*this) << std::endl;
    };

    void size()
    {
        me();
        std::cout << "    size: " << sizeof(*this) << std::endl;
    };
};

class dev1 : public base
{
  private:
    const char *name = "dev1";

  public:
    virtual void me() const override
    {
        std::cout << name << std::endl;
    }

    virtual void size_virt() override
    {
        me();
        std::cout << "    size: " << sizeof(*this) << std::endl;
    };

    void size()
    {
        me();
        std::cout << "    size: " << sizeof(*this) << std::endl;
    };

    virtual void method2(){};
};

class dev2 : public base
{
  private:
    const char *name = "dev2";

  public:
    virtual void me() const override
    {
        std::cout << name << std::endl;
    }

    virtual void size_virt() override
    {
        me();
        std::cout << "    size: " << sizeof(*this) << std::endl;
    };

    void size()
    {
        me();
        std::cout << "    size: " << sizeof(*this) << std::endl;
    };

    virtual void method2(){};

    virtual void method3(){};
};

} // namespace p14

void run_practica_14()
{
    auto ext = p14::ext();
    auto base = p14::base();
    auto dev1 = p14::dev1();
    auto dev2 = p14::dev2();

    // ¿Cuanto espacio ocupa la tabla de funciones virtuales?
    //
    //      En un sistema x64 ocuparía 8 bytes * el numero de
    //      funciones virtuales a las que pueda acceder la clase.
    //
    //      vtable base: 8 * 1 = 8 bytes
    //      vtable dev1: 8 * 2 = 16 bytes
    //      vtable dev2: 8 * 3 = 24 bytes
    //
    // ¿Donde esta situada la vtable?
    //
    //      Las vtables se crean en compile time así que estarán
    //      en algún lugar del binario. En runtime se cargaran en memoria.
    //      Por otra parte, el puntero a la vtable estará situado al
    //      principio del bloque de memoria alocado al crear un objeto
    //      con funciones virtuales.
    //
    // ¿Cuanto espacio adicional ocupa un objeto que implemente un vtable?
    //
    //      Estaticamente, el tamaño de la tabla. Dinamicamente, el
    //      tamaño del puntero a la tabla por cada instancia del objeto.

    ext.size();       // returns: 1
    base.size_virt(); // returns: 8
    dev1.size_virt(); // returns: 8
    dev2.size_virt(); // returns: 8

    //      ext tiene tamaño 1 porque es el tamaño mínimo al que poder apuntar
    //
    // ¿Que pasa si llamo a un metodo virtual desde el constructor?
    //
    //      A pesar de que debería estar llamando a la funcion de la derivada,
    //      llama a la funcion de la base. Esto es porque la alocacion de la clase
    //      derivada todavia no ha ocurrido y la ejecucion de su override podria
    //      intentar acceder a variables que todavia no existen.
    //
    // Comparar la llamada a una funcion virtual con la llamada a una función
    // no virtual ¿Cuantos pasos adicionales tienen que realizarse cuando la
    // funcion es virtual?
    //
    //      La virtual tiene que visitar el vtable de dev1 y ver donde apunta la
    //      funcion que quiero llamar, que en este caso esta implementada en dev1.
    //      Esto se traduce en los siguientes saltos en lectura de memoria:
    //
    //          llamada en codigo > clase > vtable > funcion > retorno a codigo
    //
    //      Por otra parte, una llamada no virtual haría:
    //
    //          llamada en codigo > clase > funcion > retorno a codigo
    //
    dev1.size_virt();
    dev1.size();
    //
    //      Según los dioses de stackoverflow, mirar la vtable solo añade alrededor
    //      de 7ns en ordenadores modernos. El peligro viene de que puede romper
    //      la branch prediction y/o causar cache misses. Pero esto depende del
    //      procesador así que a menos que estemos desarrollando para una plataforma
    //      especifica, es inutil medir su eficiencia.
    //
}
