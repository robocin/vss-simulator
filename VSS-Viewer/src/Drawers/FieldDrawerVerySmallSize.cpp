/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "FieldDrawerVerySmallSize.h"

FieldDrawerVerySmallSize::FieldDrawerVerySmallSize(){
	material = new Material();
}

void FieldDrawerVerySmallSize::draw(){
	// Center Block Floor Field 150x130
	glPushMatrix();
	glScalef( 1, fieldDepth, fieldWidth );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	// Left Block Goal Floor Field
	glPushMatrix();
	glTranslatef( 0, 0, -fieldWidth / 1.88 );
	glScalef( 1, goalWidth + 2.0, goalDepth + 2.0 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	// Left Goal White Paint Center
	glPushMatrix();
	glTranslatef( thickOfThings, 0.0, (-fieldWidth / 1.88) - (thickOfThings) * 1.9 );
	glScalef( wallHeight, goalWidth + 2.0, 0.1 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	// Left Wall White Paint Bottom
	glPushMatrix();
	glTranslatef( thickOfThings, 38, (-fieldWidth / 2.0) + 0.1 );
	glScalef( wallHeight, 34, 0.1 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	// Left Wall White Paint Top
	glPushMatrix();
	glTranslatef( thickOfThings, -37.7, (-fieldWidth / 2.0) + 0.1 );
	glScalef( wallHeight, 34.2, 0.1 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	// Right Block Goal Floor Field
	glPushMatrix();
	glTranslatef( 0, 0, fieldWidth / 1.88 );
	glScalef( 1, goalWidth + 2.0, goalDepth + 2.0 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	// Right Goal White Paint Center
	glPushMatrix();
	glTranslatef( thickOfThings, 0.0, (fieldWidth / 1.88) + (thickOfThings) * 1.9 );
	glScalef( wallHeight, goalWidth + 2.0, 0.1 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	// Right Wall White Paint Bottom
	glPushMatrix();
	glTranslatef( thickOfThings, 38, (fieldWidth / 2.0) - 0.1 );
	glScalef( wallHeight, 34, 0.1 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	// Right Wall White Paint Top
	glPushMatrix();
	glTranslatef( thickOfThings, -38, (fieldWidth / 2.0) - 0.1 );
	glScalef( wallHeight, 34, 0.1 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	// Top Wall
	glPushMatrix();
	glTranslatef( thickOfThings, -fieldDepth / 2.0, 0 );
	glScalef( wallHeight, thickOfThings, fieldWidth );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	// Top Wall White Paint
	glPushMatrix();
	glTranslatef( thickOfThings, -fieldDepth / 2.0 + (thickOfThings / 2.0), 0 );
	glScalef( wallHeight, 0.2, fieldWidth - (9.0 * 2.0));
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, fieldDepth / 2.0, 0 );
	glScalef( wallHeight, thickOfThings, fieldWidth );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, fieldDepth / 2.0 - (thickOfThings / 2.0), 0 );
	glScalef( wallHeight, 0.1, fieldWidth - (9.0 * 2.0));
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, 43.2, -fieldWidth / 1.97 );
	glScalef( wallHeight, wallTop, thickOfThings );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -43.2, -fieldWidth / 1.97 );
	glScalef( wallHeight, wallTop, thickOfThings );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, 0, (-fieldWidth / 1.98) - goalDepth );
	glScalef( wallHeight, goalWidth + 1.25, thickOfThings );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -22, -fieldWidth / 1.85 );
	glScalef( wallHeight, thickOfThings, goalDepth + 1.35 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -20.6, -fieldWidth / 1.85 );
	glScalef( wallHeight, 0.1, goalDepth + 1.35 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, 22, -fieldWidth / 1.85 );
	glScalef( wallHeight, thickOfThings, goalDepth + 1.35 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, 20.6, -fieldWidth / 1.875 );
	glScalef( wallHeight, 0.1, goalDepth + 0.5 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, 20.6, fieldWidth / 1.875 );
	glScalef( wallHeight, 0.1, goalDepth + 0.5 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -20.6, fieldWidth / 1.875 );
	glScalef( wallHeight, 0.1, goalDepth + 0.5 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, 44.0, fieldWidth / 1.97 );
	glScalef( wallHeight, wallTop, thickOfThings );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -44.0, fieldWidth / 1.97 );
	glScalef( wallHeight, wallTop, thickOfThings );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, 0, fieldWidth / 1.98 + goalDepth );
	glScalef( wallHeight, goalWidth + 1.25, thickOfThings );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -22, fieldWidth / 1.85 );
	glScalef( wallHeight, thickOfThings, goalDepth + 1.35 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, 22, fieldWidth / 1.85 );
	glScalef( wallHeight, thickOfThings, goalDepth + 1.35 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, (fieldDepth / 2.0) - 4.5, (fieldWidth / 2.0) - 4.5 );
	glRotatef( 45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 14.1 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, (fieldDepth / 2.0) - 5.5, (fieldWidth / 2.0) - 5.5 );
	glRotatef( 45.0, 1, 0, 0 );
	glScalef( wallHeight, 0.1, 14.5 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, (fieldDepth / 2.0) - 3.0, (fieldWidth / 2.0) - 3.0 );
	glRotatef( 45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 9.5 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, (fieldDepth / 2.0) - 1.5, (fieldWidth / 2.0) - 1.5 );
	glRotatef( 45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 5.5 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -(fieldDepth / 2.0) + 5.5, -(fieldWidth / 2.0) + 5.5 );
	glRotatef( 45.0, 1, 0, 0 );
	glScalef( wallHeight, 0.1, 14.5 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -(fieldDepth / 2.0) + 4.5, -(fieldWidth / 2.0) + 4.5 );
	glRotatef( 45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 14.1 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -(fieldDepth / 2.0) + 3.0, -(fieldWidth / 2.0) + 3.0 );
	glRotatef( 45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 9.5 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -(fieldDepth / 2.0) + 1.5, -(fieldWidth / 2.0) + 1.5 );
	glRotatef( 45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 5.5 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -(fieldDepth / 2.0) + 5.5, (fieldWidth / 2.0) - 5.5 );
	glRotatef( -45.0, 1, 0, 0 );
	glScalef( wallHeight, 0.1, 14.5 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -(fieldDepth / 2.0) + 4.5, (fieldWidth / 2.0) - 4.5 );
	glRotatef( -45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 14.1 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -(fieldDepth / 2.0) + 3.0, (fieldWidth / 2.0) - 3.0 );
	glRotatef( -45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 9.5 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, -(fieldDepth / 2.0) + 1.5, (fieldWidth / 2.0) - 1.5 );
	glRotatef( -45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 5.5 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, (fieldDepth / 2.0) - 5.5, -(fieldWidth / 2.0) + 5.5 );
	glRotatef( -45.0, 1, 0, 0 );
	glScalef( wallHeight, 0.1, 14.5 );
	material->applyMaterial( ColorName::White );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, (fieldDepth / 2.0) - 4.5, -(fieldWidth / 2.0) + 4.5 );
	glRotatef( -45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 14.1 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, (fieldDepth / 2.0) - 3.0, -(fieldWidth / 2.0) + 3.0 );
	glRotatef( -45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 9.5 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glTranslatef( thickOfThings, (fieldDepth / 2.0) - 1.5, -(fieldWidth / 2.0) + 1.5 );
	glRotatef( -45.0, 1, 0, 0 );
	glScalef( wallHeight, thickOfThings, 5.5 );
	material->applyMaterial( ColorName::Black );
	glutSolidCube( 1 );
	glPopMatrix();

	glPushMatrix();
	glLineWidth( 5.0f );
	material->applyMaterial( ColorName::White );
	glBegin( GL_LINES );
	glVertex3f( 0.9, -fieldDepth / 2.0, 0 );
	glVertex3f( 0.9, fieldDepth / 2.0, 0 );
	glEnd();

	// CIRCLE CENTER
	float radius = 20.0;
	for(float arco = 0; arco < 2 * M_PI; arco += 0.05) {
		glBegin( GL_LINES );
		glVertex3f( 1, radius * cos( arco ), radius * sin( arco ));
		glVertex3f( 1, radius * cos((arco + 0.1)), radius * sin((arco + 0.1)) );
		glEnd();
	}

	// CIRCLE GOAL
	radius = 10.0;
	for(float arco = M_PI * 1.15; arco < 1.85 * M_PI; arco += 0.05) {
		glBegin( GL_LINES );
		glVertex3f( 1, radius * cos( arco ), 64.5 + radius * sin( arco ));
		glVertex3f( 1, radius * cos((arco + 0.1)), 64.5 + radius * sin((arco + 0.1)) );
		glEnd();
	}

	// CIRCLE GOAL
	radius = 10.0;
	for(float arco = 0.4; arco < M_PI * 0.85; arco += 0.05) {
		glBegin( GL_LINES );
		glVertex3f( 1, radius * cos( arco ), -64.5 + radius * sin( arco ));
		glVertex3f( 1, radius * cos((arco + 0.1)), -64.5 + radius * sin((arco + 0.1)) );
		glEnd();
	}

	// GOAL LINE
	glBegin( GL_LINES );
	glVertex3f( 0.9, -20, 75.5 );
	glVertex3f( 0.9, 20, 75.5 );
	glEnd();

	// AREA LINE
	glBegin( GL_LINES );
	glVertex3f( 0.9, -35, 60.5 );
	glVertex3f( 0.9, 35, 60.5 );
	glEnd();

	// AREA BOTTOM LINE
	glBegin( GL_LINES );
	glVertex3f( 0.9, 35, 60.5 );
	glVertex3f( 0.9, 35, 75 );
	glEnd();

	// AREA TOP LINE
	glBegin( GL_LINES );
	glVertex3f( 0.9, -35, 60.5 );
	glVertex3f( 0.9, -35, 75 );
	glEnd();

	// GOAL LINE
	glBegin( GL_LINES );
	glVertex3f( 0.9, -20, -75.5 );
	glVertex3f( 0.9, 20, -75.5 );
	glEnd();

	// AREA BOTTOM LINE
	glBegin( GL_LINES );
	glVertex3f( 0.9, 35, -60.5 );
	glVertex3f( 0.9, 35, -75 );
	glEnd();

	// AREA TOP LINE
	glBegin( GL_LINES );
	glVertex3f( 0.9, -35, -60.5 );
	glVertex3f( 0.9, -35, -75 );
	glEnd();

	// AREA LINE
	glBegin( GL_LINES );
	glVertex3f( 0.9, -35, -60.5 );
	glVertex3f( 0.9, 35, -60.5 );
	glEnd();

	// CROSS MIDDLE RIGHT
	glBegin( GL_LINES );
	glVertex3f( 0.9, 0, 37.5 - 2.5 );
	glVertex3f( 0.9, 0, 37.5 + 2.5 );
	glEnd();
	glBegin( GL_LINES );
	glVertex3f( 0.9, -2.5, 37.5 );
	glVertex3f( 0.9, 2.5, 37.5 );
	glEnd();

	// CROSS DOWN RIGHT
	glBegin( GL_LINES );
	glVertex3f( 0.9, (fieldDepth / 2.0) - 25, 37.5 - 2.5 );
	glVertex3f( 0.9, (fieldDepth / 2.0) - 25, 37.5 + 2.5 );
	glEnd();
	glBegin( GL_LINES );
	glVertex3f( 0.9, (fieldDepth / 2.0) - 25 - 2.5, 37.5 );
	glVertex3f( 0.9, (fieldDepth / 2.0) - 25 + 2.5, 37.5 );
	glEnd();

	// CROSS UP RIGHT
	glBegin( GL_LINES );
	glVertex3f( 0.9, -(fieldDepth / 2.0) + 25, 37.5 - 2.5 );
	glVertex3f( 0.9, -(fieldDepth / 2.0) + 25, 37.5 + 2.5 );
	glEnd();
	glBegin( GL_LINES );
	glVertex3f( 0.9, -(fieldDepth / 2.0) + 25 - 2.5, 37.5 );
	glVertex3f( 0.9, -(fieldDepth / 2.0) + 25 + 2.5, 37.5 );
	glEnd();

	// CROSS MIDDLE LEFT
	glBegin( GL_LINES );
	glVertex3f( 0.9, 0, -37.5 - 2.5 );
	glVertex3f( 0.9, 0, -37.5 + 2.5 );
	glEnd();
	glBegin( GL_LINES );
	glVertex3f( 0.9, -2.5, -37.5 );
	glVertex3f( 0.9, 2.5, -37.5 );
	glEnd();

	// CROSS DOWN LEFT
	glBegin( GL_LINES );
	glVertex3f( 0.9, (fieldDepth / 2.0) - 25, -37.5 - 2.5 );
	glVertex3f( 0.9, (fieldDepth / 2.0) - 25, -37.5 + 2.5 );
	glEnd();
	glBegin( GL_LINES );
	glVertex3f( 0.9, (fieldDepth / 2.0) - 25 - 2.5, -37.5 );
	glVertex3f( 0.9, (fieldDepth / 2.0) - 25 + 2.5, -37.5 );
	glEnd();

	// CROSS UP LEFT
	glBegin( GL_LINES );
	glVertex3f( 0.9, -(fieldDepth / 2.0) + 25, -37.5 - 2.5 );
	glVertex3f( 0.9, -(fieldDepth / 2.0) + 25, -37.5 + 2.5 );
	glEnd();
	glBegin( GL_LINES );
	glVertex3f( 0.9, -(fieldDepth / 2.0) + 25 - 2.5, -37.5 );
	glVertex3f( 0.9, -(fieldDepth / 2.0) + 25 + 2.5, -37.5 );
	glEnd();
	glPopMatrix();
}
