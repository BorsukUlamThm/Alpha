#ifndef ALPHA_PLOT_H
#define ALPHA_PLOT_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Graphics/Model/Global_variables.h"

#include "Point.h"
#include "Segment.h"
#include "Vector.h"
#include "Polygon.h"
#include "Circle.h"
#include "Line.h"
#include "Text.h"


namespace gr
{

enum Plot_type {POINT, SEGMENT, VECTOR, POLYGON, CIRCLE, LINE, TEXT};

union Plot_value
{
    Point point;
    Segment segment;
    Vector vector;
    Polygon polygon;
    Circle circle;
    Line line;
    Text text;

    Plot_value(){};
    ~Plot_value(){};
};

class Plot
{
private:
    Plot_type plot_type;
    Plot_value plot_value;

public:
    Plot() = default;
    explicit Plot(const Point& point);
    explicit Plot(const Segment& segment);
    explicit Plot(const Vector& vector);
    explicit Plot(const Polygon& polygon);
    explicit Plot(const Circle& circle);
    explicit Plot(const Line& line);
    explicit Plot(const Text& text);
    Plot(const Plot& other);

    Plot_type type() const;
    Point point() const;
    Segment segment() const;
    Vector vector() const;
    Polygon polygon() const;
    Circle circle() const;
    Line line() const;
    Text text() const;

    Coordinate get_min_abscissa() const;
    Coordinate get_max_abscissa() const;
    Coordinate get_min_ordinate() const;
    Coordinate get_max_ordinate() const;
};

Plot::Plot(const Point& point)
{
    plot_type = POINT;
    plot_value.point = Point(point);
}

Plot::Plot(const Segment& segment)
{
    plot_type = SEGMENT;
    plot_value.segment = Segment(segment);
}

Plot::Plot(const Vector& vector)
{
    plot_type = VECTOR;
    plot_value.vector = Vector(vector);
}

Plot::Plot(const Polygon& polygon)
{
    plot_type = POLYGON;
    plot_value.polygon = Polygon(polygon);
}

Plot::Plot(const Circle& circle)
{
    plot_type = CIRCLE;
    plot_value.circle = Circle(circle);
}

Plot::Plot(const Line& line)
{
    plot_type = LINE;
    plot_value.line = Line(line);
}

Plot::Plot(const Text& text)
{
    plot_type = TEXT;
    plot_value.text = Text(text);
}

Plot::Plot(const Plot& other)
{
    plot_type = other.plot_type;
    switch(plot_type)
    {
        case POINT:
            plot_value.point = other.plot_value.point;
            break;
        case SEGMENT:
            plot_value.segment = other.plot_value.segment;
            break;
        case VECTOR:
            plot_value.vector = other.plot_value.vector;
            break;
        case POLYGON:
            plot_value.polygon = other.plot_value.polygon;
            break;
        case CIRCLE:
            plot_value.circle = other.plot_value.circle;
            break;
        case LINE:
            plot_value.line = other.plot_value.line;
            break;
        case TEXT:
            plot_value.text = other.plot_value.text;
            break;
    }
}

Plot_type Plot::type() const
{
    return plot_type;
}

Point Plot::point() const
{
    return plot_value.point;
}

Segment Plot::segment() const
{
    return plot_value.segment;
}

Vector Plot::vector() const
{
    return plot_value.vector;
}

Polygon Plot::polygon() const
{
    return plot_value.polygon;
}

Circle Plot::circle() const
{
    return plot_value.circle;
}

Line Plot::line() const
{
    return plot_value.line;
}

Text Plot::text() const
{
    return plot_value.text;
}

Coordinate Plot::get_min_abscissa() const
{
    switch(plot_type)
    {
        case POINT:
            return plot_value.point.get_min_abscissa();
        case SEGMENT:
            return plot_value.segment.get_min_abscissa();
            case VECTOR:
                return plot_value.vector.get_min_abscissa();
        case POLYGON:
            return plot_value.polygon.get_min_abscissa();
        case CIRCLE:
            return plot_value.circle.get_min_abscissa();
        case LINE:
            return plot_value.line.get_min_abscissa();
        case TEXT:
            return plot_value.text.get_min_abscissa();
    }
    return 0;
}

Coordinate Plot::get_max_abscissa() const
{
    switch(plot_type)
    {
        case POINT:
            return plot_value.point.get_max_abscissa();
        case SEGMENT:
            return plot_value.segment.get_max_abscissa();
            case VECTOR:
                return plot_value.vector.get_max_abscissa();
        case POLYGON:
            return plot_value.polygon.get_max_abscissa();
        case CIRCLE:
            return plot_value.circle.get_max_abscissa();
        case LINE:
            return plot_value.line.get_max_abscissa();
        case TEXT:
            return plot_value.text.get_max_abscissa();
    }
    return 0;
}

Coordinate Plot::get_min_ordinate() const
{
    switch(plot_type)
    {
        case POINT:
            return plot_value.point.get_min_ordinate();
        case SEGMENT:
            return plot_value.segment.get_min_ordinate();
            case VECTOR:
                return plot_value.vector.get_min_ordinate();
        case POLYGON:
            return plot_value.polygon.get_min_ordinate();
        case CIRCLE:
            return plot_value.circle.get_min_ordinate();
        case LINE:
            return plot_value.line.get_min_ordinate();
        case TEXT:
            return plot_value.text.get_min_ordinate();
    }
    return 0;
}

Coordinate Plot::get_max_ordinate() const
{
    switch(plot_type)
    {
        case POINT:
            return plot_value.point.get_max_ordinate();
        case SEGMENT:
            return plot_value.segment.get_max_ordinate();
        case VECTOR:
            return plot_value.vector.get_max_ordinate();
        case POLYGON:
            return plot_value.polygon.get_max_ordinate();
        case CIRCLE:
            return plot_value.circle.get_max_ordinate();
        case LINE:
            return plot_value.line.get_max_ordinate();
        case TEXT:
            return plot_value.text.get_max_ordinate();
    }
    return 0;
}

}


#endif //ALPHA_PLOT_H
