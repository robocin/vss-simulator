/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "OriginalDebugDrawer.h"

OriginalDebugDrawer::OriginalDebugDrawer(){
	material = new Material();
}

void OriginalDebugDrawer::drawPath( const Robot3d &robot, const vss::Path &path ){
	if(path.points.size() < 2)
		return;

	glPushMatrix();
	material->applyMaterial( robot.robotColor );
	for(unsigned int j = 0; j < path.points.size() - 1; j++) {
		glBegin( GL_LINES );
		glVertex3f( 1, path.points.at( j ).x, path.points.at( j ).y );
		glVertex3f( 1, path.points.at( j + 1 ).x, path.points.at( j + 1 ).y );
		glEnd();
	}
	glPopMatrix();
}

void OriginalDebugDrawer::drawStep( const Robot3d &robot, const vss::Pose &stepPose ){
	if(Core::isOriginInGlut( stepPose ))
		return;

	glPushMatrix();
	material->applyMaterial( robot.robotColor );

	glBegin( GL_LINES );
	glVertex3f( 2, robot.pose.x, robot.pose.y );
	glVertex3f( 2, stepPose.x, stepPose.y );
	glEnd();
	glPopMatrix();
}

void OriginalDebugDrawer::drawFinal( const Robot3d &robot, const vss::Pose &finalPose ){
	if(Core::isOriginInGlut( finalPose ))
		return;

	glPushMatrix();
	//! Desenha o corpo do robô transladado
	glTranslatef( 1.5, finalPose.x, finalPose.y );
	glRotatef( -finalPose.angle, 1, 0, 0 );
	glScalef( 1.0f, 8.0, 8.0 );
	material->applyMaterial( ColorName::Gray );
	glLineWidth( 4.0f );
	glutWireCube( 1 );

	//! Desenha a etiqueta do time
	glPushMatrix();
	glTranslatef( 0.1, -0.2, -0.2 );
	glScalef( 1.0f, 3.5 / 8.0, 3.5 / 8.0 );
	material->applyMaterial( robot.teamColor );
	glutSolidCube( 1 );
	glPopMatrix();

	//! Desenha a etiqueta secundária do robô
	glPushMatrix();
	glTranslatef( 0.1, 0.2, 0.2 );
	glScalef( 1.0f, 3.5 / 8.0, 3.5 / 8.0 );
	material->applyMaterial( robot.robotColor );
	glutSolidCube( 1 );
	glPopMatrix();

	glPopMatrix();
}
