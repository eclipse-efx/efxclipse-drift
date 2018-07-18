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

#ifndef SHAREDSURFACE_WIN32_ERROR_H_
#define SHAREDSURFACE_WIN32_ERROR_H_

#include "../Common.h"

#include <windows.h>

#include <string>
#include <iostream>
#include <iomanip>

#define WERR(errcode) errcode; { DWORD err = GetLastError(); SetLastError(0); if (err != 0) LogError("Windows Error 0x" << hex << HRESULT_CODE(err) << " (" << #errcode ")" << endl << "Message: " << ToString(HRESULT_CODE(err))) }

std::string ToString(DWORD err);

#endif /* SHAREDSURFACE_WIN32_ERROR_H_ */
