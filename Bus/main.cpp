#include<iostream>
#include<string>
#include<vector>
#include<stdexcept>
#include"bus.h"
#include"fleet.h"

/* vordefiniert in bus.h
enum class Station{Bar,Restaurant,Church,Main,Railway,School,University,Park,Parliament,Center};
const std::vector<std::string> station_names{"Bar","Restaurant","Church","Main","Railway","School","University","Park",
	                                         "Parliament","Center"};
*/

using namespace std;

int main() {
	cout << "Basisfunktionalitaet\n\nBus\n";
	try {
		cout << Bus{"1A",{Station::Main}};
		cout << Bus{"",{Station::Main},5};
	}
	catch (runtime_error& e) {
		cout << " Error1\n";
	}
	try {
		cout << Bus{"1A",{Station::Church},1};
		cout << Bus{"2B",{Station::Church},0};
	}
	catch (runtime_error& e) {
		cout << " Error2\n";
	}
	try {
		cout << Bus{"1A",{Station::Church,Station::Main,Station::Center},20};
		cout << Bus{"2B",{Station::Main},21};
	}
	catch (runtime_error& e) {
		cout << " Error3\n";
	}
	try {
		cout << Bus{"1A",{Station::Main,Station::Park},5};
		cout << Bus{"2B",{Station::Main},-5};
	}
	catch (runtime_error& e) {
		cout << " Error4\n";
	}
	try {
		cout << Bus{"1A",{},5};
	}
	catch (runtime_error& e) {
		cout << " Error5\n";
	}
	const Bus a1{"A1",{Station::Bar,Station::Restaurant,Station::Church,Station::Main,Station::Railway,Station::School,
		               Station::Park,Station::Parliament,Station::Center}};
	const Bus a2{"A2",{Station::Bar,Station::Bar,Station::Park,Station::Bar,Station::Parliament},5};
	cout << a1 << '\n';
	cerr << a1 << '\n';
	cout << a2 << '\n';

	cout << a1.stops_at(Station::Park) << a1.stops_at(Station::Restaurant) << a2.stops_at(Station::Church) 
		 << a2.stops_at(Station::Bar) << '\n';
	cout << a1.cost(Station::Bar,Station::Parliament) << " " << a1.cost(Station::Park,Station::Bar) << '\n';
	cout << a2.cost(Station::Bar,Station::Parliament) << " " << a2.cost(Station::Park,Station::Bar) << '\n';
	cout << a2.cost(Station::Park,Station::Parliament) << " " << a2.cost(Station::Parliament,Station::Park) << '\n';
	cout << a1.cost(Station::University,Station::Park) << " " << a2.cost(Station::Bar,Station::Bar) << '\n';


	cout << "\n\nFleet\n";
	try {
		cout << Fleet{"Hans",{}};
		cout << Fleet{"",{}};
	}
	catch (runtime_error& e) {
		cout << " Error6\n";
	}
	const Fleet cf{"Hans",{a1,a2}};
	cout << cf << '\n';
	cerr << cf << '\n';
	cout << Fleet{"Bar",cf.stops_at(Station::Bar)} << '\n';
	cout << Fleet{"Church",cf.stops_at(Station::Church)} << '\n';
	cout << Fleet{"University",cf.stops_at(Station::University)} << '\n';
	Fleet f{cf};
	f.add_line(Bus{"Comfort",{Station::Bar,Station::Parliament,Station::University},20});
	cout << Fleet{"University",f.stops_at(Station::University)} << '\n';
	f.add_line(Bus{"Dummy",{Station::Main,Station::Main,Station::Main}});
	cout << f << '\n';

	//Dekommentieren fuer Zusatz has_loop

	cout << "\n\nZusatz 10 Punkte\n";
	cout << Fleet{"Loop1", cf.has_loop()} << '\n';
	cout << Fleet{"Loop2", f.has_loop()} << '\n';
	cout << Fleet{"Loop3", Fleet{"Flash",{Bus{"Comfort",{Station::Bar,Station::Parliament,Station::University},20},a1}}.has_loop()} << '\n';


	//Dekommentieren fuer Zusatz cheapest_connection

	cout << "\n\nZusatz 15 Punkte\n";
	cout << Fleet{"Cheap1", f.cheapest_connection(Station::University,Station::Bar)} << '\n';
	cout << Fleet{"Cheap2", f.cheapest_connection(Station::Bar,Station::Parliament)} << '\n';
	cout << Fleet{"Cheap3", f.cheapest_connection(Station::Parliament,Station::Bar)} << '\n';
	cout << Fleet{"Cheap4", f.cheapest_connection(Station::Park,Station::Bar)} << '\n';
	cout << Fleet{"Cheap5", f.cheapest_connection(Station::Park,Station::Parliament)} << '\n';
	Fleet insane{"Insane",{a2,Bus{"Comfort",{Station::Bar,Station::Parliament,Station::University},20},a2,a2}};
	cout << Fleet{"Cheap6", insane.cheapest_connection(Station::Bar,Station::Parliament)} << '\n';

	return 0;
}

/** Erwartete Ausgabe
Basisfunktionalitaet

Bus
[1A 7 cent/station {Main}] Error1
[1A 1 cent/station {Church}] Error2
[1A 20 cent/station {Church, Main, Center}] Error3
[1A 5 cent/station {Main, Park}] Error4
 Error5
[A1 7 cent/station {Bar, Restaurant, Church, Main, Railway, School, Park, Parliament, Center}]
[A1 7 cent/station {Bar, Restaurant, Church, Main, Railway, School, Park, Parliament, Center}]
[A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}]
1101
49 0
20 5
10 0
0 5


Fleet
[Hans {}] Error6
[Hans {[A1 7 cent/station {Bar, Restaurant, Church, Main, Railway, School, Park, Parliament, Center}], [A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}]}]
[Hans {[A1 7 cent/station {Bar, Restaurant, Church, Main, Railway, School, Park, Parliament, Center}], [A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}]}]
[Bar {[A1 7 cent/station {Bar, Restaurant, Church, Main, Railway, School, Park, Parliament, Center}], [A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}]}]
[Church {[A1 7 cent/station {Bar, Restaurant, Church, Main, Railway, School, Park, Parliament, Center}]}]
[University {}]
[University {[Comfort 20 cent/station {Bar, Parliament, University}]}]
[Hans {[A1 7 cent/station {Bar, Restaurant, Church, Main, Railway, School, Park, Parliament, Center}], [A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}], [Comfort 20 cent/station {Bar, Parliament, University}], [Dummy 7 cent/station {Main, Main, Main}]}]


Zusatz 10 Punkte
[Loop1 {[A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}]}]
[Loop2 {[A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}], [Dummy 7 cent/station {Main, Main, Main}]}]
[Loop3 {}]


Zusatz 15 Punkte
[Cheap1 {}]
[Cheap2 {[A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}], [Comfort 20 cent/station {Bar, Parliament, University}]}]
[Cheap3 {}]
[Cheap4 {[A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}]}]
[Cheap5 {[A1 7 cent/station {Bar, Restaurant, Church, Main, Railway, School, Park, Parliament, Center}]}]
[Cheap6 {[A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}], [Comfort 20 cent/station {Bar, Parliament, University}], [A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}], [A2 5 cent/station {Bar, Bar, Park, Bar, Parliament}]}]
**/