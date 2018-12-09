/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "SimpleBallDrawer.h"

SimpleBallDrawer::SimpleBallDrawer(){
	material = new Material();
}

void SimpleBallDrawer::draw( const vss::Pose &pose ){
	glPushMatrix();
	glTranslatef( thickOfThings * 1.4, pose.x, pose.y );
	material->applyMaterial( ColorName::Orange );
	glutSolidSphere( 2.0, 8.0, 8.0 );
	glPopMatrix();
}
