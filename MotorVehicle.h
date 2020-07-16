#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include <iostream>

namespace sdds
{
	class MotorVehicle {
	private:
		char	m_licensePlate[32];			// License plate number as statically allocated array of chars.
		char	m_currentAddress[64];		// Address where the vehicle is located, statically allocated array of chars.
		int		m_year;						// Year vehicle was built.

	public:
		MotorVehicle(const char* plate, int year);	// Custom constructor.
		void moveTo(const char* address);			// Moves vehicle to new address if address is different from the current address.  Prints to screen.

		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os) const;
	};

	std::istream& operator>>(std::istream& in, MotorVehicle& v);		// duplicates read()
	std::ostream& operator<<(std::ostream& out, const MotorVehicle& v);	// duplicates write()
}

#endif