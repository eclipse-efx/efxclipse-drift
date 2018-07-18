/*
 * Copyright (c) 2018 BestSolution and Others. All rights reserved.
 *
 * This program and the accompanying materials are made available under the
 * terms of the Eclipse Public License v. 2.0, which is available at
 * http://www.eclipse.org/legal/epl-2.0.
 *
 * This Source Code may also be made available under the following Secondary
 * Licenses when the conditions for such availability set forth in the
 * Eclipse Public License v. 2.0 are satisfied: GNU General Public License,
 * version 2 with the GNU Classpath Exception, which is available at
 * https://www.gnu.org/software/classpath/license.html.
 *
 * SPDX-License-Identifier: EPL-2.0 OR GPL-2.0 WITH Classpath-exception-2.0
 */

#ifndef UTILS_LOGGER_H_
#define UTILS_LOGGER_H_


#include <iostream>
#include <ostream>
#include <string>

enum LogLevel { Debug, Error, Info };

std::ostream& operator<<(std::ostream& ostr, const LogLevel& level);
std::ostream& Log(LogLevel level, std::string file, int line, std::string func);

#define WITH_LOGGING 0

#ifdef WITH_LOGGING

#define LogDebug(msg) Log(Debug, __FILE__, __LINE__, __PRETTY_FUNCTION__) << msg << std::endl;
#define LogError(msg) Log(Error, __FILE__, __LINE__, __PRETTY_FUNCTION__) << msg << std::endl;
#define LogInfo(msg) Log(Info, __FILE__, __LINE__, __PRETTY_FUNCTION__) << msg << std::endl;
#else
#define LogDebug(msg)
#define LogError(msg)
#define LogInfo(msg)
#endif


#endif /* COMMON_H_ */
