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

#pragma once

#include <android.h>
#include <android/app/Service.h>
#include <android/os/Messenger.h>

namespace com {
namespace example {

class TestService : public Service {
public:
    /** Command to the service to display a message */
    static const int32_t MSG_SAY_HELLO = 1;

    ANDROID_EXTERN TestService();
    ANDROID_EXTERN ~TestService();

    std::shared_ptr<IBinder> onBind(Intent& intent) override;
    void onConfigurationChanged(Configuration& newConfig) override;
    void onCreate() override;
    void onDestroy() override;
    void onLowMemory() override;
    void onRebind(Intent& intent) override;
    void onStartCommand(Intent& intent, int32_t flags, int32_t startId) override;
    void onTaskRemoved(Intent& rootIntent) override;
    void onTrimMemory(int32_t level) override;
    bool onUnbind(Intent& intent) override;

private:
    std::shared_ptr<Messenger> mMessenger;
};

} // namespace example
} // namespace com
