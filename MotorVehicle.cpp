#include <iostream>
#include <iomanip>
#include <cstring>
#include "MotorVehicle.h"

using namespace std;

namespace sdds {
	MotorVehicle::MotorVehicle(const char* plate, int year) {
		// Set to default address:
		strcpy(m_currentAddress, "Factory");
		
		// Copy string to m_licensePlate:
		strcpy(m_licensePlate, plate);
		
		// Set year of manufacture:
		m_year = year;
	}

	void MotorVehicle::moveTo(const char* address) {
		if (address != m_currentAddress) {
			cout << "|";
			// setup output width as 10, set up right allignment print license plate
			std::cout << fixed;
			std::cout << std::setprecision(10);
			std::cout << std::right;
			cout << m_licensePlate << "| ";
			// setup output width as 20, set up right alignment and print the current address
			std::cout << std::setprecision(20);
			std::cout << std::right;
			cout << m_currentAddress
				<< " --->--- ";
			// setup output width as 20, set up left alignment and print the new address
			std::cout << std::setprecision(20);
			std::cout << std::left;
			cout << m_currentAddress << "|\n";

			// replace the address
			strcpy(m_currentAddress, address);

			// Reset display properties:
			std::cout << std::setprecision(6);
			std::cout << right;
		}
	}

	ostream& MotorVehicle::write(ostream& os) const {
		os << "| ";
		// Print the year:
		os << m_year;
		os << " | ";
		// Print the license plate:
		os << m_licensePlate;
		os << " | ";
		// print the address
		os << m_currentAddress;
		return os;
	}

	istream& MotorVehicle::read(istream& in) {
		int year;			// Holds year.
		int licensePlate;	// Holds license plate.
		char address[64];

		// print the prompt
		cout << "Built year: ";
		// read the year
		in >> year;
		
		// print the prompt
		cout << std::endl << "License plate: ";
		// read the license plate
		in >> licensePlate;

		// print the prompt
		cout << std::endl << "Current location: ";
		// read the address
		in.getline(address, 64);

		return in;
	}

	ostream& operator<<(ostream& os, const MotorVehicle& theVehicle) {
		return theVehicle.write(os);
	}

	istream& operator>>(istream& in, MotorVehicle& theVehicle) {
		return theVehicle.read(in);
	}
}