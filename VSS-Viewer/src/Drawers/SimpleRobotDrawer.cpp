/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "SimpleRobotDrawer.h"
#include "iostream"

SimpleRobotDrawer::SimpleRobotDrawer(){
	material = new Material();
	qobj = gluNewQuadric();
	gluQuadricNormals( qobj, GLU_SMOOTH );
	robot = new Robot3d();

	robotWidth = 8.0;
	robotDepth = 8.0;
	robotHeight = 7.0;
}

void SimpleRobotDrawer::draw( const Robot3d &robot ){
	glPushMatrix();
	//! Desenha o corpo do robô
	glTranslatef( thickOfThings * 1.8, robot.pose.x, robot.pose.y );
	glRotatef( -robot.pose.angle, 1, 0, 0 );
	glScalef( robotHeight, robotWidth, robotDepth );

	if(robot.selected)
		material->applyMaterial( ColorName::Gray );
	else
		material->applyMaterial( ColorName::Black2 );

	glutSolidCube( 1 );

	//! Desenha a etiqueta do time. Azul ou Amarelo
	glPushMatrix();
	glTranslatef( 0.5, -0.2, -0.2 );
	glScalef( 0.1f, colorLabelSize / robotWidth, colorLabelSize / robotWidth );
	material->applyMaterial( robot.teamColor );
	glutSolidCube( 1 );
	glPopMatrix();

	//! Desenha a segunda etiqueta do robô
	glPushMatrix();
	glTranslatef( 0.5, 0.2, 0.2 );
	glScalef( 0.1f, colorLabelSize / robotWidth, colorLabelSize / robotWidth );
	material->applyMaterial( robot.robotColor );
	glutSolidCube( 1 );
	glPopMatrix();

	//! Desenha as rodas de um robô
	glPushMatrix();
	glRotatef( 90.0, 1, 0, 0 );
	glTranslatef( -0.22, 0.0, -0.58 );
	material->applyMaterial( ColorName::Gray2 );
	gluCylinder( qobj, 0.2f, 0.2f, 1.15f, 16.0, 16.0 ); // Radius 1, Radius 2, Lenght, Precision1, Precision2
	glPopMatrix();

	glPopMatrix();
}
