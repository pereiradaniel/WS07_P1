#include <iostream>
#include <cstring>
#include "Truck.h"
#include "MotorVehicle.h"

using namespace std;

namespace sdds {
	Truck::Truck(const char* plate, int year, double capacity, const char* address)
		: MotorVehicle(plate, year) {
		// Set up capacity.
		m_capacity = capacity;

		// Set cargo to zero.
		m_cargo = 0;

		// Call base class moveTo method:
		MotorVehicle::moveTo(address);
	}

	bool Truck::addCargo(double cargo) {
		// IF CURRENT LOAD CHANGES, RETURN TRUE!
		bool result = false;

		// if m_cargo >= m_capactiy return false
		if (m_cargo >= m_capacity) {
			result = false;
		}
		else if (cargo > m_capacity) {
			// If new cargo is greater than capacity
			// set m_cargo to m_capacity
			m_cargo = m_capacity;
			
			// Return true.
			result = true;
		}
		else if (cargo < m_capacity) {
			// if new cargo is not greater than capacity
			// increase m_cargo by cargo
			m_cargo += cargo;
			
			// return true
			result = true;
		}

		return result;
	}

	bool Truck::unloadCargo() {
		// IF CURRENT LOAD HAS BEEN CHANGED, RETURN TRUE!
		bool unload = m_cargo > 0;
		m_cargo = 0;
		return unload;
	}

	ostream& Truck::write(ostream& os) const {
		MotorVehicle::write(os);
		os << "| ";
		// Print the current cargo:
		os << m_cargo;
		os << " | ";
		// Print the capacity:
		os << m_capacity;
		return os;
	};

	istream& Truck::read(istream& in) {
		Truck::read(in);
		int capacity;		// Holds capacity.
		int cargo;			// Holds cargo.

		// print the prompt
		cout << "Capacity: ";
		// read the year
		in >> capacity;

		// print the prompt
		cout << std::endl << "Cargo: ";
		// read the license plate
		in >> cargo;

		return in;
	};
	
	istream& operator>>(istream& in, Truck& c) {
		return c.read(in);
	}

	ostream& operator<<(ostream& out, const Truck& c) {
		return c.write(out);
	}

	
}