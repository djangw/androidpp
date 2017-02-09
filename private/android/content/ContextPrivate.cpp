/*
 * Copyright (C) 2016 Naver Corp. All rights reserved.
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

#include "ContextPrivate.h"

#include <android/content/ContextWrapper.h>

namespace android {
namespace content {

static ApplicationContext* globalContext = nullptr;

ContextPrivate::ContextPrivate()
{
}

ContextPrivate& ContextPrivate::getPrivate(Context& context)
{
    return *context.m_private;
}

void ContextPrivate::setPrivate(Context& context, std::unique_ptr<ContextPrivate>&& contextPrivate)
{
    context.m_private = std::move(contextPrivate);
}

ApplicationContext& ContextPrivate::getGlobalContext()
{
    return *globalContext;
}

void ContextPrivate::setGlobalContext(ApplicationContext& context)
{
    globalContext = &context;
}

void ContextPrivate::setAsActivity()
{
    m_isActivity = true;
}

void ContextPrivate::setAsService()
{
    m_isService = true;
}

void ContextPrivate::setAsApplicationContext()
{
    m_isApplicationContext = true;
}

bool ContextPrivate::isActivity()
{
    return m_isActivity;
}

bool ContextPrivate::isService()
{
    return m_isService;
}

bool ContextPrivate::isApplication()
{
    return isActivity() || isService();
}

bool ContextPrivate::isApplicationContext()
{
    return m_isApplicationContext;
}

app::ApplicationLoader* ContextPrivate::getApplicationLoader()
{
    return m_loader;
}

void ContextPrivate::setApplicationLoader(app::ApplicationLoader* loader)
{
    m_loader = loader;
}

} // namespace content
} // namespace android
