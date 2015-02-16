/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * All-inclusive internal header file.  Include this to get everything useful.
 */
#ifndef DALVIK_DALVIK_H_
#define DALVIK_DALVIK_H_

#include "Common.h"
#include "Inlines.h"
#include "DvmDex.h"
#include "ReferenceTable.h"
#include "IndirectRefTable.h"
#include "Sync.h"
#include "Debugger.h"
#include "Thread.h"
#include "libdex/DexProto.h"
#include "oo/Object.h"
#include "Native.h"

#include "interp/Stack.h"
#include "oo/Class.h"
#include "oo/Array.h"
#include "Exception.h"
#include "alloc/Alloc.h"
#if defined(WITH_JIT)
#endif
#include "Globals.h"
#include "reflect/Reflect.h"
#include "Atomic.h"
#include "interp/Stack.h"

#endif  // DALVIK_DALVIK_H_

char* dvmNameToDescriptor(const char* str);
extern "C" void dvmAbort(void);
