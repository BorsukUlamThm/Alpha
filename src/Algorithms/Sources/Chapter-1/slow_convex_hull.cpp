#include "Graphics/View/View.h"
#include "Algorithms/Model/Point_2.h"
#include "Algorithms/Model/Segment_2.h"
#include "Algorithms/Model/Polygon_2.h"
#include "Algorithms/Tools/Point_comparisons.h"


namespace chap1_slow_convex_hull
{
typedef alg::Point_2<int> point;
typedef alg::Segment_2<int> segment;
typedef alg::Polygon_2<int> convex_hull;
typedef std::vector<point> point_set;
typedef std::vector<segment> segment_set;

gr::Slide_show slides;
gr::Figure fig_points;
gr::Figure fig_outside_segments;


segment_set make_outside_segments(const point_set& P)
{
    unsigned n = P.size();
    segment_set E;
    for(unsigned i = 0; i < n; ++i)
    {
        for(unsigned j = 0; j < n; ++j)
        {
            if(i == j)
                continue;

            fig_outside_segments.add_vector(
                    P[i].x, P[i].y, P[j].x, P[j].y, sf::Color::Blue);
            slides.add_slide(fig_points, fig_outside_segments);

            bool is_ok = true;
            for(unsigned k = 0; k < n; ++k)
            {
                if(alg::point_strictly_left_line(P[k], P[i], P[j]))
                {
                    is_ok = false;
                    fig_points.add_point(P[k].x, P[k].y, sf::Color::Red, 7);
                    fig_outside_segments.add_vector(
                            P[i].x, P[i].y, P[j].x, P[j].y, sf::Color::Red);
                    slides.add_slide(fig_points, fig_outside_segments);
                    fig_points.pop_last_plot();
                    fig_outside_segments.pop_last_plot();
                    break;
                }
                else
                {
                    fig_points.add_point(P[k].x, P[k].y, sf::Color::Green, 7);
                    slides.add_slide(fig_points, fig_outside_segments);
                    fig_points.pop_last_plot();
                }
            }
            fig_outside_segments.pop_last_plot();
            if(is_ok)
            {
                E.emplace_back(P[i], P[j]);
                fig_outside_segments.add_vector(
                        P[i].x, P[i].y, P[j].x, P[j].y, sf::Color::Green);
            }
            slides.add_slide(fig_points, fig_outside_segments);
        }
    }

    for(unsigned i = 0; i < E.size(); ++i)
    {
        gr::Vector v (E[i].ogn.x, E[i].ogn.y, E[i].dst.x, E[i].dst.y);
        fig_outside_segments.add_text(std::to_string(i), v);
    }
    slides.add_slide(fig_points, fig_outside_segments);
    fig_outside_segments.pop_last_n_plots(E.size());

    return E;
}

convex_hull sort_outside_segment(segment_set& E)
{
    convex_hull CH;

    

    return CH;
}

void slow_convex_hull(const point_set& P)
{
    for(auto p : P)
    {
        fig_points.add_point(p.x, p.y);
    }
    slides.add_slide(fig_points);

    segment_set E = make_outside_segments(P);
    convex_hull CH = sort_outside_segment(E);
}
}

int main()
{
    using namespace chap1_slow_convex_hull;

    point_set S;
    S.push_back(point(0, 0));
    S.push_back(point(10, 0));
    S.push_back(point(0, 10));
    S.push_back(point(10, 10));
    S.push_back(point(5, 5));

    slow_convex_hull(S);
    gr::Canvas canvas;
    canvas.display_slide_show(slides);

    return 0;
}