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

#ifndef GLUT_FRAMEWORK_H
#define GLUT_FRAMEWORK_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux
#include <GL/glut.h>
#endif

#include "Keyboard.h"
#include <unistd.h>

class GlutFramework {

private:

	Keyboard keyStates;

protected:

	static GlutFramework *instance;

public:

	int FPS;

public:
	int windowWidth;
	int windowHeight;
	int fieldHeight;
	int fieldWidth;

	GlutFramework();

	virtual void start( int argc, char *argv[] );
	virtual void display();
	virtual void reshape( int width, int height );
	virtual void mouseButtonPress( int button, int state, int x, int y );
	virtual void mouseMove( int x, int y );
	virtual void keyboardDown( unsigned char key, int x, int y );
	virtual void keyboardUp( unsigned char key, int x, int y );
	virtual void specialKeyboardDown( int key, int x, int y );
	virtual void specialKeyboardUp( int key, int x, int y );
	void setDisplayMatricies();
	void setupLights();

	void init();
	void setInstance();
	void run();
	void displayFramework();

	static void displayWrapper();
	static void reshapeWrapper( int width, int height );
	static void runWrapper();
	static void mouseButtonPressWrapper( int button, int state, int x, int y );
	static void mouseMoveWrapper( int x, int y );
	static void keyboardDownWrapper( unsigned char key, int x, int y );
	static void keyboardUpWrapper( unsigned char key, int x, int y );
	static void specialKeyboardDownWrapper( int key, int x, int y );
	static void specialKeyboardUpWrapper( int key, int x, int y );
};

#endif // GLUT_FRAMEWORK_H
