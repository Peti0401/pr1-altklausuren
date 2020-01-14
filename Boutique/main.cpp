#include <iostream>
#include <string>
#include <vector>
#include "garment.h"
#include "boutique.h"

using namespace std;

int main() {
try {
  cout << "Class Garment:\n";
  try {
    Garment g("", 3);
    cout << "test 1 " << g << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 1\n";
  }
  try {
    Garment g("Shoe", 0);
    cout << "test 2 " << g << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 2\n";
  }
  try {
    Garment g("Shoe", -1, Designer::Prada);
    cout << "test 3 " << g << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 3\n";
  }

  const vector<Garment> cv{{"Exquisite Shoe", 6, Designer::Dior}, {"Green Skirt", 1, Designer::Prada},
                          {"T-Shirt", 10}, {"Black Skirt", 12, Designer::Chanel}, 
                          {"Leather Jacket", 2, Designer::Prada}, {"Velvet Scarf", 0, Designer::Chanel},
                          {"White Socks", 7, Designer::Unknown}, {"Blue Gloves",14}};
  for (const auto& g : cv)
    cout << g << " " << g.available() << " " <<g.by_designer({}) << g.by_designer({Designer::Dior, Designer::Prada}) << '\n';
  for (const auto& g : cv)
    cerr << g << '\n';
  
  vector<Garment> v{cv};
  cout << v.at(0).reserve("Herbert");
  cout << v.at(0).reserve("Susanne");
  cout << v.at(1).reserve("Maria");
  cout << v.at(0).reserve("Susanne");
  cout << v.at(4).reserve("Herbert");
  cout << v.at(4).reserve("Susanne");
  cout << v.at(4).reserve("Maria");
  cout << v.at(5).reserve("Hugo") << '\n';
  try {
    cout << v.at(2).reserve("") << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 3a\n";
  }
  for (const auto& g : v)
    cout << g << " " << g.available() << " " << g.by_designer({Designer::Unknown, Designer::Chanel, Designer::Unknown}) << '\n';

  cout << "\nClass Boutique:\n";
  try {
    Boutique b({});
    cout << "test 4 " << b << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 4\n";
  }
  const Boutique cb{v};
  cout << cb << '\n';
  cerr << cb << '\n';
  cout << '\n';

  cout << Boutique{cb.selection({Designer::Dior, Designer::Dior, Designer::Chanel, Designer::Chanel})} << '\n';
  cout << Boutique{cb.selection({Designer::Unknown, Designer::Prada})} << '\n';
  
// Dekommentieren fuer Zusatz buy
/*
  cout << "\nAdditional task buy\n";
  Garment g1{v.at(4)};
  cout << g1.buy("Susanne") << g1.buy("Susanne") << '\n';
  cout << g1 << '\n';
  g1 = v.at(5);
  cout << g1.buy("Maria") << '\n';
  cout << g1 << '\n';
  g1 = v.at(2);
  cout << g1.buy("Maria") << '\n';
  cout << g1 << '\n';
*/

// Dekommentieren fuer Zusatz sale
/*
  cout << "\nAdditional task sale\n";
  Boutique b1{cb};
  try {
    cout << Boutique{b1.sale(Designer::Unknown)} << '\n';
    cout << b1 << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 5\n";
  }
  try {
    cout << Boutique{b1.sale(Designer::Prada)} << '\n';
    cout << b1 << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 6\n";
  }
  try {
    cout << Boutique{b1.sale(Designer::Chanel)} << '\n';
    cout << b1 << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 7\n";
  }
  try {
    cout << Boutique{b1.sale(Designer::Dior)} << '\n';
    cout << b1 << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 8\n";
  }
*/

}
catch (exception& e) {
  cout << "Unexpected exception: " << e.what() << '\n';
}
catch (...) {
  cout << "Non standard exception thrown!";
}
return 0;
}

/* Erwarteter Output
Class Garment:
catch 1
test 2 [Shoe: Unknown, 0, {}]
catch 3
[Exquisite Shoe: Dior, 6, {}] 6 01
[Green Skirt: Prada, 1, {}] 1 01
[T-Shirt: Unknown, 10, {}] 10 00
[Black Skirt: Chanel, 12, {}] 12 00
[Leather Jacket: Prada, 2, {}] 2 01
[Velvet Scarf: Chanel, 0, {}] 0 00
[White Socks: Unknown, 7, {}] 7 00
[Blue Gloves: Unknown, 14, {}] 14 00
[Exquisite Shoe: Dior, 6, {}]
[Green Skirt: Prada, 1, {}]
[T-Shirt: Unknown, 10, {}]
[Black Skirt: Chanel, 12, {}]
[Leather Jacket: Prada, 2, {}]
[Velvet Scarf: Chanel, 0, {}]
[White Socks: Unknown, 7, {}]
[Blue Gloves: Unknown, 14, {}]
11101100
catch 3a
[Exquisite Shoe: Dior, 4, {Herbert, Susanne}] 4 0
[Green Skirt: Prada, 0, {Maria}] 0 0
[T-Shirt: Unknown, 10, {}] 10 1
[Black Skirt: Chanel, 12, {}] 12 1
[Leather Jacket: Prada, 0, {Herbert, Susanne}] 0 0
[Velvet Scarf: Chanel, 0, {}] 0 1
[White Socks: Unknown, 7, {}] 7 1
[Blue Gloves: Unknown, 14, {}] 14 1

Class Boutique:
catch 4
[{[Exquisite Shoe: Dior, 4, {Herbert, Susanne}], *[Green Skirt: Prada, 0, {Maria}]*, [T-Shirt: Unknown, 10, {}], [Black Skirt: Chanel, 12, {}], *[Leather Jacket: Prada, 0, {Herbert, Susanne}]*, *[Velvet Scarf: Chanel, 0, {}]*, [White Socks: Unknown, 7, {}], [Blue Gloves: Unknown, 14, {}]}]
[{[Exquisite Shoe: Dior, 4, {Herbert, Susanne}], *[Green Skirt: Prada, 0, {Maria}]*, [T-Shirt: Unknown, 10, {}], [Black Skirt: Chanel, 12, {}], *[Leather Jacket: Prada, 0, {Herbert, Susanne}]*, *[Velvet Scarf: Chanel, 0, {}]*, [White Socks: Unknown, 7, {}], [Blue Gloves: Unknown, 14, {}]}]

[{[Exquisite Shoe: Dior, 4, {Herbert, Susanne}], [Black Skirt: Chanel, 12, {}]}]
[{[T-Shirt: Unknown, 10, {}], [White Socks: Unknown, 7, {}], [Blue Gloves: Unknown, 14, {}]}]

Additional task buy
10
[Leather Jacket: Prada, 0, {Herbert}]
0
[Velvet Scarf: Chanel, 0, {}]
1
[T-Shirt: Unknown, 9, {}]

Additional task sale
catch 5
[{*[Green Skirt: Prada, 0, {Maria}]*, *[Leather Jacket: Prada, 0, {Herbert, Susanne}]*}]
[{[Exquisite Shoe: Dior, 4, {Herbert, Susanne}], *[Green Skirt: Prada, 0, {Maria}]*, [Black Skirt: Chanel, 12, {}], *[Leather Jacket: Prada, 0, {Herbert, Susanne}]*, *[Velvet Scarf: Chanel, 0, {}]*}]
catch 7
[{[Exquisite Shoe: Dior, 4, {Herbert, Susanne}]}]
[{[Exquisite Shoe: Dior, 4, {Herbert, Susanne}], *[Green Skirt: Prada, 0, {Maria}]*, *[Leather Jacket: Prada, 0, {Herbert, Susanne}]*}]
*/