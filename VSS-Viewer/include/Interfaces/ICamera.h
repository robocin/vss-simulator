/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#ifndef ICAMERA_H
#define ICAMERA_H

class ICamera {
public:

	void virtual applyPosition() = 0;
};

#endif // ICAMERA_H
