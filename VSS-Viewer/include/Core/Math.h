/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef CORE_MATH_H
#define CORE_MATH_H

#include <limits>
#include "Domain/Pose.h"
#include "Robot3d.h"
#include "Helpers/Math.h"

namespace Core {
	vss::Pose inline bulletToGlut( const vss::Pose &bullet ){
		return vss::Pose( bullet.y - (130 / 2.0), bullet.x - (170 / 2.0), bullet.angle );
	}

	vss::Pose inline glutToBullet( const vss::Pose &glut ){
		return vss::Pose( glut.y + (170 / 2.0), glut.x + (130 / 2.0), glut.angle );
	}

	bool inline isOriginInGlut( const vss::Pose &glut ){
		return (glut.x == -65 && glut.y == -85) ? true : false;
	}

	vss::Pose inline originInGlut(){
		return vss::Pose( -65, -85, 0 );
	}

	vss::Pose inline windowToBullet( const vss::Pose &window, float windowWidth, float windowHeight, float fieldWidth, float fieldHeight ){
		auto different_x = (windowWidth - fieldWidth) / 2.0;
		auto fc_x = window.x - different_x;
		auto new_x = fc_x * 170.0 / fieldWidth;

		auto different_y = (windowHeight - fieldHeight) / 2.0;
		auto fc_y = window.y - different_y;
		auto new_y = fc_y * 130 / fieldHeight;

		return vss::Pose( new_x, new_y, 0.0 );
	}

	std::pair<float, int> inline robotMostCloseToClick( vss::Pose &click, std::vector<Robot3d> &robots ){
		auto minDistance = vss::Math::distance( click, robots.at( 0 ).pose );
		auto idMinDistance = 0;

		for(unsigned int i = 1; i < robots.size(); i++) {
			auto actDistance = vss::Math::distance( click, robots.at( i ).pose);
			if(actDistance < minDistance) {
				minDistance = actDistance;
				idMinDistance = i;
			}
		}

		return std::make_pair(minDistance, idMinDistance);
	}

	float inline distanceClickToBall(vss::Pose &click, vss::Pose &ball) {
		return vss::Math::distance(click, ball);
	}
}

#endif // CORE_MATH_H
