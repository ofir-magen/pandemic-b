
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Scientist.hpp"
#include "Researcher.hpp"
#include "Virologist.hpp"
#include "GeneSplicer.hpp"
#include "FieldDoctor.hpp"
#include "Medic.hpp"

using namespace pandemic;

#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	Board board;
	cout << "the board is cleanclean?: " << board.is_clean() << endl;
	cout << "-add Disease cubes to the board-" << endl;
	board[City::Paris] = 4;
	board[City::Madrid] = 2;
	board[City::Lagos] = 5;
	board[City::Algiers] = 3;
	board[City::Chicago] = 5;
	board[City::HongKong] = 4;
	board[City::Jakarta] = 4;
	board[City::Lima] = 4;
	board[City::Bogota] = 2;
	cout << "the board is clean?: " << board.is_clean() << endl;

	cout << "===============================================" << endl;
	Medic medic{board, City::Atlanta};
	cout << "the player is:   " << medic.role() << "  starting at city: Atlanta \n" << endl;

	cout << "TAKE CARD:[Paris, London, Madrid, Atlanta, Milan, NewYork, Miami, Bogota, HongKong]" << endl;
	medic.take_card(City::Paris)	//blue
		.take_card(City::London)	//blue
		.take_card(City::Madrid)	//blue
		.take_card(City::Atlanta)	//blue
		.take_card(City::Milan)		//blue
		.take_card(City::NewYork)	//blue
		.take_card(City::Miami)		// yellow
		.take_card(City::Bogota)	// yellow
		.take_card(City::HongKong); // red

	cout << "DRIVE TO: [Chicago, MexicoCity, Miami]" << endl;
	medic.drive(Chicago).drive(MexicoCity).drive(Miami);

	cout << "BUILD" << endl;
	medic.build();

	cout << "DRIVE TO: [Bogota]" << endl;
	medic.drive(Bogota);
	cout << "pandemic val at Bogota : " << board[City::Bogota] << endl;
	cout << "TREAT" << endl;
	medic.treat(City::Bogota);
	cout << "pandemic val at Bogota : " << board[City::Bogota] << endl;

	cout << "FLAY_DIRECT (HongKong)" << endl;
	medic.fly_direct(HongKong);

	cout << "pandemic val at HongKong : " << board[City::HongKong] << endl;
	cout << "TREAT" << endl;
	medic.treat(City::HongKong);
	cout << "pandemic val at HongKong : " << board[City::HongKong] << endl;

	cout << "TAKE CARD:[HongKong]" << endl;
	medic.take_card(City::HongKong);

	cout << "FLAY_CHARTER (London)" << endl;
	medic.fly_charter(London);

	cout << "BUILD" << endl;
	medic.build();

	cout << "DISCOVER_CURE" << endl;
	medic.discover_cure(Blue);

	cout << "pandemic val at Paris : " << board[City::Paris] << endl;
	cout << "DRIVE TO: [Paris]" << endl;
	cout << "---do Special action---" << endl;
	cout << "DRIVE TO: [London]" << endl;
	medic.drive(Paris).drive(London);								  //Special action
	cout << "pandemic val at Paris : " << board[City::Paris] << endl; // NEED TO BE CURED

	cout << "pandemic val at Lima : " << board[City::Lima] << endl;
	cout << "FLAY_SHUTTLE (Miami), ";
	cout << "DRIVE TO: [Bogota], ";
	cout << "DRIVE TO: [Lima]" << endl;
	medic.fly_shuttle(Miami).drive(Bogota).drive(Lima);

	cout << "pandemic val at Lima : " << board[City::Lima] << endl;
	cout << "TREAT" << endl;
	medic.treat(City::Lima);
	cout << "pandemic val at Lima : " << board[City::Lima] << endl;

	cout << "===============================================" << endl;
	OperationsExpert operationsExpert{board, City::Atlanta};
	cout << "the player is:   " << operationsExpert.role() << "  starting at city: Atlanta \n"<< endl;

	cout << "TAKE CARD:[Manila]" << endl;
	operationsExpert.take_card(City::Manila);

	cout << "FLAY_DIRECT (Manila)" << endl;
	operationsExpert.fly_direct(Manila);

	cout << "---do Special action---" << endl;
	cout << "BUILD" << endl;
	operationsExpert.build(); //Special action

	cout << "TAKE CARD:[Delhi]" << endl;
	cout << "FLAY_DIRECT (Delhi)" << endl;
	operationsExpert.take_card(City::Delhi).fly_direct(Delhi);

	cout << "---do Special action---" << endl;
	cout << "BUILD" << endl;
	operationsExpert.build(); //Special action

	cout << "===============================================" << endl;
	Dispatcher dispatcher{board, City::London};
	cout << "the player is:   " << dispatcher.role() << "  starting at city: London \n"<< endl;

	cout << "---do Special action---" << endl;
	cout << "FLAY_DIRECT (Seoul)" << endl;
	dispatcher.fly_direct(Seoul); //Special action

	cout << "===============================================" << endl;
	GeneSplicer geneSplicer{board, City::Miami};
	cout << "the player is:   " << geneSplicer.role() << "  starting at city: Miami \n"<< endl;

	cout << "TAKE CARD:[Seoul, Moscow, Tehran, Santiago, StPetersburg]" << endl;
	geneSplicer.take_card(City::Seoul)	//red
		.take_card(City::Moscow)		//black
		.take_card(City::Tehran)		//black
		.take_card(City::Santiago)		// yellow
		.take_card(City::StPetersburg); // vlue

	cout << "---do Special action---" << endl;
	cout << "DISCOVER_CURE" << endl;
	geneSplicer.discover_cure(Black); //Special action

	cout << "===============================================" << endl;
	FieldDoctor fieldDoctor{board, City::Cairo};
	cout << "the player is:   " << fieldDoctor.role() << "  starting at city: Cairo \n"<< endl;

	cout << "pandemic val at Algiers : " << board[City::Algiers] << endl;
	cout << "---do Special action---" << endl;
	cout << "TREAT" << endl;
	fieldDoctor.treat(Algiers); //Special action
	cout << "pandemic val at Algiers : " << board[City::Algiers] << endl;

	cout << "===============================================" << endl;
	Scientist scientist{board, City::Manila, 2};
	cout << "the player is:   " << scientist.role() << "  starting at city: Manila \n"<< endl;

	cout << "TAKE CARD:[Seoul, Taipei, Tehran]" << endl;
	scientist.take_card(City::Seoul) //red
		.take_card(City::Taipei)	 //red
		.take_card(City::Tehran);	 //black

	cout << "---do Special action---" << endl;
	cout << "DISCOVER_CURE" << endl;
	scientist.discover_cure(Red); //Special action

	cout << "===============================================" << endl;
	Researcher researcher{board, City::Manila};
	cout << "the player is:   " << researcher.role() << "  starting at city: Manila \n"<< endl;

	cout << "TAKE CARD:[Khartoum, Kinshasa, Johannesburg, Santiago, BuenosAires]" << endl;
	researcher.take_card(City::Khartoum) //yellow
		.take_card(City::Kinshasa)		 //yellow
		.take_card(City::Johannesburg)	 //yellow
		.take_card(City::Santiago)		 //yellow
		.take_card(City::BuenosAires);	 //yellow

	cout << "---do Special action---" << endl;
	cout << "DISCOVER_CURE" << endl;
	researcher.discover_cure(Yellow); //Special action

	cout << "===============================================" << endl;
	Virologist virologist{board, City::NewYork};
	cout << "the player is:   " << virologist.role() << "  starting at city: NewYork \n"<< endl;

	cout << "TAKE CARD:[Madrid, Lagos, Jakarta, Chicago]" << endl;
	virologist.take_card(Madrid).take_card(Lagos).take_card(Jakarta).take_card(Chicago);

	cout << "pandemic val at Madrid : " << board[City::Madrid] << endl;
	cout << "---do Special action---" << endl;
	cout << "TREAT" << endl;
	virologist.treat(Madrid); //Special action
	cout << "pandemic val at Madrid : " << board[City::Madrid] << endl;

	cout << "pandemic val at Lagos : " << board[City::Lagos] << endl;
	cout << "---do Special action---" << endl;
	cout << "TREAT" << endl;
	virologist.treat(Lagos); //Special action
	cout << "pandemic val at Lagos : " << board[City::Lagos] << endl;

	cout << "pandemic val at Jakarta : " << board[City::Jakarta] << endl;
	cout << "---do Special action---" << endl;
	cout << "TREAT" << endl;
	virologist.treat(Jakarta); //Special action
	cout << "pandemic val at Jakarta : " << board[City::Jakarta] << endl;

	cout << "pandemic val at Chicago : " << board[City::Chicago] << endl;
	cout << "---do Special action---" << endl;
	cout << "TREAT" << endl;
	virologist.treat(Chicago); //Special action
	cout << "pandemic val at Chicago : " << board[City::Chicago] << endl;

	cout << "===============================================" << endl;
	cout << board << endl;
	cout << "the board is clean?: " << board.is_clean() << endl;
}