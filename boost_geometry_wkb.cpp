#include <boost/geometry/core/cs.hpp>
#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/geometries.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/io/wkt/wkt.hpp>
#include <boost/geometry/extensions/gis/io/wkb/read_wkb.hpp>
#include <boost/geometry/extensions/gis/io/wkb/utility.hpp>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "geometry_utility.hpp"
using namespace std;
using namespace workshop;
namespace bg = boost::geometry;

int main()
{
    try
    {
            bg::model::point<float, 2,  bg::cs::geographic<bg::degree>> p0;
            bg::model::d2::point_xy<double> p1;
            bg::model::d2::point_xy<int> p2;
            auto wkb = make_wkb("0101000000000000000000f03f0000000000000040");
            if (!bg::read_wkb(wkb.cbegin(), wkb.cend(), p0))
                throw std::runtime_error("read_wkb failed");

            clog << bg::wkt(p0) << std::endl;
    }
    catch (std::exception const& e)
    {
        cerr << e.what() << endl;
    }
    return 0;
}