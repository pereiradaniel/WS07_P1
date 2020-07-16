#define _CRT_SECURE_NO_WARNINGS
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
			std::cout.width(10);
			std::cout << std::right << m_licensePlate;
			std::cout << "| |";
			// setup output width as 20, set up right alignment and print the current address
			std::cout.width(20);
			std::cout << std::right << m_currentAddress;
			std::cout << " --->--- ";
			// setup output width as 20, set up left alignment and print the new address
			std::cout.width(20);
			std::cout << std::left << address;
			std::cout << "|" <<std::endl;

			// replace the address
			strcpy(m_currentAddress, address);
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
		// print the prompt
		cout << "Built year: ";
		// read the year
		in >> m_year;
		
		// print the prompt
		cout << "License plate: ";
		// read the license plate
		in >> m_licensePlate;

		// print the prompt
		cout << "Current location: ";
		// read the address
		in >> m_currentAddress;

		return in;
	}

	ostream& operator<<(ostream& out, const MotorVehicle& theVehicle) {
		return theVehicle.write(out);
	}

	istream& operator>>(istream& in, MotorVehicle& theVehicle) {
		return theVehicle.read(in);
	}
}