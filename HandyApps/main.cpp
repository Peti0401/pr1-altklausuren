#include <iostream>
#include <string>
#include <vector>
#include "app.h"
#include "cellular.h"

using namespace std;

int main() {
try {
  cout << "Class App:\n";
  try {
    App a{"", 27, Category::Social};
    cout << "test 1" << a << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 1\n";
  }
  try {
    App a{"Angry Birds", 0};
    cout << "test 2" << a << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 2\n";
  }
  try {
    App a{"Angry Birds", -5};
    cout << "test 3" << a << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 3\n";
  }

  const vector<App> apps{{"Angry Birds", 12}, {"WhatsApp", 244, Category::Social},
                         {"StopWatch", 2, Category::Gadget}, {"VirusTotal", 46, Category::Tool},
                         {"Telegram", 74, Category::Social}, {"Excel", 1024, Category::Tool},
                         {"Flashlight", 1, Category::Gadget}, {"Flappy Bird", 4},
                         {"Tetris", 1}, {"COD", 762}};
  for (const auto& a : apps) {
    cout << a << " " << a.get_id() << " " << a.get_memory();
    cout << " " << a.in_category(Category::Game) << a.in_category(Category::Gadget) << '\n';
  }
  for (const auto& a : apps)
    cerr << a << '\n';

  cout << "\nClass Cellular:\n";
  try {
    Cellular c{-5};
    cout << "test 4" << c << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 4\n";
  }
  try {
    Cellular c{0};
    cout << "test 5" << c << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 5\n";
  }

  const Cellular ccell{16};
  cout << ccell << '\n';
  cerr << ccell << '\n';

  Cellular cell{16};
  for (const auto& a: apps)
    cout << cell.install(a);
  cout << '\n';
  cout << cell.install(apps.at(2)) << cell.install(apps.at(9)) << '\n';
  cout << cell << '\n';
  cout << cell.install({"GigaApp", 14215, Category::Tool});
  cout << cell.install({"MegaApp", 14214, Category::Tool}) << '\n';
  cout << cell << '\n';

  cout << cell.run({"Pokemon Go",14}) << '\n';
  for (const auto& i : vector<size_t>{2, 6, 7, 9})
    cout << cell.run(apps.at(i));
  cout << '\n';
  for (const auto& i : vector<size_t>{2, 0, 7})
    cout << cell.run(apps.at(i));
  cout << '\n' << cell << '\n';

// Dekommentieren fuer Zusatz deinstall
/*
  cout << "\nAddition deinstall\n";
  Cellular work1{cell};
  for (const auto& a : work1.deinstall(Category::Gadget))
    cout << a << ' ';
  cout << '\n' << work1 << '\n';
  for (const auto& a : work1.deinstall(Category::Game))
    cout << a << ' ';
  cout << '\n' << work1 << '\n';
  for (const auto& a : work1.deinstall(Category::Tool))
    cout << a << ' ';
  cout << '\n' << work1 << '\n';
  for (const auto& a : work1.deinstall(Category::Social))
    cout << a << ' ';
  cout << '\n' << work1 << '\n';
*/

// Dekommentieren fuer Zusatz optimize
/*
  cout << "\nAddition optimize\n";
  Cellular work2{cell};
  cout << work2.optimize() << '\n';
  cout << work2 << '\n';
  cout << Cellular{64}.optimize() << '\n';
  work2 = Cellular{128};
  for (const auto& i : vector<size_t>{3, 1, 5, 4})
    work2.install(apps.at(i));
  cout << work2.optimize() << '\n';
  cout << work2 << '\n';
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

/* Erwartete Ausgabe
Class App:
catch 1
catch 2
catch 3
[Angry Birds: Game, 12 MB] Angry Birds 12 10
[WhatsApp: Social, 244 MB] WhatsApp 244 00
[StopWatch: Gadget, 2 MB] StopWatch 2 01
[VirusTotal: Tool, 46 MB] VirusTotal 46 00
[Telegram: Social, 74 MB] Telegram 74 00
[Excel: Tool, 1024 MB] Excel 1024 00
[Flashlight: Gadget, 1 MB] Flashlight 1 01
[Flappy Bird: Game, 4 MB] Flappy Bird 4 10
[Tetris: Game, 1 MB] Tetris 1 10
[COD: Game, 762 MB] COD 762 10
[Angry Birds: Game, 12 MB]
[WhatsApp: Social, 244 MB]
[StopWatch: Gadget, 2 MB]
[VirusTotal: Tool, 46 MB]
[Telegram: Social, 74 MB]
[Excel: Tool, 1024 MB]
[Flashlight: Gadget, 1 MB]
[Flappy Bird: Game, 4 MB]
[Tetris: Game, 1 MB]
[COD: Game, 762 MB]

Class Cellular:
catch 4
catch 5
[{} 0/16 GB]
[{} 0/16 GB]
1111111111
00
[{[Angry Birds: Game, 12 MB], [WhatsApp: Social, 244 MB], [StopWatch: Gadget, 2 MB], [VirusTotal: Tool, 46 MB], [Telegram: Social, 74 MB], [Excel: Tool, 1024 MB], [Flashlight: Gadget, 1 MB], [Flappy Bird: Game, 4 MB], [Tetris: Game, 1 MB], [COD: Game, 762 MB]} 2.11914/16 GB]
01
[{[Angry Birds: Game, 12 MB], [WhatsApp: Social, 244 MB], [StopWatch: Gadget, 2 MB], [VirusTotal: Tool, 46 MB], [Telegram: Social, 74 MB], [Excel: Tool, 1024 MB], [Flashlight: Gadget, 1 MB], [Flappy Bird: Game, 4 MB], [Tetris: Game, 1 MB], [COD: Game, 762 MB], [MegaApp: Tool, 14214 MB]} 16/16 GB]
0
1111
010
[{[Angry Birds: Game, 12 MB]*, [WhatsApp: Social, 244 MB], [StopWatch: Gadget, 2 MB]*, [VirusTotal: Tool, 46 MB], [Telegram: Social, 74 MB], [Excel: Tool, 1024 MB], [Flashlight: Gadget, 1 MB]*, [Flappy Bird: Game, 4 MB]*, [Tetris: Game, 1 MB], [COD: Game, 762 MB]*, [MegaApp: Tool, 14214 MB]} 16/16 GB]

Addition deinstall
[StopWatch: Gadget, 2 MB] [Flashlight: Gadget, 1 MB]
[{[Angry Birds: Game, 12 MB]*, [WhatsApp: Social, 244 MB], [StopWatch: Gadget, 2 MB]*, [VirusTotal: Tool, 46 MB], [Telegram: Social, 74 MB], [Excel: Tool, 1024 MB], [Flashlight: Gadget, 1 MB]*, [Flappy Bird: Game, 4 MB]*, [Tetris: Game, 1 MB], [COD: Game, 762 MB]*, [MegaApp: Tool, 14214 MB]} 16/16 GB]
[Angry Birds: Game, 12 MB] [Flappy Bird: Game, 4 MB] [COD: Game, 762 MB]
[{[Angry Birds: Game, 12 MB]*, [WhatsApp: Social, 244 MB], [StopWatch: Gadget, 2 MB]*, [VirusTotal: Tool, 46 MB], [Telegram: Social, 74 MB], [Excel: Tool, 1024 MB], [Flashlight: Gadget, 1 MB]*, [Flappy Bird: Game, 4 MB]*, [COD: Game, 762 MB]*, [MegaApp: Tool, 14214 MB]} 15.999/16 GB]

[{[Angry Birds: Game, 12 MB]*, [WhatsApp: Social, 244 MB], [StopWatch: Gadget, 2 MB]*, [Telegram: Social, 74 MB], [Flashlight: Gadget, 1 MB]*, [Flappy Bird: Game, 4 MB]*, [COD: Game, 762 MB]*} 1.07324/16 GB]

[{[Angry Birds: Game, 12 MB]*, [StopWatch: Gadget, 2 MB]*, [Flashlight: Gadget, 1 MB]*, [Flappy Bird: Game, 4 MB]*, [COD: Game, 762 MB]*} 0.762695/16 GB]

Addition optimize
0
[{[WhatsApp: Social, 244 MB], [Telegram: Social, 74 MB], [StopWatch: Gadget, 2 MB]*, [Flashlight: Gadget, 1 MB]*, [VirusTotal: Tool, 46 MB], [Excel: Tool, 1024 MB], [MegaApp: Tool, 14214 MB], [Angry Birds: Game, 12 MB]*, [Flappy Bird: Game, 4 MB]*, [Tetris: Game, 1 MB], [COD: Game, 762 MB]*} 16/16 GB]
4
2
[{[WhatsApp: Social, 244 MB], [Telegram: Social, 74 MB], [VirusTotal: Tool, 46 MB], [Excel: Tool, 1024 MB]} 1.35547/128 GB]
*/