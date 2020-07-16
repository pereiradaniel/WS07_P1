#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H
#include <iostream>
#include "MotorVehicle.h"

namespace sdds {
	class Truck : public MotorVehicle {
		double m_capacity;		// Load capacity in KG.
		double m_cargo;			// Cargo loaded in the truck in KG.
	
	public:
		Truck(const char* plate, int year, double capacity, const char* address);	// Custom constructor.

		bool addCargo(double cargo);	// Mutator that adds to the attribute that stores current cargo, the weight specified as a parameter.
		bool unloadCargo();				// Mutator that unloads current cargo.

		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& out) const;
	};

	std::istream& operator>>(std::istream& in, Truck& c);
	std::ostream& operator<<(std::ostream& out, const Truck& c);
}

#endif