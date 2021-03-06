/*
 * Copyright (C) 2017 Daewoong Jang.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "PlatformHandle.h"

namespace android {
namespace os {

void PlatformHandle::platformClose(intptr_t handle)
{
    if (handle)
        ::CloseHandle(reinterpret_cast<HANDLE>(handle));
}

intptr_t PlatformHandle::platformDuplicate(intptr_t handle)
{
    HANDLE processHandle = ::GetCurrentProcess();

    HANDLE duplicatedHandle;
    if (!::DuplicateHandle(processHandle, reinterpret_cast<HANDLE>(handle), processHandle, &duplicatedHandle, 0, FALSE, DUPLICATE_SAME_ACCESS))
        return 0;

    return reinterpret_cast<intptr_t>(duplicatedHandle);
}

intptr_t PlatformHandle::platformDuplicate(intptr_t handle, int64_t sourcePid)
{
    if (!sourcePid || !handle)
        return 0;

    HANDLE sourceProcess = ::OpenProcess(PROCESS_DUP_HANDLE, FALSE, sourcePid);
    if (!sourceProcess)
        return 0;

    HANDLE duplicatedHandle;
    BOOL ok = ::DuplicateHandle(sourceProcess, reinterpret_cast<HANDLE>(handle), ::GetCurrentProcess(), &duplicatedHandle, 0, FALSE, DUPLICATE_SAME_ACCESS | DUPLICATE_CLOSE_SOURCE);
    assert_wtf(ok);

    ::CloseHandle(sourceProcess);

    return reinterpret_cast<intptr_t>(duplicatedHandle);
}

} // namespace os
} // namespace android
