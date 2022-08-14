#pragma once

#include "Graphics/Model/Global_variables.h"


namespace graphics
{
	struct Geometric_object
	{
		virtual ~Geometric_object() = default;
	};

	struct Point_obj : public Geometric_object
	{
		Coordinate abscissa = 0;
		Coordinate ordinate = 0;

		Point_obj() = default;

		Point_obj(const Coordinate& x,
				  const Coordinate& y)
		{
			abscissa = x;
			ordinate = y;
		}
	};

	struct Segment_obj : public Geometric_object
	{
		Coordinate origin_x = 0;
		Coordinate origin_y = 0;
		Coordinate destination_x = 0;
		Coordinate destination_y = 0;

		Segment_obj() = default;

		Segment_obj(const Coordinate& ogn_x,
					const Coordinate& ogn_y,
					const Coordinate& dst_x,
					const Coordinate& dst_y)
		{
			origin_x = ogn_x;
			origin_y = ogn_y;
			destination_x = dst_x;
			destination_y = dst_y;
		}

		Segment_obj(const Point_obj& ogn,
					const Point_obj& dst)
		{
			origin_x = ogn.abscissa;
			origin_y = ogn.ordinate;
			destination_x = ogn.abscissa;
			destination_y = ogn.ordinate;
		}
	};

	struct Circle_obj : Geometric_object
	{
		Coordinate center_x = 0;
		Coordinate center_y = 0;
		Coordinate radius = 0;

		Circle_obj() = default;

		Circle_obj(const Coordinate& x,
				   const Coordinate& y,
				   const Coordinate& rad)
		{
			center_x = x;
			center_y = y;
			radius = rad;
		}
	};

	typedef std::vector<Point_obj> Polygon_obj;

	struct Line_obj : Geometric_object
	{
		Coordinate a = 1;
		Coordinate b = -1;
		Coordinate c = 0;

		Line_obj() = default;

		Line_obj(const Coordinate& a,
				 const Coordinate& b,
				 const Coordinate& c)
		{
			this->a = a;
			this->b = b;
			this->c = c;
		}
	};
}