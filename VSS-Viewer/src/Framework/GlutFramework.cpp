/*
 * The MIT License
 *
 * Copyright (c) 2010 Paul Solt, PaulSolt@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "GlutFramework.h"

GlutFramework *GlutFramework::instance = NULL;

GlutFramework::GlutFramework() {
	FPS = 30;
	windowWidth = 1280;
	windowHeight = 720;

	// TODO: Isso varia de campo para campo
	fieldHeight = windowHeight - (13 * 2);
	fieldWidth = fieldHeight * 1.307692308;
}

void GlutFramework::start( int argc, char *argv[] ) {
	setInstance();

	glutInit( &argc, argv );
	glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE );
	glutInitWindowPosition( 100, 100 );
	glutInitWindowSize( windowWidth, windowHeight );
	glutCreateWindow( "vss-viewer" );

	glutReshapeFunc( reshapeWrapper );
	glutMouseFunc( mouseButtonPressWrapper );
	glutMotionFunc( mouseMoveWrapper );
	glutDisplayFunc( displayWrapper );
	glutKeyboardFunc( keyboardDownWrapper );
	glutKeyboardUpFunc( keyboardUpWrapper );
	glutSpecialFunc( specialKeyboardDownWrapper );
	glutSpecialUpFunc( specialKeyboardUpWrapper );

	init();
	glutIdleFunc( runWrapper );
	glutMainLoop();
}

void GlutFramework::display() {
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glLoadIdentity();

	glTranslatef( 0.0f, 0.0f, 0 );
	glRotatef( 180.0, 1, 0, 0 );
	glRotatef( 90.0, 0, 1, 0 );
	glTranslatef( -130.0, 0.0, -0.0 );
}

void GlutFramework::reshape( int width, int height ) {
}

void GlutFramework::mouseButtonPress( int button, int state, int x, int y ) {
}

void GlutFramework::mouseMove( int x, int y ) {
}

void GlutFramework::keyboardDown( unsigned char key, int x, int y ){
}

void GlutFramework::keyboardUp( unsigned char key, int x, int y ){
}

void GlutFramework::specialKeyboardDown( int key, int x, int y ){
}

void GlutFramework::specialKeyboardUp( int key, int x, int y ){
}

void GlutFramework::setDisplayMatricies() {
	int width = glutGet( GLUT_WINDOW_WIDTH );
	int height = glutGet( GLUT_WINDOW_HEIGHT );

	glViewport( 0, 0, width, height );
	float aspect = (float)width / height;
	float depthObs = 3000;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	gluPerspective( 15, aspect, 0.1f, depthObs );
	glMatrixMode( GL_MODELVIEW );
}

void GlutFramework::setupLights() {
	GLfloat white_light[] = { 0.25, 0.25, 0.25, 1.0 };
	GLfloat lmodel_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat ambient_light[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light1_position[] = { 0.0, 1.0, 1.0, 0.0 };

	glLightfv( GL_LIGHT0, GL_AMBIENT, ambient_light );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, white_light );
	glLightfv( GL_LIGHT0, GL_SPECULAR, white_light );
	glLightfv( GL_LIGHT0, GL_POSITION, light1_position );

	glLightModelfv( GL_LIGHT_MODEL_AMBIENT, lmodel_ambient );

	glClearColor( 0.05f, 0.05f, 0.3f, 1.0f );
}

void GlutFramework::init() {
	glClearColor( 0.0, 0.0, 0.0, 1.0 );

	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0 );
	glShadeModel( GL_SMOOTH );
	glEnable( GL_DEPTH_TEST );
}

void GlutFramework::setInstance() {
	instance = this;
}

void GlutFramework::run() {
	usleep( FPS / 1000000 );
	glutPostRedisplay();
}

void GlutFramework::displayFramework() {
	glClearColor( 0.0, 0.0, 0.0, 1.0 );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Clear once

	setupLights();
	setDisplayMatricies();

	display();

	glutSwapBuffers();
}

void GlutFramework::displayWrapper() {
	instance->displayFramework();
}

void GlutFramework::reshapeWrapper( int width, int height ) {
	instance->reshape( width, height );
}

void GlutFramework::runWrapper() {
	instance->run();
}

void GlutFramework::mouseButtonPressWrapper( int button, int state, int x, int y ) {
	instance->mouseButtonPress( button, state, x, y );
}

void GlutFramework::mouseMoveWrapper( int x, int y ) {
	instance->mouseMove( x, y );
}

void GlutFramework::keyboardDownWrapper( unsigned char key, int x, int y ) {
	instance->keyboardDown( key, x, y );
}

void GlutFramework::keyboardUpWrapper( unsigned char key, int x, int y ) {
	instance->keyboardUp( key, x, y );
}

void GlutFramework::specialKeyboardDownWrapper( int key, int x, int y ) {
	instance->specialKeyboardDown( key, x, y );
}

void GlutFramework::specialKeyboardUpWrapper( int key, int x, int y ) {
	instance->specialKeyboardUp( key, x, y );
}
