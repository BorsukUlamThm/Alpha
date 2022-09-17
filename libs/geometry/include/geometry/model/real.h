#pragma once

#include <boost/rational.hpp>


namespace geometry
{
	struct real
	{
		typedef long integer;
		typedef boost::rational<integer> rational;

		rational val {};

		real() = default;
		explicit real(const integer& n);
		explicit real(const rational& x);

		explicit operator float() const;
	};

	bool operator==(const real& x,
					const real& y);
	bool operator!=(const real& x,
					const real& y);
	bool operator>=(const real& x,
					const real& y);
	bool operator<=(const real& x,
					const real& y);
	bool operator>(const real& x,
				   const real& y);
	bool operator<(const real& x,
				   const real& y);

	real operator+(const real& x,
				   const real& y);
	real operator-(const real& x,
				   const real& y);
	real operator-(const real& x);
	real operator*(const real& x,
				   const real& y);
	real operator/(const real& x,
				   const real& y);
}