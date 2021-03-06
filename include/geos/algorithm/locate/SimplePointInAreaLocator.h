/**********************************************************************
 *
 * GEOS - Geometry Engine Open Source
 * http://geos.osgeo.org
 *
 * Copyright (C) 2005-2006 Refractions Research Inc.
 * Copyright (C) 2001-2002 Vivid Solutions Inc.
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU Lesser General Public Licence as published
 * by the Free Software Foundation.
 * See the COPYING file for more information.
 *
 **********************************************************************/

#ifndef GEOS_ALGORITHM_LOCATE_SIMPLEPOINTINAREALOCATOR_H
#define GEOS_ALGORITHM_LOCATE_SIMPLEPOINTINAREALOCATOR_H

#include <geos/algorithm/locate/PointOnGeometryLocator.h> // inherited

// Forward declarations
namespace geos {
namespace geom {
class Geometry;
class Coordinate;
class Polygon;
}
}

namespace geos {
namespace algorithm { // geos::algorithm
namespace locate { // geos::algorithm::locate

/** \brief
 * Computes the location of points
 * relative to an areal {@link Geometry},
 * using a simple O(n) algorithm.
 *
 * This algorithm is suitable for use in cases where
 * only one or a few points will be tested against a given area.
 *
 * The algorithm used is only guaranteed to return correct results
 * for points which are <b>not</b> on the boundary of the Geometry.
 *
 * @version 1.7
 */
class SimplePointInAreaLocator : public PointOnGeometryLocator {

public:

    static int locate(const geom::Coordinate& p,
                      const geom::Geometry* geom);

    /**
    * Determines the {@link Location} of a point in a {@link Polygon}.
    * Computes {@link Location::BOUNDARY} if the point lies exactly
    * on the polygon boundary.
    *
    * @param p the point to test
    * @param poly the geometry to test
    * @return the Location of the point in the polygon
    */
    static int locatePointInPolygon(const geom::Coordinate& p,
                                    const geom::Polygon* poly);

    SimplePointInAreaLocator(const geom::Geometry* p_g)
        :	g(p_g)
    { }

    int
    locate(const geom::Coordinate* p) override
    {
        return locate(*p, g);
    }

private:

    static int locateInGeometry(const geom::Coordinate& p,
                                const geom::Geometry* geom);

    const geom::Geometry* g;

};

} // geos::algorithm::locate
} // geos::algorithm
} // geos


#endif // GEOS_ALGORITHM_LOCATE_SIMPLEPOINTINAREALOCATOR_H
