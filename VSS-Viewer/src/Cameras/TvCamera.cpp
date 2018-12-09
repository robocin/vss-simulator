/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "TvCamera.h"

TvCamera::TvCamera(){

}

void TvCamera::applyPosition(){
	glTranslatef( 0.0f, 0.0f, -0 );
	glRotatef( 135.0, 1, 0, 0 );

	glRotatef( 90.0, 0, 1, 0 );
	glTranslatef( -310.0, -310.0, -0.0 );
}
