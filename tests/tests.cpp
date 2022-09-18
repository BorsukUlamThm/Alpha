#include "graphics/view/Display_canvas.h"
#include "graphics/view/Acquisition_canvas.h"
#include "utils/Program_options.h"
#include "geometry/DCEL/DCEL.h"
#include "geometry/model/serialization.h"
#include "geometry/utils/polygon_utils.h"
#include "geometry/utils/Event_queue.h"
#include "geometry/utils/line_intersections.h"


namespace gr = graphics;
namespace geo = geometry;

int main(int argc, char** argv)
{
	geo::polygon P;
	P.emplace_back(0, 0);
	P.emplace_back(1, 0);
	P.emplace_back(1, 1);
	P.emplace_back(0, 1);

	geo::DCEL dcel(P);

	std::cout << "dcel is "
			  << (dcel.is_valid() ? "" : "NOT ")
			  << "valid" << std::endl;

	P.clear();
	P.emplace_back(0, 1);
	P.emplace_back(1, 1);
	P.emplace_back(1, 0);
	P.emplace_back(0, 0);

	geo::DCEL dcel1(P);

	std::cout << "dcel is "
			  << (dcel1.is_valid() ? "" : "NOT ")
			  << "valid";

	return 0;
}