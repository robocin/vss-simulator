/*
 * This file is part of the VSS-Viewer project.
 *
 * This Source Code Form is subject to the terms of the GNU GENERAL PUBLIC LICENSE,
 * v. 3.0. If a copy of the GPL was not distributed with this
 * file, You can obtain one at http://www.gnu.org/licenses/gpl-3.0/.
 */

#include "Kernel.h"
#include "Builders/StdinInterpreterBuilder.h"

vss::ExecutionConfig loadExecutionConfig(int argc, char** argv){
	auto stdinInterpreterBuilder = new vss::StdinInterpreterBuilder();

	stdinInterpreterBuilder
			->onStateRecvAddr()
			->onStatePort()
			->onCtrlPort()
			->onYellowDebugPort()
			->onBlueDebugPort();

	auto stdinInterpreter = stdinInterpreterBuilder->buildInterpreter();

	return stdinInterpreter->extractExecutionConfig(argc, argv);
}


int main( int argc, char *argv[] ) {
	auto executionConfig = loadExecutionConfig(argc, argv);

	if(!executionConfig.isValidConfiguration)
		return 0;

	Kernel kernel(argc, argv, executionConfig);
	kernel.init();
	return 0;
}
