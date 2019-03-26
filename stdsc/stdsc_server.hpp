/*
 * Copyright 2018 Yamana Laboratory, Waseda University
 * Supported by JST CREST Grant Number JPMJCR1503, Japan.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE‐2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef STDSC_SERVER_HPP
#define STDSC_SERVER_HPP

#include <memory>
#include <stdsc/stdsc_thread.hpp>

namespace stdsc
{
class Packet;
class ServerParam;
class CallbackFunctionContainer;
class StateContext;

/**
 * @brief Provides server function.
 */
template <class T = ServerParam>
class Server : public Thread<T>
{
    using super = Thread<T>;

public:
    Server(const char* port, StateContext& state);
    virtual ~Server(void);

    void set_callback(CallbackFunctionContainer& callback);
    void start(void);
    void wait_for_finish(void);

private:
    virtual void exec(T& args, std::shared_ptr<ThreadException> te) const;

    struct Impl;
    std::shared_ptr<Impl> pimpl_;
};

struct ServerParam
{
    int dummy;
};

} /* namespace stdsc */

#endif /* STDSC_SERVER_HPP */
