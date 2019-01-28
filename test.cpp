/***************************************************************************
 *   Copyright (C) 2004 by Paolo Capriotti                                 *
 *   p.capriotti@sns.it                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "cpplua.h"
#include <iostream>
using namespace cpplua;
using namespace std;

int l_printcpp(LuaState*) {
  cout << "Hello World" << endl;
  cout << "ok (inside printcpp)" << endl;
  return 0;
}

class A {
private:
  string w;
public:
  A(const string& w) : w(w) {}
  int foo(LuaState*) {
    cout << "Hello " << w << "!" << endl;
    cout << "ok (inside printcpp2)" << endl;
    return 0;
  }
};

/*
*/

int main() {
  LuaState state;
  try {
    LuaFunction print = state["print"];

    A a("World (2)");
    LuaFunction printcpp2 = state.createFunction(a, &A::foo);
    printcpp2();

    cout << "ok" << endl;

    LuaFunction printcpp = state.createFunction(l_printcpp);
    printcpp();

    LuaObject n = 100;
    print(n);

    // testing global table
    state["var1"] = "var1 value";
    state["var"] = "var1 value";
    if (state["var"] != state["var1"])
      print("no");
    else
      print("ok");

    state["var2"] = 4;
    print(state["var1"]);
    print(state["var2"]);

    // testing table looping
    state.doFile("test.lua");
//    LuaTable cities = state["cities"];
//    for(LuaTable::iterator i = cities.begin(); i != cities.end(); ++i)
//      print(*i);
  }
  catch(exception& e) {
    cerr << "exception caught"<< e.what() << endl;
  }

  return 0;
}
