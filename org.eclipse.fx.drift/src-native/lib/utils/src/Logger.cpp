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

#include <iomanip>
#include <string>
#include <string.h>
#include <algorithm>

#include <utils/Logger.h>

std::ostream& operator<<(std::ostream& ostr, const LogLevel& level) {
	switch (level) {
	case Debug: return ostr << "DEBUG";
	case Error: return ostr << "ERROR";
	case Info: return ostr << "INFO";
	default: return ostr;
	}
}

#ifdef WIN32
	struct MatchPathSeparator {
		bool operator()(char c) const {
			return c == '\\' || c == '/';
		}
	};
#else
	struct MatchPathSeparator {
		bool operator()(char c) const {
			return c == '/';
		}
	};
#endif


std::string filename(std::string file) {
	return std::string(
		std::find_if( file.rbegin(), file.rend(), MatchPathSeparator() ).base(),
		file.end() );
}

std::string cut(std::string str, int size) {
	int len = str.length();
	if (len < size) return str;
	else return str.substr(len-size, size);
}

std::ostream& Log(LogLevel level, std::string file, int line, std::string func) {
	std::string fname = filename(file);
	return std::cout << "[C] [" << std::setw(5) << level << "] " << std::setw(40) << std::right << cut(fname, 40) << ":" << std::dec << std::setw(3) << line << " - " << std::setw(100) << std::left << cut(func, 100) << " ";
}
