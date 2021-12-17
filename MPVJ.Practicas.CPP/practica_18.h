#pragma once

#define MEMORY_LEAKS_MONITOR

#include "memory_leaks.h"
#include <iostream>

void run_practica_18() {
  //
  // >> NO HACE FALTA LEER NADA DE ESTO <<
  //
  // Se que se puede hacer en plan
  //
  //	#DEFINE NEW(_TYPE, _NAME, ...) \
  //		_TYPE* _NAME = new _TYPE(__VA_ARGS__)
  //
  // Pero es la primera solucion que sale en google
  // y siendo practica opcional pues quería comerme
  // la cabeza un poco aunque no este bien del todo.
  //
  // Cosas:
  //	+ No hace falta NEW_ARR o DEL_ARR
  //	+ No hace falta parametros en las macros NEW
  //	- No se puede registrar nombre de la variable
  //	- No se puede registrar el tipo de la variable
  //	- Tengo que usar DEL en vez de DELETE por redefinition
  //
  // Me parece mas intuitivo que el otro metodo ya que
  // solo hay que poner new y del en mayusculas, pero
  // pierdo la capacidad de de anunciar el nombre de la
  // variable y el tipo. ¯\_(ツ)_/¯
  //
  // Maldades:
  //	Como se basa en overridear el operador new, se
  //	puede adaptar para incluir news ocultos en plan
  //	"registrame el siguiente new que ocurra, lo haga
  //	quien lo haga, use o no use la macro" lo cual puede
  //	ser util para testear librerias externas o algo.
  //
  //	También se pueden quitar los allows de OnMemAlloc
  //	y OnMemFreed para que se registren todos los news
  //	y deletes, pero tendria que pasar todo el sistema
  //	a usar malloc porque si usase new para registrar
  //	las cosas, generaría recursion infinita.

  MemLeakMonitor::PrintUsage();

  char *a = NEW char;                  //  1 byte
  char *b = NEW char[10]{"123456789"}; // 10 byte

  MemLeakMonitor::PrintUsage();

  DEL a;
  DEL b;

  MemLeakMonitor::PrintUsage();

  size_t *c = NEW size_t(420); //  8 bytes
  size_t *d = NEW size_t[10];  // 80 bytes

  MemLeakMonitor::PrintUsage();

  // DEL c;
  // DEL_ARR d;

  // Esto es increible
  MemLeakMonitor::Flush();
}
