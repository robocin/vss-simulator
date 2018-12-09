/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef FIELD_DRAWER_150X130_H
#define FIELD_DRAWER_150X130_H

#ifdef _WIN32
#include <windows.h>
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linux
#include <GL/glut.h>
#endif

#include "ColorEnum.h"
#include "IFieldDrawer.h"
#include "Material.h"

class FieldDrawerVerySmallSize : public IFieldDrawer {
private:

	const float fieldWidth = 150.0;
	const float fieldDepth = 130.0;
	const float goalWidth = 40.0;
	const float goalDepth = 10.0;
	const float wallHeight = 5.0;
	const float wallTop = 45.0;
	const float thickOfThings = 2.5;

public:

	Material *material;

	FieldDrawerVerySmallSize();
	void draw() override;
};

#endif // FIELD_DRAWER_150X130_H
