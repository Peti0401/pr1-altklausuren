#include <iostream>
#include <string>
#include <vector>
#include "passenger.h"
#include "flight.h"

using namespace std;

int main() {
try {
  cout << "Class Passenger:\n";
  try {
    Passenger p{""};
    cout << "test 1 " << p << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 1\n";
  }
  try {
    Passenger p{"",Category::Business};
    cout << "test 2 " << p << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 2\n";
  }

  const vector<Passenger> v{{"Conny"}, {"Maria", Category::First}, {"Franz", Category::Business}, {"Hubert"},
                            {"Susanne", Category::Business}, {"Karl", Category::Business}, {"Mark"},
                            {"Tony"}, {"Xaver", Category::Economy}, {"Alex"}, {"Franz", Category::First}};

  for (const auto& p : v)
     cout << p << '\n';
  for (const auto& p : v)
     cerr << p << '\n';
  cout << '\n';

  for (const auto& c : vector<Category>{Category::Economy, Category::Business, Category::First}) {
    for (const auto& p : v)
      cout << p.in_category(c);
    cout << '\n';
  }
  cout << '\n';

  for (const auto& ref : v) {
    for (const auto& p : v)
      cout << (p==ref);
    cout << '\n';
  }


  cout << "\nClass Flight:\n";
  try {
    Flight f{"", 12};
    cout << "test 3 " << f << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 3\n";
  }
  try {
    Flight f{"A4711", 0};
    cout << "test 4 " << f << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 4\n";
  }
  try {
    Flight f{"A4711", -1};
    cout << "test 5 " << f << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 5\n";
  }

  const Flight cf("B0815",120);
  cout << cf << '\n';
  cerr << cf << '\n';

  Flight f("AZU24",15);
  for (const auto& p : v)
    cout << f.check_in(p);
  cout << '\n';
  for (const auto& p : v)
    cout << f.check_in(p);
  cout << '\n' << f << '\n';
  cerr << f << '\n';

  Flight tiny("TIN5Y",4);
  for (const auto& p : v)
    cout << tiny.check_in(p);
  cout << '\n' << tiny << '\n';
  cout << '\n';

  for (auto it{v.begin()+1}; it!=v.end(); it+=2)
    cout << f.board(*it);
  cout << f.board({"Cornelia"});
  cout << '\n' << f << '\n';

  Flight work{f};
  for (auto it{v.begin()}; it!=v.end(); ++it)
    cout << work.board(*it);
  cout << '\n' << work << '\n';

// Dekommentieren fuer Zusatz ready
  cout << "\nAdditional task ready\n";
  try {
    f.ready({});
    cout << "test 6 " << f << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 6\n";
  }
  try {
    f.ready({1, 2, 3, 4});
    cout << "test 7 " << f << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 7\n";
  }
  try {
    f.ready({0, -1, 17});
    cout << "test 8 " << f << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 8\n";
  }

  cout << f.ready({10, 10, 10}) << work.ready({10, 10, 10}) << '\n';
  cout << work.ready({4, 10, 10}) << work.ready({10, 2, 10});
  cout << work.ready({10, 10, 0}) << work.ready({6, 3, 1}) << '\n';

// Dekommentieren fuer Zusatz pretty_print
  cout << "\nAdditional task pretty_print\n";
  cf.pretty_print();
  cout << '\n';
  f.pretty_print();
  cout << '\n';
  work.pretty_print();
  cout << '\n';
  tiny.pretty_print();
  cout << '\n';
}
catch (exception& e) {
  cout << "Unexpected exception: " << e.what() << '\n';
}
catch (...) {
  cout << "Non standard exception thrown!";
}
return 0;
}

/* Erwartete Ausgabe
Class Passenger:
catch 1
catch 2
[Conny: Economy]
[Maria: First]
[Franz: Business]
[Hubert: Economy]
[Susanne: Business]
[Karl: Business]
[Mark: Economy]
[Tony: Economy]
[Xaver: Economy]
[Alex: Economy]
[Franz: First]
[Conny: Economy]
[Maria: First]
[Franz: Business]
[Hubert: Economy]
[Susanne: Business]
[Karl: Business]
[Mark: Economy]
[Tony: Economy]
[Xaver: Economy]
[Alex: Economy]
[Franz: First]

10010011110
00101100000
01000000001

10000000000
01000000000
00100000001
00010000000
00001000000
00000100000
00000010000
00000001000
00000000100
00000000010
00100000001

Class Flight:
catch 3
test 4 [A4711, {}]
catch 5
[B0815, {}]
[B0815, {}]
11111111110
00000000000
[AZU24, {[Conny: Economy], [Maria: First], [Franz: Business], [Hubert: Economy], [Susanne: Business], [Karl: Business], [Mark: Economy], [Tony: Economy], [Xaver: Economy], [Alex: Economy]}]
[AZU24, {[Conny: Economy], [Maria: First], [Franz: Business], [Hubert: Economy], [Susanne: Business], [Karl: Business], [Mark: Economy], [Tony: Economy], [Xaver: Economy], [Alex: Economy]}]
11110000000
[TIN5Y, {[Conny: Economy], [Maria: First], [Franz: Business], [Hubert: Economy]}]

111110
[AZU24, {[Conny: Economy], [Maria: First]*, [Franz: Business], [Hubert: Economy]*, [Susanne: Business], [Karl: Business]*, [Mark: Economy], [Tony: Economy]*, [Xaver: Economy], [Alex: Economy]*}]
10101010100
[AZU24, {[Conny: Economy]*, [Maria: First]*, [Franz: Business]*, [Hubert: Economy]*, [Susanne: Business]*, [Karl: Business]*, [Mark: Economy]*, [Tony: Economy]*, [Xaver: Economy]*, [Alex: Economy]*}]

Additional task ready
catch 6
catch 7
catch 8
01
0001

Additional task pretty_print
B0815
AZU24, boarded: {[Maria: First], [Hubert: Economy], [Karl: Business], [Tony: Economy], [Alex: Economy]}, missing: {[Conny: Economy], [Franz: Business], [Susanne: Business], [Mark: Economy], [Xaver: Economy]}
AZU24, boarded: {[Maria: First], [Hubert: Economy], [Karl: Business], [Tony: Economy], [Alex: Economy], [Conny: Economy], [Franz: Business], [Susanne: Business], [Mark: Economy], [Xaver: Economy]}
TIN5Y, missing: {[Conny: Economy], [Maria: First], [Franz: Business], [Hubert: Economy]}
*/
